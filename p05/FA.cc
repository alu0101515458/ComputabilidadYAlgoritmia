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

FA::FA(std::set<State> estados, State* inicial) {
  estados_ = estados;
  inicial_ = inicial;
}

void FA::setInitialState(State* estado) {
  inicial_ = estado;
}

bool FA::Simulate_(State* estado, const Chain& cadena, int pos) {
  if (pos == cadena.GetSymbolsLength()) return true;
  else {
    if (estado->FindTransition(cadena.GetSymbols()[pos]) != estado->GetTransitions().end()) {
      return Simulate_(estado->FindTransition(cadena.GetSymbols()[pos])->second, cadena, pos+1);
    } else {
      return false;
    }
  } // abc q1 -> A -> q2 -> B -> q3F
}

void FA::Add(const State& estado) {
  estados_.insert(estado);
}

bool FA::Simulate(const Chain& cadena, int pos=0) {
  return Simulate_(inicial_, cadena, pos);
}