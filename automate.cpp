#include "automate.h"

automate::automate(string flux) {
    stateStack = new stack<state*>();
    symboleStack = new stack<symbole*>();
    lexer = new Lexer(flux);

    stateStack->push(new E0());
}

automate::~automate() {
    delete stateStack;
    delete symboleStack;
}

void automate::decalage(symbole *s, state *state){
    symboleStack->push(s);
    stateStack->push(state);

}

void automate::reduction(int n, symbole *s){

}