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

#pragma once

#include<set>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

/**
 * @brief Clase Symbol que tendrá que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructores, sobrecarga de operadores y un método.
 * @private Char
 */
class Symbol {
  public:
    Symbol();
    Symbol(char symbol);

    friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol);
    friend bool operator==(const Symbol& first_symbol, const Symbol& second_symbol);
    friend bool operator<(const Symbol& first_symbol, const Symbol& second_symbol);
    
    char GetSymbol() const;

  private:
    char char_;
};

std::ostream& operator<<(std::ostream& os, const Symbol& symbol);
bool operator==(const Symbol& first_symbol, const Symbol& second_symbol);
bool operator<(const Symbol& first_symbol, const Symbol& second_symbol);