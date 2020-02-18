#pragma once
#include <stack>

#include "state.h"
#include "symbole.h"
#include "lexer.h"

using namespace std;

class automate {
    public:
        automate(string flux);
        ~automate();
        void decalage(symbole *s, state *state);
        void reduction(int n, symbole *s);

    protected:
        stack<state*> *stateStack;
        stack<symbole*> *symboleStack;
        Lexer *lexer;
};