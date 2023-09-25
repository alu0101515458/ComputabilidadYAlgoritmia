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
 * @brief Metodo mencionado que obtiene el simbolo.
 * 
 * @return char 
 */
char Symbol::GetSymbol() const {
  return this->char_;
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
 * @return true 
 * @return false 
 */
bool operator==(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() == second_symbol.GetSymbol()) ? true : false;
}

/**
 * @brief Sobrecarga del operador< para comparar
 * simbolos.
 * 
 * @param first_symbol 
 * @param second_symbol 
 * @return true 
 * @return false 
 */
bool operator<(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() < second_symbol.GetSymbol()) ? true : false;
}