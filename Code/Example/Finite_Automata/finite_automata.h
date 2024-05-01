#ifndef FINITE_AUTOMATA_H
#define FINITE_AUTOMATA_H

#include <iostream> 
#include <string> //string
#include <map> // map
#include <set> // set
#include <utility> //pair

using namespace std;

/*
    DFA:Deterministic Finite Automaton
    1.the set of states used by the DFA
    2.the DFA's alphabet
    3.the start state
    4.the state transitions(the most important)
    5.the set of accpeting states;

    for example,the state transitions is :
    -----------------------
    state| 0   |  1  |
    -----------------------
    q_0  | q_1 | q_2 |     
    q_1  | q_0 |  q_3|
    .....  
*/
struct DFA{
    map<pair<int, char>, int> transitions;
    set<int> accpetingStates;
    int StartState;
};

bool SimulatDFA(DFA& d, string input);

#endif