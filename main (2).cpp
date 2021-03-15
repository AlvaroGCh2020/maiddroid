/////////////////////////////////////////////////////////////////
#include"sim.h"
///////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
	int cant, ancho, largo, robotcant, modo;
	pCallback p = parseCallback;
	printf("El primer dato es el ancho, el segundo el largo, el tercero la cantidad de robots, y el cuarto el modo, mandar solo parametros \n");
	printf("El modo es 1 para simulacion , y 2 para grafico.\n");
	if (((cant = parseCmdLine(argc, argv, p)) > 4) || ((cant = parseCmdLine(argc, argv, p)) < 3)) {//si pase una cantidad incorrecta de datos
		printf("Parametros incorrectos o insuficientes. \n");
		return (EXIT_FAILURE);
	}
	else {//pase una cantidad correcta de datos, veo que estos sean correctos
		ancho = atoi(argv[1]);
		largo = atoi(argv[2]);//casteo a int
		robotcant = atoi(argv[3]);
		modo = atoi(argv[4]);
		printf("ancho:%d largo:%d robots:%d modo:%d \n", ancho, largo, robotcant, modo);
		if (ancho <= 0 || ancho > ANCHOMAX) {//si es un acho no valido
			printf("Ancho no valido\n");
			return (EXIT_FAILURE);
		}
		if (largo <= 0 || largo > LARGOMAX) {//si es un largo no valido
			printf("Largo no valido\n");
			return (EXIT_FAILURE);
		}
		if (robotcant <= 0) {//cant de robot no valido
			printf("Cantidad de robots no valida\n");
			return (EXIT_FAILURE);
		}
		if (modo < 1 || modo>2) {//si es un modo no valido
			printf("Modo no valido\n");
			return (EXIT_FAILURE);
		}
	}
#define TICKPRUEBA 20
	Floor *a;
	a=createfloor(largo, ancho);
	deletefloor(a);
	int b, tick;


	Robot* arr[MAXROBOTS];
	for (b = 0; b < robotcant; ++b) {
		arr[b] = createrobot(largo, ancho);
	}

	for (tick = 0; tick < TICKPRUEBA; ++tick) {
		for (b = 0; b < robotcant; ++b) {
			movrobot(arr, b, largo, ancho);//el b es el robot que estoy moviendo
			printf("%d\n", tick);
		}
	}

	for (b = 0; b < robotcant; ++b) {
		deleteRobot(arr[b]);
	}

	return(EXIT_SUCCESS);
}
///////////////////////////////////////
