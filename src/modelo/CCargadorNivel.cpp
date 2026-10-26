/*
    Bus Fever Party! FPOO C++ Edition - Universidad del Valle
    Clase: CCargadorNivel (Modelo)

    Las dos ayudas de validación (esColorValido y esDireccionValida) ya están
    implementadas porque solo repiten lo que dice el formato.
    Leer y validar el archivo completo (cargar y cargarDesde) es trabajo del grupo:
    reemplace los STUB siguiendo el contrato de CCargadorNivel.h.
*/
#include "CCargadorNivel.h"
#include <string>
using namespace std;

CCargadorNivel::CCargadorNivel() : error("") {
}

bool CCargadorNivel::cargar(const string& ruta, SDatosNivel& datos) {
    // STUB (grupo): abrir el archivo de 'ruta' y delegar en cargarDesde()
    error = "CCargadorNivel::cargar sin implementar";
    return false;
}

bool CCargadorNivel::cargarDesde(istream& entrada, SDatosNivel& datos) {
    // STUB (grupo): leer línea por línea, validar el formato y llenar 'datos'
    error = "CCargadorNivel::cargarDesde sin implementar";
    return false;
}

string CCargadorNivel::getError() const {
    return error;
}

bool CCargadorNivel::esColorValido(char color) {
    const string COLORES = "RAVMN";
    return COLORES.find(color) != string::npos;
}

bool CCargadorNivel::esDireccionValida(const string& direccion) {
    return direccion == "ARRIBA" || direccion == "ABAJO"
        || direccion == "IZQUIERDA" || direccion == "DERECHA";
}
