/**
 * @file automaton.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief Automaton class definition
 * @version 1.10.2
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
    //Q : (finite set of states) size
    for (unsigned int states = 0; states < num_states; states++) {
      AutomatonState state;
      states_.push_back(state);
    }
    myfile >> starting;
    states_[starting].SetStart(true); // q0 : initial (or start) state
    // State identifier to operate
    while(!myfile.eof()) {
      unsigned int state_identifier;
      myfile >> state_identifier;
      // Is an accepting state?
      bool is_accepting;
      int accepted;
      myfile >> accepted;
      if (accepted == 1)
        is_accepting = true;
      if (is_accepting) {
        states_[state_identifier].SetFinal(true);
      } else {
        states_[state_identifier].SetFinal(false);
      }
      // Num of state transitions
      unsigned int num_transitions;
      myfile >> num_transitions;
      for (unsigned int aux = 0; aux < num_transitions; aux++) {
        // Transitions alike [Stimulation -> Next_State_ID] by pair {char,unsigned int}
        char stimulation;
        unsigned int next_id;
        bool is_in_alphabet;
        myfile >> stimulation >> next_id;
        for (unsigned int foo = 0; aux < alphabet_.size(); foo ++) {
          if (stimulation == alphabet_[foo])
            is_in_alphabet = true;
        }
        if (!is_in_alphabet)
          alphabet_.SetSymbol(stimulation);
        states_[state_identifier].SetLinked(stimulation, next_id);
      }
    }
    myfile.close();
  } else {
    std::cout << "Unable to open file " << input_nfa << std::endl;
  } 
}
/**
 * @brief Asign an alphabet to the automaton (Σ)
 * 
 * @param alphabet object
 //Si problemas con el alphabet
void Automaton::SetAlphabet(Alphabet &alphabet) {
  alphabet_ = alphabet;
}/*
/**
 * @brief Check words from a file
 * 
 * @param input_file container of words
 * @param output_file result of parsing with automata
 */
void Automaton::CheckInputData(std::string input_file) {
  std::ifstream indatafile(input_file);
  std::string parser_data;
  if (indatafile.is_open()) {
    while(!indatafile.eof()) {
      indatafile >> parser_data;
      words_.push_back(parser_data);
    }
    indatafile.close();
  } else {
    std::cout << "Unable to open file " << input_file << std::endl;
  } 
}
/**
 * @brief Print into a file the result of parsing words letter by letter
 * 
 * @param output_file 
 */
void Automaton::PrintOutputData(std::string output_file) {
  bool word;
  std::ofstream outdatafile(output_file);
  if (outdatafile.is_open()) {
    for (unsigned int aux = 0; aux < words_.size(); aux ++) {
      word = CheckWord(words_[aux]);
      if (!supported_symbol_) {
        outdatafile << "Error \n";
      } else if (word) {
        outdatafile << "True \n";
      } else { 
        outdatafile << "False \n";
      }
    }
  } else {
    std::cout << "Unable to open file " << output_file << std::endl;
  }
  outdatafile.close();
}
/**
 * @brief Split a word into characters (stimulus) and try to get a final state
 * 
 * @param word word to split into characters
 * @return true if it makes final state
 * @return false if it not makes final state
 */
bool Automaton::CheckWord(std::string word) {
  supported_symbol_ = true;
  CheckAlphabet(word);
  if ((word.size() < states_.size()) | (!supported_symbol_))
    return false;
  unsigned int counter = 0;
  bool final;
  unsigned int actual_state;
  for (unsigned int aux = 0; aux < states_.size(); aux ++) {
    if (states_[aux].GetStart()) {
      actual_state = aux;
      break;
    }
  }
  do {
    final = 0;
    if (states_[actual_state].GetFinal()) {
      final = 1;
      break;
    }
    actual_state = states_[actual_state].NextState(actual_state,word[counter]);
    if (actual_state == 999) {
      final = 0;
      break;
    }
    counter ++;
  } while(counter < word.size());
  return final;
}
bool Automaton::CheckAlphabet(std::string word) {
  for(unsigned int aux = 0; aux < word.size(); aux++) {
    if (alphabet_.CheckSymbol(word[aux]) == false) {
      supported_symbol_ = false;
      break;
    }
  }
  return supported_symbol_;
}
