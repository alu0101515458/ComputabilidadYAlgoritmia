// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Algoritmo de construcción de subconjuntos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 24/10/20233
// Archivo FA.h: Clase FA.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#pragma once

#include "State.h"
#include "Chain.h"
#include <stack>
#include <set>

/**
 * @brief Clase FA que tiene que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructores y metodos.
 * @private std::set<Symbol>, State* inicial_, Alphabet alfabeto_, metodo privado Simulate_.
 */
class FA {
  public:
    FA();
    FA(Alphabet);
    FA(Alphabet, std::set<State*>, State*);
    FA(std::set<State*>);

    ~FA();

    Alphabet GetAlphabet() const;
    int GetStatesNumber() const;
    std::string GetInitialState() const;

    void SetInitialState(State* estado);
    void SetAlphabet(Alphabet alfabeto);


    void Add(State* estado);
    bool Simulate(const Chain& cadena);

    std::set<State*> EpsilonClausura(std::set<State*> estados) const;
    std::set<State*> Move(std::set<State*> estados, Symbol simbolo) const;
    FA SubassemblyConstruction() const;
    
    friend std::ostream& operator<<(std::ostream& os, const FA& fa);

  private:
    std::set<State*> estados_;
    // Utilizamos un puntero para no generar una copia del estado inicial.
    State* inicial_;
    Alphabet alfabeto_;
    bool AnyAccepted(const std::set<State*>& estados) const;
    bool Simulate_(const State*, const Chain&, int);
};

std::ostream& operator<<(std::ostream& os, const FA& fa);