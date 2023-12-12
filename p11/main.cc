#include <iostream>
#include "point_types.h"  // Asegúrate de incluir tu archivo de definiciones
#include "point_set.h"

/*
  * Para compilar:
  * make
  * 
  * Para ejecutar:
  * ./program
  * (DATOS DE ENTRADA)
  * 5
  * 1.0 2.0
  * 3.4 5.6
  * 7.8 9.0
  * 2.3 4.5
  * 6.7 8.9
  * 
  * Para limpiar:
  * make clean
*/
int main() {
  // Crear un vector de puntos
  CyA::point_vector points;

  // Leer puntos desde la entrada estándar
  std::cin >> points;

  // Crear un point_set con los puntos leídos
  point_set ps(points);

  // Calcular el árbol de expansión mínima y emitir el resultado
  ps.write_tree(std::cout);

  return 0;
}