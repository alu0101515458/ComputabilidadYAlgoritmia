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
// para: que dado un fichero de entrada con la especificacion de las
// calificaciones, almacene los valores correspondientes y los muestre por pantalla de forma
// ordenada en funcion del alu.


// Referencias:
// Enlaces de interes

// Historial de revisiones
// 12/09/2023 - Creacion (primera version) del codigo
#include <iostream>
#include "Student.h"

int main(int argc, char* argv[]) {
  if(argc != 2) {
    std::cout << "Modo de empleo: ./p01_single_grades grades.txt" << std::endl;
    std::cout << "Pruebe ’p01_single_grades --help’ para mas informacion." << std::endl;
    return 0;
  }
  std::string palabra = argv[1];
  if(argc == 2 && palabra == "--help") {
    std::cout << "La entrada que debería recibir es: ./p01_single_grades y un fichero de texto donde se almacenen las notas." << std::endl;
    return 0;
  }
  Student Estudiante;
  Estudiante.UnicGrades(palabra);
  return 0;
}