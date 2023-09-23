#pragma once

#include<set>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

class Symbol {
  public:
    Symbol();
    Symbol(const char& symbol);

    friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol);
    friend bool operator==(const Symbol& first_symbol, const Symbol& second_symbol);
    friend bool operator<(const Symbol& first_symbol, const Symbol& second_symbol);
    char GetSymbol() const;

  private:
    char char_;
};

std::ostream& operator<<(std::ostream& os, const Symbol& symbol);
bool operator==(const Symbol& first_symbol, const Symbol& second_symbol);
bool operator<(const Symbol& first_symbol, const Symbol& second_symbol);