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
    std::cout << "Modo de empleo: ./Grammar2CNF input.gra output.gra" << std::endl;
    std::cout << "Pruebe 'Grammar2CNF --help' para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string palabra = argv[1];
  if(argc == 2 && palabra == "--help") {
    std::cout << "Para ejecutar el programa correctamente se necesita un fichero" << std::endl;
    std::cout << "con extension '.gra' en el que figura la especificacion de una gramatica independiente del contexto" << std::endl;
    std::cout << "y como segundo parametro un fichero de salida con extension '.gra'" << std::endl;
    std::cout << "en el que se muestra una gramática equivalente"<< std::endl;
    std::cout << std::endl;
    std::cout << "El programa se encarga de convertir una gramatica independiente del contexto a una gramática equivalente." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if(argc != 3) {
    std::cout << "Modo de empleo: ./Grammar2CNF input.gra output.gra" << std::endl;
    std::cout << "Pruebe './Grammar2CNF --help' para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}