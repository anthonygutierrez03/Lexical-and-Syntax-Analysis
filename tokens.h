#ifndef TOKENS_H
#define TOKENS_H

// Token definitions for various symbols and operators
enum {
    T_EOF,        // End of file
    T_IDENT,      // Identifier (variable, function, etc.)
    T_INT,        // Integer literal
    T_STRING,     // String literal
    T_CHARCON,    // Character constant (like 'a')
    T_ASSIGN,     // Assignment operator (=)
    T_PLUS,       // Plus (+)
    T_MINUS,      // Minus (-)
    T_MULT,       // Multiplication (*)
    T_DIV,        // Division (/)
    T_SEMI,       // Semicolon (;)
    T_LPAREN,     // Left parenthesis (()
    T_RPAREN,     // Right parenthesis ())
    T_LBRACE,     // Left brace ({)
    T_RBRACE,     // Right brace (})
    T_LT,         // Less than (<)
    T_GT,         // Greater than (>)
    T_DIRECTIVE,  // Directives (like `#include`)
    T_ERROR       // Unknown or invalid token
};

int get_token(char* &stream);

#endif // TOKENS_H

