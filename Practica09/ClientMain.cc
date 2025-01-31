// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo ClientMain.cc: Implementación del main.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#include "Tools.h"
#include "TuringMachine.h"
#include <fstream>

int main(int argc, char* argv[]) {
  // SI EL NUMERO DE ARGUMENTOS ES DISTINTO DE 3, MOSTRAMOS EL USO CORRECTO DEL PROGRAMA Y SALIMOS.
  if (argc != 3) {
    Tools::Usage(argc, argv);
  }
  // ABRIMOS EL FICHERO DE LA MAQUINA DE TURING.
  TuringMachine turing_machine(argv[1]);
  // NOTIFICAMOS SI HAY UN ERROR AL CREAR LA MÁQUINA DE TURING.
  if (turing_machine.GetInitialState() == nullptr) {
    std::cout << "Error al crear la maquina de turing." << std::endl;
    return 0;
  }
  // LEEMOS LA CADENA DE LA CINTA.
  Chain chain;
  std::ifstream chain_file(argv[2]);
  chain_file >> chain;
  std::cout << "Cadena: " << chain << std::endl;
  // SIMULAMOS LA MAQUINA DE TURING.
  turing_machine.Simulate(chain);
  std::cout << "Cadena ACEPTADA" << std::endl;
  // CERRAMOS EL FICHERO DE ENTRADA DE LA CADENA.
  chain_file.close();
  return 0;
}