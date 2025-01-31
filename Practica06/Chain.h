// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Algoritmo de construcción de subconjuntos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 24/10/2023
// Archivo Chain.h: Clase Cadena.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#include "Alphabet.h"
#pragma once


/**
 * @brief Clase Chain que tendrá que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructores, sobrecarga de operadores, metodos.
 * @private std::vector<Symbol>
 */
class Chain {
  public:
    Chain();
    Chain(std::string chain);
    Chain(std::vector<Symbol> chain);
    
    void Add(const Symbol& Symbol);
    std::vector<Symbol> GetSymbols() const;
    int GetSymbolsLength() const;
    
    // METODOS SOLVENTADORES
    Alphabet GetAlphabet(std::string aux);
    Chain Inverse(std::string aux);
    int Length(Chain Chain);

    friend bool operator<(const Chain& first_chain, const Chain& second_chain);
    friend std::ostream& operator<<(std::ostream& os, const Chain& chain);

  private:
    std::vector<Symbol> chain_;
};

std::ostream& operator<<(std::ostream& os, const Chain& chain);