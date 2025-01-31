// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramáticas en Forma Normal de Chomsky.
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 30/10/2023
// Archivo Alphabet.cc: Implementacion de la clase Alfabeto.

// Historial de revisiones
// 24/10/2023 - Creacion (primera version) del codigo

#include "Alphabet.h"

/**
 * @brief CONSTRUCTOR POR DEFECTO DEL ALFABETO.
 * 
 */
Alphabet::Alphabet() {}

/**
 * @brief CONSTRUCTOR DEL ALFABETO A PARTIR DE UN STRING.
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
 * @brief CONSTRUCTOR DEL ALFABETO A PARTIR DE UN CONJUNTO DE SÍMBOLOS.
 * 
 * @param alphabet 
 */
Alphabet::Alphabet(const std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
}

/**
 * @brief MÉTODO DE ADICIÓN DE UN SÍMBOLO AL ALFABETO.
 * 
 * @param symbol 
 */
void Alphabet::Add(const Symbol& symbol) {
  alphabet_.insert(symbol);
}

/**
 * @brief MÉTODO QUE DEVUELVE LOS SÍMBOLOS DEL ALFABETO.
 * 
 * @return std::set<Symbol> 
 */
std::set<Symbol> Alphabet::GetSymbols() const {
  return this->alphabet_;
}



/**
 * @brief MÉTODO QUE DEVUELVE TRUE SI ENCUENTRA 
 * UN SIMBOLO ESPECÍFICO
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Alphabet::FindSymbol(const Symbol& symbol) const {
  for (const Symbol& symbol_: alphabet_) {
    if (symbol_ == symbol) {
      return true;
    }
  }
  return false;
}

/**
 * @brief MÉTODO QUE DEVUELVE LA UNION DE DOS ALFABETOS.
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
 * @brief SOBRECARCA DEL OPERADOR << PARA IMPRIMIR EL ALFABETO.
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