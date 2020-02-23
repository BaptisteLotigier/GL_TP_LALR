#include "automate.h"
#include "state.h"

#include <iostream>

Automate::Automate(Lexer* lexer)
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
    bool end = false;
    while (!end) {
        Symbole* s = lexer->Consulter();
        State* state = stateStack->back();
        end = state->transition(*this, s);
    }
    return true;
}

void Automate::decalage(Symbole* s, State* state) 
{
    std::cout<<"########################"<<std::endl;
    std::cout<<"before decalage"<<std::endl;
    printStack();
    std::cout<<"decalage vers "<<state->getName()<<std::endl;
    symboleStack->push_back(s);
    stateStack->push_back(state);
    if (s->isTerminal()) lexer->Avancer();
    std::cout<<"after decalage"<<std::endl;
    printStack();
    std::cout<<"########################"<<std::endl;
    return;
}

void Automate::reduction(Symbole* s, int n)
{
    std::cout<<"########################"<<std::endl;
    std::cout<<"before reduction"<<std::endl;
    printStack();
    std::cout<<"reduction vers ";
    s->Affiche();
    std::cout<<std::endl;
    for(int i = 0; i < n; i++)
    {
        delete(stateStack->back());
        stateStack->pop_back();
    }
    std::cout<<"after reduction"<<std::endl;
    printStack();
    std::cout<<"###########"<<std::endl;
    stateStack->back()->transition(*this, s);
    std::cout<<"###########"<<std::endl;
    std::cout<<"########################"<<std::endl;
    return;
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
    std::cout << "Stack symbole : ";
    int i = 0;
    for(; i < symboleStack->size(); i++)
    {
        (*symboleStack)[i]->Affiche();
        std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Stack state : ";
    for(i=0; i < stateStack->size(); i++)
    {
        std::cout<<(*stateStack)[i]->getName();
        std::cout << " ";
    }
    std::cout << std::endl;
}
