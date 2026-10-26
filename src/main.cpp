/*
    Bus Fever Party! FPOO C++ Edition
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    main solo arma las piezas (Vista y Controlador) y le entrega el control al
    Controlador. No contiene lógica del juego.

    Uso:  ./busfever                     (carga niveles/nivel01.txt)
          ./busfever niveles/nivel02.txt
*/
#include <string>
#include "CVistaConsola.h"
#include "CControladorJuego.h"
using namespace std;

int main(int argc, char* argv[]){
    string rutaNivel = (argc > 1) ? argv[1] : "niveles/nivel01.txt";

    CVistaConsola vista;
    CControladorJuego controlador(vista, rutaNivel);
    controlador.ejecutar();
    return 0;
}
