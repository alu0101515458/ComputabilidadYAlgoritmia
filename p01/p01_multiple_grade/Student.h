// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 12/09/2023
// Archivo cya-P01-single-grades.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las clases X e Y
// para: que dado un fichero de entrada con la especificacion de las calificaciones,
// agrupe todos los valores correspondientes a un estudiante y los muestre por pantalla
// de forma ordenada en funcion del alu

// Referencias:
// Enlaces de interes

// Historial de revisiones
// 12/09/2023 - Creacion (primera version) del codigo
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Student {
  public:
    void MultiGrades(std::string palabra);
};