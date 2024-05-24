#include <iostream>
#include "tokens.h"

int parse_expression(char* stream) {
    int token = get_token(stream);
    if (token == T_IDENT || token == T_INT || token == T_STRING) {
        // Operand parsing
        std::cout << "Operand: ";
        while (token == T_IDENT || token == T_INT || token == T_STRING) {
            std::cout << *stream; // Output the operand
            stream++;
            token = get_token(stream);
        }
        std::cout << std::endl;
        return 1; // Success
    } else if (token == T_LPAREN) {
        // Handle expression within parentheses
        std::cout << "Expression: ";
        std::cout << "(";
        stream++; // Move past '('
        token = get_token(stream);
        while (token != T_RPAREN && token != T_EOF) {
            if (!parse_expression(stream)) {
                return 0; // Failed to parse sub-expression
            }
            stream++; // Skip parsed tokens
            token = get_token(stream);
        }
        if (token == T_RPAREN) {
            std::cout << ")"; // Closing parenthesis
            std::cout << std::endl;
        } else {
            std::cerr << "Error: Expected ')' but found EOF" << std::endl;
            return 0; // Failure
        }
    } else {
        std::cerr << "Error: Expected operand or '(' but found unknown token" << std::endl;
        return 0; // Failure
    }
    return 1; // Success
}
