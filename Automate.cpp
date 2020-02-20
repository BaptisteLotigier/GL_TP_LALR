#include "Automate.h"
#include "State.h"

#include <iostream>

Automate::Automate(Lexer *lexer)
: lexer(lexer)
{
    stateStack = new std::vector<State*>();
    symboleStack = new std::vector<Symbole*>();

    stateStack->push_back(new E0);
}

Automate::~Automate()
{
    delete(stateStack);

    delete(symboleStack);
}

bool Automate::start()
{
    Symbole* s = lexer->Consulter();
    State* state = stateStack->back();
    return state->transition(*this, s);
}

bool Automate::decalage(Symbole* s, State* state) 
{
    printStack();
    symboleStack->resize(symboleStack->size()+1);
    symboleStack->push_back(s);
    stateStack->push_back(state);
    if(s->isTerminal()) lexer->Avancer();
    Symbole* newS = lexer->Consulter();
    State* topState = stateStack->back();
    return topState->transition(*this, newS);
}

bool Automate::reduction(Symbole *s, int n)
{
    printStack();
    for(int i = 0; i < n; i++)
    {
        delete(stateStack->back());
        stateStack->pop_back();
    }
    State* topState = stateStack->back();
    return topState->transition(*this, s);
}

Symbole* Automate::popSymbole()
{
    Symbole* s = symboleStack->back();
    symboleStack->pop_back();
    return s;
}

void Automate::popAndDeleteSymbole()
{
    delete(symboleStack->back());
    symboleStack->pop_back();
}

void Automate::printStack() 
{
    std::cout << symboleStack->size() << std::endl;
    std::cout << "Stack symbole : ";
    int i = 0;
    for(; i < symboleStack->size(); i++)
    {
        (*symboleStack)[i]->Affiche();
        std::cout << " ";
    }
    std::cout << std::endl;
}