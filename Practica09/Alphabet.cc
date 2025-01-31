// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo Alphabet.cc: Implementacion de la clase Alfabeto.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#include "Alphabet.h"

/**
 * @brief Constructor del alfabeto.
 * 
 */
Alphabet::Alphabet() {}

/**
 * @brief Constructor del alfabeto a partir de una cadena string.
 * 
 * @param alphabet 
 */
Alphabet::Alphabet(std::string alphabet) {
  for (unsigned int i = 0; i < alphabet.size(); ++i) {
    if (alphabet[i] != ' ' && alphabet[i] != '\n') {
      alphabet_.insert(alphabet[i]);
    }
  }
}

/**
 * @brief Constructor del alfabeto a partir de un set de simbolos.
 * 
 * @param alphabet 
 */
Alphabet::Alphabet(const std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
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


/**
 * @brief Sobrecarga del operador<< para la correcta
 * visualizacion de alfabetos.
 * 
 * @param os 
 * @param alphabet 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  for (auto it = alphabet.alphabet_.begin(); it != alphabet.alphabet_.end(); ++it) {
    os << *it << " ";
  }
  return os;
}