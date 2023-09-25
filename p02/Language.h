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

#include "Chain.h"

#pragma once

/**
 * @brief Clase Lenguage que tendrá que ver con la funcionalidad
 * del programa.
 * 
 * @public Constructor, sobrecarga de operador<< y metodos.
 * @private std::set<Chain>, Alphabet
 */
class Language {
  public:
    Language();
    friend std::ostream& operator<<(std::ostream& os, const Language& language);

    std::set<Chain> GetChains() const;    
    void Add(const Chain& chain);

    Language Prefix(std::string aux);
    Language Sufix(std::string aux);
    
  private:
    std::set<Chain> language_;
    Alphabet alphabet_;
};

std::ostream& operator<<(std::ostream& os, const Language& language);
