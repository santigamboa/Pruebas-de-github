# include "selection.h"

float** reservarMemoria ( int N ){
	int i;
	float** Lista = malloc ( (N)*sizeof( float* ));
	if (Lista != NULL ){
		for ( i=0; i<N; i++ ){
			Lista[i] = malloc ((1)*sizeof( float ));
		}
	}else{
			printf("Reserva fallida\n");
			return 0;
	}
	return Lista;
}

float** llenarMatriz ( float** Lista, int N ){
	int i;
	float num;
	for ( i=0; i<N; i++ ){
		printf("Elemento %i: ", i+1);
		scanf("%f", &num);
		Lista[i][0] = num;
	}
	return Lista;
}

int buscarMenor ( float** Lista, int i, int N ){
	int menor = VALOR_MAYOR;
	int pos_menor;
	for ( ; i<N; i++ ){
		if ( Lista[i][0] <= menor ){ //Inicialmente cualquier valor será menor que VALOR_MAYOR; así que automáticamente el menor éstará en la posición i
			menor = Lista[i][0];
			pos_menor = i;
		}
	}
	return pos_menor;
}

void intercambiar ( float** Lista, int i, int pos_menor ){
	float a, b; //Evitan que se pierdan los valores originales
	
	a = Lista[i][0];
	b = Lista[pos_menor][0];

	Lista[i][0] = b;
	Lista[pos_menor][0] = a;

}

void imprimirMatriz ( float** Lista, int N ){
	int i;
	for ( i=0; i<N; i++ ){
		printf("Elemento %i: %.2f\n", i+1, Lista[i][0]);
	}
}