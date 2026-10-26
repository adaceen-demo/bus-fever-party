/**
 * @file CVistaConsola.h
 * @brief Vista en consola: lo único que habla con el usuario.  (ESQUELETO)
 *
 * Responsabilidades:
 *   - Mostrar mensajes, el tablero, la fila y la zona de espera.
 *   - Leer lo que escribe el jugador y validarlo como entrada (por ejemplo, que
 *     una coordenada sea un número), sin aplicar reglas del juego.
 * Colaboradores:
 *   - Ninguno del Modelo directamente: el Controlador le pasa lo que debe mostrar.
 *
 * Los flujos se reciben por referencia (por defecto cin/cout) para poder probar
 * la vista con stringstream.
 *
 * mostrarMensaje() ya está implementado. El resto lo diseña cada grupo.
 */
#ifndef _CVISTACONSOLA_H_
#define _CVISTACONSOLA_H_
#include <iostream>
#include <string>
using namespace std;

class CVistaConsola
{
  private:
    istream& entrada;
    ostream& salida;

  public:
    CVistaConsola(istream& entrada = cin, ostream& salida = cout);
    void mostrarMensaje(const string& mensaje);

    // TODO (grupo): mostrarTablero, mostrarFila, leerJugada, etc.
};
#endif
