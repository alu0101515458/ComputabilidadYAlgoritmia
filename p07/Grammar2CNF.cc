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
  // Si el conteo de parametros no es el indicado, llamamos a la funcion Usage.
  if (argc != 3) {
    Tools::Usage(argc, argv);
  }
  std::ifstream input_gra(argv[1]);
  Grammar grammar;
  Alphabet alphabet;
  int num_symbols;
  input_gra >> num_symbols;
  for (int i = 0; i < num_symbols; ++i) {
    Symbol terminal;
    input_gra >> terminal;
    alphabet.Add(terminal);
  }
  grammar.SetAlphabet(alphabet);
  input_gra >> num_symbols;
  // SET DE SIMBOLOS NO TERMINALES
  std::set<Symbol> non_terminals;
  for (int i = 0; i < num_symbols; ++i) {
    Symbol non_terminal;
    input_gra >> non_terminal;
    non_terminals.insert(non_terminal);
  }
  int num_productions;
  input_gra >> num_productions;
  for (int i = 0; i < num_productions; ++i) {
    Symbol non_terminal;
    input_gra >> non_terminal;
    std::vector<Symbol> chain;
    std::string chain_string;
    input_gra >> chain_string;
    for (unsigned int i = 0; i < chain_string.size(); ++i) {
      chain.push_back(chain_string[i]);
    }
    grammar.AddProduction(non_terminal, chain);
  }
  std::multimap<Symbol, std::vector<Symbol>> empty_num_productions = grammar.FindEmptyProductions();
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
  std::multimap<Symbol, std::vector<Symbol>> unitary_productions = grammar.FindUnitaryProductions();
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
  std::ofstream output_gra(argv[2]);
  output_gra << grammar.CFGtoFNC();
  input_gra.close();
  output_gra.close();
}