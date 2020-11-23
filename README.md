# NFA
A nondeterministic finite automaton (NFA), or nondeterministic finite-state machine, does not need to obey these restrictions. In particular every DFA is also an NFA. check out this [link](https://campusingenieriaytecnologia.ull.es/pluginfile.php/344702/mod_assign/introattachment/0/p08_NFA.pdf)
## Requisites
An NFA is represented formally by a 5-tuple, {Σ, Q, Δ, q0, F, δ}, consisting of:
* a finite set of states Q.
* a finite set of input symbols Σ .
* a transition function Δ : Q x Σ => P(Q).
* an initial (or start) state q0 ϵ Q.
* a set of states F distinguished as accepting (or final) states F ⊆ Q.
## NFA Configuration file
```bash
4 // Q
0 // q0
// ACTUAL STATE, IS FINAL STATE, NUM TRANSITIONS, TRANSITION {STIMULATION, STATE ...} 
0 0 3 a 0 b 0 b 1  
1 0 2 a 2 b 2
2 0 2 a 3 b 3
3 1 0
```
An example:
<p>

![nfa_configuration](./img/nfa.gif)

## Running the program
After building the program, you can execute it with:
```bash
./nfa_simulation input.nfa input.txt output.txt
```
where:
* input.nf -> nfa specifications
* input.txt -> words automaton have to parse
* output.txt -> parsing result

## Use example by images
#### NFA CONFIGURATION FILE
![nfa_configuration](./img/nfa_input.gif)
#### DATA INPUT (WORDS)
![nfa](./img/input.gif)
#### PROCESSED OUTPUT
![nfa_configuration](./img/output.gif)