// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Algoritmo de construcción de subconjuntos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 24/10/2023
// Archivo Tools.h: Namespace Tools.

// Historial de revisiones
// 1/10/2023 - Creacion (primera version) del codigo

#pragma once

#include "Alphabet.h"
#include "Symbol.h"
#include "State.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

/**
 * @brief Namespace que tiene una funcion de uso. 
 * Utilizacion de namespace para ahorrar memoria creando objetos.
 * 
 */
namespace Tools {
    void Usage(int argc, char* argv[]);
    void ExistsSymbol(const Symbol& symbol, const Alphabet& alphabet);
}