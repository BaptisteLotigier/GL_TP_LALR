#pragma once

#include <string>

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const std::string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

class Symbole
{
public:
   Symbole(int i) : ident(i), terminal(true) {}
   Symbole(int i, bool terminal) : ident(i), terminal(terminal) {}
   virtual ~Symbole() {}
   operator int() const { return ident; }
   virtual bool isTerminal() { return terminal; }
   virtual void Affiche();

protected:
   int ident;
   bool terminal;
};

class Entier : public Symbole
{
public:
   Entier(int v) : Symbole(INT, true), valeur(v) {}
   virtual ~Entier() {}
   virtual void Affiche();
   int getValeur() { return valeur; }

protected:
   int valeur;
};

class Expr : public Symbole
{
public:
   Expr() : Symbole(EXPR, false) {}
   virtual ~Expr() {}
   virtual int eval() = 0;
};

class ExprPlus : public Expr
{
public:
   ExprPlus(Expr* lExpr, Expr* rExpr) : lExpr(lExpr), rExpr(rExpr) {}
   virtual ~ExprPlus() { delete(lExpr); delete(rExpr); }
   int eval() { return lExpr->eval() + rExpr->eval(); }

protected:
   Expr* lExpr;
   Expr* rExpr;
};

class ExprMult : public Expr
{
public:
   ExprMult(Expr* lExpr, Expr* rExpr) : lExpr(lExpr), rExpr(rExpr) {}
   virtual ~ExprMult() { delete(lExpr); delete(rExpr); }
   int eval() { return lExpr->eval() * rExpr->eval(); }

protected:
   Expr* lExpr;
   Expr* rExpr;
};

class Number : public Expr
{
public:
   Number(int value) : value(value) {}
   virtual ~Number() {}
   int eval() { return value; }

protected:
   int value;
};