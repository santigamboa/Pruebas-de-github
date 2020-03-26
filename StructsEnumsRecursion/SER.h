#include <stdio.h>

struct persona{
	char nombre[20];
	int dia;
	int mes;
	int anio;
}matriz[12][5];

typedef enum meses{
	ENERO=1, FEBRERO=2, MARZO=3, ABRIL=4, MAYO=5, JUNIO=6, JULIO=7, AGOSTO=8, SEPTIEMBRE=9, OCTUBRE=10, NOVIEMBRE=11, DICIEMBRE=12
}meses_e;

//Menu que muestra las opciones disponibles
void mostrarMenu();

//Retorna la columna disponible en la cual almacenar el nuevo usuario
int espacioLibre(int i);

//Permite al usuario ingresar un nuevo registro de cumpleaños
void nuevoUsuario();

//Muestra los datos de todas las personas que cumplan durante ese mes
void mostrarDatosMes();

//Perimite saber cuantos registros disponibles quedan para un mes en específico
int espaciosDisponibles(int mes, int max); 

void imprimirMes(int mes);

void mesesDisponibles();