// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 19/09/2023
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la funcion main del proyecto que usa la clase Strings
// para: 

// Referencias:
// Enlaces de interes

// Historial de revisiones
// 12/09/2023 - Creacion (primera version) del codigo
#include "Alphabet.h"
#pragma once

class Chain {
  public:
    Chain();
    Chain(std::vector<Symbol> chain);

    friend bool operator<(const Chain& first_chain, const Chain& second_chain);
    friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
    std::vector<Symbol> GetSymbols() const;
    int GetSymbolsLength() const;
    
    void Add(const Symbol& Symbol);
    void GetAlphabet(std::string input_file, std::string output_file);
    void Inverse(std::string input_file, std::string output_file);
    void Length(std::string input_file, std::string output_file);

  private:
    std::vector<Symbol> chain_;
    Alphabet alphabet_;
};

std::ostream& operator<<(std::ostream& os, const Chain& chain);