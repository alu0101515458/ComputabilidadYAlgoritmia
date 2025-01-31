// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Implementacion de un simulador de automatas finitos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 10/10/2023
// Archivo FA.h: Clase FA.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#pragma once

#include "State.h"
#include "Chain.h"
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

    Alphabet GetAlphabet() const;
    void SetInitialState(State* estado);
    void Add(State* estado);
    bool Simulate(const Chain& cadena);

  private:
    std::set<State*> estados_;
    // Utilizamos un puntero para no generar una copia del estado inicial.
    State* inicial_;
    Alphabet alfabeto_;
    bool Simulate_(const State*, const Chain&, int);
};