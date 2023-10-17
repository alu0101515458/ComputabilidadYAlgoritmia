// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 5: Implementacion de un simulador de automatas finitos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 10/10/2023
// Archivo FA.cc: Implementacion de la clase FA.

// Historial de revisiones
// 10/10/2023 - Creacion (primera version) del codigo

#include "FA.h"

/**
 * @brief CONSTRUCTOR POR DEFECTO DE LA CLASE FA.
 * 
 */
FA::FA() {
  inicial_ = nullptr;
}

/**
 * @brief CONSTRUCTOR DE LA CLASE FA QUE RECIBE UN ALFABETO.
 * 
 * @param alfabeto 
 */
FA::FA(Alphabet alfabeto) {
  alfabeto_ = alfabeto;
  inicial_ = nullptr;
}

/**
 * @brief CONSTRUCTOR DE LA CLASE FA QUE RECIBE UN ALFABETO, UN CONJUNTO DE ESTADOS Y UN ESTADO INICIAL.
 * 
 * @param alfabeto 
 * @param estados 
 * @param inicial 
 */
FA::FA(Alphabet alfabeto, std::set<State*> estados, State* inicial) {
  alfabeto_ = alfabeto;
  estados_ = estados;
  inicial_ = inicial;
}

/**
 * @brief METODO GETTER QUE DEVUELVE EL ALFABETO DEL AUTOMATA FINITO.
 * 
 * @return Alphabet 
 */
Alphabet FA::GetAlphabet() const {
  return alfabeto_;
}

/**
 * @brief METODO SETTER QUE ESTABLECE EL ESTADO INICIAL DEL AUTOMATA FINITO.
 * COMPROBANDO QUE EXISTE Y ES VALIDO.
 * 
 * @param estado 
 */
void FA::SetInitialState(State* estado) {
  inicial_ = estado;

  // COMPROBAMOS QUE EL ESTADO INICIAL PERTENECE AL CONJUNTO DE ESTADOS DEL AUTOMATA FINITO
  bool exist = false;
  for (auto it = estados_.begin(); it != estados_.end(); ++it) {
    // SI EL ESTADO INICIAL PERTENECE AL CONJUNTO DE ESTADOS, ASEGURAMOS QUE EL ESTADO EXISTE Y ES VALIDO.
    if ((*it)->GetIdentifier() == inicial_->GetIdentifier()) {
      exist = true;
    }
  }
  if (!exist) {
    std::cout << "El estado inicial " << inicial_->GetIdentifier() << " no pertenece al conjunto de estados del automata finito." << std::endl;
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief METODO RECURSIVO QUE RECORRE EL AUTOMATA FINITO PARA COMPROBAR 
 * SI LA CADENA ES ACEPTADA O NO.
 * 
 * @param estado 
 * @param cadena 
 * @param pos 
 * @return true 
 * @return false 
 */
bool FA::Simulate_(const State* estado, const Chain& cadena, int pos) {
  // SI LLEGAMOS AL FINAL DE LA CADENA, COMPROBAMOS SI HAY TRANSICIONES VACIAS.
  if (pos == cadena.GetSymbolsLength()) {
    // SI HAY TRANSICIONES VACIAS.
    if (!estado->FindEmptyTransitions().empty()) {
      // COMPROBAMOS PARA CADA TRANSICION VACÍA SI EL ESTADO AL QUE LLEVA ES ACEPTADO.
      for (unsigned int i = 0; i < estado->FindEmptyTransitions().size(); ++i) {
        // LLAMAMOS RECURSIVAMENTE A LA FUNCION PARA COMPROBAR EL VECTOR DE TRANSICIONES (VACIAS) DEL ESTADO.
        if (Simulate_(estado->FindEmptyTransitions()[i], cadena, pos)) {
          return true;
        }
      }
    }
    // SI NO HAY TRANSICIONES VACIAS, COMPROBAMOS SI EL ESTADO ACTUAL ES ACEPTADO (ES EL ESTADO FINAL PARA LA CADENA).
    return estado->IsAccepted();
  }

  // SI NO HEMOS LLEGADO AL FINAL DE LA CADENA, COMPROBAMOS SI EN EL ESTADO ACTUAL HAY TRANSICIONES DE SIMBOLO O VACIAS.
  if (!estado->FindSymbolTransitions(cadena.GetSymbols()[pos]).empty()
    || !estado->FindEmptyTransitions().empty()) {
    // COMPROBAMOS PARA CADA TRANSICION VACÍA SI EL ESTADO AL QUE LLEVA ES ACEPTADO.
    for (unsigned int i = 0; i < estado->FindEmptyTransitions().size(); ++i) {
      // LLAMAMOS RECURSIVAMENTE A LA FUNCION PARA COMPROBAR EL VECTOR DE TRANSICIONES VACIAS DEL ESTADO.
      if (Simulate_(estado->FindEmptyTransitions()[i], cadena, pos)) {
        return true;
      }
    }
    // COMPROBAMOS PARA CADA TRANSICION DEL SIMBOLO DEL ESTADO ACTUAL SI EL ESTADO AL QUE LLEVA ES ACEPTADO.
    for (unsigned int i = 0; i < estado->FindSymbolTransitions(cadena.GetSymbols()[pos]).size(); ++i) {
      // LLAMAMOS RECURSIVAMENTE A LA FUNCION PARA COMPROBAR EL VECTOR DE TRANSICIONES DEL ESTADO CON POS+1.
      if (Simulate_(estado->FindSymbolTransitions(cadena.GetSymbols()[pos])[i], cadena, pos+1)) {
        return true;
      }
    }
  }

  // SI NO SE CUMPLE NINGUNA DE LAS CONDICIONES ANTERIORES, LA CADENA NO ES ACEPTADA.
  return false;
}

/**
 * @brief METODO PARA INSERTAR UN ESTADO EN EL CONJUNTO DE ESTADOS DEL AUTOMATA FINITO.
 * 
 * @param estado 
 */
void FA::Add(State* estado) {
  estados_.insert(estado);
}

/**
 * @brief METODO QUE RECOGE UNA CADENA Y COMPRUEBA SI EL AUTOMATA FINITO LA ACEPTA O NO
 * MEDIANTE OTRA FUNCION RECURSIVA QUE RECORRE EL AUTOMATA FINITO.
 * 
 * @param cadena 
 * @return true 
 * @return false 
 */
bool FA::Simulate(const Chain& cadena) {
  int pos = 0;
  return Simulate_(this->inicial_, cadena, pos);
}