// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 19/09/2023
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la funcion main del proyecto que usa la clase Strings
// para: 

// Referencias:
// Enlaces de interes

// Historial de revisiones
// 12/09/2023 - Creacion (primera version) del codigo
#include "Chain.h"

Chain::Chain() {}

Chain::Chain(std::vector<Symbol> chain) {
  chain_ = chain;
}

bool operator<(const Chain& first_chain, const Chain& second_chain) {
  return (first_chain.chain_ < second_chain.chain_) ? true : false;
}

std::vector<Symbol> Chain::GetSymbols() const {
  return chain_;
}

int Chain::GetSymbolsLength() const {
  return GetSymbols().size();
}

std::ostream& operator<<(std::ostream& os, const Chain& chain) {
  for(const Symbol& symbol: chain.GetSymbols()) {
    os << symbol;
  }
  return os;
}

void Chain::Add(const Symbol& Symbol) {
  chain_.push_back(Symbol);
}

// abbab -> {a, b}
// hola -> {a, h, l, o}
void Chain::GetAlphabet(std::string input_file, std::string output_file) {
  std::ifstream ifile(input_file);
  std::ofstream ofile(output_file);
  std::string aux;

  // Declarar el alfabeto fuera del bucle

  while (ifile >> aux) { // Utilizar una lectura segura
    Alphabet Result;
    for (unsigned int i = 0; i < aux.length(); ++i) {
      Symbol symb = aux[i];
      if (Result.GetSymbols().find(symb) != Result.GetSymbols().end()) {
        Result.Add(symb);
      }
    }
    ofile << Result << std::endl;
  }

  // Cerrar los archivos
  ifile.close();
  ofile.close();
}

void Chain::Inverse(std::string input_file, std::string output_file) {
  std::ifstream ifile(input_file);
  std::ofstream ofile(output_file);
  std::string aux;

  while(ifile >> aux) {
    Chain Result;
    for(int i = aux.length() - 1; i >= 0; --i) {
      Result.Add(aux[i]);
    }
    ofile << Result << std::endl;
  }
  ifile.close();
  ofile.close();
}

void Chain::Length(std::string input_file, std::string output_file) {
  std::ifstream ifile(input_file);
  std::ofstream ofile(output_file);
  std::string aux;
  int count = 0;

  while(ifile >> aux) {
    for (unsigned int i = 0; i < aux.size(); ++i) {
      ++count;
    }
    ofile << count << std::endl;
    count = 0;
  }

  ifile.close();
  ofile.close();
}