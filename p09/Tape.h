// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo Tape.h: Clase Tape.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#pragma once

#include <iostream>
#include <list>
#include "Chain.h"

// Se declaran constantes para el simbolo blanco
// y los movimientos de la cinta.
const Symbol SIMBOLO_BLANCO('$');
const Symbol LEFT('L');
const Symbol RIGHT('R');

/**
 * @brief Clase Tape que tiene que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructores, sobrecarga de operadores y metodos (getters, setters, ...).
 * @private Alphabet tape_alphabet_, std::list<Symbol> tape_, std::list<Symbol>::iterator pointer_.
 */
class Tape {
  public:
    Tape();
    Tape(Chain chain);
    void Left();
    void Right();
    void Write(const Symbol& symbol);
    Symbol Read() const;

    void WriteOutput(std::ostream& os, std::string identifier) const;
  private:
    Alphabet tape_alphabet_;
    std::list<Symbol> tape_;
    std::list<Symbol>::iterator pointer_;
};