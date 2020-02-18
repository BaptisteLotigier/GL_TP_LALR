#include "state.h"

//Generic class
state::state(){}

state::~state(){}

//E0 class
E0::E0() {

}

E0::~E0() {

}

bool E0::transition(automate & automate, symbole * s) {
    switch (*s)
    {
        case INT:
            //automate.decalage(s, new E3());
            break;
        case OPENPAR:
            //automate.decalage(s, new E2());
            break;
    }
}

//E1 class