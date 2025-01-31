// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramáticas en Forma Normal de Chomsky.
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 30/10/2023
// Archivo Grammar.cc: Implementación de la clase Grammar.

// Historial de revisiones
// 24/10/2023 - Creacion (primera version) del codigo

#include "Grammar.h"

/**
 * @brief CONSTRUCTOR POR DEFECTO DE LA GRAMÁTICA.
 * 
 */
Grammar::Grammar() {
  alphabet_ = Alphabet();
  non_terminals_ = std::set<Symbol>();
  productions_ = std::multimap<Symbol, std::vector<Symbol>>();
}

/**
 * @brief GETTER QUE DEVUELVE EL ALFABETO DE LA GRAMÁTICA.
 * 
 * @return Alphabet 
 */
Alphabet Grammar::GetAlphabet() const {
  return alphabet_;
}

/**
 * @brief GETTER QUE DEVUELVE LOS SÍMBOLOS NO TERMINALES DE LA GRAMÁTICA.
 * 
 * @return std::set<Symbol> 
 */
std::set<Symbol> Grammar::GetSimbolsNonTerminal() const {
  return non_terminals_;
}

/**
 * @brief SETTER QUE ESTABLECE EL ALFABETO DE LA GRAMÁTICA.
 * 
 * @param alphabet 
 */
void Grammar::SetAlphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}

/**
 * @brief SETTER QUE ESTABLECE LOS SÍMBOLOS NO TERMINALES DE LA GRAMÁTICA.
 * 
 * @param non_terminals 
 */
void Grammar::SetSimbolsNonTerminal(std::set<Symbol> non_terminals) {
  non_terminals_ = non_terminals;
}

/**
 * @brief MÉTODO QUE DEVUELVE LAS PRODUCCIONES VACÍAS DE LA GRAMÁTICA.
 * 
 * @return std::multimap<Symbol, std::vector<Symbol>> 
 */
std::multimap<Symbol, std::vector<Symbol>> Grammar::FindEmptyProductions() {
  // MULTIMAP DE PRODUCCIONES VACÍAS.
  std::multimap<Symbol, std::vector<Symbol>> empty_productions;
  // PARA CADA PRODUCCIÓN DE LA GRAMÁTICA.
  for (auto production : productions_) {
    // SI LA CADENA DE LA PRODUCCIÓN TIENE TAMAÑO 0, AÑADIMOS LA PRODUCCIÓN AL MULTIMAP.
    if (production.second.size() == 0) {
      empty_productions.insert(production);
    }
  }
  return empty_productions;
}

/**
 * @brief MÉTODO QUE DEVUELVE LAS PRODUCCIONES UNITARIAS DE LA GRAMÁTICA.
 * 
 * @return std::multimap<Symbol, std::vector<Symbol>> 
 */
std::multimap<Symbol, std::vector<Symbol>> Grammar::FindUnitaryProductions() {
  // MULTIMAP DE PRODUCCIONES UNITARIAS.
  std::multimap<Symbol, std::vector<Symbol>> unitary_productions;
  // PARA CADA PRODUCCIÓN DE LA GRAMÁTICA.
  for (auto production : productions_) {
    // SI LA CADENA DE LA PRODUCCIÓN TIENE TAMAÑO 1 Y EL SÍMBOLO ES NO TERMINAL, AÑADIMOS LA PRODUCCIÓN AL MULTIMAP.
    if (production.second.size() == 1 && non_terminals_.find(production.second[0]) != non_terminals_.end()) {
      unitary_productions.insert(production);
    }
  }
  return unitary_productions;
}

/**
 * @brief MÉTODO QUE AÑADE UNA PRODUCCIÓN A LA GRAMÁTICA.
 * 
 * @param non_terminal 
 * @param chain 
 */
void Grammar::AddProduction(const Symbol& non_terminal, const std::vector<Symbol>& chain) {
  productions_.insert(std::pair<Symbol, std::vector<Symbol>>(non_terminal, chain));
}

/**
 * @brief MÉTODO QUE DEVUELVE LA GRAMÁTICA EN FORMA NORMAL DE CHOMSKY.
 * 
 * @return Grammar 
 */
Grammar Grammar::CFGtoFNC() const {
  Grammar grammar(*this);
  // UTILIZAREMOS UN CHAR PARA CREAR LOS SÍMBOLOS AUXILIARES.
  char c = 'A';
  // CON MAPA_AUX_1 VERIFICAMOS SI EXISTE UN SÍMBOLO Y NO HAY NECESIDAD DE CREAR MÁS QUE GENEREN EL MISMO SÍMBOLO.
  std::map<Symbol, Symbol> mapa_aux_1;
  // PARA CADA PRODUCCIÓN DE LA GRAMÁTICA CON NÚMERO DE SÍMBOLOS MAYOR IGUAL QUE 2
  for (auto& production: grammar.productions_) {
    if (production.second.size() >= 2) {
      // PARA CADA SÍMBOLO DE LA CADENA DE LA PRODUCCIÓN
      for (unsigned int i = 0; i < production.second.size(); ++i) {
        // SI EL SÍMBOLO ES TERMINAL
        if (grammar.alphabet_.FindSymbol(production.second[i])) {
          // SI NO EXISTE UN SÍMBOLO AUXILIAR QUE LO GENERE, LO CREAMOS.
          if (mapa_aux_1.find(production.second[i]) == mapa_aux_1.end()) {
            // BUSCAMOS UN SÍMBOLO AUXILIAR QUE NO ESTÉ EN LA GRAMÁTICA.
            while (grammar.non_terminals_.find(Symbol(c)) != grammar.non_terminals_.end()) {
              ++c;
            }
            // AÑADIMOS EL SÍMBOLO AUXILIAR A LA GRAMÁTICA.
            grammar.non_terminals_.insert(Symbol(c));
            // AÑADIMOS EL SÍMBOLO AUXILIAR AL MAPA AUXILIAR PARA COMPROBACIONES POSTERIORES.
            mapa_aux_1.insert(std::pair<Symbol, Symbol>(production.second[i], Symbol(c)));
            // AÑADIMOS LA PRODUCCIÓN DEL SÍMBOLO AUXILIAR A LA GRAMÁTICA.
            grammar.productions_.insert(std::pair<Symbol, std::vector<Symbol>>(mapa_aux_1[production.second[i]], std::vector<Symbol>(1, production.second[i])));
          }
          // SUSTITUIMOS EL SÍMBOLO TERMINAL POR EL SÍMBOLO AUXILIAR.
          production.second[i] = mapa_aux_1[production.second[i]];
        }
      }
    }
  }
  // MAPA_AUX_2 SIMILAR A MAPA_AUX_1 PERO SU CLAVE SERÁ UN VECTOR DE SÍMBOLOS PARA ASEGURARNOS QUE TIENE UN SIMBOLO AUXILIAR QUE LO GENERE.
  std::map<std::vector<Symbol>, Symbol> mapa_aux_2;
  // PARA CADA PRODUCCIÓN DE LA GRAMÁTICA CON NÚMERO DE SÍMBOLOS MAYOR IGUAL QUE 3
  for (auto& production: grammar.productions_) {
    if (production.second.size() >= 3) {
      // MIENTRAS LA CADENA DE LA PRODUCCIÓN TENGA MÁS DE 2 SÍMBOLOS
      while (production.second.size() > 2) {
        // VECTOR DE SÍMBOLOS QUE CONTIENE LOS DOS ÚLTIMOS SÍMBOLOS DE LA CADENA DE LA PRODUCCIÓN.
        std::vector<Symbol> chain;
        chain.push_back(production.second[production.second.size() - 2]);
        chain.push_back(production.second[production.second.size() - 1]);
        // ELIMINAMOS LOS DOS ÚLTIMOS SÍMBOLOS DE LA CADENA DE LA PRODUCCIÓN.
        production.second.pop_back();
        production.second.pop_back();
        // SI NO EXISTE LA CADENA DE SÍMBOLOS EN EL MAPA AUXILIAR.
        if (mapa_aux_2.find(chain) == mapa_aux_2.end()) {
          // MIENTRAS EL SÍMBOLO AUXILIAR EXISTA EN LA GRAMÁTICA, BUSCAMOS OTRO.
          while (grammar.non_terminals_.find(Symbol(c)) != grammar.non_terminals_.end()) {
            ++c;
          }
          // AÑADIMOS EL SÍMBOLO AUXILIAR NO TERMINAL A LA GRAMÁTICA.
          grammar.non_terminals_.insert(Symbol(c));
          // AÑADIMOS EL SÍMBOLO AUXILIAR AL MAPA AUXILIAR JUNTO CON LA CADENA DE SÍMBOLOS.
          mapa_aux_2.insert(std::pair<std::vector<Symbol>, Symbol>(std::vector<Symbol>(chain), Symbol(c)));
          // AÑADIMOS LA PRODUCCIÓN DEL SÍMBOLO AUXILIAR A LA GRAMÁTICA.
          grammar.productions_.insert(std::pair<Symbol, std::vector<Symbol>>(mapa_aux_2[chain], chain));
        }
        // SI EXISTE LA CADENA DE SÍMBOLOS EN EL MAPA AUXILIAR, SUSTITUIMOS LA CADENA DE SÍMBOLOS POR EL SÍMBOLO AUXILIAR.
        production.second.push_back(mapa_aux_2[chain]);
      }
    }
  }
  return grammar;
}

/**
 * @brief SOBRERACARGA DEL OPERADOR << PARA LA GRAMÁTICA.
 * 
 * @param os 
 * @param grammar 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Grammar& grammar) {
  // IMPRIMIMOS LA LONGITUD DEL ALFABETO.
  os << grammar.alphabet_.GetSymbols().size() << std::endl;
  // IMPRIMIMOS LOS SÍMBOLOS DEL ALFABETO.
  for (auto symbol : grammar.alphabet_.GetSymbols()) {
    os << symbol << std::endl;
  }
  // IMPRIMIMOS LA LONGITUD DE LOS SÍMBOLOS NO TERMINALES.
  os << grammar.non_terminals_.size() << std::endl;
  // IMPRIMIMOS LOS SÍMBOLOS NO TERMINALES.
  for (auto non_terminal : grammar.non_terminals_) {
    os << non_terminal << std::endl;
  }
  // IMPRIMIMOS LA LONGITUD DE LAS PRODUCCIONES.
  os << grammar.productions_.size() << std::endl;
  // IMPRIMIMOS LAS PRODUCCIONES.
  for (auto production : grammar.productions_) {
    os << production.first << " ";
    for (auto symbol : production.second) {
      os << symbol;
    }
    os << std::endl;
  }
  return os;
}