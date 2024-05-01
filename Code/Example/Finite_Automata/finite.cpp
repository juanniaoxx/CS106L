#include "finite_automata.h"

/*
    Function:SimulatDFA(DFA& d, string input)
    the function accpets as input a DAF struct and a string repressenting the input;
    simulates the DFA when run on the given input,and the return whether the input was 
    accepted.

*/
bool SimulatDFA(DFA& d, string input){
    int currState = d.StartState;//maintain the state we're currently in
    //asume the input string is composed only of characters from the DFA's alphabet.
    for (auto iter = input.begin(); iter != input.end(); iter++){
        currState = d.transitions[make_pair(currState, *iter)];
    }
    return d.accpetingStates.find(currState) != d.accpetingStates.end();
}