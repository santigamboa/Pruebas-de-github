# include "selection.h"

int main(){

	int N; //Cantidad de datos
	int i;
	int pos_menor; //Posición del menor valor de la lista
	printf("Cantidad de datos: ");
	scanf("%i", &N);
	if ( N<= 0 ){
		printf("Valor invalido\n");
	}else{
		float** Lista = reservarMemoria ( N );
		Lista = llenarMatriz ( Lista, N );
		for ( i=0; i<N; i++ ){
			pos_menor = buscarMenor ( Lista, i, N );
			intercambiar ( Lista, i, pos_menor );
		}
		printf("\n");

		imprimirMatriz( Lista, N );
	}
	return 0;
}