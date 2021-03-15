#pragma once
/*File:   input.h
* Author : Alejandro Alatsis
*
* Created on 8 de octubre de 2020, 18 : 44
* */

#ifndef SIM_H
#define SIM_H
#include<cstdlib>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<stddef.h>
#include<math.h>
//////////////////////////////////////////////////////////////
#define ERROR -1
#define NOPARAM 0
#define OK 1
#define SUCIO 1
#define LIMPIO 0
#define DISTANCE 1.0
#define ANCHOMAX 70
#define LARGOMAX 100
#define MAXROBOTS 1000
#define PI 3.141592
/////////////////////////////////////////////////////////////
typedef int(*pCallback) (char*, char*);
typedef struct {
	double x; 
	double y;
} Point;
typedef struct {
	Point abajizq;
	Point arribader;
}Rect;
typedef struct {
	int largo;
	int ancho;
	bool* tiles;
}Floor;
typedef struct {
	double x;
	double y;
	double angle;
}Robot;
typedef struct {
	Robot* robs;
	Floor* f;
	long tickcount;
}Sim;
/// ////////////////////////////////////////////////////////////
int parseCmdLine(int argc, char* argv[], int(*pCallback) (char*, char*));
//separa parametros/opciones, devuelve la cantidad de opciones y parametros encontrados o un -1 en caso de error
int parseCallback(char* key, char* value);//analiza parametros/opciones
double getRectArea(Rect* r); // calcula el área del rectángulo.
bool isPointInRect(Point* p, Rect* r); //que determina si el punto p está dentro de o en el borde del rectángulo r.
double getDistanceBetweenPoints(Point* , Point* );//calculo la distancia entre 2 puntos
double getAngleBetweenPoitns(Point*, Point*);//calculo el angulo entre dos puntos
Point translatePoint(Point* p, double distance, double angle);//traslada un punto una distancia en cierto angulo
bool isPointEqual(Point* p1, Point* p2);//determina si dos puntos son iguales
Floor* createfloor(long, long);//crea el piso en el heap
void deletefloor(Floor*);//borra el piso del heap
Robot* createrobot(long largo, long ancho);//crea robots en el heap
void deleteRobot(Robot*);//borra el robot
void movrobot(Robot*[],int robotcant,long largo,long ancho);//mueve los robots y se fija que no se salgan del piso
/*Sim* createsim(long largo, long ancho, long robotcant, int mode);//crea la simulacion
void deleteSim(Sim*);*/

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* SIM_H */