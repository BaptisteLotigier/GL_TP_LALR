#include "Automate.h"
#include "State.h"

#include <iostream>

Automate::Automate(Lexer *lexer)
    : lexer(lexer), error(false)
{
    stateStack = new std::vector<State *>();
    symboleStack = new std::vector<Symbole *>();

    stateStack->push_back(new E0);
}

Automate::~Automate()
{
    delete (stateStack);
    delete (symboleStack);
}

void Automate::start()
{
    bool end = false;
    while (!end && !error)
    {
        Symbole *s = lexer->Consulter();
        State *state = stateStack->back();
        end = state->transition(*this, s);
    }

    if(error)
    {
        std::cout << "The expression is incorrect or malformed" << std::endl;
    }

    if(end)
    {
        std::cout << "Expression correctly recognized" << std::endl;
        std::cout << "Value of expression : " << ((Entier*)symboleStack->back())->getValeur() << std::endl;
    }

}

void Automate::decalage(Symbole *s, State *state)
{
#ifdef VERBOSE
    std::cout << "########################" << std::endl;
    std::cout << "before decalage" << std::endl;
    printStack();
    std::cout << "decalage vers " << state->getName() << std::endl;
#endif

    symboleStack->push_back(s);
    stateStack->push_back(state);
    if (s->isTerminal())
        lexer->Avancer();

#ifdef VERBOSE
    std::cout << "after decalage" << std::endl;
    printStack();
    std::cout << "########################" << std::endl;
#endif
}

void Automate::reduction(Symbole *s, int n)
{
#ifdef VERBOSE
    std::cout << "########################" << std::endl;
    std::cout << "before reduction" << std::endl;
    printStack();
    std::cout << "reduction vers ";
    s->Affiche();
    std::cout << std::endl;
#endif

    for (int i = 0; i < n; i++)
    {
        delete (stateStack->back());
        stateStack->pop_back();
    }

#ifdef VERBOSE
    std::cout << "after reduction" << std::endl;
    printStack();
    std::cout << "###########" << std::endl;
#endif

    stateStack->back()->transition(*this, s);
}

Symbole *Automate::popSymbole()
{
    Symbole *s = symboleStack->back();
    symboleStack->pop_back();
    return s;
}

void Automate::popAndDeleteSymbole()
{
    delete (symboleStack->back());
    symboleStack->pop_back();
}

void Automate::errorDetected()
{
    error = true;
}

void Automate::printStack()
{
    std::cout << "Stack symbole : ";
    int i = 0;
    for (; i < symboleStack->size(); i++)
    {
        (*symboleStack)[i]->Affiche();
        std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Stack state : ";
    for (i = 0; i < stateStack->size(); i++)
    {
        std::cout << (*stateStack)[i]->getName();
        std::cout << " ";
    }
    std::cout << std::endl;
}
