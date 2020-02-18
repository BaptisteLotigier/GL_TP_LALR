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

class E4 : public state
{
    public:
        E4();
        ~E4();
        bool transition(automate & automate, symbole * s);
};

class E5 : public state
{
    public:
        E5();
        ~E5();
        bool transition(automate & automate, symbole * s);
};

class E6 : public state
{
    public:
        E6();
        ~E6();
        bool transition(automate & automate, symbole * s);
};

class E7 : public state
{
    public:
        E7();
        ~E7();
        bool transition(automate & automate, symbole * s);
};

class E8 : public state
{
    public:
        E8();
        ~E8();
        bool transition(automate & automate, symbole * s);
};

class E9 : public state
{
    public:
        E9();
        ~E9();
        bool transition(automate & automate, symbole * s);
};