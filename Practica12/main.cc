#include <fstream>
#include <iostream>

#include "point_set.h"
#include "point_types.h"

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
      if (i + 1 <argc) {  // Asegurarse de que haya un nombre de archivo después de -d
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
    ps.write_hull(std::cout);
  }
  // MODIFICACIÓN
  std::cout << "Profundidad de la recursividad: " << ps.get_depth() << std::endl;
}
