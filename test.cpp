#include <iostream>
#include "tokens.h"

int main() {
    char input[100];

    while (std::cin.getline(input, 100)) {
        char* stream = input;
        int token;
        while ((token = get_token(stream)) != T_EOF) {
            switch (token) {
                case T_IDENT:
                    std::cout << "Identifier" << std::endl;
                    break;
                case T_INT:
                    std::cout << "Integer literal" << std::endl;
                    break;
                case T_LPAREN: case T_RPAREN: case T_SEMI: case T_ASSIGN:
                case T_PLUS: case T_MINUS:
                    std::cout << *stream << std::endl; // Print the Symbol
                    break;
                case T_ERROR:
                    std::cerr << "Error: Unexpected character '" << *stream << "' at line X" << std::endl; // Replace X with line number
                    break;
            }
            stream++;
        }
    }

    return 0;
}
