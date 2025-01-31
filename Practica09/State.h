// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo State.h: Clase State.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#pragma once
#include "Symbol.h"
#include <string>
#include <map>
#include <utility> 

/**
 * @brief ESTRUCTURA TRANSITION QUE REPRESENTA
 * UNA TRANSICIÓN DE LOS ESTADOS.
 * 
 */
struct Transition {
  Symbol read_symbol_;
  Symbol write_symbol_;
  Symbol move_;
  std::string next_state_;
};

/**
 * @brief Clase State que tiene que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructores, sobrecarga de operadores y metodos (getters, setters, ...).
 * @private bool accepted_, std::string identifier_, std::multimap<Symbol, State*> transiciones_.
 */
class State {
  public:
    State();
    State(std::string identifier);
    State(const std::string& nombre_estado, const bool& accepted);

    ~State() = default;

    std::string GetIdentifier() const;
    bool IsAccepted() const;

    void SetAccepted(bool accepted);
    void SetNumberTransitions(int number_transitions);

    void AddTransition(Symbol& simbolo, Symbol& simbolo_escritura, Symbol& movimiento, State* estado_destino);
    std::map<Symbol, Transition> FindSymbolTransitions(const Symbol& simbolo) const;
    std::map<Symbol, Transition> GetTransitions() const;
    std::map<Symbol, Transition> GetTransitionsBySymbol(Symbol symbol) const;

    friend bool operator<(const State& first_estado, const State& second_chain);
    friend std::istream& operator>>(std::istream& is, State*& state_ptr);

  private:
    int number_transitions_ = 0; 
    bool accepted_ = false;
    std::string identifier_;
    std::map<Symbol, Transition> transiciones_;
};

bool operator<(const State& first_estado, const State& second_estado);
std::ostream& operator<<(std::ostream& os, const State& estado);
std::istream& operator>>(std::istream& is, State*& state_ptr);