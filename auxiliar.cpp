#include "problemas.h"
#include "auxiliar.h"

int longitud (char *c) {
    int i = 0;
    for (;c[i]!='\0';i++);
    return i+1;
}

int GenNumRand () {
    srand(time(NULL));
    int NumRand;
    NumRand = rand() % (91 - 65);
    return NumRand;
}

long long int Potencia(int pot, int base) {
    long long int res = 1;
    for (int i=0; i<pot; i++) {
        res *= base;
    }
    return  res;
}

void ImpMatriz(int **Matriz){
    for (int f=0; f<5; f++ ) {
        for (int c=0; c<5; c++) {
            cout << Matriz[f][c] << '\t';
        }
        cout << endl << endl;
    }
}

void RotarMatriz(int **Matriz){
    int copy[5][5];

    for (int f=0; f<5; f++) {
        for (int c=0; c<5; c++) {
            copy[f][c] = Matriz[f][c];
        }
    }

    for (int f=0; f<5; f++) {
        for (int c=0; c<5; c++) {
            Matriz[c][4-f] = copy[f][c];
        }
    }
}

int FindRoads(int fnodo, int cnodo, int v, int nodos) {
    bool roads[2];
    roads[0] = (cnodo<v-1);
    roads[1] = (fnodo<v-1);

    if (fnodo == v-1 && cnodo == v-1) {
        nodos++;
    }
    if (roads[0]) {
        nodos = FindRoads(fnodo, cnodo+1, v, nodos);
    }
    if (roads[1]) {
        nodos = FindRoads(fnodo+1, cnodo, v, nodos);
    }

    return nodos;
}



int **matriz(int *m, int elementos){
    int n = sqrt(elementos);
    int **mat = new int*[n];

    for (int i=0; i<n; i++) {
        mat[i] = new int[n];
    }

    for (int f=0; f<n; f++) {
        for (int c=0; c<n; c++) {
            mat[f][c] = m[c+f*n];
        }
    }
    return mat;
}

int FindNum(char *c) {
    int nums = 0;
    for (int i=0; c[i]!='\0'; i++) {
        if (!isalpha(c[i])) nums++;
    }
    return nums;
}

int FindLet(char *c){
    int lets = 0;
    for (int i=0; c[i]!='\0'; i++) {
        if (isalpha(c[i])) lets++;
    }
    return lets;
}

long long int factorial(int n) {
    long long int fact = 1;
    for (; n>1;n--) fact *= n;
    return fact;
}

char *permutaciones(int y, int num) {
    int grupo;
    char combina[]="0123456789";
    static char permuta[11];
    permuta[10] = '\0';

    for (; num>=1; num--) {
        grupo = y/factorial(num-1);
        permuta[10-num] = combina[grupo];
        eliminar(combina, grupo);
        y %= factorial(num-1);
    }
    return permuta;
}

void eliminar(char *p, int n)
{
    for (int i=n; p[i]!='\0'; i++) {
        p[i] = p[i+1];
    }
}

bool numAmigable (int n){

    bool x=true;
    int divisor1=0, divisor2=0;

    for(int i=1;i<=n/2;i++)if(n%i==0)divisor1+=i;
    for(int i=1;i<=divisor1/2;i++)if(divisor1%i==0)divisor2+=i;


    if(n!=divisor2 || n==divisor1) x=false;
    return x;
}
