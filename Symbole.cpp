#include "Symbole.h"
#include <iostream>

// Symbole definition
Symbole::Symbole(int id, bool terminal)
: ident(id), terminal(terminal)
{}

Symbole::Symbole(int id)
: ident(id), terminal(true)
{}

Symbole::~Symbole()
{}

bool Symbole::isTerminal()
{
    return terminal;
}

void Symbole::Affiche()
{
    std::cout << Etiquettes[ident] << std::endl;
}

int Symbole::getIdent()
{
    return ident;
}

// Expr definition
Expr::Expr(int id, bool terminal)
: Symbole(id, terminal)
{}

Expr::~Expr()
{}

// ExprPlus definition
ExprPlus::ExprPlus(Expr* lExpr, Expr* rExpr)
: Expr(EXPR, false), lExpr(lExpr), rExpr(rExpr)
{}

ExprPlus::~ExprPlus()
{}

int ExprPlus::eval()
{
    return lExpr->eval() + rExpr->eval();
}

// ExprMult definition
ExprMult::ExprMult(Expr* lExpr, Expr* rExpr)
: Expr(EXPR, false), lExpr(lExpr), rExpr(rExpr)
{}

ExprMult::~ExprMult()
{}

int ExprMult::eval()
{
    return lExpr->eval() * rExpr->eval();
}

// Entier definition
Entier::Entier(int value)
: Expr(INT, true),  value(value)
{}

Entier::~Entier()
{}

int Entier::eval()
{
    return value;
}