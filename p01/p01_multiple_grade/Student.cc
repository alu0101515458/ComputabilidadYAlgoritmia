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

void NuevaNota(std::multimap<std::string, float> smap) {
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
      smap.insert(par);
      std::cout << "\n";
      std::cout << "Nuevas Notas" << std::endl;
      std::string clave = "";
      for(const auto& p: smap) {
        if(clave == p.first) {
          std::cout << p.second << " ";
        } else {
          std::cout << "\n" << p.first << ": " << p.second << " ";
          clave = p.first;
        }
      }
      std::cout << "\n";
      std::cout << "Desea insertar otra nota de otro alumno?: ";
      std::cin >> afirmacion;
    }
  }
}

// void GuardarArchivo(std::multimap<std::string, float> smap) {
//  GUARDARLO EN ARCHIVO
//  std::ofstream output_file{"resultados.txt"};
//  std::string clave = "";
//  for(const auto& p: smap) {
//    if(clave == p.first) {
//      output_file << p.second << " ";
//    } else {
//      output_file << "\n" << p.first << ": " << p.second << " ";
//      clave = p.first;
//    }
//  }
//  output_file.close();
// }

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
  std::cout << std::endl;
  NuevaNota(smap);
  // GuardarArchivo(smap);
} // prueba