#pragma once

#include "Symbole.h"
#include "Automate.h"

class State {
    public:
        State();
        virtual ~State();
        virtual bool transition(Automate& automate, Symbole* s) = 0;
};

class E0 : public State {
    public:
        E0();
        virtual ~E0();
        bool transition(Automate& automate, Symbole* s);
};

class E1 : public State {
    public:
        E1();
        virtual ~E1();
        bool transition(Automate& automate, Symbole* s);
};

class E2 : public State {
    public:
        E2();
        virtual ~E2();
        bool transition(Automate& automate, Symbole* s);
};

class E3 : public State {
    public:
        E3();
        virtual ~E3();
        bool transition(Automate& automate, Symbole* s);
};

class E4 : public State {
    public:
        E4();
        virtual ~E4();
        bool transition(Automate& automate, Symbole* s);
};

class E5 : public State {
    public:
        E5();
        virtual ~E5();
        bool transition(Automate& automate, Symbole* s);
};

class E6 : public State {
    public:
        E6();
        virtual ~E6();
        bool transition(Automate& automate, Symbole* s);
};

class E7 : public State {
    public:
        E7();
        virtual ~E7();
        bool transition(Automate& automate, Symbole* s);
};

class E8 : public State {
    public:
        E8();
        virtual ~E8();
        bool transition(Automate& automate, Symbole* s);
};

class E9 : public State {
    public:
        E9();
        virtual ~E9();
        bool transition(Automate& automate, Symbole* s);
};