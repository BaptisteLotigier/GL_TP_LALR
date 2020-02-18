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

class E1 : public state
{
    public:
        E1();
        ~E1();
        bool transition(automate & automate, symbole * s);
};

class E2 : public state
{
    public:
        E2();
        ~E2();
        bool transition(automate & automate, symbole * s);
};

class E3 : public state
{
    public:
        E3();
        ~E3();
        bool transition(automate & automate, symbole * s);
};
