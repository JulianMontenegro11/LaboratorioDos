#include "problemas.h"



int main (){

    char p3c1[]="Cadena1", p3c2[]="Cadena1", p4c[]="12345", p6c[]="Man-zana", p8c[]="abc54rst", c;
    char p10c[]="CLXXIV", reserva, silla[3], *p18c = new char[11], p7c[]="bananas";
    int p12c[9]={4,9,2,3,5,7,8,1,6}, p5n=123;
    int menu;

    cout << "Ingrese el problema:" << endl;
    cin >> menu;

    switch (menu) {
    case 2:
        problema2();
        break;

    case 3:
        char a[]={"Hola"}, b[]={"Hola"};
           problema3(a, b);
           if(problema3(a,b)==1){
               cout<<"Las cadenas de caracteres son iguales"<<endl;
           }else{
               cout<<"Las cadenas de caracteres son diferentes"<<endl;
           }
        break;

    case 4:
        cout << problema4(p4c) << endl;
        break;

    case 5:
        int num;
            char x[20];
            cout<<"Ingrese numero entero que desea convertir"<<endl;
            cin>>num;

            problema5(num,x);
        break;

    case 6:
        cout << "Original: " << p6c << ".\t";
        cout << "En mayuscula: " << problema6(p6c) << endl;
        break;

    case 7:
        char a[]={"esternocleidomastoideo"};
            problema7(a);
        break;

    case 8:
        problema8(p8c, &c);
        break;

    case 9:
        int num;
        char  x[20]={};
       cout<<"Por favor ingrese el numero n"<<endl;
        cin>>num;
        cout<<"Por favor ingrese la cadena numerica"<<endl;
        cin>>x;



        problema9(x, num);
        break;

    case 10:
        cout << problema10(p10c) << endl;
        break;

    case 11:
        while (true) {
            cout << "Ingrese I para reservar, C para cancelar reserva: ";
            cin >> reserva;
            cout << "Ingrese la sila: ";
            cin >> silla;

            problema11(reserva, silla);
        }
        break;

    case 12:
        if (problema12(p12c, 9)) cout << "Es un cubo magico" << endl;
        else cout << "No es un cubo magico" << endl;
        break;

    case 13:
        int estrellas,imagen[6][8]={{0,3,4,0,0,0,6,8},{5,13,6,0,0,0,2,3},{2,6,2,7,3,0,10,0},{0,0,4,15,4,1,6,0},{0,0,7,12,6,9,10,4},{5,0,6,10,6,4,8,0}};
           estrellas=problema13(&imagen[0][0]);
           cout<<"La cantidad de estremmas en la imagen es: "<<estrellas<<endl;
        break;

    case 14:
        problema14();
        break;

    case 15:
        int c1[4]={0,0,8,4},c2[4]={5,2,6,7},c3[4]={0,0,0,0};
           problema15(c1,c2,c3);
        break;

    case 16:
        cout << problema16(2) << endl;
        break;

    case 17:
        cout<<problema17(285)<<endl;
        break;

    case 18:
        p18c[10] = '\0';
        problema18(p18c, 1000000);
        cout << p18c << endl;
        break;
    }
    return 0;
}



