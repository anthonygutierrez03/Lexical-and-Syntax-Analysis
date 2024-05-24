#include <cctype>
#include "tokens.h"

int get_token(char* &stream) {
    // Skip whitespace and comments
    while (*stream) {
        if (isspace(*stream)) {
            stream++; // Skip whitespace
        } else if (*stream == '/' && (*(stream + 1) == '*' || *(stream + 1) == '/')) {
            // Multi-line and single-line comments handling
            if (*(stream + 1) == '*') {
                stream += 2; // Skip '/*'
                while (*stream && !(*stream == '*' && *(stream + 1) == '/')) {
                    stream++;
                }
                if (*stream) {
                    stream += 2; // Skip '*/'
                }
            } else {
                stream += 2; // Skip '//'
                while (*stream && *stream != '\n') {
                    stream++; // End of single-line comment
                }
            }
        } else {
            break; // Not whitespace or comment, proceed with tokenizing
        }
    }

    // Check for end of file
    if (*stream == '\0') {
        return T_EOF;
    }

    // Identify token type
    switch (*stream) {
        case '(':
            stream++;
            return T_LPAREN;
        case ')':
            stream++;
            return T_RPAREN;
        case '{':
            stream++;
            return T_LBRACE;
        case '}':
            stream++;
            return T_RBRACE;
        case ';':
            stream++;
            return T_SEMI;
        case '=':
            stream++;
            return T_ASSIGN;
        case '+':
            stream++;
            return T_PLUS;
        case '-':
            stream++;
            return T_MINUS;
        case '<':
            stream++;
            return T_LT;
        case '>':
            stream++;
            return T_GT;
        case '"':  // Handle string literals
            stream++; // Skip opening quote
            while (*stream && *stream != '"') {
                stream++; // Go to closing quote
            }
            if (*stream) {
                stream++; // Skip closing quote
            }
            return T_STRING;
        case '#':  // Handle directives (like `#include`)
            stream++;
            return T_DIRECTIVE;
        default:
            if (isalpha(*stream)) {
                while (isalnum(*stream) || *stream == '_') {
                    stream++;
                }
                return T_IDENT;
            } else if (isdigit(*stream)) {
                while (isdigit(*stream)) {
                    stream++;
                }
                return T_INT;
            } else {
                return T_ERROR; // Unknown character
            }
    }
}
