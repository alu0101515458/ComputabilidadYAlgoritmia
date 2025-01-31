// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Algoritmo de construcción de subconjuntos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 24/10/2023
// Archivo ClientFA.cc: programa cliente.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#include "Tools.h"
#include "Alphabet.h"
#include "FA.h"

#include <map>

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
  // ABRIMOS EL FICHERO DE ENTRADA Y ALMACENAMOS EL ALFABETO.
  std::ifstream ifile{argv[1]};
  std::string alphabet;
  std::getline(ifile, alphabet);
  // CREAMOS EL ALFABETO RECORRIENDO LOS SIMBOLOS ALMACENADOS EN LA VARIABLE (alphabet).
  Alphabet alfabeto(alphabet);
  // CREAMOS EL AUTOMATA FINITO
  FA automata(alfabeto);
  // RECOGEMOS EL NUMERO DE ESTADOS Y EL ESTADO INICIAL.
  int num_states;
  std::string initial_state;
  ifile >> num_states >> initial_state;
  // CREAMOS UN MAP PARA RECOGER LOS ESTADOS Y SUS TRANSICIONES.
  std::map<std::string, State*> states_vector;
  // CREAMOS EL ESTADO INICIAL
  states_vector[initial_state] = new State(initial_state);
  
  // MIENTRAS SIGAN HABIENDO ESTADOS
  while (num_states != 0) {
    std::string nombre;
    bool accepted;
    ifile >> nombre >> accepted;
    // CREAMOS EL ESTADO CON SU NOMBRE Y SI ES DE ACEPTACION O NO.
    // SI NO EXISTE EL ESTADO, LO CREAMOS EN EL MAP CON SU NOMBRE Y SI ES DE ACEPTACION O NO.
    if (states_vector.find(nombre) == states_vector.end()) {
      states_vector[nombre] = new State(nombre, accepted);
    } else { // SI EXISTE, ACTUALIZAMOS SI ES DE ACEPTACION O NO.
      states_vector[nombre]->SetAccepted(accepted);
    }
    // RECOGEMOS EL NUMERO DE TRANSICIONES DEL ESTADO.
    int transiciones;
    ifile >> transiciones;
    states_vector[nombre]->SetNumberTransitions(transiciones);
    // PARA CADA TRANSICION DEL ESTADO, RECOGEMOS EL SIMBOLO Y EL ESTADO AL QUE VA.
    for (int i = 0; i < transiciones; ++i) {
      char symbol;
      ifile >> symbol;
      Symbol simbolo(symbol);
      // COMPROBAMOS QUE EL SIMBOLO PERTENECE AL ALFABETO DEL AUTOMATA FINITO
      Tools::ExistsSymbol(simbolo, alfabeto);
      // AÑADIMOS LA TRANSICION AL ESTADO RECOGIENDO EL NOMBRE DEL ESTADO AL QUE VA.
      std::string nombreEstado2;
      ifile >> nombreEstado2;
      // SI NO EXISTE EL ESTADO, LO CREAMOS EN EL MAP CON SU NOMBRE.
      if (states_vector.find(nombreEstado2) == states_vector.end()) {
        states_vector[nombreEstado2] = new State(nombreEstado2);
      }
      // SI ES UN SIMBOLO VACIO, AÑADIMOS UNA TRANSICION VACIA.
      if (simbolo == EMPTY) {
        states_vector[nombre]->AddEmptyTransition(states_vector[nombreEstado2]);
      } else { // SI NO ES UN SIMBOLO VACIO, AÑADIMOS UNA TRANSICION CON EL SIMBOLO.
        states_vector[nombre]->AddTransition(simbolo, states_vector[nombreEstado2]);
      }
    }
    // AÑADIMOS EL ESTADO CON SUS TRANSICIONES AL AUTOMATA FINITO.
    automata.Add(states_vector[nombre]);
    --num_states;
  }
  // ESTABLECEMOS EL ESTADO INICIAL DEL AUTOMATA FINITO.
  automata.SetInitialState(states_vector[initial_state]);
  // RECOGEMOS LAS CADENAS Y LAS COMPROBAMOS
  std::ofstream output_dfa{argv[2]};
  output_dfa << automata.SubassemblyConstruction();

  // CERRAMOS EL FICHERO.
  ifile.close();
  return 0;
}