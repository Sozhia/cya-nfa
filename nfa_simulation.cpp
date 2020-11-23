/**
 * @file nfa_simulation.cpp
 * @author Miqueas (Sozhia) Garcia Gonzalez
 * CONTACT: sozhia.business@gmail.com
 * @brief Main function
 * @version 1.5
 * @date 2020-11-21
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: CYA
 * REFERENCE: https://github.com/Sozhia/lib
 */
#include "./lib/automaton.cpp"
#include <string.h>
void PrintHelp() {
    std::cout << "This is a implementation of an Non Deterministic Finite Automaton (NFA)"<< std::endl;
    std::cout << "in the C++ programming language for academic purposes."<< std::endl;
    std::cout << "To run the program in your local machine check out the following steps:"<< std::endl;
    std::cout << "\t ./nfa_simulation input.nfa input.txt output.txt"<< std::endl;
    std::cout << "\t where:"<< std::endl;
    std::cout << "\t \tinput.nf -> nfa specifications"<< std::endl;
    std::cout << "\t \tinput.txt -> words automaton have to parse"<< std::endl;
    std::cout << "\t \toutput.txt -> parsing result"<< std::endl;
  }

int main (int argc, char** argv) {
  std::string f_output, f_input, f_nfa;
  if (argc == 2 && strcmp(argv[1], "--help")==0) {
		PrintHelp();
		exit(1);
	}
  if (argc != 4) {
    std::cout << "Use example: ./nfa_simulation input.nfa input.txt output.txt"<< std::endl;
    std::cout << "\t Try ./nfa_simulation --help for more information."<< std::endl;
    exit(1);
	} else {
    f_output = argv[3];
    f_input = argv[2];
    f_nfa = argv[1];
    Alphabet alphabet;
    alphabet.SetAlphabet();
    Automaton automaton(f_nfa);
    automaton.SetAlphabet(alphabet);
    automaton.CheckInputData(f_input);
    automaton.PrintOutputData(f_output);
  }
  return 0;
}