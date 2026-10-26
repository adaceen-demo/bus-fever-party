/**
 * @file SDatosNivel.h
 * @brief Datos "crudos" de un nivel, tal como vienen en el archivo de texto.
 *
 * ATENCIÓN: este archivo es parte del CONTRATO del cargador. No se edita.
 *
 * CCargadorNivel solo LEE y VALIDA el archivo y llena esta estructura. No crea
 * tableros, vehículos ni pasajeros: eso lo hace el Modelo de cada grupo a partir
 * de estos datos (por ejemplo, CJuego). Así el cargador no depende del diseño de
 * clases que elija cada grupo (principio de responsabilidad única).
 *
 * Es un struct (todo público) porque solo transporta datos: no tiene reglas propias.
 */
#ifndef _SDATOSNIVEL_H_
#define _SDATOSNIVEL_H_
#include <string>
#include <vector>
using namespace std;

// Una línea VEHICULO del archivo.
struct SDatosVehiculo
{
    char color = '?';         // R, A, V, M o N
    int capacidad = 0;        // cuántos pasajeros caben
    int columna = 0;          // x, desde 0 (izquierda)
    int renglon = 0;          // y, desde 0 (arriba)
    string direccion;         // ARRIBA, ABAJO, IZQUIERDA o DERECHA
};

// Un nivel completo.
struct SDatosNivel
{
    string nombre;                     // línea NOMBRE
    int ancho = 0, alto = 0;           // línea TABLERO
    int puestosEspera = 0;             // línea ESPERA
    vector<SDatosVehiculo> vehiculos;  // líneas VEHICULO, en el orden del archivo
    string fila;                       // línea FILA: un color por pasajero, del frente al final
};
#endif
