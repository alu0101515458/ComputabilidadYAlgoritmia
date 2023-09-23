#include "Symbol.h"

Symbol::Symbol() {}

Symbol::Symbol(const char& symbol) { 
  char_ = symbol;  
}

char Symbol::GetSymbol() const {
  return this->char_;
}

std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.char_;
  return os;
}

bool operator==(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() == second_symbol.GetSymbol()) ? true : false;
}

bool operator<(const Symbol& first_symbol, const Symbol& second_symbol) {
  return (first_symbol.GetSymbol() < second_symbol.GetSymbol()) ? true : false;
}