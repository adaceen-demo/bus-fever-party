/**
 * @file CCargadorNivel.h
 * @brief CONTRATO del cargador de niveles de Bus Fever Party.
 *
 * ATENCIÓN: ESTE ARCHIVO ES UN CONTRATO. NO SE EDITA.
 * Si cree que falta algo o hay un error, abra un issue en el repositorio base.
 *
 * -----------------------------------------------------------------------------
 * Estándar CRC
 * -----------------------------------------------------------------------------
 *   Clase: CCargadorNivel   (capa Modelo)
 *   Responsabilidades:
 *     - Leer un archivo de nivel en texto plano y validar su formato.
 *     - Llenar un SDatosNivel con lo leído.
 *     - Explicar, con un mensaje, por qué un archivo no es válido.
 *     - NO imprime nada, NO usa cin ni cout, NO crea objetos del juego.
 *   Colaboradores:
 *     - SDatosNivel / SDatosVehiculo: lo que entrega.
 *
 * -----------------------------------------------------------------------------
 * FORMATO DEL ARCHIVO DE NIVEL (ver ejemplos en niveles/)
 * -----------------------------------------------------------------------------
 *   - Una instrucción por línea. Las palabras se separan con uno o más espacios.
 *   - Las líneas vacías y las que empiezan con # (comentarios) se ignoran.
 *   - Las palabras clave van en MAYÚSCULA y en este ORDEN:
 *
 *       NOMBRE <texto>                     una vez; el texto es el resto de la línea
 *       TABLERO <ancho> <alto>             una vez; enteros entre 1 y 20
 *       ESPERA <puestos>                   una vez; entero entre 1 y 10 (zona de espera)
 *       VEHICULO <color> <capacidad> <columna> <renglon> <direccion>
 *                                          una o más veces
 *       FILA <colores>                     una vez; un color por pasajero, sin espacios,
 *                                          del frente de la fila (izquierda) al final
 *
 *   - Colores: R rojo, A azul, V verde, M morado, N naranja (una letra mayúscula).
 *   - VEHICULO:
 *       capacidad entre 1 y 12;
 *       columna en [0, ancho) y renglon en [0, alto); el renglón 0 es el de arriba;
 *       dos vehículos no pueden estar en la misma casilla;
 *       direccion: ARRIBA, ABAJO, IZQUIERDA o DERECHA (hacia donde sale el vehículo).
 *   - Consistencia: para cada color, la cantidad de pasajeros en FILA debe ser igual
 *     a la suma de las capacidades de los vehículos de ese color.
 *
 *   Ejemplo (niveles/nivel01.txt):
 *       # Nivel 1
 *       NOMBRE Primer viaje
 *       TABLERO 4 4
 *       ESPERA 3
 *       VEHICULO R 3 0 0 ABAJO
 *       VEHICULO A 3 3 3 ARRIBA
 *       FILA RRRAAA
 *
 * -----------------------------------------------------------------------------
 * REGLAS DEL CONTRATO
 * -----------------------------------------------------------------------------
 *   - cargar(ruta, datos): abre el archivo y hace lo mismo que cargarDesde().
 *       Si el archivo no se puede abrir devuelve false.
 *   - cargarDesde(entrada, datos): lee todo el flujo y lo valida. Si es válido llena
 *       'datos' y devuelve true. Si no, devuelve false, NO modifica 'datos' y deja
 *       en getError() un mensaje que indique la línea y el motivo
 *       (ej: "linea 6: color invalido 'X'").
 *       Recibe un istream (no cin) para poder probarlo con stringstream.
 *   - getError(): el mensaje del último error ("" si la última carga funcionó).
 *   - esColorValido(c): true si c es uno de los colores del formato.
 *   - esDireccionValida(d): true si d es una de las cuatro direcciones del formato.
 */
#ifndef _CCARGADORNIVEL_H_
#define _CCARGADORNIVEL_H_
#include <istream>
#include <string>
#include "SDatosNivel.h"
using namespace std;

class CCargadorNivel
{
  private:
    string error;

  public:
    CCargadorNivel();

    bool cargar(const string& ruta, SDatosNivel& datos);
    bool cargarDesde(istream& entrada, SDatosNivel& datos);
    string getError() const;

    // Ayudas de validación del formato (ya implementadas en el repositorio base).
    static bool esColorValido(char color);
    static bool esDireccionValida(const string& direccion);
};
#endif
