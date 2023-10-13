// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Francisco Raúl Fernández Gómez
// Correo: alu0101427324@ull.edu.es
// Fecha: 26/09/2023
// Archivo ClienteStrings.cc: programa cliente.
// El programa recibe por parametros un fichero de entrada, otro de salida y un opcode. Realiza distintas operaciones con cadenas
// más alta. Historial de revisiones 
// 21/09/2023 - Creacion (primera version) del codigo 
// 22/09/2023 - Solucionando bugs 
// 23-25/09/23 - Solucionando bugs 
// 26/09/23 - Ultima versión del programa y comentarios 

#include "Alphabet.h"
#include "Chain.h"
#include "Language.h"
#include <fstream>

/**
 * @brief Lee las cadenas del fichero de lectura
 * 
 * @param filename 
 * @return Language 
 */
Language ReadFile(const std::string& filename) {
  std::ifstream file(filename);
  Chain readed_string;
  Language readed_language;
  while(file >> readed_string) {
    std::cout << readed_string << std::endl;
    readed_language.Insert(readed_string);
  }
  file.close();
  return readed_language;
}

/**
 * @brief Asegura una correcta ejecucion por parte del usuario
 * 
 * @param argc 
 * @param argv 
 */
void Usage(int argc, char* argv[]) {
  if (argc != 4 && argc != 2) {
    std::cerr << "Numero de argumentos incorrecto" << std::endl;
    std::cerr << "Pruebe './p02_strings --help' para mas informacion" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (std::string(argv[1]) == "--help") {
    std::cout << "Este programa se encarga de realizar diversas operaciones con cadenas de un fichero, dependiendo del opcode, e imprimir el resultado en un fichero." << std::endl;
    std::cout << "\n\t ./p02_strings filein.txt fileout.txt opcode\n" << std::endl;
    std::cout << "El formato del fichero de entrada debe ser el siguiente: \n"
              << "cadena_1\ncadena_2\n...\ncadena_n" << std::endl;
    std::cout << "\nOPCODES:\n"
              << "1. Alfabetos -> Imprime los alfabetos de las cadenas.\n"
              << "2. Longitud -> Imprime el tamaño de las cadenas.\n"
              << "3. Inversa -> Imprime las cadenas a la inversa.\n"
              << "4. Prefijos -> Imprime todos los prefijos que forman las cadenas.\n"
              << "5. Sufijos -> Imprime todos los sufijos que forman las cadenas."
              << std::endl;
    exit(EXIT_SUCCESS);
  } else if (argc != 4){
    std::cerr << "Numero de argumentos incorrecto" << std::endl;
    std::cerr << "Pruebe './p02_strings --help' para mas informacion" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream filein;
  int opcode(std::stoi(argv[3]));
  filein.open(argv[1]);
  Language file_strings(filein);
  std::cout << file_strings << std::endl;
  std::ofstream fileout(argv[2]);
  switch (opcode) {
    case 1: /// Alfabeto
      for (auto& it : file_strings.GetterChains())  {
        fileout << it.GetAlphabet() << std::endl;
      }
      break;
    case 2: /// Longitud
      for (auto& it : file_strings.GetterChains()) {
        fileout << it.Size() << std::endl;
      } 
      break;
    case 3: /// Inversa
      for (auto& it : file_strings.GetterChains()) {
        fileout << it.Backward() << std::endl;
      }
      break;
    case 4: /// Prefijos
      for (auto& it : file_strings.GetterChains()) {
        fileout << file_strings.Preffix(it);
        fileout << std::endl;
      }
      break;
    case 5: /// Sufijos
      for (auto& it : file_strings.GetterChains()) {
        fileout << file_strings.Suffix(it);
        fileout << std::endl;
      }
      break;
//    case 6:  /// Concatenacion
//      std::ifstream concatenation_file(argv[4]);
//      Language concatenation_strings(concatenation_file);
//      for (auto& it_string = file_strings.GetterChains().begin(),) {
//        
//      }
      

//     break;
    default:
      std::cerr << "Opcode Incorrecto!" << std::endl;
      break;
  }
  fileout.close();
  return 0;
}