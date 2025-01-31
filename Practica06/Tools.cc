// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Algoritmo de construcción de subconjuntos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 24/10/2023
// Archivo Tools.cc: Implementacion del namespace Tools.

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
    std::cout << "con extension '.nfa' en el que figura la especificacion de un NFA" << std::endl;
    std::cout << "y como segundo parametro un fichero de salida con extension '.dfa'" << std::endl;
    std::cout << "en el que se almacena el DFA." << std::endl;
    std::cout << std::endl;
    std::cout << "El programa se encarga de convertir un NFA a un DFA" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if(argc != 3) {
    std::cout << "Modo de empleo: ./p05_automata_simulator input.fa output.fa" << std::endl;
    std::cout << "Pruebe 'p05_automata_simulator --help' para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief METODO QUE COMPRUEBA SI UN SIMBOLO PERTENECE AL ALFABETO.
 * 
 * @param simbolo 
 * @param alfabeto 
 */
void Tools::ExistsSymbol(const Symbol& simbolo, const Alphabet& alfabeto) {
  bool exist = false;
    for (unsigned int j = 0; j < alfabeto.GetSymbols().size(); ++j) {
      if (alfabeto.GetSymbols().find(simbolo) != alfabeto.GetSymbols().end()) {
        exist = true;
      }
    }
    if (!exist) {
      std::cout << "El simbolo " << simbolo << " no pertenece al alfabeto del automata finito." << std::endl;
      exit(EXIT_FAILURE);
    }
}