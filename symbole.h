#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class symbole {
   public:
      symbole(int i) : ident(i) {  }
      virtual ~symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      bool isTerminal() {return ident != EXPR; }

   protected:
      int ident;
};

class Entier : public symbole {
   public:
      Entier(int v) : symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};

class Expr : public symbole {
   public:
      Expr() : symbole(EXPR) {};
      virtual ~Expr();
      virtual int eval();
};

class Nombre : public Expr {
   public:
      Nombre(int val) : Expr(), val(val) {};
      virtual ~Nombre();
      int eval() {return val;};

   protected:
      int val;
};

class ExprPlus : public Expr {
   public:
      ExprPlus(Expr lExpr, Expr rExpr) : Expr(), lExpr(lExpr), rExpr(rExpr) {};
      virtual ~ExprPlus();
      int eval() {return lExpr.eval() + rExpr.eval();};

   protected:
      Expr lExpr;
      Expr rExpr;
};

class ExprMult : public Expr {
   public:
      ExprMult(Expr lExpr, Expr rExpr) : Expr(), lExpr(lExpr), rExpr(rExpr) {};
      virtual ~ExprMult();
      int eval() {return lExpr.eval() * rExpr.eval();};

   protected:
      Expr lExpr;
      Expr rExpr;
};