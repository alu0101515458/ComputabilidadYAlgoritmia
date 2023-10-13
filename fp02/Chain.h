// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Francisco Raúl Fernández Gómez
// Correo: alu0101427324@ull.edu.es
// Fecha: 26/09/2023
// Archivo Chain.h:
// 21/09/2023 - Creacion (primera version) del codigo 
// 22/09/2023 - Solucionando bugs 
// 23-25/09/23 - Solucionando bugs 
// 26/09/23 - Ultima versión del programa y comentarios 

#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include "Alphabet.h"


/**
 * @brief Clase cadena heredera de Alphabet
 * 
 */
class Chain : public Alphabet {
  public:
    /// Constructors
    Chain() = default;
    Chain(const std::vector<char>& chain) : Alphabet(chain), chain_(chain) {} 
    Chain(const std::string& chain); 
    
    /// Member Functions  
    int Size() const {return chain_.size();}
    Chain Backward() const;

    /// Getters & Setters 
    std::vector<char> GetChain() const {return chain_;}
    void SetChain(const std::vector<char>& new_chain) {chain_ = new_chain;}
    void AddSymbolBack(char symbol) {chain_.push_back(symbol);}
    void AddSymbolFront(char symbol) {chain_.insert(chain_.begin(), symbol);}
    Chain Concatenation(const Chain& new_chain);

    /// Operators
    friend std::ostream& operator<<(std::ostream& os, const Chain& string);
    friend std::istream& operator>>(std::istream& is, Chain& string);
    friend bool operator<(const Chain& string_1, const Chain& string_2); 

  private:
    std::vector<char> chain_;
};

std::ostream& operator<<(std::ostream& os, const Chain& string);
std::istream& operator>>(std::istream& in, Chain& string);
bool operator<(const Chain& string_1, const Chain& string_2);

#endif