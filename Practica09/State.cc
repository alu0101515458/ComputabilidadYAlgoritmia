// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo State.cc: Implementacion de la clase State.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

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
 * @brief SETTER QUE ESTABLECE EL NUMERO DE TRANSICIONES DEL ESTADO.
 * 
 * @param number_transitions 
 */
void State::SetNumberTransitions(int number_transitions) {
  this->number_transitions_ = number_transitions;
}

/**
 * @brief METODO QUE AÑADE UNA TRANSICION AL ESTADO.
 * 
 * @param simbolo 
 * @param estado 
 */
void State::AddTransition(Symbol& simbolo, Symbol& simbolo_escritura, Symbol& movimiento, State* estado_destino) {
  Transition transition;
  transition.read_symbol_ = simbolo;
  transition.write_symbol_ = simbolo_escritura;
  transition.move_ = movimiento;
  transition.next_state_ = estado_destino->GetIdentifier();
  transiciones_.insert(std::pair<Symbol, Transition>(simbolo, transition));
}

/**
 * @brief METODO QUE DEVUELVE LAS TRANSICIONES DEL ESTADO
 * ALMACENADAS EN UN VECTOR.
 * 
 * @param simbolo 
 * @return std::map<Symbol, Transition>
 */
std::map<Symbol, Transition> State::FindSymbolTransitions(const Symbol& simbolo) const {
  std::map<Symbol, Transition> result;
  for (auto it = transiciones_.begin(); it != transiciones_.end(); ++it) {
    if (it->first == simbolo) {
      result.insert(std::pair<Symbol, Transition>(it->first, it->second));
    }
  }
  return result;
}

/**
 * @brief METODO GETTER QUE DEVUELVE LAS TRANSICIONES DEL ESTADO.
 * 
 * @return std::map<Symbol, Transition>
 */
std::map<Symbol, Transition> State::GetTransitions() const {
  return transiciones_;
}

/**
 * @brief MÉTODO GETTER QUE DEVUELVE LAS TRANSICIONES DEL ESTADO
 * DE LA MÁQUINA DE TURING.
 * 
 * @return std::map<Symbol, Transition> 
 */
std::map<Symbol, Transition> State::GetTransitionsBySymbol(Symbol symbol) const {
  std::map<Symbol, Transition> result;
  for (auto it = transiciones_.begin(); it != transiciones_.end(); ++it) {
    if (it->first == symbol) {
      result.insert(std::pair<Symbol, Transition>(it->first, it->second));
    }
  }
  return result;
}


/**
 * @brief SOBRECARGA DEL OPERADOR< QUE COMPARA DOS ESTADOS.
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
 * @brief SOBRERCARGA DEL OPERADOR>> QUE LEE UN ESTADO.
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