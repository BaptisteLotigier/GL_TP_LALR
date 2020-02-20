#include "State.h"

//Generic class
State::State()
{}

State::~State()
{}

//E0 class
E0::E0()
{}

E0::~E0()
{}

bool E0::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent())
    {
        case INT:
            return automate.decalage(s, new E3);
            break;
            
        case OPENPAR:
            return automate.decalage(s, new E2);
            break;
            
        case EXPR:
            return automate.decalage(s, new E1);
            break;
            
        default:
            break;
    }
    return false;
}

//E1 class
E1::E1()
{}

E1::~E1()
{}

bool E1::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case PLUS:
            return automate.decalage(s, new E4);
            break;
            
        case MULT:
            return automate.decalage(s, new E5);
            break;
            
        case FIN:
            return true;
            
        default:
            break;
    }
    return false;   
}

//E2 class
E2::E2()
{}

E2::~E2()
{}

bool E2::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case INT:
            return automate.decalage(s, new E3);
            break;
            
        case OPENPAR:
            return automate.decalage(s, new E2);
            break;
            
        case EXPR:
            return automate.decalage(s, new E6);
            break;
            
        default:
            break;
    }
    return false;
}

//E3 class
E3::E3()
{}

E3::~E3()
{}

bool E3::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            Expr* s = (Expr*) automate.popSymbole();
            return automate.reduction(s, 1);
            break;
        }

        default:
            break;
    }
    return false;
}

//E4 class
E4::E4()
{}

E4::~E4()
{}

bool E4::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case INT:
            return automate.decalage(s, new E3);
            break;
            
        case OPENPAR:
            return automate.decalage(s, new E2);
            break;
            
        case EXPR:
            return automate.decalage(s, new E7);
            break;
            
        default:
            break;
    }
    return false;
}

//E5 class
E5::E5()
{}

E5::~E5()
{}

bool E5::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case INT:
            return automate.decalage(s, new E3);
            break;
            
        case OPENPAR:
            return automate.decalage(s, new E2);
            break;
            
        case EXPR:
            return automate.decalage(s, new E8);
            break;
            
        default:
            break;
    }
    return false;
}

//E6 class
E6::E6()
{}

E6::~E6()
{}

bool E6::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case PLUS:
            return automate.decalage(s, new E4);
            break;
            
        case MULT:
            return automate.decalage(s, new E5);
            break;
            
        case CLOSEPAR:
            return automate.decalage(s, new E9);
            break;
            
        default:
            break;
    }
    return false;
}

//E7 class
E7::E7()
{}

E7::~E7()
{}

bool E7::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case PLUS:
        case CLOSEPAR:
        case FIN:
        {
            Expr* s1 = (Expr*) automate.popSymbole();
            automate.popAndDeleteSymbole();
            Expr* s2 = (Expr*) automate.popSymbole();
            return automate.reduction(new ExprPlus(s1, s2), 3);
            break;
        }

        case MULT:
            return automate.decalage(s, new E5);
            break;
            
        default:
            break;
    }
    return false;
}

//E8 class
E8::E8()
{}

E8::~E8()
{}

bool E8::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            Expr* s1 = (Expr*) automate.popSymbole();
            automate.popAndDeleteSymbole();
            Expr* s2 = (Expr*) automate.popSymbole();
            return automate.reduction(new ExprMult(s1, s2), 3);
            break;
        }
            
        default:
            break;
    }
    return false;
}

//E9 class
E9::E9()
{}

E9::~E9()
{}

bool E9::transition(Automate& automate, Symbole* s)
{
    switch (s->getIdent()) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            automate.popAndDeleteSymbole();
            Expr* s = (Expr*) automate.popSymbole();
            automate.popAndDeleteSymbole();
            return automate.reduction(s, 3);
            break;
        }
            
        default:
            break;
    }
    return false;
}