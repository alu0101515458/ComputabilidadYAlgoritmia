// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramáticas en Forma Normal de Chomsky.
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 30/10/2023
// Archivo Grammar2CNF.cc: Implementación del main.

// Historial de revisiones
// 24/10/2023 - Creacion (primera version) del codigo

#include "Tools.h"
#include "Grammar.h"
#include<fstream>

int main(int argc, char* argv[]) {
  // SI EL NUMERO DE ARGUMENTOS ES DISTINTO DE 3, MOSTRAMOS EL USO CORRECTO DEL PROGRAMA Y SALIMOS.
  if (argc != 3) {
    Tools::Usage(argc, argv);
  }
  // ABRIMOS EL FICHERO DE ENTRADA.
  std::ifstream input_gra(argv[1]);
  Grammar grammar;
  Alphabet alphabet;
  int num_symbols;
  // LEEMOS EL NUMERO DE SIMBOLOS TERMINALES Y LOS AÑADIMOS AL ALFABETO.
  input_gra >> num_symbols;
  for (int i = 0; i < num_symbols; ++i) {
    Symbol terminal;
    input_gra >> terminal;
    alphabet.Add(terminal);
  }
  // AÑADIMOS EL ALFABETO A LA GRAMATICA.
  grammar.SetAlphabet(alphabet);
  // LEEMOS EL NUMERO DE SIMBOLOS NO TERMINALES.
  input_gra >> num_symbols;
  // USAREMOS UN SET PARA AÑADIR LOS SIMBOLOS NO TERMINALES, DE ESTA FORMA NO SE REPETIRAN.
  std::set<Symbol> non_terminals;
  for (int i = 0; i < num_symbols; ++i) {
    Symbol non_terminal;
    input_gra >> non_terminal;
    non_terminals.insert(non_terminal);
  }
  int num_productions;
  // LEEMOS EL NUMERO DE PRODUCCIONES.
  input_gra >> num_productions;
  // PARA CADA PRODUCCION, LEEMOS EL SIMBOLO NO TERMINAL Y LA CADENA DE SIMBOLOS QUE LO ACOMPAÑA QUE SERÁ ALMACENADA EN UN VECTOR DE SIMBOLOS.
  for (int i = 0; i < num_productions; ++i) {
    Symbol non_terminal;
    input_gra >> non_terminal;
    std::vector<Symbol> chain;
    std::string chain_string;
    input_gra >> chain_string;
    for (unsigned int i = 0; i < chain_string.size(); ++i) {
      chain.push_back(chain_string[i]);
    }
    // AÑADIMOS LA PRODUCCION A LA GRAMATICA.
    grammar.AddProduction(non_terminal, chain);
  }
  // MULTIMAP DE PRODUCCIONES VACIAS.
  std::multimap<Symbol, std::vector<Symbol>> empty_num_productions = grammar.FindEmptyProductions();
  // SI HAY PRODUCCIONES VACIAS, LAS MOSTRAMOS Y SALIMOS DEL PROGRAMA.
  if (!empty_num_productions.empty()) {
    std::cout << "Producciones vacías encontradas: " << std::endl;
    for (auto empty_production: empty_num_productions) {
      std::cout << empty_production.first << " -> ";
      for (auto symbol: empty_production.second) {
        std::cout << symbol;
      }
      std::cout << std::endl;
    }
    exit(EXIT_FAILURE);
  }
  // MULTIMAP DE PRODUCCIONES UNITARIAS.
  std::multimap<Symbol, std::vector<Symbol>> unitary_productions = grammar.FindUnitaryProductions();
  // SI HAY PRODUCCIONES UNITARIAS, LAS MOSTRAMOS Y SALIMOS DEL PROGRAMA.
  if (!unitary_productions.empty()) {
    std::cout << "Producciones unitarias encontradas: " << std::endl;
    for (auto unitary_production: unitary_productions) {
      std::cout << unitary_production.first << " -> ";
      for (auto symbol: unitary_production.second) {
        std::cout << symbol;
      }
      std::cout << std::endl;
    }
    exit(EXIT_FAILURE);
  }
  // ABRIMOS EL FICHERO DE SALIDA Y ESCRIBIMOS LA GRAMATICA EN FORMA NORMAL DE CHOMSKY.
  std::ofstream output_gra(argv[2]);
  output_gra << grammar.CFGtoFNC();
  input_gra.close();
  output_gra.close();
}