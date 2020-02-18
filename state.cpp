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
            automate.decalage(s, new E3);
            break;
            
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
            
        case EXPR:
            automate.decalage(s, new E1);
            break;
            
        default:
            break;
    }
    return false;
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
            break;
    }
    return false;
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
            break;
    }
    return false;
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
            Expr* s = (Expr*) automate.popSymbole();
            automate.reduction(1, s);
            break;
            
        default:
            break;
    }
    return false;
}

//E4 class
E4::E4() {

}

E4::~E4() {

}

bool E4::transition(automate & automate, symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
            
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
            
        case EXPR:
            automate.decalage(s, new E7);
            break;
            
        default:
            break;
    }
    return false;
}

//E5 class
E5::E5() {

}

E5::~E5() {

}

bool E5::transition(automate & automate, symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
            
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
            
        case EXPR:
            automate.decalage(s, new E8);
            break;
            
        default:
            break;
    }
    return false;
}

//E6 class
E6::E6() {

}

E6::~E6() {

}

bool E6::transition(automate & automate, symbole * s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
            
        case MULT:
            automate.decalage(s, new E5);
            break;
            
        case CLOSEPAR:
            automate.decalage(s, new E9);
            break;
            
        default:
            break;
    }
    return false;
}

//E7 class
E7::E7() {

}

E7::~E7() {

}

bool E7::transition(automate & automate, symbole * s) {
    switch (*s) {
        case PLUS:
        case CLOSEPAR:
        case FIN:
            Expr* s1 = (Expr*) automate.popSymbole();
            automate.popAndDeleteSymbole();
            Expr* s2 = (Expr*) automate.popSymbole();
            automate.reduction(3, new ExprPlus(s1, s2));
            break;
            
        case MULT:
            automate.decalage(s, new E5);
            break;
            
        default:
            break;
    }
    return false;
}

//E8 class
E8::E8() {

}

E8::~E8() {

}

bool E8::transition(automate & automate, symbole * s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            Expr* s1 = (Expr*) automate.popSymbole();
            automate.popAndDeleteSymbole();
            Expr* s2 = (Expr*) automate.popSymbole();
            automate.reduction(3, new ExprMult(s1, s2));
            break;
            
        default:
            break;
    }
    return false;
}

//E9 class
E9::E9() {

}

E9::~E9() {

}

bool E9::transition(automate & automate, symbole * s) {
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.popAndDeleteSymbole();
            Expr* s = (Expr*) automate.popSymbole();
            automate.popAndDeleteSymbole();
            automate.reduction(3, s);
            break;
            
        default:
            break;
    }
    return false;
}
