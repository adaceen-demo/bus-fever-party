# Bus Fever Party! FPOO C++ Edition
Fundamentos de Programación Orientada a Objetos (FPOO), Universidad del Valle

Repositorio base del proyecto del curso. Cada grupo replica el juego de rompecabezas
*Bus Fever*: en un tablero hay vehículos de colores y una fila de pasajeros; el jugador elige qué
vehículo sale y cada uno recoge a los pasajeros de su color. Los niveles se leen desde un archivo
de texto plano.

El objetivo es aplicar Programación Orientada a Objetos, los principios SOLID y una arquitectura
MVC estricta de tres capas.

> **Este repositorio no trae el juego.** Solo tiene la estructura, el contrato del cargador de
> niveles, esqueletos documentados de las clases principales y un `main` que compila. El diseño y
> la implementación son trabajo de cada grupo y se califican.

## Entregas

| Fecha | Entrega | Qué se entrega |
|---|---|---|
| 27-10-2026 | **Primera entrega** (en Moodle) | Diagrama de clases, tarjetas CRC y los `.h`/`.cpp` que ya funcionen. |
| 04-11-2026 | **Presentación** | El grupo presenta su diseño y su avance. |
| 01-12-2026 | **Entrega final** | Juego funcionando y **pruebas unitarias para cada método** (en `pruebas/`). |

En cada entrega el grupo abre además un Pull Request hacia este repositorio (ver más abajo).

## Arquitectura MVC (estricta)

```
src/
  main.cpp                      arma Vista y Controlador; no tiene lógica
  modelo/                       reglas y datos del juego
    CCargadorNivel.h  .cpp      CONTRATO: lee y valida el archivo de nivel (no se edita el .h)
    SDatosNivel.h               datos crudos de un nivel (no se edita)
    CJuego.h  CTablero.h  CVehiculo.h  CFila.h  CPasajero.h
                                esqueletos documentados: los completa cada grupo
  vista/
    CVistaConsola.h  .cpp       lo único que lee o escribe en la consola
  controlador/
    CControladorJuego.h  .cpp   conecta Vista y Modelo; ciclo del juego
niveles/                        archivos de nivel de ejemplo
pruebas/                        minitest.h, resumen_pruebas.cpp y un test_<algo>.cpp por clase
docs/                           diagrama UML base y plantilla CRC
```

Reglas de las capas:

1. **El Modelo no usa `cin` ni `cout`** (ni `printf`/`scanf`). No sabe que existe una consola,
   no conoce a la Vista ni al Controlador, y se puede probar sin teclado.
2. **La Vista no aplica reglas del juego.** Muestra datos y lee la entrada del jugador.
3. **El Controlador no imprime ni decide reglas.** Pide la jugada a la Vista, se la pasa al Modelo
   y le pide a la Vista que muestre el resultado.

Puede agregar todas las clases y archivos que su diseño necesite (por ejemplo `src/modelo/CBus.h`).
El `Makefile` los encuentra solo. Dos `.cpp` no pueden llamarse igual, aunque estén en carpetas
distintas.

## Formato del archivo de nivel

El contrato completo está en `src/modelo/CCargadorNivel.h`. Resumen:

```
# Comentario: las líneas con # y las vacías se ignoran
NOMBRE Primer viaje                     nombre del nivel (resto de la línea)
TABLERO 4 4                             ancho y alto (1 a 20)
ESPERA 3                                puestos en la zona de espera (1 a 10)
VEHICULO R 3 0 0 ABAJO                  color capacidad columna renglon direccion
VEHICULO A 3 3 3 ARRIBA                 (una línea por vehículo)
FILA RRRAAA                             un color por pasajero, del frente al final
```

- Palabras clave en mayúscula y en ese orden: `NOMBRE`, `TABLERO`, `ESPERA`, uno o más `VEHICULO`, `FILA`.
- Colores: `R` rojo, `A` azul, `V` verde, `M` morado, `N` naranja.
- Posición desde 0; el renglón 0 es el de arriba. Dos vehículos no comparten casilla.
- Direcciones: `ARRIBA`, `ABAJO`, `IZQUIERDA`, `DERECHA` (hacia donde sale el vehículo).
- Capacidad de 1 a 12. Para cada color, los pasajeros de `FILA` suman lo mismo que las
  capacidades de los vehículos de ese color.

Ejemplos: `niveles/nivel01.txt` y `niveles/nivel02.txt`. Los grupos pueden crear más niveles.

`CCargadorNivel` solo lee y valida: deja el resultado en un `SDatosNivel` y el Modelo del grupo
(por ejemplo `CJuego`) construye con esos datos el tablero, los vehículos y la fila. Las dos ayudas
`esColorValido` y `esDireccionValida` ya están implementadas. **`cargar` y `cargarDesde` son stubs
que el grupo debe implementar y probar.**

## Cómo compilar y probar

Necesita `g++` (C++17) y `make`. Verifique con `g++ --version` y `make --version`.

```
make                 # compila el juego -> busfever (busfever.exe en Windows)
./busfever           # corre con niveles/nivel01.txt
./busfever niveles/nivel02.txt
make test            # corre TODAS las pruebas y muestra el total al final
make run-formato     # corre solo pruebas/test_formato.cpp
make clean           # borra lo compilado
```

Hoy `./busfever` muestra un mensaje de bienvenida y avisa que no pudo cargar el nivel, porque
`cargar` todavía es un stub.

**Sobre `make test`:** el repositorio trae una sola prueba de ejemplo, `pruebas/test_formato.cpp`,
y **pasa** a propósito. Prueba las dos ayudas de formato que ya están implementadas, para que vean
cómo se escriben las pruebas con `minitest.h` sin regalar nada de la lógica del juego. Para la
entrega final cada grupo agrega un `pruebas/test_<clase>.cpp` por clase, con al menos una prueba
por método. El `Makefile` corre automáticamente todos los `pruebas/test_*.cpp`.

## Flujo de trabajo con Git y GitHub

```
# 1. Un integrante hace fork de este repositorio y agrega a los demás como colaboradores
git clone https://github.com/<usuario>/bus-fever-party.git
cd bus-fever-party
git remote add upstream <URL de este repositorio>

# 2. Trabajen en ramas y unan a main del fork cuando funcione
git checkout -b cargador-niveles
make && make test
git commit -m "CCargadorNivel: implementa cargarDesde"

# 3. Antes de cada entrega, traigan los cambios del repositorio base
git pull upstream main

# 4. Suban y abran un Pull Request desde su fork hacia este repositorio
git push origin main
```

- Commits pequeños con mensajes claros. Todos los integrantes deben tener commits.
- Un Pull Request por entrega, con la lista de verificación de la plantilla completa.
- No editen `CCargadorNivel.h`, `SDatosNivel.h`, `minitest.h` ni `resumen_pruebas.cpp`. Si creen
  que falta algo, abran un *issue* en este repositorio.
