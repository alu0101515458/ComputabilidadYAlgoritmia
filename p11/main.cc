#include <iostream>
#include <fstream>
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
int main(int argc, char* argv[]) {
  // Crear un vector de puntos
  CyA::point_vector points;

  // Leer puntos desde la entrada estándar
  std::cin >> points;

  // Crear un point_set con los puntos leídos
  point_set ps(points);

  // Verificar si la opción -d está presente
  bool dotOutput = false;
  std::string dotFilename;
  for (int i = 1; i < argc; ++i) {
      if (std::string(argv[i]) == "-d") {
          if (i + 1 < argc) { // Asegurarse de que haya un nombre de archivo después de -d
              dotOutput = true;
              dotFilename = argv[i + 1];
              break;
          }
      }
  }
  // Si se pide salida DOT, generar archivo DOT
  if (dotOutput) {
      std::ofstream dotFile(dotFilename);
      ps.write_dot(dotFile);
      dotFile.close();
  } else {
      // De lo contrario, imprimir el árbol como se hacía previamente
      ps.write_tree(std::cout);
  }

  // MODIFICACIÓN
  std::cout << "CONTADOR: ";
  int contador = ps.verify_max_cost_arcs();
  std::cout << contador << std::endl;
  return 0;
}