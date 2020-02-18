#include "automate.h"

automate::automate(string flux) {
    stateStack = new stack<state*>();
    symboleStack = new stack<symbole*>();
    lexer = new Lexer(flux);

    stateStack->push(new E0());

    symbole *s = lexer->Consulter();
    stateStack->top()->transition(*this, s);
}

automate::~automate() {
    delete stateStack;
    delete symboleStack;
}

void automate::decalage(symbole *s, state *state){
    symboleStack->push(s);
    stateStack->push(state);
    if(s->isTerminal()) {
        lexer->Avancer();
    }
}

void automate::reduction(int n, symbole *s){
    for(int i = 0; i < n; i++) {
        delete(stateStack->top());
        stateStack->pop();
    }
    stateStack->top()->transition(*this, s);
}