// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo Tools.cc: Implementacion del namespace Tools.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#include "Tools.h"

/**
 * @brief MÉTODO QUE ESPECIFICA EL MODO DE EMPLEO DEL PROGRAMA.
 * 
 * @param argc 
 * @param argv 
 */
void Tools::Usage(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de empleo: ./p09_turing_machine fichero.tm fichero.tape" << std::endl;
    std::cout << "Pruebe './p09_turing_machine --help' para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string palabra = argv[1];
  if(argc == 2 && palabra == "--help") {
    std::cout << "Para ejecutar el programa correctamente se necesita un fichero" << std::endl;
    std::cout << "con extension '.tm' en el que figura la especificacion de una máquina de turing" << std::endl;
    std::cout << "y como segundo parametro un fichero de entrada con extension '.tape'" << std::endl;
    std::cout << "en el que se figure una cadena que servirá para simular la máquina"<< std::endl;
    std::cout << std::endl;
    std::cout << "El programa se encarga de simular una cadena sobre una cinta infinita en una máquina de turing." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if(argc != 3) {
    std::cout << "Modo de empleo: ./p09_turing_machine fichero.tm fichero.tape" << std::endl;
    std::cout << "Pruebe './p09_turing_machine --help' para mas informacion." << std::endl;
    exit(EXIT_SUCCESS);
  }
}