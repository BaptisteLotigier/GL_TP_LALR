#include "State.h"

//State
State::State()
{}

State::~State()
{}

//E0 class
E0::E0()
{}

E0::~E0()
{}

bool E0::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case OPENPAR:
        automate.decalage(s, new E2);
        break;

    case INT:
        automate.decalage(s, new E3);
        break;

    case EXPR:
        automate.decalage(s, new E1);
        break;

    default:
        automate.errorDetected();
        break;
    }
    return false;
}

//E1 class
E1::E1()
{}

E1::~E1()
{}

bool E1::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
        automate.decalage(s, new E4);
        break;

    case MULT:
        automate.decalage(s, new E5);
        break;

    case FIN:
        return true;

    default:
        automate.errorDetected();
        break;
    }
    return false;
}

//E2 class
E2::E2()
{}

E2::~E2()
{}

bool E2::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case OPENPAR:
        automate.decalage(s, new E2);
        break;

    case INT:
        automate.decalage(s, new E3);
        break;

    case EXPR:
        automate.decalage(s, new E6);
        break;

    default:
        automate.errorDetected();
        break;
    }
    return false;
}

//E3 class
E3::E3()
{}

E3::~E3()
{}

bool E3::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
        Entier *s = (Entier *)automate.popSymbole();
        int value = s->getValeur();
        delete(s);
        automate.reduction(new Number(value), 1);
        break;
    }

    default:
        automate.errorDetected();
        break;
    }
    return false;
}

//E4 class
E4::E4()
{}

E4::~E4()
{}

bool E4::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case OPENPAR:
        automate.decalage(s, new E2);
        break;

    case INT:
        automate.decalage(s, new E3);
        break;
    
    case EXPR:
        automate.decalage(s, new E7);
        break;

    default:
        automate.errorDetected();
        break;
    }
    return false;
}

//E5 class
E5::E5()
{}

E5::~E5()
{}

bool E5::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case OPENPAR:
        automate.decalage(s, new E2);
        break;

    case INT:
        automate.decalage(s, new E3);
        break;

    case EXPR:
        automate.decalage(s, new E8);
        break;

    default:
        automate.errorDetected();
        break;
    }
    return false;
}

//E6 class
E6::E6()
{}

E6::~E6()
{}

bool E6::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
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
        automate.errorDetected();
        break;
    }
    return false;
}

//E7 class
E7::E7()
{}

E7::~E7()
{}

bool E7::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case CLOSEPAR:
    case FIN:
    {
        Expr *e1 = (Expr *)automate.popSymbole();
        automate.popAndDeleteSymbole();
        Expr *e2 = (Expr *)automate.popSymbole();
        automate.reduction(new ExprPlus(e1, e2), 3);
        break;
    }

    case MULT:
        automate.decalage(s, new E5);
        break;

    default:
        automate.errorDetected();
        break;
    }
    return false;
}

//E8 class
E8::E8()
{}

E8::~E8()
{}

bool E8::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
        Expr *e1 = (Expr *)automate.popSymbole();
        automate.popAndDeleteSymbole();
        Expr *e2 = (Expr *)automate.popSymbole();
        automate.reduction(new ExprMult(e1, e2), 3);
        break;
    }

    default:
        automate.errorDetected();
        break;
    }
    return false;
}

//E9 class
E9::E9()
{}

E9::~E9()
{}

bool E9::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
        automate.popAndDeleteSymbole();
        Expr *e = (Expr *)automate.popSymbole();
        automate.popAndDeleteSymbole();
        automate.reduction(e, 3);
        break;
    }

    default:
        automate.errorDetected();
        break;
    }
    return false;
}
