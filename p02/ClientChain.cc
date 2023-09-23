// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 19/09/2023
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la funcion main del proyecto que usa la clase Strings
// para: 

// Referencias:
// Enlaces de interes

// Historial de revisiones
// 12/09/2023 - Creacion (primera version) del codigo
#include "Language.h"
#include "Tools.h"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    //Tools Herramienta;
    Tools::Usage(argc, argv);
  }
  std::string input_file{argv[1]};
  std::string output_file{argv[2]};
  int opcode = std::stoi(argv[3]);
  switch (opcode)
  {
  case 1:
    {
      Chain Cadena;
      Cadena.Length(input_file, output_file);
      break;
    }
  case 2:
    {
      Chain Cadena;
      Cadena.GetAlphabet(input_file, output_file);
      break;
    }
  case 3:
    {
      Chain Cadena;
      Cadena.Inverse(input_file, output_file);
      break;
    }
  case 4:
    {
      Language Lenguaje;
      Lenguaje.Prefix(input_file, output_file);
      break;
      
    }
  case 5:
    {
      Language Lenguaje;
      Lenguaje.Sufix(input_file, output_file);
      break;
    }
  default:
    std::cout << "OPCODE NO VALIDO" << std::endl;
    break;
  }
  return 0;
}