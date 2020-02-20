#pragma once

#include "Symbole.h"
#include "Lexer.h"

#include <vector>

class State;

class Automate {
    public:
        Automate(Lexer *lexer);
        virtual ~Automate();
        bool decalage(Symbole* s, State* state);
        bool reduction(Symbole* s, int n);
        Symbole* popSymbole();
        void popAndDeleteSymbole();
        bool start();
        void printStack();

    protected:
        std::vector<State*> *stateStack;
        std::vector<Symbole*> *symboleStack;
        Lexer *lexer;
};