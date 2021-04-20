#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void orden(int izq, int der, char a[]);
void inverso(char num[],char inv[]);
int esRepdig(char num[]);
void escaneaNumero(char num[]);
int vectorToInt(char num[]);
void intToVector(int num, char[]);

int main()
{
    char num[4],inv[4];
    int aux, iter;

    escaneaNumero(num);
    while(num[0] != '\n'){
        if(esRepdig(num)){
            iter = 8;
        }
        else{
            iter = 0;
            while(vectorToInt(num) != 6174){
                iter++;
                orden(0,3,num);
                inverso(num, inv);
                aux = vectorToInt(inv) - vectorToInt(num);
                intToVector(aux, num);
            }
        }
        printf("%d\n", iter);
        escaneaNumero(num);
    }

    return 0;
}

void orden(int izq, int der, char a[]){
    int i,j;
    char tmp,x;
    i = izq;
    j = der;
    x = a[(izq + der)/2];
    do{
        while (a[i] < x) i++;
        while (x < a[j]) j--;
        if (i <= j){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }while (i <= j);
    if (izq < j)
        orden(izq, j, a);
    if (i < der)
        orden(i, der, a);
}

void inverso(char num[],char inv[]){
    int i;

    for(i = 0; i < 4; i++){
        inv[i] = num[3-i];
    }
}

int esRepdig(char num[]){
    return num[0] == num[1] && num[0] == num[2] && num[0] == num[3];
}

void escaneaNumero(char num[]){
    int i = 0, parada = 0;

    while(i<4 && !parada){
        scanf("%c", &num[i]);
        if(num[i] == ' ') i = 0;
        else if(num[i] == '\n'){
            num[0] = '\n';
            parada = 1;
        }
        else i++;
    }
}

int vectorToInt(char num[]){
    return (int)(num[0]-'0')*1000+(int)(num[1]-'0')*100+(int)(num[2]-'0')*10+(int)(num[3]-'0');
}

void intToVector(int num, char numc[]){
    int i, aux;
    double dnum = (double)num;

    for(i=0; i<4; i++){
        aux = floor(dnum/pow(10,3-i));
        numc[i] = aux + '0';
        dnum -= floor(dnum/pow(10,3-i))*pow(10,3-i);
    }
}
