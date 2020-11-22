/**
 * @file automaton.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief Automaton class definition
 * @version 1.0
 * @date 2020-11-21
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: CYA
 * REFERENCE: https://github.com/Sozhia/lib
 */
#include "./automaton.h"

/**
 * @brief Parameterized Automaton constructor  
 * 
 * @param input_nfa file with nfa constructor information
 */
Automaton::Automaton(std::string input_nfa) {
  std::ifstream myfile(input_nfa);
  unsigned int num_states, starting;
  std::string line;
  if (myfile.is_open()) {
    myfile >> num_states;
    std::cout << "Numero de estados: "<< num_states << std::endl;
    //states_.resize(num_states); Q : (finite set of states) size
    for (unsigned int states = 0; states < num_states; states++) {
      AutomatonState state;
      states_.push_back(state);
      std::cout << "Creado y almacenado objeto estado: " << states << std::endl;
    }
    myfile >> starting;
    std::cout << "Estado inicial asignado a q"<< starting << std::endl;
    states_[starting].SetStart(1); // q0 : initial (or start) state
    // State identifier to operate
    while(!myfile.eof()) {
      unsigned int state_identifier;
      myfile >> state_identifier;
      std::cout << "Operando con estado q" << state_identifier << std::endl;
      // Is an accepting state?
      bool accepting;
      myfile >> accepting;
      std::cout << "Aceptacion = " << accepting << std::endl;
      if (accepting) {
        states_[state_identifier].SetFinal(1);
        std::cout << "Confirmado aceptacion" << std::endl;
      }
      // Num of state transitions
      unsigned int num_transitions;
      myfile >> num_transitions;
      std::cout << "Numero de transiciones para el estado q" << state_identifier << ": " << num_transitions << std::endl;
      for (unsigned int aux = 0; aux < num_transitions; aux++) {
        // Transitions alike [Stimulation -> Next_State_ID] by pair {char,unsigned int}
        char stimulation;
        unsigned int next_id;
        myfile >> stimulation >> next_id;
        states_[state_identifier].SetLinked(stimulation, next_id);
      }
    }
    myfile.close();
  } else {
    std::cout << "Unable to open file " << input_nfa << std::endl;;
  } 
}
/* DISEÑARLO POR TILES = 10/10 NO SEAS VAGO HDP
void Automaton::PrintAutomaton() {

}*/
/**
 * @brief Check words from a file
 * 
 * @param file file that contains words
 */
void Automaton::CheckInputData(std::string file) {
  std::ifstream indatafile(file);
  std::string parser_data;
  if (indatafile.is_open()) {
    while(!indatafile.eof()) {
      indatafile >> parser_data;
      CheckWord(parser_data);
    }
    indatafile.close();
  } else {
    std::cout << "Unable to open file " << file << std::endl;
  } 
}

void Automaton::SetPredecessors() {
  unsigned int id_final;
  for (unsigned int aux = 0; aux < states_.size(); aux++) {
    if(states_[aux].GetFinal()){
      id_final = aux;
    }
  }
  predecessor_= new bool* [states_.size()];
  for (unsigned int i = 0; i < states_.size(); i++) 
    predecessor_[i] = new bool [states_.size()];
  unsigned int parsing = id_final;
  do {
    for (unsigned int i = 0; i < states_.size(); i++) {
      for (unsigned int j = 0; j < states_.size(); j++) {
        if (!predecessor_[i][j] && j == parsing && ) {

        } else {
          predecessor_[i][j] = false;
        }
      }
    }
  } while (!states_[parsing].GetStart());

}
/**
 * @brief 
 * 
 * @param word 
 * @return true 
 * @return false 
 */
bool Automaton::CheckWord(std::string word) {

}
