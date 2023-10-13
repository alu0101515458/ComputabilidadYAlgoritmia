// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Francisco Raúl Fernández Gómez
// Correo: alu0101427324@ull.edu.es
// Fecha: 26/09/2023
// Archivo Alphabet.h:
// 21/09/2023 - Creacion (primera version) del codigo 
// 22/09/2023 - Solucionando bugs 
// 23-25/09/23 - Solucionando bugs 
// 26/09/23 - Ultima versión del programa y comentarios 

#ifndef ALPHABET_H
#define ALPHABET_H

#include <set>
#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Clase Alfabeto  
 * 
 */
class Alphabet {
  public:
    /// Constructors
    Alphabet() = default;
    Alphabet(const std::set<char>& set_of_chars) : alphabet_(set_of_chars) {}
    Alphabet(const std::vector<char>& vector_of_chars);
    Alphabet(const std::string& string);
    Alphabet(const Alphabet& alphabet) : alphabet_(alphabet.alphabet_) {}

    /// Member functions 
    void Add(const Alphabet& new_alphabet);

    /// Getters & Setters 
    std::set<char> GetAlphabet() const {return alphabet_;}

    /// Operators 
    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet_to_print);
  private:
    std::set<char> alphabet_;
};

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet_to_print);

#endif