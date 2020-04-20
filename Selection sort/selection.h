# include <stdio.h>
# include "stdlib.h"
# define VALOR_MAYOR 1000000; //Este número jamás será ingresado por el usuario

/*Ejemplo del algoritmo en C++

for(int i = 0; i < n ; i++){

for(int j = i + 1 ; j <= n ; j++){

if(lista[i] > lista[j]){

intercambiar(lista , i , j);

}

}

}*/

//Regresa la matriz con su espacio reservado en la memoria del computador
float** reservarMemoria ( int N );

//Solicita los elemtos de la lista de tamaño N al usuario
float** llenarMatriz ( float** Lista, int N );

//A partir de una posición i busca en adelante cuál es el valor más pequeño en la lista, y regresa su posición {0...N-1}
int buscarMenor ( float** Lista, int i, int N );

//A partir de una posición i, recibe la posición del valor más pequeño e intercambia dichos valores
void intercambiar ( float** Lista, int i, int pos_menor );

//Imprime la matriz una vez organizada de menor a mayor
void imprimirMatriz ( float** Lista, int N );