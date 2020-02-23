#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(1+2)*((3+4)*5)");

   // Lexer l(chaine);

   // Symbole * s;
   // while(*(s=l.Consulter())!=FIN) {
   //    s->Affiche();
   //    cout<<endl;
   //    l.Avancer();
   // }

   Automate a(new Lexer(chaine));
   a.start();
   a.printStack();

   return 0;
}