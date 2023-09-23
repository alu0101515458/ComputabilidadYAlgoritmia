#include "Symbol.h"
#include<iostream>
#pragma once

class Alphabet {
  public:
    Alphabet();
    Alphabet(const std::set<Symbol> alphabet);

    std::set<Symbol> GetSymbols() const;
    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

    void Add(const Symbol& symbol);
    Alphabet NewAlphabet(Alphabet new_alphabet) const;

  private:
    std::set<Symbol> alphabet_;
};

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);