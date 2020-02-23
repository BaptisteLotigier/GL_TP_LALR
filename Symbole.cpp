#include "Symbole.h"
#include <iostream>

void Symbole::Affiche()
{
   std::cout << Etiquettes[ident];
}

void Entier::Affiche()
{
   Symbole::Affiche();
   std::cout << "(" << valeur << ")";
}
