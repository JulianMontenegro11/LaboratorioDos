# include "problemas.h"
#include "auxiliar.h"





void problema2(){
    char a[200];
    srand(time(NULL));
    for(int i=0; i<200 ; i++){
     a[i]=65 + (rand()% (91 - 65) );
     cout<<a[i];

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
    cout<<"La letra "<<j<<" se encuentra "<< contador<<" veces"<<endl<<endl;
    contador=0;
    }
}


bool problema3(char *c1, char*c2){
    int i=0;
    bool iguales;
    while(c1[i]==c2[i] && c1[i]!='\0' && c2[i]!='\0'){
        i++;

        if(c1[i]==c2[i]){
            iguales=true;
        }else{
            iguales=false;
        }

    }
return iguales;


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

long long int problema9(char *c, long long int n){
    int numero,b,contador,a,grupos,grupo,separar,suma;
    contador=0;
    separar=(10 * n);
     numero= atoi(c);
    b=numero; // b toma el valor de numero para no modificar la el valor inicial de numero
    while (b!=0) {
        a=b%10;
        b=b/10;
        contador++;
    }
    grupos=contador%n;
    if(grupos%2==0){
        while (numero!=0) {

            grupo=numero%separar;
            numero=numero/separar;
            suma=suma+grupo;

            cout<<grupo<<" + ";

        }
    }else{
        separar=(10 * (n-1));
        grupo=numero%separar;
        numero=numero/separar;
        suma=suma+grupo;

        cout<<"0"<<grupo<<" + ";
        while (numero!=0) {
            separar=(10 * n);
            grupo=numero/separar;
            numero=numero%separar;
            suma=suma+grupo;

            cout<<grupo<<" + ";
        }

    }

    cout<<" = "<<suma<<endl;



}

void problema11(char c, char *c2){
    int fila, columna;
    static char salaCine[16][42];
    static bool f=false;
    if(!f){
        for(int f=0;f<16;f++){ // construccion de filas y columnas
            for(int c=0;c<42;c++){
                if(f==0){
                    if(c%2==1){
                        salaCine[f][c]=' ';
                    }else {
                        salaCine[f][c]=char (48+(c/2));
                    }
                }

                    else{
                        if(c==0){
                            salaCine[f][c]=char(f+64);
                        }else{
                            if(c%2==0){
                                salaCine[f][c]='-';
                            }else{
                                salaCine[f][c]=' ';
                            }
                            if(c==41){
                                salaCine[f][c]='\0';
                            }
                     }
                }
            }

        }
        f=true;
    }
    fila=int (c2[0])-64;
    columna= 2*(int(c2[1])-48);
    if(c=='I'){
        salaCine[fila][columna]='+';

    }else if(c=='C'){
        salaCine[fila][columna]='-';
    }

    for(int i=0;i<16;i++){
        cout<<salaCine[i]<<endl<<endl;
    }
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

int problema17(int num){
    int suma=0;
    for(int i=1; i<num;i++){
        if(numAmigable(i))  suma+=i;
        }

        return suma;

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




