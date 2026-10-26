/*
    Bus Fever Party! FPOO C++ Edition - Universidad del Valle
    Clase: CControladorJuego (Controlador)

    Versión base: muestra un mensaje e intenta cargar el nivel de ejemplo.
    El ciclo del juego lo implementa cada grupo.
*/
#include "CControladorJuego.h"
#include "CCargadorNivel.h"
#include "SDatosNivel.h"
using namespace std;

CControladorJuego::CControladorJuego(CVistaConsola& vista_, const string& rutaNivel_)
    : vista(vista_), rutaNivel(rutaNivel_) {
}

void CControladorJuego::ejecutar() {
    vista.mostrarMensaje("Bus Fever Party! FPOO C++ Edition");
    vista.mostrarMensaje("Repositorio base: el juego todavia no esta implementado.");

    CCargadorNivel cargador;
    SDatosNivel datos;
    if (cargador.cargar(rutaNivel, datos)) {
        vista.mostrarMensaje("Nivel cargado: " + datos.nombre);
        // TODO (grupo): crear CJuego con 'datos' y empezar el ciclo del juego.
    } else {
        vista.mostrarMensaje("No se pudo cargar " + rutaNivel + ": " + cargador.getError());
    }
}
