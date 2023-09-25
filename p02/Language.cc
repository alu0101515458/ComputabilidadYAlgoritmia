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

#include "Language.h"
/**
 * @brief Constructor del lenguaje.
 * 
 * @param
 */
Language::Language() {}

/**
 * @brief Obtenemos el set de cadenas a raiz de este
 * método.
 * 
 * @param
 * @return std::set<Chain> 
 */
std::set<Chain> Language::GetChains() const {
  return this->language_;
}

/**
 * @brief Sobrecarga del operador<< para poder mostrar
 * un lenguaje de manera correcta.
 * 
 * @param os 
 * @param language 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Language& language) {
  std::set<Chain>::iterator it = language.language_.begin();
  os << "{";
  // De esta manera conseguiremos no obtener; {1, 2, }
  // sino {1, 2}
  if (it != language.language_.end()) {
    os << *it;
    ++it;
  }
  while (it != language.language_.end()) {
    os << ", " << *it;
    ++it;
  }
  os << "}";
  return os;
}

/**
 * @brief Insertamos una cadena al lenguaje.
 * 
 * @param chain 
 */
void Language::Add(const Chain& chain) {
  this->language_.insert(chain);
}

/**
 * @brief Obtenemos el prefijo de una cadena.
 * 
 * @param aux (Cadena de la que vamos a sacar el prefijo)
 * @return Language 
 */
Language Language::Prefix(std::string aux) {
  Language Result;
  Chain Cadena(aux);
  std::vector<Symbol> chain;

  chain.push_back('&');
  Result.Add(chain); // Añadimos cadena vacia.
  chain.clear();

  chain.push_back(Cadena.GetSymbols()[0]);
  Result.Add(chain); // Añadimos primer simbolo de la cadena.

  for (int j = 1; j < Cadena.GetSymbolsLength(); ++j) {
    chain.push_back(Cadena.GetSymbols()[j]);
    Result.Add(chain);
  }
  return Result;
}


/**
 * @brief Obtenemos el sufijo de una cadena.
 * 
 * @param aux (Cadena de la que vamos a sacar el sufijo)
 * @return Language 
 */
Language Language::Sufix(std::string aux) {
  Language Result;
  Chain Inversa;
  std::vector<Symbol> chain, chain_aux;
  Inversa = Inversa.Inverse(aux);

  chain.push_back('&');
  Result.Add(chain); // Añadimos cadena vacia.
  chain.clear();

  chain.push_back(Inversa.GetSymbols()[0]);
  Result.Add(chain); // Añadimos el primer simbolo de la cadena.

  // Utilizamos un for para iterar entre los simbolos de la cadena
  // y otro for para alternar el resultado obtenido ((ba) -> (ab)).
  for (int i = 1; i < Inversa.GetSymbolsLength(); ++i) {
    chain.push_back(Inversa.GetSymbols()[i]);
    for (int j = chain.size() - 1; j >= 0; --j) {
      chain_aux.push_back(chain[j]);
    }
    Result.Add(chain_aux);
    chain_aux.clear();
  }
  return Result;
}