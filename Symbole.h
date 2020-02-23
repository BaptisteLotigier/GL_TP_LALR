#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {}
      virtual ~Symbole() {}
      operator int() const { return ident; }
      virtual bool isTerminal() { return true; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v, bool isExpr) : Symbole(INT), valeur(v), isExpr(isExpr) {}
      ~Entier() {}
      virtual bool isTerminal() { return !isExpr; }
      virtual void Affiche();
      int getValeur() { return valeur; }
      void setIsExpr(bool newIsExper) { isExpr=newIsExper;}
   protected:
      int valeur;
      bool isExpr;
};
