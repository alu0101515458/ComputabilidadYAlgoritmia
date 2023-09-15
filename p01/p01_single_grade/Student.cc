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
#include "Student.h"

void Student::UnicGrades(std::string palabra) {
  std::ifstream ifile(palabra);
  std::string aux;
  float aux2;
  std::map<std::string, float> smap;
  while(!ifile.eof()) {
    ifile >> aux;
    ifile >> aux2;
    std::pair<std::string, float> par;
    par.first = aux;
    par.second = aux2;
    if(smap.find(aux) == smap.end()) {
      smap.insert(par);
    } else {
      if(smap[aux] < aux2) {
        smap[aux] = aux2;
      }
    }
  }
  ifile.close();
  for(const auto& p: smap) {
    std::cout << p.first << " " << p.second << std::endl;
  }
  // GUARDARLO EN ARCHIVO
  // std::ofstream output_file{"resultados.txt"};
  // if(!output_file) {
  //   std::cout << "error" << std::endl;
  // }
  // for(const auto& p: smap) {
  //   output_file << p.first << " " << p.second << std::endl;
  // }
  // output_file.close();
}

