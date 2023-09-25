// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con cadenas
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 19/09/2023
// Archivo ClientChain.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las clases Alphabet, Symbol,
// Chain y Language para: obtener alfabétos, longitudes de cadenas,
// inversas de cadenas, prefijos de cadenas y sufijos de cadenas.

// Historial de revisiones
// 19/09/2023 - Creacion (primera version) del codigo

#include "Chain.h"

/**
 * @brief Constructor de la cadena.
 * 
 */
Chain::Chain() {}

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
 * @brief Sobrecarga del operador< para comparar
 * cadenas
 * 
 * @param first_chain 
 * @param second_chain 
 * @return true 
 * @return false 
 */
bool operator<(const Chain& first_chain, const Chain& second_chain) {
  return (first_chain.chain_ < second_chain.chain_) ? true : false;
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
  return GetSymbols().size();
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
 * @brief Metodo para adicion de simbolos a cadenas.
 * 
 * @param Symbol 
 */
void Chain::Add(const Symbol& Symbol) {
  chain_.push_back(Symbol);
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
 * @return std::string 
 */
std::string Chain::Inverse(std::string aux) {
  std::string result;
  for(int i = aux.size() - 1; i >= 0; --i) {
    result.push_back(aux[i]);
  }
  return result;
}

/**
 * @brief Metodo que devuelve longitud de una cadena (string).
 * 
 * @param aux 
 * @return int 
 */
int Chain::Length(std::string aux) {
  int count = 0;
  for (unsigned int i = 0; i < aux.size(); ++i) {
    ++count;
  }
  return count;
}