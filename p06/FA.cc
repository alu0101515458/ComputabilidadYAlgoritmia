// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Algoritmo de construcción de subconjuntos
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 24/10/2023
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
 * @brief CONSTRUCTOR DE LA CLASE FA QUE RECIBE UN CONJUNTO DE ESTADOS.
 * 
 * @param estados 
 */
FA::FA(std::set<State*> estados) {
  estados_ = estados;
}

/**
 * @brief DESTRUCTOR DE LA CLASE FA.
 * 
 */
FA::~FA() {
  for (State* st: estados_) {
    delete st;
  }
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
 * @brief GETTER QUE DEVUELVE EL NUMERO DE ESTADOS DEL AUTOMATA FINITO.
 * 
 * @return int 
 */
int FA::GetStatesNumber() const {
  return estados_.size();
}

/**
 * @brief GETTER QUE DEVUELVE EL ESTADO INICIAL DEL AUTOMATA FINITO.
 * 
 * @return std::string 
 */
std::string FA::GetInitialState() const {
  return inicial_->GetIdentifier();
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
 * @brief SETTER DEL ALFABETO
 * 
 * @param alfabeto 
 */
void FA::SetAlphabet(Alphabet alfabeto) {
  alfabeto_ = alfabeto;
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

/**
 * @brief METODO QUE DEVUELVE EL CONJUNTO DE ESTADOS AL QUE SE PUEDE MOVER
 * CON EPSILON
 * 
 * @param estados 
 * @return std::set<State*> 
 */
std::set<State*> FA::EpsilonClausura(std::set<State*> estados) const {
  // CREAMOS UN CONJUNTO DE ESTADOS PARA ALMACENAR LA CLAUSURA.
  std::set<State*> clausura;
  // CREAMOS UNA PILA PARA ALMACENAR LOS ESTADOS SIN PROCESAR.
  std::stack<State*> stack;
  // INSERTAMOS LOS ESTADOS EN LA PILA.
  for (State* state: estados) {
    stack.push(state);
  }
  // CLAUSURA SIEMPRE VA A CONTENER EL CONJUNTO Y SUS RESPECTIVAS TRANSICIONES VACIAS.
  clausura = estados;
  // MIENTRAS HAYA ESTADOS SIN PROCESAR.
  while (!stack.empty()) {
    // RECOGEMOS LOS ESTADOS DE LA PILA.
    State* state = stack.top();
    stack.pop();
    // PARA CADA ESTADO ALCANZABLE CON TRANSICION VACIA.
    for (State* aux: state->FindEmptyTransitions()) {
      // COMPROBAMOS QUE EL ESTADO NO ESTA EN LA CLAUSURA.
      if (clausura.find(aux) == clausura.end()) {
        // LO INSERTAMOS Y POSTERIORMENTE ANALIZAMOS.
        clausura.insert(aux);
        stack.push(aux);
      }
    }
  }
  return clausura;
}

/**
 * @brief METODO QUE DEVUELVE UN CONJUNTO DE ESTADOS 
 * AL QUE SE PUEDE MOVER EL CONJUNTO DE ESTADOS
 * CON UN SIMBOLO ESPECIFICO.
 * 
 * @param estados 
 * @param simbolo 
 * @return std::set<State*> 
 */
std::set<State*> FA::Move(std::set<State*> estados, Symbol simbolo) const {
  // SET DE ESTADOS PARA ALMACENAR LOS ESTADOS A LOS QUE SE PUEDE MOVER.
  std::set<State*> movimientos;
  // PARA CADA ESTADO DEL CONJUNTO DE ESTADOS.
  for (State* state: estados) {
    // PARA CADA ESTADO ALCANZABLE CON EL SIMBOLO.
    for (State* aux: state->FindSymbolTransitions(simbolo)) {
      // INSERTAMOS LOS ESTADOS QUE SON ALCANZABLES CON EL SIMBOLO.
      movimientos.insert(aux);
    }
  }
  return movimientos;
}

/**
 * @brief METODO QUE DEVUELVE LA CONVERSION DE NFA A 
 * DFA A TRAVES DE LA CONSTRUCCION DE SUBCONJUNTOS.
 * 
 * @return FA 
 */
FA FA::SubassemblyConstruction() const {
  // EPSILON-CLAUSURA DEL ESTADO INICIAL.
  std::set<State*> q0 = EpsilonClausura({inicial_});

  // std::cout << "e-clausura({" << inicial_->GetIdentifier() << "}) = {";
  // for (State* state: q0) {
  //   std::cout << state->GetIdentifier() << ", ";
  // }
  // std::cout << "}" << std::endl;

  // CONJUNTO DE ESTADOS DEL DFA.
  std::set<std::set<State*>> estadosDFA;
  // PILA PARA LOS ESTADOS SIN PROCESAR.
  std::stack<std::set<State*>> stack;
  stack.push(q0);
  // MAPA QUE RECOGE UN CONJUNTO DE ESTADOS Y LOS ESTADOS ALCANZABLES CON X SIMBOLO.
  std::map<std::set<State*>, std::map<Symbol, std::set<State*>>> transiciones;
  // CREAMOS UN ESTADO DE MUERTE Y EN EL CASO DE NECESITARLO, LO INSERTAMOS AL DFA.
  std::set<State*> estado_muerte;
  // EN EL MAP ESTARÁ EL ESTADO DE MUERTE CON TODOS LOS SIMBOLOS DEL ALFABETO HACIA SI MISMO.
  for (Symbol simbolo: alfabeto_.GetSymbols()) {
    transiciones[estado_muerte][simbolo] = estado_muerte;
  }
  // MIENTRAS HAYA ESTADOS SIN PROCESAR.
  while (!stack.empty()) {
    // RECOGEMOS EL CONJUNTO DE ESTADOS DE LA PILA.
    std::set<State*> estados = stack.top();
    stack.pop();
    // PARA CADA SIMBOLO DEL ALFABETO.
    for (Symbol simbolo: alfabeto_.GetSymbols()) {
      // RECOGEMOS EL CONJUNTO DE ESTADOS AL QUE SE PUEDE MOVER 
      // EL CONJUNTO DE ESTADOS DE LA PILA CON EL SIMBOLO X.
      std::set<State*> move_states = Move(estados, simbolo);

      // std::cout << "move({";
      // for (State* state: estados) {
      //   std::cout << state->GetIdentifier() << ", ";
      // }
      // std::cout << "}, " << simbolo << ") = {";
      // for (State* state: move_states) {
      //   std::cout << state->GetIdentifier() << ", ";
      // }
      // std::cout << "}" << std::endl;

      // ALMACENAMOS EN CONJUNTO_H LA EPSILON-CLAUSURA DEL CONJUNTO DE ESTADOS
      // AL QUE SE PUEDE TRANSITAR CON EL SIMBOLO.
      std::set<State*> conjunto_H = EpsilonClausura(move_states);

      // std::cout << "e-clausura({";
      // for (State* state: move_states) {
      //   std::cout << state->GetIdentifier() << ", ";
      // }
      // std::cout << "}) = {";
      // for (State* state: conjunto_H) {
      //   std::cout << state->GetIdentifier() << ", ";
      // }
      // std::cout << "}" << std::endl;

      // SI EL CONJUNTO DE ESTADOS NO ESTA EN EL DFA.
      if (estadosDFA.find(conjunto_H) == estadosDFA.end()) {

        // std::cout << "El conjunto H = {";
        // for (State* state: conjunto_H) {
        //   std::cout << state->GetIdentifier() << ", ";
        // }
        // std::cout << "} no esta en el conjunto de estados del DFA." << std::endl;
        // for (State* state: move_states) {
        //   std::cout << state->GetIdentifier() << ", ";
        // }

        // INSERTAMOS EL CONJUNTO DE ESTADOS EN EL DFA.
        estadosDFA.insert(conjunto_H);
        // AÑADIMOS EL CONJUNTO DE ESTADOS A LA PILA PARA PROCESAR SUS TRANSICIONES POSTERIORMENTE.
        stack.push(conjunto_H);
      }
      if (!conjunto_H.empty()) {
        // GUARDAMOS EL CONJUNTO_H EN EL MAPA DE TRANSICIONES.
        transiciones[estados][simbolo] = conjunto_H;
      } else {
        // SI EL CONJUNTO_H ESTA VACIO, LO RELACIONAMOS CON EL ESTADO DE MUERTE.
        // INSERTAMOS EL ESTADO DE MUERTE EN EL DFA.
        transiciones[estados][simbolo] = estado_muerte;
        if (estadosDFA.find(estado_muerte) == estadosDFA.end()) {
          estado_muerte = {new State("Z", false)};
          estadosDFA.insert(estado_muerte);
        }
      }
    }
  }

  // CREAMOS EL DFA RESULTANTE.
  FA dfa;
  // DEFINIMOS EL ALFABETO DEL DFA.
  dfa.SetAlphabet(alfabeto_);
  // DEFINIMOS EL ESTADO INICIAL DEL DFA.
  char identificador = 'A';
  // COMPARAMOS SI LOS ESTADOS DE "ESTADOSDFA" ESTAN EN EL MAPA DE
  // ESTADOS DE "DFA"
  std::map<std::set<State*>, char> estados;
  // RECORREMOS EL CONJUNTO DE ESTADOS DEL DFA.
  for (auto it = estadosDFA.begin(); it != estadosDFA.end(); ++it) {
    // CREAMOS UN ESTADO DEL DFA AL CUAL LE DAREMOS VALOR.
    State* st = nullptr;
    // SI EL CONJUNTO DE ESTADOS DE "ESTADOSDFA" NO ESTA EN EL MAPA DE ESTADOS DE "DFA".
    if (estados.find(*it) == estados.end()) {
      // LO INSERTAMOS EN EL MAPA DE ESTADOS CON UN IDENTIFICADOR PARA POSTERIORES COMPARACIONES.
      estados.insert({*it, identificador});
      // CREAMOS UN ESTADO DEL DFA CON EL IDENTIFICADOR Y COMPROBAMOS SI ES DE ACEPTACION
      // A PARTIR DEL SET DE ESTADOS INTRODUCIDO EN "ESTADOS".
      st = new State(std::string(1,identificador), AnyAccepted(*it));
      // LO INSERTAMOS EN EL DFA.
      dfa.Add(st);
      // SI ES EL ESTADO INICIAL, LO DEFINIMOS.
      if (identificador == 'A') {
        dfa.SetInitialState(st);
      }
      ++identificador;
    } else {
      // PARA CADA ESTADO DEL DFA.
      for (auto st2: dfa.estados_) {
        // SI EL IDENTIFICADOR DEL ESTADO ES IGUAL AL IDENTIFICADOR DEL CONJUNTO DE ESTADOS.
        if (st2->GetIdentifier() == std::string(1, estados[*it])) {
          // LO DEFINIMOS PARA POSTERIORMENTE AÑADIRLE LAS TRANSICIONES.
          st = st2;
        }
      }
    }

    // PARA CADA MAPA (ESTADOSDESTINO) DE LAS TRANSICIONES.
    for (auto estadosDestino: transiciones.at(*it)) {
      // CREAMOS UN ESTADO DEL DFA AL CUAL LE DAREMOS VALOR.
      State* stDestino = nullptr;
      // SI NO EXISTE EL CONJUNTO DE ESTADOS EN EL MAPA DE ESTADOS.
      if (estados.find(estadosDestino.second) == estados.end()) {
        // LO INSERTAMOS EN EL MAPA DE ESTADOS CON SU IDENTIFICADOR
        // PARA POSTERIORES COMPARACIONES.
        estados[estadosDestino.second] = identificador;
        ++identificador;
        // CREAMOS UN ESTADO DEL DFA CON EL IDENTIFICADOR Y COMPROBAMOS SI ES DE ACEPTACION
        // A PARTIR DE LOS ESTADOS INTRODUCIDOS EN "ESTADOSDESTINO".
        stDestino = new State(std::string(1, estados[estadosDestino.second]), AnyAccepted(estadosDestino.second));
        // AÑADIMOS EL ESTADO DESTINO AL DFA.
        dfa.Add(stDestino);
      } else {
        // PARA CADA ESTADO DEL DFA.
        for (auto st2: dfa.estados_) {
          // SI EL IDENTIFICADOR DEL ESTADO ES IGUAL AL IDENTIFICADOR DEL CONJUNTO DE ESTADOS.
          if (st2->GetIdentifier() == std::string(1, estados[estadosDestino.second])) {
            // LO DEFINIMOS PARA POSTERIORMENTE AÑADIR A LA TRANSICION EL ESTADO DESTINO.
            stDestino = st2;
          }
        }
      }
      // AÑADIMOS LA TRANSICION AL ESTADO DEL DFA.
      st->AddTransition(estadosDestino.first, stDestino);
    }
  }
  return dfa;
}

/**
 * @brief SOBRECARGA DEL OPERADOR<< PARA IMPRIMIR EL AUTOMATA FINITO.
 * 
 * @param os 
 * @param fa 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const FA& fa) {
  os << fa.GetAlphabet() << std::endl;
  os << fa.GetStatesNumber() << std::endl;
  os << fa.GetInitialState() << std::endl;
  for (auto it = fa.estados_.begin(); it != fa.estados_.end(); ++it) {
    os << (*it)->GetIdentifier() << " ";
    if ((*it)->IsAccepted()) {
      os << "1 ";
    } else {
      os << "0 ";
    }
    int number_transitions = 0;
    for (auto pair: (*it)->GetTransitions()) {
      if (pair.first != EMPTY) {
        ++number_transitions;
      }
    }
    os << number_transitions << " ";
    for (auto pair: (*it)->GetTransitions()) {
      os << pair.first << " " << pair.second->GetIdentifier() << " ";
    }
    os << std::endl;
  }
  return os;
}

/**
 * @brief METODO QUE DEVUELVE TRUE SI ALGUNO DE LOS ESTADOS DEL CONJUNTO
 * ES DE ACEPTACION. SIRVE PARA LA CONVERSION DE NFA A DFA.
 * 
 * @param estados 
 * @return true 
 * @return false 
 */
bool FA::AnyAccepted(const std::set<State*>& estados) const {
  for (State* st: estados) {
    if (st->IsAccepted()) {
      return true;
    }
  }
  return false;
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