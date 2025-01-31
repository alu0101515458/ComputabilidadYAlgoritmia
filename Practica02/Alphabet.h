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
    Alphabet(const std::set<Symbol> alphabet);

    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

    void Add(const Symbol& symbol);
    std::set<Symbol> GetSymbols() const;
    Alphabet NewAlphabet(Alphabet new_alphabet) const;

  private:
    std::set<Symbol> alphabet_;
};

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);