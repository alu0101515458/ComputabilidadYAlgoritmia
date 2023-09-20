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

// FUNCION PARA AÑADIR UN/UNOS NUEVO/S ALUMNO/S CON SU/S RESPECTIVA/S NOTA/S
void NuevaNota(std::multimap<std::string, float>& smap) {
  std::string afirmacion;
  std::cout << "Le gustaría insertar alguna nueva nota de otro alumno?: " << std::endl;
  std::cout << "1. si" << std::endl; 
  std::cout << "2. no" << std::endl; 
  std::cout << "Respuesta: "; 
  std::cin >> afirmacion;
  if(afirmacion == "si") {
    while(afirmacion != "no") {
      if(afirmacion == "si") {
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
      }
      std::cout << "\n";
      std::cout << "Desea insertar otra nota de otro alumno?: ";
      std::cin >> afirmacion;
    }
  }
}

/*
// FUNCION PARA GUARDAR EN ARCHIVO LOS RESULTADOS
void GuardarArchivo(std::multimap<std::string, float>& smap) {
 GUARDARLO EN ARCHIVO
 std::ofstream output_file{"resultados.txt"};
 std::string clave = "";
 for(const auto& p: smap) {
   if(clave == p.first) {
     output_file << p.second << " ";
   } else {
     output_file << "\n" << p.first << ": " << p.second << " ";
     clave = p.first;
   }
 }
 output_file.close();
}
*/

/*
// FUNCION PARA ELIMINAR A UN/UNOS USUARIO/S DE LA LISTA DE ALUMNOS
void EliminarAlumno(std::multimap<std::string, float>& smap) {
  std::string afirmacion, alumno;
  std::cout << "Desea eliminar a algun alumno?: " << std::endl;
  std::cout << "1. si" << std::endl;
  std::cout << "2. no" << std::endl;
  std::cout << "Respuesta: ";
  std::cin >> afirmacion;
  if(afirmacion == "si") {
    while(afirmacion != "no") {
      if(afirmacion == "si") {
        std::cout << "Teclee el alumno: ";
        std::cin >> alumno;
        smap.erase(alumno);
        std::cout << "\n";
        std::cout << "Nuevas Notas";
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
      }
      std::cout << "Desea eliminar a algun otro alumno?: ";
      std::cin >> afirmacion;
    }
  }
}
*/

/*
void MaxMin(std::multimap<std::string, float> smap) {
  float max = -1.f, min = 11.f;
  for(const auto& p: smap) {
    if(max < p.second) max = p.second;
    if(min > p.second) min = p.second;
  }
  std::cout << "Maximo: " << max << ", minimo: " << min << std::endl;
}
*/

void Media(std::multimap<std::string, float> smap) {
  float result = 0.f;
  int count = 0;
  for(const auto& p: smap) {
    result += p.second;
    ++count;
  }
  std::cout << "MEDIA: " << result/count << std::endl;
}

// FUNCION PRINCIPAL LA CUAL AGRUPA LAS NOTAS DE UN ALUMNO PARA POSTERIOR MOSTRAR POR PANTALLA
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
  std::cout << "\n\n";
  NuevaNota(smap);
  // GuardarArchivo(smap);
  // std::cout << "\n";
  // EliminarAlumno(smap);
  // MaxMin(smap);
  Media(smap);
}
