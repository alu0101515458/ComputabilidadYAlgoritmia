// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo Symbol.cc: Implementacion de la clase Symbol.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#include "Symbol.h"

/**
 * @brief Constructor del simbolo.
 * 
 */
Symbol::Symbol() {}

/**
 * @brief Constructor del simbolo a partir de un char
 * 
 * @param symbol 
 */
Symbol::Symbol(char symbol) { 
  char_ = symbol;  
}

/**
 * @brief Sobrecarga del operador<< para la correcta
 * visualizacion del simbolo.
 * 
 * @param os 
 * @param symbol 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.char_;
  return os;
}

/**
 * @brief Sobrecarga del operador== para comparar
 * simbolos.
 * 
 * @param first_symbol 
 * @param second_symbol 
 * @return true or false
 */
bool operator==(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() == second_symbol.GetSymbol());
}

/**
 * @brief Sobrecarga del operador< para comparar
 * simbolos.
 * 
 * @param first_symbol 
 * @param second_symbol 
 * @return true or false
 */
bool operator<(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() < second_symbol.GetSymbol()) ? true : false;
}

/**
 * @brief Sobrecarga del operador!= para comparar
 * simbolos.
 * 
 * @param first_symbol 
 * @param second_symbol 
 * @return true or false
 */
bool operator!=(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() != second_symbol.GetSymbol()) ? true : false;
}

/**
 * @brief Sobrecarga del operador>> para la correcta
 * lectura del simbolo.
 * 
 * @param is 
 * @param symbol 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Symbol& symbol) {
  is >> symbol.char_;
  symbol = Symbol(symbol.char_);
  return is;
}

/**
 * @brief Metodo mencionado que obtiene el simbolo.
 * 
 * @return char 
 */
char Symbol::GetSymbol() const {
  return this->char_;
}