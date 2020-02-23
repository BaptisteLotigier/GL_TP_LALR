#include "Lexer.h"
#include "Automate.h"

#include <iostream>

int main(void)
{
   std::string chaine;

   std::cout << "Enter expression to analyse : ";
   std::cin >> chaine;

   Automate a(new Lexer(chaine));
   a.start();

   return 0;
}