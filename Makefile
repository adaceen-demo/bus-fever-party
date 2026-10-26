# Makefile de Bus Fever Party! FPOO C++ Edition.
# Los grupos NO necesitan editarlo: toma automáticamente todos los .cpp de
# src/modelo, src/vista y src/controlador, y todos los pruebas/test_*.cpp.
#
#   make                compila el juego (ejecutable: busfever)
#   make test           compila y corre TODAS las pruebas y muestra el total
#   make run-formato    corre solo pruebas/test_formato.cpp (cambie 'formato')
#   make clean          borra lo compilado
#
# Funciona en Linux, macOS y Windows (con MinGW-w64/MSYS2 y make).

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Isrc -Isrc/modelo -Isrc/vista -Isrc/controlador -Ipruebas -MMD -MP

ifeq ($(OS),Windows_NT)
EXE = .exe
else
EXE =
endif

# Si falta la carpeta build/ (por ejemplo, después de borrarla a mano), se crea.
ifeq ($(wildcard build/.),)
$(shell mkdir build)
endif

# Los .cpp se buscan en estas carpetas; todo lo compilado va a build/ (carpeta plana).
# Por eso dos .cpp no pueden llamarse igual aunque estén en carpetas distintas.
vpath %.cpp src src/modelo src/vista src/controlador pruebas

SRC_LIB    = $(wildcard src/modelo/*.cpp src/vista/*.cpp src/controlador/*.cpp)
OBJ_LIB    = $(addprefix build/, $(notdir $(SRC_LIB:.cpp=.o)))
TEST_SRC   = $(wildcard pruebas/test_*.cpp)
TEST_NAMES = $(patsubst test_%,%,$(basename $(notdir $(TEST_SRC))))
RESUMEN    = build/resumen_pruebas$(EXE)

all: busfever$(EXE)

busfever$(EXE): $(OBJ_LIB) build/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/test_%$(EXE): build/test_%.o $(OBJ_LIB)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(RESUMEN): build/resumen_pruebas.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# El "-" deja seguir con las demás pruebas aunque un ejecutable se caiga.
run-%: build/test_%$(EXE)
	$(info === pruebas de $* ===)
	-@build/test_$*$(EXE)

correr-todas: $(addprefix run-, $(TEST_NAMES))

test: $(RESUMEN)
	@$(RESUMEN) --reiniciar
	@$(MAKE) --no-print-directory correr-todas
	@$(RESUMEN) $(words $(TEST_NAMES))

clean:
ifeq ($(OS),Windows_NT)
	-@del /Q /F build\*.o build\*.d build\*.exe build\*.txt busfever.exe
else
	@rm -f build/*.o build/*.d build/*.txt build/test_* build/resumen_pruebas busfever
endif

-include $(wildcard build/*.d)

.PHONY: all test correr-todas clean
.SECONDARY:
