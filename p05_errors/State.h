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
#include "Symbol.h"
#include <string>
#include <map>
#include <utility> 

const Symbol EMPTY('&');

class State {
  public:
    State();
    State(const State& estado);
    State(const std::string& nombre_estado, const bool& accepted);

    std::string GetIdentifier() const;
    bool IsAccepted() const;

    void AddTransition(const Symbol& simbolo, const State& estado);
    void AddEmptyTransition(const State& estado);
    std::multimap<Symbol, State>::iterator FindTransition(const Symbol& simbolo) const;
    std::multimap<Symbol, State> GetTransitions() const;

    friend bool operator<(const State& first_estado, const State& second_chain);
    friend std::ostream& operator<<(std::ostream& os, const State& State);
  private:
    bool accepted_ = false;
    std::string identifier_;
    std::multimap<Symbol, State> transiciones_;
};

bool operator<(const State& first_estado, const State& second_estado);
std::ostream& operator<<(std::ostream& os, const State& estado);