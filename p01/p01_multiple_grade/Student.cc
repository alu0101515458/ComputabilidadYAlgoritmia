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
#include "Student.h"

void Student::MultiGrades(std::string palabra) {
  std::ifstream ifile(palabra);
  std::string aux;
  float aux2;
  std::multimap<std::string, float> smap;
  while(!ifile.eof()) {
    ifile >> aux;
    ifile >> aux2;
    std::pair<std::string, float> par;
    par.first = aux;
    par.second = aux2;
    smap.insert(par);
  }
  ifile.close();
  std::string clave = "";
  for(const auto& p: smap) {
    if(clave == p.first) {
      std::cout << p.second << " ";
    } else {
      std::cout << "\n" << p.first << ": " << p.second << " ";
      clave = p.first;
    }
  }
  // GUARDARLO EN ARCHIVO
  // std::ofstream output_file{"resultados.txt"};
  // for(const auto& p: smap) {
  //   if(clave == p.first) {
  //     output_file << p.second << " ";
  //   } else {
  //     output_file << "\n" << p.first << ": " << p.second << " ";
  //     clave = p.first;
  //   }
  // }
  // output_file.close();
  std::cout << std::endl;
}