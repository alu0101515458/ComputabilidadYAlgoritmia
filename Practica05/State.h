// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Implementacion de un simulador de automatas finitos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 10/10/2023
// Archivo State.h: Clase State.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#pragma once
#include "Symbol.h"
#include <string>
#include <map>
#include <utility> 

// CONSTANTE QUE REPRESENTA EL SIMBOLO VACIO.
const Symbol EMPTY('&');

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

    std::string GetIdentifier() const;
    bool IsAccepted() const;

    void SetAccepted(bool accepted);

    void AddTransition(const Symbol& simbolo, State* estado);
    void AddEmptyTransition(State* estado);
    std::vector<State*> FindSymbolTransitions(const Symbol& simbolo) const;
    std::vector<State*> FindEmptyTransitions() const;
    std::multimap<Symbol, State*> GetTransitions() const;

    friend bool operator<(const State& first_estado, const State& second_chain);
    friend std::ostream& operator<<(std::ostream& os, const State& State);
    friend std::istream& operator>>(std::istream& is, State*& state_ptr);
  private:
    bool accepted_ = false;
    std::string identifier_;
    std::multimap<Symbol, State*> transiciones_;
};

bool operator<(const State& first_estado, const State& second_estado);
std::ostream& operator<<(std::ostream& os, const State& estado);
std::istream& operator>>(std::istream& is, State*& state_ptr);