// Prueba de ejemplo: ayudas de validación del formato de nivel (CCargadorNivel).
// Esta prueba PASA en el repositorio base porque esas dos ayudas ya están implementadas.
// Úsela como modelo: para la entrega final cada método debe tener sus pruebas.
#include <sstream>
#include "minitest.h"
#include "CCargadorNivel.h"
using namespace std;

int main(){
    SECCION("CCargadorNivel: esColorValido");
    CHECK(CCargadorNivel::esColorValido('R'));
    CHECK(CCargadorNivel::esColorValido('A'));
    CHECK(CCargadorNivel::esColorValido('V'));
    CHECK(CCargadorNivel::esColorValido('M'));
    CHECK(CCargadorNivel::esColorValido('N'));
    CHECK(!CCargadorNivel::esColorValido('r'));   // solo mayúsculas
    CHECK(!CCargadorNivel::esColorValido('X'));
    CHECK(!CCargadorNivel::esColorValido(' '));

    SECCION("CCargadorNivel: esDireccionValida");
    CHECK(CCargadorNivel::esDireccionValida("ARRIBA"));
    CHECK(CCargadorNivel::esDireccionValida("ABAJO"));
    CHECK(CCargadorNivel::esDireccionValida("IZQUIERDA"));
    CHECK(CCargadorNivel::esDireccionValida("DERECHA"));
    CHECK(!CCargadorNivel::esDireccionValida("arriba"));
    CHECK(!CCargadorNivel::esDireccionValida("NORTE"));
    CHECK(!CCargadorNivel::esDireccionValida(""));

    // TODO (grupo): cuando implementen cargarDesde(), agreguen pruebas como esta
    // (con stringstream no hace falta crear archivos):
    //
    //   stringstream archivo("NOMBRE Prueba\nTABLERO 2 2\nESPERA 1\n"
    //                        "VEHICULO R 1 0 0 ARRIBA\nFILA R\n");
    //   CCargadorNivel cargador;
    //   SDatosNivel datos;
    //   CHECK(cargador.cargarDesde(archivo, datos));
    //   CHECK_EQ(datos.ancho, 2);
    //   CHECK_EQ((int)datos.vehiculos.size(), 1);
    //
    // Y casos inválidos: color desconocido, vehículo fuera del tablero, casilla
    // repetida, palabras clave fuera de orden, FILA que no cuadra con las capacidades...

    return RESUMEN();
}
