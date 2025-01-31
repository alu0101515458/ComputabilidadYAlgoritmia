// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramáticas en Forma Normal de Chomsky.
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 30/10/2023
// Archivo Grammar.h: Clase Grammar.

// Historial de revisiones
// 24/10/2023 - Creacion (primera version) del codigo

#pragma once

#include "Alphabet.h"

#include<set>
#include<map>
#include<iostream>

/**
 * @brief Clase Grammar que tiene que ver con la funcionalidad
 * del programa
 * 
 * @public Constructores, getters, setters, métodos
 * y sobrecarga del operador<<.
 * @private std::set<Symbol>, Alphabet,
 * std::multimap<Symbol, std::vector<Symbol>>
 */
class Grammar {
  public:
    // CONSTRUCTORES
    Grammar();

    // GETTERS
    Alphabet GetAlphabet() const;
    std::set<Symbol> GetSimbolsNonTerminal() const;

    // SETTERS
    void SetAlphabet(Alphabet alphabet);
    void SetSimbolsNonTerminal(std::set<Symbol> non_terminals);

    // MÉTODOS
    std::multimap<Symbol, std::vector<Symbol>> FindEmptyProductions();
    std::multimap<Symbol, std::vector<Symbol>> FindUnitaryProductions();
    void AddProduction(const Symbol& non_terminal, const std::vector<Symbol>& chain);
    Grammar CFGtoFNC() const;

    // SOBRECARGA DE OPERADORES
    friend std::ostream& operator<<(std::ostream& os, const Grammar& grammar);

  private:
    Alphabet alphabet_;
    std::set<Symbol> non_terminals_;
    std::multimap<Symbol, std::vector<Symbol>> productions_;
};

std::ostream& operator<<(std::ostream& os, const Grammar& grammar);