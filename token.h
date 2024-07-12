#pragma once

typedef enum
{
    TOKEN_EOF = 0,
    TOKEN_TEXT = 258,
    TOKEN_DEF = 259,
    TOKEN_L_TAG = 260,
    TOKEN_R_TAG = 261,
    TOKEN_L_PAREN = 262,
    TOKEN_R_PAREN = 263,
    TOKEN_L_BRACE = 264,
    TOKEN_R_BRACE = 265,
    TOKEN_DOT = 266,
    TOKEN_COMMA = 267,
    TOKEN_AT = 268,
    TOKEN_UNDERSCORE = 269,
    TOKEN_HYPHEN = 270,
    TOKEN_SLASH = 271,
    TOKEN_WILDCARD = 272,
    TOKEN_IDENTIFIER = 273,
    TOKEN_WAVE = 274,
    TOKEN_SCAPE = 275,
    TOKEN_UNDEFINED = 276
    }
token_t;

inline const char* to_str(token_t t)
{
    switch (t)
    {
        case TOKEN_TEXT: return "TEXT";
        case TOKEN_DEF: return "DEF";
        case TOKEN_L_TAG: return "L_TAG";
        case TOKEN_R_TAG: return "R_TAG";
        case TOKEN_L_PAREN: return "L_PAREN";
        case TOKEN_R_PAREN: return "R_PAREN";
        case TOKEN_L_BRACE: return "L_BRACE";
        case TOKEN_R_BRACE: return "R_BRACE";
        case TOKEN_DOT: return "DOT";
        case TOKEN_COMMA: return "COMMA";
        case TOKEN_AT: return "AT";
        case TOKEN_UNDERSCORE: return "UNDERSCORE";
        case TOKEN_HYPHEN: return "HYPHEN";
        case TOKEN_SLASH: return "SLASH";
        case TOKEN_WAVE: return "WAVE";
        case TOKEN_WILDCARD: return "WILDCARD";
        case TOKEN_SCAPE: return "SCAPE";
        case TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
    }
}
