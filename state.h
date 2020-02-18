#pragma once

#include <string>
#include "symbole.h"
#include "automate.h"

class state {
    public:
        state();
        virtual ~state();
        void print() const;
        virtual bool transition(automate & automate, symbole * s);
};

class E0 : public state
{
    public:
        E0();
        ~E0();
        bool transition(automate & automate, symbole * s);
};