// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Francisco Raúl Fernández Gómez
// Correo: alu0101427324@ull.edu.es
// Fecha: 26/09/2023
// Archivo Chain.cc:
// 21/09/2023 - Creacion (primera version) del codigo 
// 22/09/2023 - Solucionando bugs 
// 23-25/09/23 - Solucionando bugs 
// 26/09/23 - Ultima versión del programa y comentarios 

#include "Chain.h"

/**
 * @brief Constructor de una cadena
 * 
 * @param chain 
 */
Chain::Chain(const std::string& chain) : Alphabet(chain) {
    for (char symbol : chain) {
      chain_.push_back(symbol);
    }
  
}

/**
 * @brief Devuelve la cadena inversa
 * 
 * @return Chain 
 */
Chain Chain::Backward() const {
  std::vector<char> backward_string;
  /// Recorremos el vector a la inversa y lo introducimos en el chain inverso
  for (auto it = chain_.rbegin(); it != chain_.rend(); it++) {
    backward_string.push_back(*it);
  }

  return Chain(backward_string);
}

/**
 * @brief Imprime una cadena
 * 
 * @param os 
 * @param string 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Chain& string) {
  for (char symbol : string.chain_) {
    os << symbol;
  }
  return os;
}

/**
 * @brief Lee una cadena
 * 
 * @param is 
 * @param string 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Chain& string) {
  std::string readed_string;
  if (is >> readed_string) {
    string = Chain(readed_string); // Convierte la cadena a un objeto Chain
  }
  return is;
}

/**
 * @brief Compara que cadena precede a otra
 * 
 * @param chain_1 
 * @param chain_2 
 * @return true 
 * @return false 
 */
bool operator<(const Chain& chain_1, const Chain& chain_2) {
  /// Convertimos los Chain en strings
  std::string string_1(chain_1.chain_.begin(), chain_1.chain_.end());
  std::string string_2(chain_2.chain_.begin(), chain_2.chain_.end());
  return string_1 < string_2;
}

Chain Chain::Concatenation(const Chain& new_chain) {
  Chain result;
  result.chain_ = this->chain_;
  for(char symbol : new_chain.chain_) {
    result.AddSymbolBack(symbol);
  }
  return result;
}