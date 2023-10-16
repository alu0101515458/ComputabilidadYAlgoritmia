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
  // ABRIMOS EL FICHERO DE ENTRADA Y ALMACENAMOS EL ALFABETO.
  std::ifstream ifile{argv[1]};
  std::string alphabet;
  std::getline(ifile, alphabet);
  // CREAMOS EL ALFABETO RECORRIENDO LOS SIMBOLOS ALMACENADOS EN LA VARIABLE (alphabet).
  Alphabet alfabeto;
  for (unsigned int i = 0; i < alphabet.size(); ++i) {
    if (alphabet[i] != ' ' && alphabet[i] != '\n') {
      alfabeto.Add(alphabet[i]);
    }
  }
  // RECOGEMOS EL NUMERO DE ESTADOS Y EL ESTADO INICIAL.
  int num_states;
  std::string initial_state;
  ifile >> num_states >> initial_state;
  // RECOGEMOS LOS ESTADOS Y SUS TRANSICIONES.
  std::set<State*> set_estados;
  while (num_states != 0) {
    std::string nombre;
    bool accepted;
    ifile >> nombre >> accepted;
    // CREAMOS EL ESTADO CON SU NOMBRE Y SI ES DE ACEPTACION O NO.
    State* estado = new State(nombre, accepted);
    int transiciones;
    ifile >> transiciones;
    // PARA CADA TRANSICION DEL ESTADO, RECOGEMOS EL SIMBOLO Y EL ESTADO AL QUE VA.
    for (int i = 0; i < transiciones; ++i) {
      char symbol;
      ifile >> symbol;
      Symbol simbolo(symbol);
      // COMPROBAMOS QUE EL SIMBOLO PERTENECE AL ALFABETO DEL AUTOMATA FINITO
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
      // AÑADIMOS LA TRANSICION AL ESTADO
      State* estado2;
      ifile >> estado2;
      estado->AddTransition(simbolo, estado2);
      delete estado2;
    }
    set_estados.insert(estado);
    delete estado;
    --num_states;
  }
  // COMPROBAMOS QUE EL ESTADO INICIAL PERTENECE AL CONJUNTO DE ESTADOS DEL AUTOMATA FINITO
  bool exist = false;
  for (auto it = set_estados.begin(); it != set_estados.end(); ++it) {
    if ((*it)->GetIdentifier() == initial_state) {
      exist = true;
    }
  }
  if (!exist) {
    std::cout << "El estado inicial " << initial_state << " no pertenece al conjunto de estados del automata finito." << std::endl;
    exit(EXIT_FAILURE);
  }
  // CREAMOS EL AUTOMATA FINITO
  State* estado_inicial = new State(initial_state);
  FA automata(alfabeto, set_estados, estado_inicial);
  // RECOGEMOS LAS CADENAS Y LAS COMPROBAMOS
  std::ifstream input_chains{argv[2]};
  std::string cadena;

  while (input_chains >> cadena) {
    // CONVERSION DE STRING A CHAIN
    Chain chain{cadena};
    // COMPROBACION DE LA CHAIN
    std::cout << "Cadena " << chain << (automata.Simulate(chain) ? " aceptada." : " no aceptada.") << std::endl;
  }
  delete estado_inicial;
  ifile.close();
  input_chains.close();
  return 0;
}

/*
  FA automata;

  // Mejor asi para todos los estados que crees!!
  // Así no dependen del scope y se pueden usar sus punteros con tranquilidad
  State* initialState = new State("q1", false);
  */