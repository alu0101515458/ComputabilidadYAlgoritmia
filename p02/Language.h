#include "Chain.h"

#pragma once

class Language {
  public:
    Language();
    friend std::ostream& operator<<(std::ostream& os, const Language& language);
    friend bool operator<(const Language& first_language, const Language& second_language);
    std::set<Chain> GetChains() const;

    void Add(const Chain& chain);
    void Prefix(std::string input_file, std::string output_file);
    void Sufix(std::string input_file, std::string output_file);
  private:
    std::set<Chain> language_;
    Alphabet alphabet_;
};

std::ostream& operator<<(std::ostream& os, const Language& language);
bool operator<(const Language& first_language, const Language& second_language);