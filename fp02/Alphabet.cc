// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Francisco Raúl Fernández Gómez
// Correo: alu0101427324@ull.edu.es
// Fecha: 26/09/2023
// Archivo Alphabet.cc:
// 21/09/2023 - Creacion (primera version) del codigo 
// 22/09/2023 - Solucionando bugs 
// 23-25/09/23 - Solucionando bugs 
// 26/09/23 - Ultima versión del programa y comentarios 


#include "Alphabet.h"

/**
 * @brief Constructor de Alfabeto usando un vector de chars
 * 
 * @param vector_of_chars 
 */
Alphabet::Alphabet(const std::vector<char>& vector_of_chars) {
  for (int i = 0; i < vector_of_chars.size(); i++) {
    alphabet_.insert(vector_of_chars.at(i));
  }
}

/**
 * @brief Constructor de Alfabeto usando un string
 * 
 * @param vector_of_chars 
 */
Alphabet::Alphabet(const std::string& string) {
  for (char symbol : string) {
    alphabet_.insert(symbol);
  }
}


/**
 * @brief Añade nuevos simbolos al alfabeto
 * 
 * @param vector_of_chars 
 */
void Alphabet::Add(const Alphabet& new_alphabet) {
  for (auto it = new_alphabet.alphabet_.begin(); it != new_alphabet.alphabet_.end(); it++) {
    this->alphabet_.insert(*it);
  }
}

/**
 * @brief Imprime un alfabeto con su correspondiente formato
 * 
 * @param os 
 * @param alphabet_to_print 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet_to_print) {
  os << "{";
  /// Recorremos el alfabeto iterando
  for (auto it = alphabet_to_print.alphabet_.begin(); it != alphabet_to_print.alphabet_.end(); it++) {
    /// Si no es el primero imprimimos la coma
    if (it != alphabet_to_print.alphabet_.begin()) {
      os << ", ";
    }
    os << *it;
  }
  os << "}";
  return os;
}