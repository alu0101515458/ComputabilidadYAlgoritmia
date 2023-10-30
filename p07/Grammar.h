// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Algoritmo de construcción de subconjuntos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 24/10/2023
// Archivo Symbol.h: Clase Symbol.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#pragma once

#include "Alphabet.h"

#include<set>
#include<map>
#include<iostream>

class Grammar {
  public:
    // CONSTRUCTORES
    Grammar();

    // MÉTODOS
    Grammar CFGtoFNC() const;
    void AddProduction(const Symbol& non_terminal, const std::vector<Symbol>& chain);
    std::multimap<Symbol, std::vector<Symbol>> FindEmptyProductions();
    std::multimap<Symbol, std::vector<Symbol>> FindUnitaryProductions();

    // GETTERS
    Alphabet GetAlphabet() const;
    std::set<Symbol> GetSimbolNonTerminal() const;

    // SETTERS
    void SetAlphabet(Alphabet alphabet);
    void SetSimbolsNonTerminal(std::set<Symbol> non_terminals);

    // SOBRECARGA DE OPERADORES
    friend std::ostream& operator<<(std::ostream& os, const Grammar& grammar);

  private:
    Alphabet alphabet_;
    std::set<Symbol> non_terminals_;
    std::multimap<Symbol, std::vector<Symbol>> productions_;
};

std::ostream& operator<<(std::ostream& os, const Grammar& grammar);