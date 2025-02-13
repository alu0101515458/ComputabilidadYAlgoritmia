// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo Chain.cc: Implementacion de la clase Cadena.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#include "Chain.h"

/**
 * @brief Constructor de la cadena.
 * 
 */
Chain::Chain() {}

/**
 * @brief Constructor de la cadena a partir de una string.
 * 
 * @param chain 
 */
Chain::Chain(std::string chain) {
  for (unsigned int i = 0; i < chain.size(); ++i) {
    chain_.push_back(chain[i]);
  }
}

/**
 * @brief Constructor de la cadena a partir 
 * de un vector de simbolos.
 * 
 * @param chain 
 */
Chain::Chain(std::vector<Symbol> chain) {
  chain_ = chain;
}

/**
 * @brief Metodo para adicion de simbolos a cadenas.
 * 
 * @param Symbol 
 */
void Chain::Add(const Symbol& Symbol) {
  chain_.push_back(Symbol);
}


/**
 * @brief Metodo para obtener los simbolos de la cadena.
 * 
 * @return std::vector<Symbol> 
 */
std::vector<Symbol> Chain::GetSymbols() const {
  return chain_;
}

/**
 * @brief Metodo para obtener longitud de cadenas.
 * 
 * @return int 
 */
int Chain::GetSymbolsLength() const {
  return chain_.size();
}

/**
 * @brief Metodo que devuelve un alfabeto a partir de una cadena.
 * 
 * @param aux 
 * @return Alphabet 
 */
Alphabet Chain::GetAlphabet(std::string aux) {
    Alphabet Result;
    for (unsigned int i = 0; i < aux.length(); ++i) {
      Symbol symb = aux[i];
      if (Result.GetSymbols().find(symb) != Result.GetSymbols().end()) {
        Result.Add(symb);
      }
    }
  return Result;
}


/**
 * @brief Metodo que devuelve la inversa de una cadena.
 * 
 * @param aux 
 * @return Chain
 */
Chain Chain::Inverse(std::string aux) {
  Chain result;
  for(int i = aux.size() - 1; i >= 0; --i) {
    result.Add(aux[i]);
  }
  return result;
}

/**
 * @brief Metodo que devuelve longitud de una cadena (string).
 * 
 * @param aux 
 * @return int 
 */
int Chain::Length(Chain Chain) {
  if(Chain.GetSymbols()[0] == '&') return 0; // Cadena vacia, su longitud = 0.
  int count = 0;
  for (int i = 0; i < Chain.GetSymbolsLength(); ++i) {
    ++count;
  }
  return count;
}

/**
 * @brief Sobrecarga del operador< para comparar
 * cadenas
 * 
 * @param first_chain 
 * @param second_chain 
 * @return true or false
 */
bool operator<(const Chain& first_chain, const Chain& second_chain) {
  return (first_chain.chain_ < second_chain.chain_) ? true : false;
}

/**
 * @brief Sobrecarga del operador<< para la correcta
 * visualizacion de las cadenas.
 * 
 * @param os 
 * @param chain 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Chain& chain) {
  for(const Symbol& symbol: chain.GetSymbols()) {
    os << symbol;
  }
  return os;
}

/**
 * @brief Sobrecarga del operador>> para la correcta
 * lectura de las cadenas.
 * 
 * @param is 
 * @param chain 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Chain& chain) {
  std::string aux;
  is >> aux;
  chain = Chain(aux);
  return is;
}