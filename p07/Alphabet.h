// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramáticas en Forma Normal de Chomsky.
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 30/10/2023
// Archivo Alphabet.h: Clase Alfabeto.

// Historial de revisiones
// 24/10/2023 - Creacion (primera version) del codigo

#include "Symbol.h"
#pragma once

/**
 * @brief Clase Alfabeto que tiene que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructores, getter, métodos y sobrecarga de operador<<.
 * @private std::set<Symbol>
 */
class Alphabet {
  public:
    // CONSTRUCTORES
    Alphabet();
    Alphabet(std::string alphabet);
    Alphabet(const std::set<Symbol> alphabet);

    // GETTERS
    std::set<Symbol> GetSymbols() const;

    // MÉTODOS
    void Add(const Symbol& symbol);
    bool FindSymbol(const Symbol& symbol) const;
    Alphabet NewAlphabet(Alphabet new_alphabet) const;

    // SOBRECARGA DE OPERADORES
    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

  private:
    std::set<Symbol> alphabet_;
};

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);