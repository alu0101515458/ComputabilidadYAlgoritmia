// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Implementacion de un simulador de automatas finitos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 10/10/2023
// Archivo State.cc: Implementacion de la clase State.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#include "State.h"

/**
 * @brief CONSTRUCTOR POR DEFECTO DE LA CLASE STATE.
 * 
 */
State::State() {
  identifier_ = "";
  accepted_ = false;
}

/**
 * @brief CONSTRUCTOR DE LA CLASE STATE QUE RECIBE 
 * UN IDENTIFICADOR COMO PARAMETRO.
 * 
 * @param identifier 
 */
State::State(std::string identifier) {
  identifier_ = identifier;
  accepted_ = this->IsAccepted();
}

/**
 * @brief CONSTRUCTOR DE LA CLASE STATE QUE RECIBE UN IDENTIFICADOR Y 
 * UN BOOLEANO (ACEPTADO) COMO PARAMETROS.
 * 
 * @param nombre_State 
 * @param accepted 
 */
State::State(const std::string& nombre_State, const bool& accepted) {
  identifier_ = nombre_State;
  accepted_ = accepted;
}

/**
 * @brief METODO GETTER QUE DEVUELVE EL IDENTIFICADOR DEL ESTADO.
 * 
 * @return std::string 
 */
std::string State::GetIdentifier() const {
  return identifier_;
}

/**
 * @brief METODO GETTER QUE DEVUELVE EL BOOLEANO (ACEPTADO) DEL ESTADO.
 * 
 * @return true 
 * @return false 
 */
bool State::IsAccepted() const {
  return accepted_;
}

/**
 * @brief METODO SETTER QUE ESTABLECE EL BOOLEANO (ACEPTADO) DEL ESTADO.
 * 
 * @param accepted 
 */
void State::SetAccepted (bool accepted) {
  accepted_ = accepted;
}

/**
 * @brief METODO QUE DEVUELVE LAS TRANSICIONES DEL ESTADO
 * ALMACENADAS EN UN VECTOR.
 * 
 * @param simbolo 
 * @return std::vector<State*> 
 */
std::vector<State*> State::FindSymbolTransitions(const Symbol& simbolo) const {
  std::vector<State*> result;
  // PARA CADA TRANSICION DEL ESTADO, COMPROBAMOS SI EL SIMBOLO ES IGUAL AL QUE BUSCAMOS.
  for (auto it = transiciones_.begin(); it != transiciones_.end(); ++it) {
    if (it->first == simbolo) {
      result.push_back(it->second);
    }
  }
  return result;
}

/**
 * @brief METODO QUE DEVUELVE LAS TRANSICIONES VACIAS DEL ESTADO
 * ALMACENADAS EN UN VECTOR.
 * 
 * @return std::vector<State*> 
 */
std::vector<State*> State::FindEmptyTransitions() const {
  return FindSymbolTransitions(EMPTY);
}

/**
 * @brief METODO GETTER QUE DEVUELVE LAS TRANSICIONES DEL ESTADO.
 * 
 * @return std::multimap<Symbol,State*> 
 */
std::multimap<Symbol,State*> State::GetTransitions() const {
  return transiciones_;
}

/**
 * @brief METODO QUE AÑADE UNA TRANSICION AL ESTADO.
 * 
 * @param simbolo 
 * @param estado 
 */
void State::AddTransition(const Symbol& simbolo, State* estado) {
  transiciones_.insert(std::pair<Symbol, State*>(simbolo, estado));
}

/**
 * @brief METODO QUE AÑADE UNA TRANSICION VACIA AL ESTADO.
 * 
 * @param estado 
 */
void State::AddEmptyTransition(State* estado) {
  transiciones_.insert(std::pair<Symbol, State*>(EMPTY, estado));
}

/**
 * @brief SOBRECARGA DEL OPERADOR < QUE COMPARA DOS ESTADOS.
 * 
 * @param first_State 
 * @param second_State 
 * @return true 
 * @return false 
 */
bool operator<(const State& first_State, const State& second_State) {
  return (first_State.identifier_.size() < second_State.identifier_.size()) ? true : false;
}

/**
 * @brief SOBRECARGA DEL OPERADOR << QUE IMPRIME UN ESTADO.
 * 
 * @param os 
 * @param estado 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const State& estado) {
  os << estado.identifier_;
  if (estado.accepted_) {
    os << "|final|";
    for (auto it = estado.transiciones_.begin(); it != estado.transiciones_.end(); ++it) {
      os << " -> " << it->first << " -> " << it->second->identifier_ << std::endl;
    }
  } else {
    os << "|no final|";
    for (auto it = estado.transiciones_.begin(); it != estado.transiciones_.end(); ++it) {
      os << " -> " << it->first << " -> " << it->second->identifier_ << std::endl;
    }
  }
  return os;
}

/**
 * @brief SOBRERCARGA DEL OPERADOR >> QUE LEE UN ESTADO.
 * 
 * @param is 
 * @param state_ptr 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, State*& state_ptr) {
  std::string identifier;
  is >> identifier;
  state_ptr = new State(identifier);
  return is;
}