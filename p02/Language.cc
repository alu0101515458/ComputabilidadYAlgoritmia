#include "Language.h"

Language::Language() {}

std::set<Chain> Language::GetChains() const {
  return this->language_;
}

bool operator<(const Language& first_language, const Language& second_language) {
  
}

std::ostream& operator<<(std::ostream& os, const Language& language) {
  std::set<Chain>::iterator it = language.language_.begin();
  os << "{";
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

void Language::Add(const Chain& chain) {
  this->language_.insert(chain);
}

// {& , a , ab , abb , abba , abbab }
// {& , 6 , 67 , 679 , 6793 , 67938 , 679383 , 6793836}
// {& , h , ho , hol , hola }
void Language::Prefix(std::string input_file, std::string output_file) {
  std::ifstream ifile(input_file);
  std::ofstream ofile(output_file);
  std::string aux;

  while (ifile >> aux) { // Utilizar una lectura segura
    Language Result;
    Result.Add({{'&'}});
    std::vector<Symbol> chain;
    chain.push_back(aux[0]);
    Result.Add(chain);
    for(unsigned int j = 1; j < aux.length(); ++j) {
      chain.push_back(aux[j]);
      Result.Add(chain);
    }
    ofile << Result << std::endl;
  }
  ifile.close();
  ofile.close();
}

// {& , b , ab , bab , bbab , abbab }
// {& , 6 , 36 , 836 , 3836 , 93836 , 793836 , 6793836}
// {& , a , la , ola , hola }
void Language::Sufix(std::string input_file, std::string output_file) {
  std::ifstream ifile(input_file);
  std::ofstream ofile(output_file);
  std::string aux;

  while (ifile >> aux) { // Utilizar una lectura segura
    Language Result;
    Result.Add({{'&'}});
    std::vector<Symbol> chain, chain_aux;
    chain.push_back(aux[aux.size()-1]); // b
    Result.Add(chain);
    for(int i = aux.size() - 2; i >= 0; --i) {
      chain.push_back(aux[i]); // ba, bab, babb, babba
      for(int j = chain.size() - 1; j >= 0; --j) {
        chain_aux.push_back(chain[j]); // ab, bab, bbab, abbab
      }
      Result.Add(chain_aux);
      chain_aux.clear();
    }
    ofile << Result << std::endl;
  }
  ifile.close();
  ofile.close();
}