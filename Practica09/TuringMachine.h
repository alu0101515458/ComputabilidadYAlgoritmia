// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo TuringMachine.h: Clase TuringMachine.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#pragma once

#include <iostream>
#include "Alphabet.h"
#include "Tape.h"
#include "State.h"
#include "Chain.h"
#include <set>

/**
 * @brief Clase TuringMachine que tiene que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructores, sobrecarga de operadores y metodos (getters, setters, ...).
 * @private int num_transitions, std::set<State*> states_, State* initial_state_, Tape cinta_.
 */
class TuringMachine {
  public:
    TuringMachine();
    TuringMachine(std::string file_name);
    ~TuringMachine();
    
    void SetInitialState(State* state);
    void SetNumTransitions(int num_transitions);

    State* GetInitialState() const;
    State* GetFinalState() const;
    std::map<Symbol, Transition> GetTransitions() const;
    int GetNumTransitions() const;
    State* GetStateByIdentifier(std::string identifier) const;

    void AddState(State* state);
    void Simulate(const Chain& chain) const;

    friend std::ostream& operator<<(std::ostream& os, const TuringMachine& turing_machine);
    
  private:
    int num_transitions_;
    std::set<State*> states_;
    State* initial_state_;
    Tape cinta_;
};

std::ostream& operator<<(std::ostream& os, const TuringMachine& turing_machine);