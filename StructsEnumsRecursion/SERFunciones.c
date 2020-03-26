#include "SER.h"

void mostrarMenu() {
	int opcion = 0;
	int mes;
	do {
		printf("Opciones para matrices \n\n");
		printf("1. Ingresar un nuevo usuario\n");
		printf("2. Mostrar cumpleanios por mes\n");
		printf("3. Saber cuales meses tienen registros disponibles\n"); 
		printf("4. Mostrar registros disponibles por mes\n");
		printf("0. Salir\n\n");
		printf(" Opc: ");
		scanf("%d", &opcion);
		printf("\n");
		switch (opcion) {
			case 1:
				nuevoUsuario();
				break;
			case 2:
				mostrarDatosMes();
				break;
			case 3:
				mesesDisponibles();
				printf("\n");
				break;
			case 4: 
				printf("Ingrese el mes para conocer sus registros disponibles: ");
				scanf("%d", &mes);
				printf("%d registros disponibles", espaciosDisponibles(mes-1, 4));
				printf("\n\n");
				break;
		}
		//Cuando el usuario ingrese 0 se terminará el menu
	} while(opcion!=0);
}


int espacioLibre(int i){
	int j=0;
	do{
		if (matriz[i][j].mes!=0){
			j++;
			if (j==5){
				return -1;
			}		
		}else{
			return j;
		}
	}while(j!=5);	
}


void nuevoUsuario(){
	int mes;
	int j;
	printf("Ingrese el mes de nacimiento: ");
	scanf("%d", &mes);
	if (mes>0 && mes<=12){
		j=espacioLibre(mes-1);
		printf("%d\n", j+1);
		if (j!=-1){
			matriz[mes-1][j].mes=mes;
			printf("Ingrese el nombre del individuo: ");
			fflush(stdin);
			fgets(matriz[mes-1][j].nombre, 20, stdin);
			printf("\n");

			printf("Ingrese el dia de nacimiento: ");
			scanf("%d", &matriz[mes-1][j].dia);
			printf("\n");

			printf("Ingrese el anio de nacimiento: ");
			scanf("%d", &matriz[mes-1][j].anio);
			printf("\n");
		}else{
			printf("Ya no hay espacio para un nuevo registro\n\n");
		}
	}else{
		printf("No ha ingresado un mes valido\n");
	}
}


void mostrarDatosMes(){
	int mes;
	int j=0;
	printf("Ingrese el mes del cual desea conocer los datos de los individuos: ");
	scanf("%i", &mes);
	if (mes>0 && mes<=12){
		do{
				if (matriz[mes-1][j].dia!=0){
					printf("Nombre: %s", matriz[mes-1][j].nombre);
					printf("Dia de nacimiento: %i\n", matriz[mes-1][j].dia);
					printf("Mes de nacimiento: %i\n", matriz[mes-1][j].mes);
					printf("Anio de nacimiento: %i\n\n", matriz[mes-1][j].anio);	
				}else if (j==0){
					printf("No hay registros\n\n");
					break;
				}else{
					printf("No hay más registros\n\n");
					break;
				}
				j++;
		}while(j!=5);
	}else{
		printf("No ha ingresado un mes valido\n");
	}
}


int espaciosDisponibles(int mes, int max){
	if (max==-1){
		return 0;	
	}else if(matriz[mes][max].mes==0){
		return 1+espaciosDisponibles(mes, max-1);
	}else{
		return 0;
	}
}

void imprimirMes(int mes){
	switch (mes){
		case ENERO:
			printf("ENERO\n");
			break;
		case FEBRERO:
			printf("FEBRERO\n");
			break;
		case MARZO:
			printf("MARZO\n");
			break;
		case ABRIL:
			printf("ABRIL\n");
			break;
		case MAYO:
			printf("MAYO\n");
			break;
		case JUNIO:
			printf("JUNIO\n");
			break;
		case JULIO:
			printf("JULIO\n");
			break;
		case AGOSTO:
			printf("AGOSTO\n");
			break;
		case SEPTIEMBRE:
			printf("SEPTIEMBRE\n");
			break;
		case OCTUBRE:
			printf("OCTUBRE\n");
			break;
		case NOVIEMBRE:
			printf("NOVIEMBRE\n");
			break;
		case DICIEMBRE:
			printf("DICIEMBRE\n");
			break;
	}
}

void mesesDisponibles(){
	int i, j=4;
	int disponible;
	for (i=0; i<12; i++){
		disponible=espaciosDisponibles(i, j);
		if (disponible!=0){
			imprimirMes(i+1);
		}	
	}
}
