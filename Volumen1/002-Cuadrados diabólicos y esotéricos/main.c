#include <stdio.h>

#define gc getchar_unlocked

int scan_fast() {
	int n = 0;
	char ch = gc();
	while (ch < '0' && ch >'9') {
		ch = gc(); // ignoring chars that are not digit
	}
	while (ch >= '0' && ch <= '9') {
		n = n * 10 + ch - '0'; // for each digit add it to n in proper place
		ch = gc();
	}
	return n;
}

int rellenarMat(int n, int m[n][n], int* estado) {
	int i, j, sum, cm = -1;
	int num[n * n], col[n + 2];

	for (i = 0; i < n * n; i++) num[i] = 0;
	for (i = 0; i < n + 2; i++) col[i] = 0;

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < n; j++) {
			m[i][j] = scan_fast();
			sum += m[i][j];
			col[j] += m[i][j];
			if (i == j) col[n] += m[i][j];
			if (i + j == n - 1) col[n + 1] += m[i][j];
			if (*estado == 2 && (m[i][j] < 1 || m[i][j] > n * n))* estado = 1;
			else if (m[i][j] >= 1 && m[i][j] <= n * n) {
				if (*estado == 2 && num[m[i][j] - 1] == 1)* estado = 1;
				num[m[i][j] - 1] = 1;
			}
		}
		if (cm == -1) cm = sum;
		if ((*estado == 2 || *estado == 1) && cm != sum)* estado = 0;
	}

	if (*estado == 2 || *estado == 1) {
		i = 0;
		while (i < n + 2 && cm == col[i]) {
			i++;
		}
		if (i != n + 2)* estado = 0;
	}

	return cm;
}

int main(void) {
	int n = scan_fast(), cm, cm2, estado;

	while (n > 0) {
		estado = 2;
		int m[n][n];
		cm = rellenarMat(n, m, &estado);

		if (estado == 2) {
			cm2 = (4 * cm) / n;
			if (cm2 != m[0][0] + m[0][n - 1] + m[n - 1][0] + m[n - 1][n - 1]) estado = 1;
			if (n % 2 != 0) {
				if (cm2 != m[0][(n - 1) / 2] + m[(n - 1) / 2][0] + m[n - 1][(n - 1) / 2] + m[(n - 1) / 2][n - 1]) estado = 1;
				if (cm2 != 4 * m[(n - 1) / 2][(n - 1) / 2]) estado = 1;
			}
			else {
				if (2 * cm2 != m[0][n / 2] + m[0][(n / 2) - 1] + m[n / 2][0] + m[(n / 2) - 1][0] + m[n - 1][n / 2] + m[n - 1][(n / 2) - 1] + m[(n / 2) - 1][n - 1] + m[n / 2][n - 1]) estado = 1;
				if (cm2 != m[n / 2][n / 2] + m[n / 2][(n / 2) - 1] + m[(n / 2) - 1][n / 2] + m[(n / 2) - 1][(n / 2) - 1]) estado = 1;
			}
		}

		if (estado == 2) printf("ESOTERICO\n");
		else if (estado == 1) printf("DIABOLICO\n");
		else printf("NO\n");
		n = scan_fast();
	}

	return 0;
}