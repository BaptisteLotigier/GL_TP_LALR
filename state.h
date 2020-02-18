#pragma once

#include <string>
#include "symbole.h"
#include "automate.h"

class state {
    public:
        state();
        virtual ~state();
        void print() const;
        virtual bool transition(automate & automate, symbole * s) = 0;
};