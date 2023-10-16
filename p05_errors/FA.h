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

#pragma once

#include "State.h"
#include "Chain.h"
#include <set>

class FA {
  public:
    FA();
    FA(std::set<State>, State*);

    void setInitialState(State* estado);
    void Add(const State& estado);
    bool Simulate(const Chain& cadena, int pos);

  private:
    std::set<State> estados_;
    // Utilizamos un puntero para no generar una copia del estado inicial.
    State* inicial_;
    bool Simulate_(const State*, const Chain&, int);
};