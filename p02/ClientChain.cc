// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 2: Operaciones con cadenas
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 19/09/2023
// Archivo ClientChain.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las clases Alphabet, Symbol,
// Chain y Language para: obtener alfabétos, longitudes de cadenas,
// inversas de cadenas, prefijos de cadenas y sufijos de cadenas.

// Historial de revisiones
// 19/09/2023 - Creacion (primera version) del codigo

#include "Language.h"
#include "Tools.h"

/**
 * @brief Funcion principal donde se desarrolla
 * el programa.
 * 
 * @param argc 
 * @param argv 
 * @return int
 */
int main(int argc, char* argv[]) {
  // Si el conteo de parametros no es el indicado, llamamos a la funcion Usage.
  if (argc != 4) {
    Tools::Usage(argc, argv);
  }
  // Conversion de parametros a variables.
  std::ifstream ifile{argv[1]};
  std::ofstream ofile{argv[2]};
  int opcode = std::stoi(argv[3]);
  std::string aux; // Auxiliar que servirá de receptor de cadenas del fichero de entrada.
  switch (opcode)
  {
  case 1: // Longitud de cadena/s.
    {
      while (ifile >> aux) {
        Chain Cadena(aux);
        int result;
        result = Cadena.Length(Cadena);
        ofile << result << std::endl;
      }
      break;
    }
  case 2: // Alfabeto de cadena/s.
    {
      while(ifile >> aux) {
        Chain Cadena;
        Alphabet Alfabeto;
        Alfabeto = Cadena.GetAlphabet(aux);
        ofile << Alfabeto << std::endl;
      }
      break;
    }
  case 3: // Inversa de cadenas/s.
    {
      while(ifile >> aux) {
        Chain Cadena;
        Cadena = Cadena.Inverse(aux);
        ofile << Cadena << std::endl;
      }
      break;
    }
  case 4: // Prefijo de cadena/s.
    {
      while (ifile >> aux) {
        Language Lenguaje;
        Lenguaje = Lenguaje.Prefix(aux);
        ofile << Lenguaje << std::endl;
      }
      break;
      
    }
  case 5: // Sufijo de cadena/s.
    {
      while (ifile >> aux) {
        Language Lenguaje;
        Lenguaje = Lenguaje.Suffix(aux);
        ofile << Lenguaje << std::endl;
      }
      break;
    }
  default: // Error en opcode.
    std::cout << "OPCODE NO VALIDO" << std::endl;
    break;
  }
  return 0;
}