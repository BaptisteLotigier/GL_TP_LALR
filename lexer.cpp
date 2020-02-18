#include "lexer.h"

symbole * Lexer::Consulter() {
   if (!tampon) {

      if (tete==flux.length())
         tampon = new symbole(FIN);
      else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new symbole(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new symbole(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new symbole(MULT);
               tete++;
               break;
            case '+':
               tampon = new symbole(PLUS);
               tete++;
               break;
            default:
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new Entier(resultat);
               }
               else {
                  tampon = new symbole(ERREUR);
               }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer() {
   tampon = nullptr;
}

