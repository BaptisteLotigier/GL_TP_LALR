#pragma once

#include <string>

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const std::string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole
{
    public:
        Symbole(int id, bool terminal);
        Symbole(int id);
        virtual ~Symbole();
        bool isTerminal();
        void Affiche();
        int getIdent();

    protected:
        int ident;
        bool terminal;
};

class Expr : public Symbole
{
    public:
        Expr(int id, bool terminal);
        virtual ~Expr();
        virtual int eval() = 0;
};

class ExprPlus : public Expr
{
    public:
        ExprPlus(Expr* lExpr, Expr* rExpr);
        virtual ~ExprPlus();
        int eval();

    protected:
        Expr* lExpr;
        Expr* rExpr;
};

class ExprMult : public Expr
{
    public:
        ExprMult(Expr* lExpr, Expr* rExpr);
        virtual ~ExprMult();
        int eval();

    protected:
        Expr* lExpr;
        Expr* rExpr;
};

class Entier : public Expr
{
    public:
        Entier(int value);
        virtual ~Entier();
        int eval();

    protected:
        int value;
};