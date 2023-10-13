// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Implementacion de un simulador de automatas finitos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 10/10/2023
// Archivo Tools.h: Recursos para el correcto desarrollo del programa.
// 

// Historial de revisiones
// 1/10/2023 - Creacion (primera version) del codigo

#include "Tools.h"

/**
 * @brief En el main incluimos esta función para aclarar la utilización del programa.
 * 
 * @param argc 
 * @param argv 
 */
void Tools::Usage(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de empleo: ./p05_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "Pruebe 'p05_automata_simulator --help' para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string palabra = argv[1];
  if(argc == 2 && palabra == "--help") {
    std::cout << "Para ejecutar el programa correctamente se necesita un fichero" << std::endl;
    std::cout << "de texto en el que figura la especificacion de un automata finito" << std::endl;
    std::cout << "y un fichero de texto con extension .txt en el que figura una serie de cadenas" << std::endl;
    std::cout << "(una cadena por linea) sobre el alfabeto del automata especificado en el primero de los ficheros." << std::endl;
    std::cout << std::endl;
    std::cout << "El programa se encarga de verificar por pantalla las cadenas que pertenezcan al automata finito." << std::endl;
    std::cout << "(Accepted or Rejected)" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if(argc != 3) {
    std::cout << "Modo de empleo: ./p05_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "Pruebe 'p05_automata_simulator --help' para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}