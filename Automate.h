#pragma once

#include "symbole.h"
#include "lexer.h"

#include <vector>

class State;

class Automate {
    public:
        Automate(Lexer* lexer);
        virtual ~Automate();
        void decalage(Symbole* s, State* state);
        void reduction(Symbole* s, int n);
        Symbole* popSymbole();
        void popAndDeleteSymbole();
        bool start();
        void printStack();

    protected:
        vector<State*> *stateStack;
        vector<Symbole*> *symboleStack;
        Lexer* lexer;
};
