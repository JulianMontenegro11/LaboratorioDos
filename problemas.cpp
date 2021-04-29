# include "problemas.h"
#include "auxiliar.h"



void problema2(){
    char *a = new char[200];
    srand(time(NULL));
    for(int i=0; i<200 ; i++){
     a[i]=65 + (rand()% (91 - 65) );    //genera un número al azar y lo suma a 65
     cout<<a[i];    //El número generado se convierte en una carcater

}
    cout<<endl;
    int contador =0;
    for (char j=65; j<=90; j++){
        for(int k=0; k<=200; k++){
            char B=a[k];
            if(B==j){
                contador++;
            }
        }
        cout<< j <<": "<< contador << endl;
        contador=0;
        }
    delete[] a;
}

bool problema3(char *c1, char*c2){
    bool salida = true;
    if (longitud(c1)!=longitud(c2)) {
        salida = false;
    }
    else {
        for (int i=0; *(c1+i)!='\0'; i++) {
            if (c1[i]!=c2[i]) {
                salida = false;
                break;
            }
        }
    }
    return salida;
}

long long int problema4(char *c) {
    long long int FinalNum = 0;
    int len, pot;
    len = longitud(c);
    pot = longitud(c)-2;
    for (int i=0; i<len; i++) {
        if (c[i]=='1')  FinalNum += 1 * Potencia(pot, 10);
        else if (c[i]=='2')  FinalNum += 2 * Potencia(pot, 10);
        else if (c[i]=='3')  FinalNum += 3 * Potencia(pot, 10);
        else if (c[i]=='4')  FinalNum += 4 * Potencia(pot, 10);
        else if (c[i]=='5')  FinalNum += 5 * Potencia(pot, 10);
        else if (c[i]=='6')  FinalNum += 6 * Potencia(pot, 10);
        else if (c[i]=='7')  FinalNum += 7 * Potencia(pot, 10);
        else if (c[i]=='8')  FinalNum += 8 * Potencia(pot, 10);
        else if (c[i]=='9')  FinalNum += 9 * Potencia(pot, 10);
        pot--;
    }
    return FinalNum;
}

void problema5(int num, char *c){
    int contador=0;
    int a=num; //variable auxiliar que toma el valor del numero
    while(a>0){ //cuanta los digitos que tendra la cadena numerica
        a=a/10;
        contador++;
    }

    c[contador]='\0';
    a=num;
    int posicion = contador-1, digito;
    while (posicion>=0){
        digito =a%10;
        a=a/10;
        c[posicion]= digito +'0';
        posicion--;
    }
    cout<<"La cadena correspondiente al numero es: "<<c<<endl;
}

char * problema6(char *c) {
    int len;
    len = longitud(c);
    char letra;
    for (int i=0; i<len; i++) {
        if (islower(c[i])) {
            letra = toupper(c[i]);
            c[i] = letra;
        }
        else {
            c[i] = c[i];
        }
    }
    return c;
}

void problema7(char *c){
    char final[10];
    int contador=0;
    int repetido=0;
    for(int i=0;c[i]!='\0';i++){
       int j =0;
        while(j<=10){
           if(c[i]==final[j]){
              repetido++;
              j++;
           }else{
               j++;

            }


        }
        j=0;
        if(repetido==0){
            final[contador]=c[i];
            contador++;

        }else{

            repetido=0;
        }

    }
     cout<<"Origianl: "<<c<<"    "<<"Sin repetidos: "<<final<<endl;
}

void problema8(char *c1, char *c2) {
    int size1, size2, posl, posn;
    char *cadena;
    cadena = c1;
    size1 = FindLet(c1);
    size2 = FindNum(c1);
    c1 = new char[size1+1];
    c2 = new char[size2+1];
    posl = 0;
    posn = 0;
    for (int i=0; cadena[i]!='\0'; i++) {
        if (isalpha(cadena[i])) {
            c1[posl] = cadena[i];
            posl++;
        }
        else {
            c2[posn] = cadena[i];
            posn++;
        }
    }
    cout << c1 << endl;
    cout << c2 << endl;
}



long long int problema9(char *c, long long int n){
    int numero,b,contador,a,grupos,grupo,separar,suma;
    contador=0;
     numero= atoi(c);
    b=numero; // b toma el valor de numero para no modificar la el valor inicial de numero
    while (b!=0) {
        a=b%10;
        b=b/10;
        contador++;
    }


   grupos=contador/n;
    if(grupos%n==0){
        separar=pow(10,contador-n);
        while (numero!=0) {
            grupo=numero/separar;
            numero=numero%separar;
            suma=suma+grupo;

            cout<<grupo<<" + ";

        }
    }else{

        separar=pow(10,(contador-n));
        grupo=numero%separar;
        numero=numero/separar;
        suma=numero;


        cout<<"0"<<numero<<" + ";
        contador=0;
        int nuevoGrupo=grupo;

        while (grupo!=0) {
            a=grupo%10;
            grupo=grupo/10;
            contador++;
        }
        separar=pow(10,contador-n);
        while (nuevoGrupo!=0) {
            if(nuevoGrupo/separar==0){
                cout<<nuevoGrupo;
                suma=suma+nuevoGrupo;
                nuevoGrupo=0;

            }else{
                grupo=nuevoGrupo/separar;
                nuevoGrupo=nuevoGrupo%separar;
                suma=suma+grupo;

                cout<<grupo<<" + ";
            }

        }



    }

    cout<<" = "<<suma<<endl;



}


long long int problema10(char *c){
    int total=0, NewValue = 0, OldValue;
    for (int i=0; c[i]!='\0'; i++) {
        OldValue = NewValue;
        if (c[i] == 'M') NewValue = 1000;
        else if (c[i] == 'D') NewValue = 500;
        else if (c[i] == 'C') NewValue = 100;
        else if (c[i] == 'L') NewValue = 50;
        else if (c[i] == 'X') NewValue = 10;
        else if (c[i] == 'V') NewValue = 5;
        else if (c[i] == 'I') NewValue = 1;

        if (i==0) total = NewValue;
        else if (OldValue>=NewValue) total += NewValue;
        else total += (NewValue-(OldValue*2));
    }
    return total;
}

void problema11(char c, char *c2) {
    int fila, columna;
    static char cine[16][42];
    static bool f=false;
    if (!f) {
        for (int f=0; f<16; f++) {
            for (int c=0; c<42; c++) {
                if (f==0) {
                    cine[f][c]=' ';
                }
                else {
                    if (c==0) {
                        cine[f][c] = char(f+64);
                    }
                    else if (c%2 == 0) {
                        cine[f][c] = '-';
                    }
                    else {
                        cine[f][c] = ' ';
                    }
                }
                if (c==41) {
                    cine[f][c] = '\0';
                }
            }
        }
        f = true;
    }
    fila = int(c2[0])-64;
    columna = 2*(int(c2[1])-48);
    if (c == 'I') {
        cine[fila][columna] = '+';
    }
    else if (c == 'C') {
        cine[fila][columna] = '-';
    }

    for (int i=0; i<16; i++) {
        cout << cine[i] << endl << endl;
    }
}

bool problema12(int *mat, int elementos){
    bool cuadrado = true, *logic;
    int **m, elem, *fil, *col, diag[2]={0, 0};
    m = matriz(mat, elementos);
    elem = sqrt(elementos);

    /*Crea el arreglo donde se verifica si un número se repite*/
    logic = new bool[elementos+1]{};
    for (int i=0; i<elementos+1; i++) {
        logic[i] = 0;
    }

    /*Crea los arreglos para comprobar la suma de filas y columnas*/
    fil = new int[elem]{};
    col = new int[elem]{};
    for (int i=0; i<elem; i++) {
        fil[i] = 0;
        col[i] = 0;
    }

    for (int f=0; f<elem; f++) {
        for (int c=0; c<elem; c++) {
            if (logic[m[f][c]]) cuadrado = false;
            else logic[m[f][c]] = 1;
            fil[f] += m[f][c];
            col[c] += m[f][c];
            if (f==c) diag[0] += m[f][c];
            if (f==(elem-1)-c) diag[1] += m[f][c];
        }
    }

    for (int i=1; i<elem; i++) {
        if  (fil[i]!=fil[i-1] || col[i]!=col[i-1]) cuadrado = false;
    }
    if (diag[0]!=diag[1] || fil[0]!=col[0] || fil[0]!=diag[0] || col[0]!=diag[0]) cuadrado = false;

    delete logic;
    delete fil;
    delete col;
    delete []m;
    return cuadrado;
}

int problema13(int *mat){

    int imagen[6][8], estrellas=0; //matriz
    float resultado;
    for(int f=0, i=0;f<6;f++){
        for(int c=0;c<8;c++, i++){
            imagen[f][c]=*(mat+i);
        }


    }

    for (int f=1;f<5;f++){ //ciclo para recorrer matriz y entregar resultado
        for(int c=1;c<7;c++){
            resultado=(imagen[f][c]+imagen[f][c-1]+imagen[f][c+1]+imagen[f-1][c]+imagen[f+1][c])/5.0;
            if(resultado>6){
                estrellas++;
            }

        }
    }

return estrellas;
}

void problema14() {
    int n = 5;
    int **Matriz = new int *[n];
    for (int i=0; i<n; i ++) {
        Matriz[i] = new int[n];
    }

    for (int f=0; f<n; f++) {
        for (int c=0; c<n; c++) {
            Matriz[f][c] = 1+c+n*f;
        }
    }

    for (int j=0; j<4; j++) {
        cout << "\nRotacion " << 90*j << " grados" << endl;
        ImpMatriz(Matriz);
        RotarMatriz(Matriz);
    }

    delete [] Matriz;
}

void problema15(int *dato1, int *dato2, int *cruce){
    if(dato1[2]<dato2[0]||dato1[3]<dato2[1] || dato2[3]<dato1[1] || dato2[2]<dato1[0]){
        cout<<"No hay un cruce entre los triangulos"<<endl;
    }else if(dato2[0]>dato1[0] && dato2[2]<dato1[2]){
        for(int i=0;i<4;i++){
            cruce[i]=dato2[i];
        }if(dato1[0]>dato2[0] && dato1[2]<dato2[2]){
            for(int i=0;i<4;i++){
             cruce[i]=dato1[i];
            }

        }else{
            cruce[0]=abs((dato1[0]-dato2[0]));
            cruce[1]=abs(dato1[1]-dato2[1]);
            cruce[2]=abs(dato1[2]-dato2[0]);
            cruce[3]=abs(dato1[3]-dato2[1]);

        }
    }

    cout<<cruce<<endl;
}

int problema16(int n) {
    int roads = 0;
    roads = FindRoads(0, 0, n, roads);
    return roads;
}

int problema17(int num){
    int suma=0;
    for(int i=1; i<num;i++){
        if(numAmigable(i))  suma+=i;
        }
    return suma;
}

void problema18(char *p, int Zn) {
    char *m;
    if (Zn>=1 && Zn<=factorial(10)) {
        m = permutaciones(Zn-1, 10);
        for (int i=0; m[i]!='\0'; i++) {
            p[i] = m[i];
        }
        p[10] = '\0';
    }
    else cout << "El numero de la permutacion no es valido." << endl;
}

/*Solución Ejercicio 3
    unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};
      ┌───────────────────┬───────────────────┬───────────────────┬───────────────────┐
      │       b[0]        │       b[1]        │       b[2]        │       b[3]        │
      ├─────────┬─────────┼─────────┬─────────┼─────────┬─────────┼─────────┬─────────┤
      │ b[0][1] │ b[1][1] │ b[1][0] │ b[0][1] │ b[2][0] │ b[0][1] │ b[3][0] │ b[0][1] │
      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
0x0A12│ 0x0A14  │ 0x0A16  │ 0x0A18  │ 0x0A1A  │ 0x0A1C  │ 0x0A1E  │ 0x0A20  │ 0x0A22  │
      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
      │   77    │   50    │    5    │    2    │   28    │   39    │   99    │    3    │
 * b            => 0x0A14
 * b+2          => 0x0A1C
 * *(b+2)+1     => 0x0A1E
 * *(*(b+2)+1)  => 39
 * b[3][1]      => 3
 * *b++         => Error ¿?
*/
