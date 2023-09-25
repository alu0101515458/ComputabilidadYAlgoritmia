// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con cadenas
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 19/09/2023
// Archivo ClientChain.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las clases Alphabet, Symbol,
// Chain y Language para: obtener alfabétos, longitudes de cadenas,
// inversas de cadenas, prefijos de cadenas y sufijos de cadenas.

// Historial de revisiones
// 19/09/2023 - Creacion (primera version) del codigo

#include "Tools.h"

/**
 * @brief En el main incluimos esta función para aclarar la utilización del programa.
 * 
 * @param argc 
 * @param argv 
 */
void Tools::Usage(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Pruebe './p02_strings --help' para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string palabra = argv[1];
  if(argc == 2 && palabra == "--help") {
    std::cout << "La entrada que debería recibir es: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "siendo 'filein.txt' un fichero de entrada de cadenas de diferentes alfabetos (separadas por un salto de linea)," << std::endl;
    std::cout << "'fileout.txt' un fichero de salida con las especificaciones del opcode" << std::endl;
    std::cout << "y 'opcode' la eleccion de la utilidad del programa."<< std::endl;
    std::cout << "OPCODES:" << std::endl;
    std::cout << " 1. LONGITUD DE LA/S CADENA/S" << std::endl;
    std::cout << " 2. ALFABETO/S DE UNA/S CADENA/S" << std::endl;
    std::cout << " 3. INVERSA/S DE UNA/S CADENA/S" << std::endl;
    std::cout << " 4. PREFIJOS DE UNA/S CADENA/S" << std::endl;
    std::cout << " 5. SUFIJOS DE UNA/S CADENA/S" << std::endl;
  }
  if(argc != 4) {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Pruebe './p02_strings --help' para mas informacion." << std::endl;
  }
  exit(EXIT_SUCCESS);
}