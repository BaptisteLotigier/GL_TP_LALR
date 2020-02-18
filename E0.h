#pragma once

#include "state.h"

class E0 : public state
{
    public:
        E0();
        ~E0();
        bool transition(automate & automate, symbole * s);
};