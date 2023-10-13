// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Francisco Raúl Fernández Gómez
// Correo: alu0101427324@ull.edu.es
// Fecha: 26/09/2023
// Archivo Language.h:
// 21/09/2023 - Creacion (primera version) del codigo 
// 22/09/2023 - Solucionando bugs 
// 23-25/09/23 - Solucionando bugs 
// 26/09/23 - Ultima versión del programa y comentarios 

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Chain.h"
#include "Alphabet.h"
#include <set>
#include <fstream>

/**
 * @brief Para manejo de lenguajes y conjuntos de cadenas
 * 
 */
class Language {
  public:
    /// Constructors
    Language() = default; 
    Language(std::set<Chain> chains); 
    Language(std::ifstream& filein);
    
    /// Getters & Setters
    std::set<Chain> GetterChains();
    
    /// Member functions  
    void Insert(std::set<Chain> chains);
    void Insert(Chain chain);
    void PrintAllPreffix();
    Language Preffix(const Chain& chain);
    void PrintAllSuffix();
    Language Suffix(const Chain& chain);

    /// Operators overloaded
    friend std::ostream& operator<<(std::ostream& os, const Language& language);
  private:
    std::set<Chain> language_chains_;
    Alphabet language_alphabet_;                                       
};

std::ostream& operator<<(std::ostream& os, const Language& language);
std::istream& operator>>(std::istream& is,  Language& language); 
#endif