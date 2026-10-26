/*
    Bus Fever Party! FPOO C++ Edition - Universidad del Valle
    Clase: CVistaConsola (Vista)
*/
#include "CVistaConsola.h"
using namespace std;

CVistaConsola::CVistaConsola(istream& entrada_, ostream& salida_) : entrada(entrada_), salida(salida_) {
}

void CVistaConsola::mostrarMensaje(const string& mensaje) {
    salida << mensaje << endl;
}
