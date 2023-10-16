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

#include "FA.h"

FA::FA() {
  inicial_ = nullptr;
}

FA::FA(Alphabet alfabeto, std::set<State*> estados, State* inicial) {
  alfabeto_ = alfabeto;
  estados_ = estados;
  inicial_ = inicial;
}

Alphabet FA::GetAlphabet() const {
  return alfabeto_;
}

void FA::SetInitialState(State* estado) {
  inicial_ = estado;
  estados_.insert(estado);
}

bool FA::Simulate_(const State* estado, const Chain& cadena, int pos) {
  if (pos == cadena.GetSymbolsLength()) {
    return true;
  }

  if (estado->GetTransitions().find(cadena.GetSymbols()[pos]) != estado->GetTransitions().end()) {
    for (unsigned int i = 0; i < estado->FindSymbolTransitions(cadena.GetSymbols()[pos]).size(); ++i) {
      if (Simulate_(estado->FindSymbolTransitions(cadena.GetSymbols()[pos])[i].second, cadena, pos+1)) {
        return true;
      }
    }
  }

  return false;
}

void FA::Add(State* estado) {
  estados_.insert(estado);
}

bool FA::Simulate(const Chain& cadena) {
  int pos = 0;
  return Simulate_(this->inicial_, cadena, pos);
}