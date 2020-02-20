#include "Symbole.h"
#include "Lexer.h"
#include "Automate.h"

#include <iostream>
#include <stack>

int main(int argc, char const *argv[])
{
    std::string m = "1*2";

    Lexer *l = new Lexer(m);

    Automate a(l);

    std::cout << a.start() << std::endl;

    return 0;
}
