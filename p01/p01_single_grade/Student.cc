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

void NuevaNota(std::map<std::string, float> smap) {
  std::string afirmacion;
  std::cout << "Le gustaría insertar alguna nueva nota de otro alumno?: " << std::endl;
  std::cout << "1. si" << std::endl; 
  std::cout << "2. no" << std::endl; 
  std::cout << "Respuesta: "; 
  std::cin >> afirmacion;
  if(afirmacion == "si") {
    while(afirmacion != "no") {
      std::string nuevo_alumno;
      float nueva_nota;
      std::cout << "Ingrese al alumno: ";
      std::cin >> nuevo_alumno;
      std::cout << "Ingrese la nota: ";
      std::cin >> nueva_nota;
      std::pair<std::string, float> par;
      par.first = nuevo_alumno;
      par.second = nueva_nota;
      if(smap.find(nuevo_alumno) == smap.end()) {
        smap.insert(par);
      } else {
        if(smap[nuevo_alumno] < nueva_nota) {
          smap[nuevo_alumno] = nueva_nota;
        }
      }
      std::cout << "\n";
      std::cout << "Nuevas Notas" << std::endl;
      for(const auto& p: smap) std::cout << p.first << " " << p.second << std::endl;
      std::cout << "Desea insertar otra nota de otro alumno?: ";
      std::cin >> afirmacion;
    }
  }
}

// void GuardarArchivo(std::map<std::string, float> smap) {
//   // GUARDARLO EN ARCHIVO
//   std::ofstream output_file{"resultados.txt"};
//   if(!output_file) {
//    std::cout << "error" << std::endl;
//   }
//   for(const auto& p: smap) output_file << p.first << " " << p.second << std::endl;
//   output_file.close();
// }

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
  for(const auto& p: smap) std::cout << p.first << " " << p.second << std::endl;
  NuevaNota(smap);
  // GuardarArchivo(smap);
}