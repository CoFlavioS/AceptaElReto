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

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < n; j++) {
			m[i][j] = scan_fast();
			sum += m[i][j];
			if (*estado == 2 && (m[i][j] < 1 || m[i][j] > n * n))* estado = 1;
		}
		if (cm == -1) cm = sum;
		if ((*estado == 2 || *estado == 1) && cm != sum)* estado = 0;
	}

	return cm;
}

int main(void) {
	int n = scan_fast(), m[n][n], cm, estado;

	while (n > 0) {
		estado = 2;
		cm = rellenarMat(n, m, &estado);

		if (estado == 2) {

		}

		if (estado == 2) printf("ESOTERICO");
		else if (estado == 1) printf("DIABOLICO");
		else printf("NO");
		n = scan_fast();
	}

	return 0;
}