#include "Alphabet.h"

Alphabet::Alphabet() {}

Alphabet::Alphabet(const std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
}


std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  std::set<Symbol>::iterator it = alphabet.alphabet_.begin();
  os << "{";
  if (it != alphabet.alphabet_.end()) {
    os << *it;
    ++it;
  }
  while (it != alphabet.alphabet_.end()) {
    os << ", " << *it;
    ++it;
  }
  os << "}";
  return os;
}
std::set<Symbol> Alphabet::GetSymbols() const {
  return this->alphabet_;
}

void Alphabet::Add(const Symbol& symbol) {
  alphabet_.insert(symbol);
}

Alphabet Alphabet::NewAlphabet(Alphabet alphabet) const {
  Alphabet new_alphabet;
  for (const Symbol& symbol: alphabet.GetSymbols()) {
    new_alphabet.Add(symbol);
  }
  return new_alphabet;
}