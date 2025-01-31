// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo Tools.h: Namespace Tools.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#pragma once

#include <iostream>

/**
 * @brief NAMESPACE QUE CONTIENE UN METODO PARA MOSTRAR
 * LA FORMA CORRECTA DE USAR EL PROGRAMA.
 * UTILIZADO EN EL MAIN.
 * UTILIZAMOS NAMESPACE PARA NO TENER QUE CREAR UNA CLASE
 * Y AHORRAR MEMORIA.
 * 
 */
namespace Tools {
    void Usage(int argc, char* argv[]);
}