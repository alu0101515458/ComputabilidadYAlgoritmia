#include "Tools.h"

void Tools::Usage(int argc, char* argv[]) {
  std::string palabra = argv[1];
  if(argc == 2 && palabra == "--help") {
    std::cout << "La entrada que debería recibir es: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "siendo 'filein.txt una fichero de entrada de cadenas de diferentes alfabetos (separadas por un salto de linea)," << std::endl;
    std::cout << "'fileout.txt' un fichero de salida con las especificaciones del opcode" << std::endl;
    std::cout << "y 'opcode' la eleccion de la utilidad del programa."<< std::endl;
  }
  if(argc != 4) {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Pruebe './p02_strings --help' para mas informacion." << std::endl;
  }
  exit(EXIT_SUCCESS);
}