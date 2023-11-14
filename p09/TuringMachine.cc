// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Tomas Javes Tommasone
// Correo: alu0101515458@ull.edu.es
// Fecha: 14/11/2023
// Archivo TuringMachine.cc: Implementación de la clase TuringMachine.

// Historial de revisiones
// 14/11/2023 - Creacion (primera version) del codigo

#include "TuringMachine.h"

/**
 * @brief CONSTRUCTOR POR DEFECTO DE LA MAQUINA DE TURING.
 * 
 */
TuringMachine::TuringMachine() {
  std::set<State*> states_ = {};
  initial_state_ = nullptr;
}

/**
 * @brief CONSTRUCTOR DE LA MAQUINA DE TURING QUE RECIBE UN FICHERO COMO PARAMETRO.
 * 
 * @param file_name 
 */
TuringMachine::TuringMachine(std::string file_name) {
  std::ifstream input_file(file_name);
  // LEEMOS EL NUMERO DE ESTADOS, EL ESTADO INICIAL, EL ESTADO FINAL Y EL NUMERO DE TRANSICIONES.
  int num_states, num_transitions;
  std::string initial_state, final_state;
  input_file >> num_states >> initial_state >> final_state >> num_transitions;
  // SETEAMOS EL NUMERO DE TRANSICIONES.
  this->SetNumTransitions(num_transitions);
  // AÑADIMOS LOS ESTADOS A LA MAQUINA DE TURING.
  for (int i = 0; i < num_states; ++i) {
    State* state = new State(std::to_string(i));
    this->AddState(state);
  }
  // SET AL ESTADO INICIAL.
  this->SetInitialState(this->GetStateByIdentifier(initial_state));
  // ESTABLECEMOS LOS ESTADOS DE ACEPTACION.
  this->GetStateByIdentifier(final_state)->SetAccepted(true);
  this->AddState(this->GetStateByIdentifier(final_state));
  // LEEMOS LAS TRANSICIONES.
  for (int i = 0; i < num_transitions; ++i) {
    std::string state_identifier, next_state_identifier;
    Symbol read_symbol, write_symbol, move;
    // LEEMOS EL ESTADO ACTUAL, EL SIMBOLO LEIDO, EL SIMBOLO ESCRITO, EL MOVIMIENTO Y EL ESTADO DESTINO.
    input_file >> state_identifier >> read_symbol >> write_symbol >> move >> next_state_identifier;
    // AÑADIMOS LA TRANSICION.
    this->GetStateByIdentifier(state_identifier)->AddTransition(read_symbol, write_symbol, move, this->GetStateByIdentifier(next_state_identifier));
  }
  // PREGUNTAMOS AL USUARIO SI QUIERE MOSTRAR LA MAQUINA DE TURING.
  std::string respuesta;
  std::cout << "¿Desea mostrar la maquina de turing? (s/n): ";
  std::cin >> respuesta;
  if (respuesta == "s") {
    std::cout << *this;
  }
  // CERRAMOS EL FICHERO.
  input_file.close();
}

/**
 * @brief DESTRUCTOR DE LA MAQUINA DE TURING.
 * 
 */
TuringMachine::~TuringMachine() {
  initial_state_ = nullptr;
  for (auto state: states_) {
    delete state;
  }
  states_.clear();
}

/**
 * @brief METODO SETTER QUE ESTABLECE EL ESTADO INICIAL
 * DE LA MAQUINA DE TURING.
 * 
 * @param state 
 */
void TuringMachine::SetInitialState(State* state) {
  initial_state_ = state;
}

/**
 * @brief METODO SETTER QUE ESTABLECE EL NUMERO DE 
 * TRANSICIONES DE LA MAQUINA DE TURING.
 * 
 * @param num_transitions 
 */
void TuringMachine::SetNumTransitions(int num_transitions) {
  num_transitions_ = num_transitions;
}

/**
 * @brief METODO GETTER QUE DEVUELVE EL ESTADO INICIAL
 * 
 * @return State* 
 */
State* TuringMachine::GetInitialState() const {
  return initial_state_;
}

/**
 * @brief METODO GETTER QUE DEVUELVE EL ESTADO FINAL
 * 
 * @return State* 
 */
State* TuringMachine::GetFinalState() const {
  for (auto state: states_) {
    if (state->IsAccepted()) {
      return state;
    }
  }
  return nullptr;
}

/**
 * @brief METODO GETTER QUE DEVUELVE EL NUMERO DE TRANSICIONES
 * 
 * @return int 
 */
int TuringMachine::GetNumTransitions() const {
  return num_transitions_;
}

/**
 * @brief METODO GETTER QUE DEVUELVE EL CONJUNTO DE ESTADOS
 * 
 * @return std::set<State*> 
 */
std::map<Symbol, Transition> TuringMachine::GetTransitions() const {
  std::map<Symbol, Transition> transitions;
  for (auto state: states_) {
    std::map<Symbol, Transition> state_transitions = state->GetTransitions();
    for (auto transition: state_transitions) {
      transitions.insert(transition);
    }
  }
  return transitions;
}

/**
 * @brief METODO GETTER QUE DEVUELVE EL ESTADO DE LA MAQUINA DE TURING
 * A PARTIR DE SU IDENTIFICADOR.
 * 
 * @param identifier 
 * @return State* 
 */
State* TuringMachine::GetStateByIdentifier(std::string identifier) const {
  for (auto state: states_) {
    if (state->GetIdentifier() == identifier) {
      return state;
    }
  }
  return nullptr;
}

/**
 * @brief METODO QUE AÑADE UN ESTADO A LA MAQUINA DE TURING.
 * 
 * @param state 
 */
void TuringMachine::AddState(State* state) {
  states_.insert(state);
}

/**
 * @brief METODO PRINCIPAL CON EL QUE SIMULAREMOS
 * LA MÁQUINA DE TURING.
 * 
 * @param chain 
 */
void TuringMachine::Simulate(const Chain& chain) const {
  State* current_state = initial_state_;
  Tape tape(chain);
  tape.WriteOutput(std::cout, current_state->GetIdentifier());
  while (!current_state->IsAccepted()) {
    // LEER CINTA.
    Symbol symbol = tape.Read();
    // AVANZAR SEGUN SÍMBOLO LEIDO.
    std::map<Symbol, Transition> transition = current_state->GetTransitionsBySymbol(symbol);
    // std::map<Symbol, Transition> all_transitions = current_state->GetTransitions();
    // for (auto it = all_transitions.begin(); it != all_transitions.end(); ++it) {
    //   std::cout << it->first << " " << it->second.write_symbol_ << " " << it->second.move_ << " " << it->second.next_state_ << std::endl;
    // }
    // std::cout << "SÍMBOLO: " << symbol << std::endl;
    if (current_state->GetTransitionsBySymbol(symbol).empty()) {
      std::cout << std::endl;
      std::cout << "No se ha encontrado transicion para el simbolo " << symbol << " en el estado " << current_state->GetIdentifier() << std::endl;
      std::cout << "Cadena RECHAZADA" << std::endl;
      exit(EXIT_FAILURE);
    }
    // ESCRIBIMOS SIMBOLO.
    tape.Write(transition.begin()->second.write_symbol_);
    // NOS MOVEMOS.
    if (transition.begin()->second.move_ == LEFT) {
      tape.Left();
    } else if (transition.begin()->second.move_ == RIGHT) {
      tape.Right();
    }
    // ACTUALIZAMOS ESTADO.
    current_state = GetStateByIdentifier(transition.begin()->second.next_state_);
    // MOSTRAMOS CINTA.
    tape.WriteOutput(std::cout, current_state->GetIdentifier());
  }
  std::cout << std::endl;
}

/**
 * @brief SOBRECARGA DEL OPERADOR DE INSERCION.
 * 
 * @param os 
 * @param turing_machine 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const TuringMachine& turing_machine) {
  os << turing_machine.states_.size() << std::endl;
  os << turing_machine.initial_state_->GetIdentifier() << std::endl;
  os << turing_machine.GetFinalState()->GetIdentifier() << std::endl;
  os << turing_machine.GetNumTransitions() << std::endl;
  // MOSTRAMOS LAS TRANSICIONES CON CADA ESTADO.
  for (auto state: turing_machine.states_) {
    std::map<Symbol, Transition> transitions = state->GetTransitions();
    for (auto transition: transitions) {
      os << state->GetIdentifier() << " " << transition.first << " " << transition.second.write_symbol_ << " " << transition.second.move_ << " " << transition.second.next_state_ << std::endl;
    }
  }
  os << std::endl;
  return os;
}