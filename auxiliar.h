#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <conio.h>
using namespace std;

int GenNumRand();           //Genera un número al azar.
int longitud(char *c);      //Determina la longitud de un arreglo
long long int Potencia(int pot, int base);      //Eleva a una potencia cualquier número.
void ImpMatriz (int **Matriz);  //Imprime una matriz.
void RotarMatriz (int **Matriz);    //Rota una matriz.
int FindRoads(int fnodo, int cnodo, int v, int nodos);  //busca si hay caminos disponibles
int ** matriz(int *m, int elementos);   //devuelve una matriz
int FindNum(char *c);   //Cuenta cuántos números hay en un arreglo
int FindLet(char *c);   //Cuenta cuántas letras hay en un arreglo
long long int factorial(int n); //Calcula un n!
char * permutaciones(int y, int num);   //Devuelve la cadena con numeros posibles por permutacion
void eliminar(char *p, int n);  //elimina un elemento en una cadena
bool numAmigable(int num);  //Verifica si un número es amigable

#endif // AUXILIAR_H
