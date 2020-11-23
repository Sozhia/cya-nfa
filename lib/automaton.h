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
 * @version 1.5
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
  std::vector<std::string> words_; // words to parse
  bool supported_symbol_; // check if a symbol is supported by the automaton
  
 public:
  Automaton();
  Automaton(std::string input_nfa);
  void SetAlphabet(Alphabet &alphabet);
  void CheckInputData(std::string input_file);
  void PrintOutputData(std::string output_file);
  bool CheckAlphabet(std::string);
  bool CheckWord(std::string word);
 };