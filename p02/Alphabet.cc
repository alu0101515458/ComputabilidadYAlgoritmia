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

#include "Alphabet.h"

/**
 * @brief Constructor del alfabeto.
 * 
 */
Alphabet::Alphabet() {}

/**
 * @brief Constructor del alfabeto a partir de un set de simbolos.
 * 
 * @param alphabet 
 */
Alphabet::Alphabet(const std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
}

/**
 * @brief Sobrecarga del operador<< para la correcta
 * visualizacion de alfabetos.
 * 
 * @param os 
 * @param alphabet 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  std::set<Symbol>::iterator it = alphabet.alphabet_.begin();
  os << "{";
  if (it != alphabet.alphabet_.end()) {
    os << *it;
    ++it;
  }
  while (it != alphabet.alphabet_.end()) {
    os << ", " << *it;
    ++it;
  }
  os << "}";
  return os;
}

/**
 * @brief Metodo que devuelve los simbolos.
 * 
 * @return std::set<Symbol> 
 */
std::set<Symbol> Alphabet::GetSymbols() const {
  return this->alphabet_;
}

/**
 * @brief Metodo de adicion de simbolos a alfabetos.
 * 
 * @param symbol 
 */
void Alphabet::Add(const Symbol& symbol) {
  alphabet_.insert(symbol);
}

/**
 * @brief Metodo que devuelve la union de dos alfabetos.
 * 
 * @param alphabet 
 * @return Alphabet 
 */
Alphabet Alphabet::NewAlphabet(Alphabet alphabet) const {
  Alphabet new_alphabet;
  for (const Symbol& symbol: alphabet.GetSymbols()) {
    new_alphabet.Add(symbol);
  }
  return new_alphabet;
}