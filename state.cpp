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
E1::E1() {

}

E1::~E1() {

}

bool E1::transition(automate & automate, symbole * s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
            
        case MULT:
            automate.decalage(s, new E5);
            break;
            
        case FIN:
            return true;
            
        default:
            return false;
    }
}

//E2 class
E2::E2() {

}

E2::~E2() {

}

bool E2::transition(automate & automate, symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
            
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
            
        case EXPR:
            automate.decalage(s, new E6);
            break;
            
        default:
            return false;
    }
}

//E3 class
E3::E3() {

}

E3::~E3() {

}

bool E3::transition(automate & automate, symbole * s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            
            break;
            
        default:
            return false;
    }
}
