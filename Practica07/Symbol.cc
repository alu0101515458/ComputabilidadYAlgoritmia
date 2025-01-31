// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramáticas en Forma Normal de Chomsky.
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 30/10/2023
// Archivo Symbol.cc: Implementacion de la clase Symbol.

// Historial de revisiones
// 24/10/2023 - Creacion (primera version) del codigo

#include "Symbol.h"

/**
 * @brief CONSTRUCTOR POR DEFECTO DEL SÍMBOLO.
 * 
 */
Symbol::Symbol() {}

/**
 * @brief CONSTRUCTOR DEL SÍMBOLO A PARTIR DE UN CHAR.
 * 
 * @param symbol 
 */
Symbol::Symbol(char symbol) { 
  char_ = symbol;  
}

/**
 * @brief GETTER QUE DEVUELVE EL CHAR DEL SIMBOLO.
 * 
 * @return char 
 */
char Symbol::GetSymbol() const {
  return this->char_;
}

/**
 * @brief SOBRECARGA DEL OPERADOR<< PARA IMPRIMIR
 * EL SÍMBOLO.
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
 * @brief SOBRECARGA DEL OPERADOR== PARA COMPARAR
 * SÍMBOLOS.
 * 
 * @param first_symbol 
 * @param second_symbol 
 * @return true 
 * @return false 
 */
bool operator==(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() == second_symbol.GetSymbol());
}

/**
 * @brief SOBRECARGA DEL OPERADOR< PARA COMPARAR
 * SÍMBOLOS.
 * 
 * @param first_symbol 
 * @param second_symbol 
 * @return true 
 * @return false 
 */
bool operator<(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() < second_symbol.GetSymbol()) ? true : false;
}

/**
 * @brief SOBRECARGA DEL OPERADOR!= PARA COMPARAR
 * SÍMBOLOS.
 * 
 * @param first_symbol 
 * @param second_symbol 
 * @return true 
 * @return false 
 */
bool operator!=(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() != second_symbol.GetSymbol()) ? true : false;
}

/**
 * @brief SOBRECARGA DEL OPERADOR>> PARA LEER
 * SÍMBOLOS.
 * 
 * @param is 
 * @param symbol 
 * @return std::ifstream& 
 */
std::ifstream& operator>>(std::ifstream& is, Symbol& symbol) {
  is >> symbol.char_;
  return is;
}