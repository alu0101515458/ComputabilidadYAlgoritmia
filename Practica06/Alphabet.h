// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Algoritmo de construcción de subconjuntos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 24/10/2023
// Archivo Alphabet.h: Clase Alfabeto.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#include "Symbol.h"
#pragma once

/**
 * @brief Clase Alfabeto que tiene que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructores, sobrecarga de operador<< y metodos.
 * @private std::set<Symbol>
 */
class Alphabet {
  public:
    Alphabet();
    Alphabet(std::string alphabet);
    Alphabet(const std::set<Symbol> alphabet);

    void Add(const Symbol& symbol);
    std::set<Symbol> GetSymbols() const;
    Alphabet NewAlphabet(Alphabet new_alphabet) const;

    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

  private:
    std::set<Symbol> alphabet_;
};

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);