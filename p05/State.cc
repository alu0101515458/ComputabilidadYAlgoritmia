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

#include "State.h"

State::State() {
  identifier_ = "";
  accepted_ = false;
}

State::State(const std::string& nombre_State, const bool& accepted) {
  identifier_ = nombre_State;
  accepted_ = accepted;
}

std::string State::GetIdentifier() const {
  return identifier_;
}

bool State::IsAccepted() const {
  return accepted_;
}

std::multimap<Symbol,const State&>::iterator State::FindTransition(const Symbol& simbolo) const {
  return transiciones_.find(simbolo);
}

std::multimap<Symbol,const State&> State::GetTransitions() const {
  return transiciones_;
}

void State::AddTransition(const Symbol& simbolo, const State& estado) {
  transiciones_.insert(std::pair<Symbol, State>(simbolo, estado));
}

void State::AddEmptyTransition(const State& estado) {
  transiciones_.insert(std::pair<Symbol, State>(EMPTY, estado));
}

bool operator<(const State& first_State, const State& second_State) {
  return (first_State.identifier_.size() < second_State.identifier_.size()) ? true : false;
}

std::ostream& operator<<(std::ostream& os, const State& estado) {
  os << estado.identifier_;
  if (estado.accepted_) {
    os << "|final|";
    for (auto it = estado.transiciones_.begin(); it != estado.transiciones_.end(); ++it) {
      std::cout << " -> " << it->first << " -> " << it->second.identifier_ << std::endl;
    }
  } else {
    os << "|no final|";
    for (auto it = estado.transiciones_.begin(); it != estado.transiciones_.end(); ++it) {
      std::cout << " -> " << it->first << " -> " << it->second.identifier_ << std::endl;
    }
  }
  return os;
}