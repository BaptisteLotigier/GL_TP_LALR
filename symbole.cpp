#include "symbole.h"
#include <iostream>

void symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   symbole::Affiche();
   cout<<"("<<valeur<<")";
}

