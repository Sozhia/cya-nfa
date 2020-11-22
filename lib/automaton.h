/**
 * @file automaton.h
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief {Σ, Q, q0, F, δ} Automaton attributes and declarations
 * Σ : finite set of input symbols
 * Q : finite set of states
 * q0 : initial (or start) state
 * F : set of states distinguished as accepting (or final) states
 * δ : transition function
 * @version 1.0
 * @date 2020-11-21
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: CYA
 * REFERENCE: https://github.com/Sozhia/lib
 */
#include "./word.h"
#include "./automaton_state.h"
#include <fstream>
#include <sstream>
#include <iostream>
class Automaton {
 private:
  std::vector <char> stimulations_; // Stimulations expected in this automaton 
  Alphabet alphabet_; // finite set of input symbols
  std::vector<AutomatonState> states_; // finite set of states
  std::vector<unsigned int> states_pathing_; // pathing to get final state
  bool** predecessor_;
  
 public:
  Automaton();
  Automaton(std::string input_nfa);
  void StateInput(char c, unsigned int id);
  //void PrintAutomatonTable();
  void SetAutomatonState ();
  void CheckInputData(std::string file);
  bool CheckWord(std::string word);
  void SetPredecessors();
  
};