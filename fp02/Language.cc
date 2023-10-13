// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Francisco Raúl Fernández Gómez
// Correo: alu0101427324@ull.edu.es
// Fecha: 26/09/2023
// Archivo Language.cc:
// 21/09/2023 - Creacion (primera version) del codigo 
// 22/09/2023 - Solucionando bugs 
// 23-25/09/23 - Solucionando bugs 
// 26/09/23 - Ultima versión del programa y comentarios 

#include "Language.h"


/**
 * @brief Construye un nuevo lenguaje
 * 
 * @param chains 
 */
Language::Language(std::set<Chain> chains) {
  for (auto it = chains.begin(); it != chains.end(); it++) {
    this->language_chains_.insert(*it); 
    /// Creamos un alfabeto con la cadena y lo añadimos al alfabeto del lenguaje 
    Alphabet aux(*it);
    this->language_alphabet_.Add(aux);
  }
}

/**
 * @brief Imprime correctamente un lenguaje
 * 
 * @param os 
 * @param language 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Language& language) {
  os << "{&";
  if (language.language_chains_.size() != 0) {
    for (auto& it : language.language_chains_) {
      os << ", " << it;
    }
  }
  os << "}";
  return os;
}

Language::Language(std::ifstream& filein) {
  std::string readed_string;
  while (filein >> readed_string) {
    language_chains_.insert(Chain(readed_string));
    language_alphabet_.Add(Chain(readed_string).GetAlphabet());
  }
  filein.close();
}

/**
 * @brief Devuelve las cadenas del lenguaje
 * 
 * @return std::set<Chain> 
 */
std::set<Chain> Language::GetterChains() {
  return this->language_chains_;
}

/**
 * @brief Añade nuevas cadenas al lenguaje
 * 
 * @param chains 
 */
void Language::Insert(std::set<Chain> chains) {
  for (auto& it : chains) {
    this->language_chains_.insert(it);
    this->language_alphabet_.Add(it);
  }
}

/**
 * @brief Añade una única nueva cadena al lenguaje
 * 
 * @param chain 
 */
void Language::Insert(Chain chain) {
  this->language_chains_.insert(chain);
  this->language_alphabet_.Add(Alphabet(chain));
}

/**
 * @brief Imprime todos los prefijos de cada cadena del lenguaje.
 * 
 */
void Language::PrintAllPreffix() {
  for (auto it : this->language_chains_) {
    std::cout << Preffix(it) << std::endl;
  }
}

/**
 * @brief Devuelve un lenguaje que contiene el conjunto de prefijos de una cadena
 * 
 * @param chain 
 * @return Language 
 */
Language Language::Preffix(const Chain& chain) {
  Language result;
  Chain aux_chain;
  for (char symbol : chain.GetChain()) {
    aux_chain.AddSymbolBack(symbol);
    result.Insert(aux_chain);
  }
  return result;
}

/**
 * @brief Imprime todos los prefijos de cada cadena del lenguaje.
 * 
 */
void Language::PrintAllSuffix() {
  for (auto it : this->language_chains_) {
    std::cout << Suffix(it) << std::endl;
  }
}

/**
 * @brief Devuelve un lenguaje que contiene el conjunto de prefijos de una cadena 
 * 
 * @param chain 
 * @return Language 
 */
Language Language::Suffix(const Chain& chain) {
  Language result;
  Chain aux_chain;
  const std::vector<char>& cadena = chain.GetChain();
  for (auto it = cadena.rbegin(); it != cadena.rend(); ++it) {
      aux_chain.AddSymbolFront(*it);
      result.Insert(aux_chain);
  }
  return result;
}