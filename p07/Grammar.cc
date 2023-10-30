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
  std::multimap<Symbol, std::vector<Symbol>> empty_productions;
  for (auto production : productions_) {
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
  std::multimap<Symbol, std::vector<Symbol>> unitary_productions;
  for (auto production : productions_) {
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
  char c = 'A';
  // CON MAPA_AUX VERIFICAMOS QUE EXISTE UN SÍMBOLO Y NO HAY NECESIDAD DE CREAR MÁS QUE GENEREN EL MISMO SÍMBOLO.
  std::map<Symbol, Symbol> mapa_aux_1;
  // PARA CADA PRODUCCIÓN DE LA GRAMÁTICA CON NÚMERO DE SÍMBOLOS MAYOR IGUAL QUE 2
  for (auto& production: grammar.productions_) {
    if (production.second.size() >= 2) {
      for (unsigned int i = 0; i < production.second.size(); ++i) {
        // SI EL SÍMBOLO ES TERMINAL
        if (grammar.alphabet_.FindSymbol(production.second[i])) {
          if (mapa_aux_1.find(production.second[i]) == mapa_aux_1.end()) {
            while (grammar.non_terminals_.find(Symbol(c)) != grammar.non_terminals_.end()) {
              ++c;
            }
            grammar.non_terminals_.insert(Symbol(c));
            mapa_aux_1.insert(std::pair<Symbol, Symbol>(production.second[i], Symbol(c)));
            grammar.productions_.insert(std::pair<Symbol, std::vector<Symbol>>(mapa_aux_1[production.second[i]], std::vector<Symbol>(1, production.second[i])));
          }
          production.second[i] = mapa_aux_1[production.second[i]];
        }
      }
    }
  }
  std::map<std::vector<Symbol>, Symbol> mapa_aux_2;
  for (auto& production: grammar.productions_) {
    if (production.second.size() >= 3) {
      while (production.second.size() > 2) {
        std::vector<Symbol> chain;
        chain.push_back(production.second[production.second.size() - 2]);
        chain.push_back(production.second[production.second.size() - 1]);
        production.second.pop_back();
        production.second.pop_back();
        if (mapa_aux_2.find(chain) == mapa_aux_2.end()) {
          while (grammar.non_terminals_.find(Symbol(c)) != grammar.non_terminals_.end()) {
            ++c;
          }
          grammar.non_terminals_.insert(Symbol(c));
          mapa_aux_2.insert(std::pair<std::vector<Symbol>, Symbol>(std::vector<Symbol>(chain), Symbol(c)));
          grammar.productions_.insert(std::pair<Symbol, std::vector<Symbol>>(mapa_aux_2[chain], chain));
        }
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
  os << grammar.alphabet_.GetSymbols().size() << std::endl;
  for (auto symbol : grammar.alphabet_.GetSymbols()) {
    os << symbol << std::endl;
  }
  os << grammar.non_terminals_.size() << std::endl;
  for (auto non_terminal : grammar.non_terminals_) {
    os << non_terminal << std::endl;
  }
  os << grammar.productions_.size() << std::endl;
  for (auto production : grammar.productions_) {
    os << production.first << " ";
    for (auto symbol : production.second) {
      os << symbol;
    }
    os << std::endl;
  }
  return os;
}