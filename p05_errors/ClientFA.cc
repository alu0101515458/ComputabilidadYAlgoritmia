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
// 10/10/2023 - Creacion (primera version) del codigo

#include "Tools.h"
#include "Alphabet.h"
#include "FA.h"

/**
 * @brief Funcion principal donde se desarrolla
 * el programa.
 * 
 * @param argc 
 * @param argv 
 * @return int
 */
int main(int argc, char* argv[]) {
  // Si el conteo de parametros no es el indicado, llamamos a la funcion Usage.
  if (argc != 3) {
    Tools::Usage(argc, argv);
  }
  // COMPROBACION DE QUE FUNCIONA CLASE STATE
  // State estado1("q1", false), estado2("q2", true);
  // estado1.AddTransition('a', estado2);
  // std::cout << estado1 << std::endl;
  FA automata;

  State initialState("q1", false), estado2("q2", false), estado3("q3", false), estado4("q4", true);
  initialState.AddTransition('a',estado2);
  estado2.AddTransition('b',estado3);
  estado3.AddTransition('c',estado4);
  automata.setInitialState(&initialState);
  
}