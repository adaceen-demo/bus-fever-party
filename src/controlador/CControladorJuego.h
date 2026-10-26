/**
 * @file CControladorJuego.h
 * @brief Controlador: conecta la Vista con el Modelo.  (ESQUELETO)
 *
 * Responsabilidades:
 *   - Pedir al Modelo que cargue un nivel (CCargadorNivel y luego CJuego).
 *   - Repetir el ciclo del juego: pedir una jugada a la Vista, entregarla al
 *     Modelo y pedir a la Vista que muestre el nuevo estado.
 *   - No aplica reglas del juego (eso es del Modelo) ni imprime directamente
 *     (eso es de la Vista).
 * Colaboradores:
 *   - CVistaConsola (Vista), CCargadorNivel y CJuego (Modelo).
 *
 * Hoy ejecutar() solo muestra un mensaje de bienvenida e intenta cargar el nivel
 * de ejemplo. Cada grupo completa el ciclo del juego.
 */
#ifndef _CCONTROLADORJUEGO_H_
#define _CCONTROLADORJUEGO_H_
#include <string>
#include "CVistaConsola.h"
using namespace std;

class CControladorJuego
{
  private:
    CVistaConsola& vista;
    string rutaNivel;

  public:
    CControladorJuego(CVistaConsola& vista, const string& rutaNivel);
    void ejecutar();
};
#endif
