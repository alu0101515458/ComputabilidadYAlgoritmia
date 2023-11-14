// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo Tape.cc: Implementación de la clase Tape.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#include "Tape.h"

/**
 * @brief CONSTRUCTOR POR DEFECTO DE LA CINTA.
 * 
 */
Tape::Tape() {
  tape_.push_back(SIMBOLO_BLANCO);
  pointer_ = tape_.begin();
}

/**
 * @brief CONSTRUCTOR DE LA CINTA A PARTIR DE UNA CADENA.
 * 
 * @param chain 
 */
Tape::Tape(Chain chain) {
  for (Symbol s: chain.GetSymbols()) {
    tape_.push_back(s);
  }
  pointer_ = tape_.begin();
}

/**
 * @brief MÉTODO QUE MUEVE EL PUNTERO A LA IZQUIERDA.
 * 
 */
void Tape::Left() {
  if (pointer_ != tape_.begin()) {
    --pointer_;
  } else {
    tape_.push_front(SIMBOLO_BLANCO);
    pointer_ = tape_.begin();
  }
}

/**
 * @brief MÉTODO QUE MUEVE EL PUNTERO A LA DERECHA.
 * 
 */
void Tape::Right() {
  if (std::next(pointer_) != tape_.end()) {
    ++pointer_;
  } else {
    tape_.push_back(SIMBOLO_BLANCO);
    pointer_++;
  }
}

/**
 * @brief MÉTODO QUE ESCRIBE UN SIMBOLO EN LA CINTA.
 * 
 * @param symbol 
*/
void Tape::Write(const Symbol& symbol) {
  *pointer_ = symbol;
}

/**
 * @brief MÉTODO QUE DEVUELVE EL SÍMBOLO ACTUAL DE LA CINTA.
 * 
 * @return Symbol 
*/
Symbol Tape::Read() const {
  return *pointer_;
}

/**
 * @brief MÉTODO QUE DEVUELVE EL ALFABETO DE LA CINTA.
 * 
 * @param os 
 * @param identifier 
 */
void Tape::WriteOutput(std::ostream& os, std::string identifier) const {
  os << SIMBOLO_BLANCO;
  for (auto it = tape_.begin(); it != tape_.end(); ++it) {
    if (it == pointer_) {
      os << " " << identifier << " ";
    }
    os << *it;
  }
  os << SIMBOLO_BLANCO;
  os << std::endl;
}