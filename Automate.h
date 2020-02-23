#pragma once

#include "Symbole.h"
#include "Lexer.h"

#include <vector>

class State;

class Automate
{
public:
    Automate(Lexer *lexer);
    virtual ~Automate();
    void decalage(Symbole *s, State *state);
    void reduction(Symbole *s, int n);
    Symbole *popSymbole();
    void popAndDeleteSymbole();
    void start();
    void printStack();
    void errorDetected();

protected:
    std::vector<State *> *stateStack;
    std::vector<Symbole *> *symboleStack;
    Lexer *lexer;
    bool error;
};
