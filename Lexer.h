#pragma once

#include <string>
#include "Symbole.h"

class Lexer {

   public:
      Lexer(std::string s);
      virtual ~Lexer();

      Symbole* Consulter();
      void Avancer();

   protected:
      std::string flux;
      int tete;
      Symbole* tampon;
};
