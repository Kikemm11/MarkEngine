/*
Authors:
- Iván Maldonado (Kikemaldonado11@gmail.com)
- Maria José Vera (nandadevi97816@gmail.com)

Developed at: November 2024
*/

#pragma once

//Def token types

typedef enum
{
    TOKEN_EOF = 0,
    TOKEN_TEXT = 258,
    TOKEN_BOLD_TEXT = 259,
    TOKEN_ITALIC_TEXT = 260,
    TOKEN_UNDERLINE_TEXT = 261,
    TOKEN_DEF = 262,
    TOKEN_L_TAG = 263,
    TOKEN_R_TAG = 264,
    TOKEN_L_PAREN = 265,
    TOKEN_R_PAREN = 266,
    TOKEN_L_BRACE = 267,
    TOKEN_R_BRACE = 268,
    TOKEN_NUMBER = 269,
    TOKEN_COMMA = 270,
    TOKEN_AT = 271,
    TOKEN_UNDERSCORE = 272,
    TOKEN_HYPHEN = 273,
    TOKEN_SLASH = 274,
    TOKEN_WILDCARD = 275,
    TOKEN_WAVE = 276,
    TOKEN_SCAPE = 277,
    TOKEN_PARAGRAPH = 278,
    TOKEN_TITLE = 279,
    TOKEN_DATE = 280,
    TOKEN_SUBTITLE = 281,
    TOKEN_CHAPTER = 282,
    TOKEN_ABSTRACT = 283,
    TOKEN_AUTHOR = 284,
    TOKEN_LIST = 285,
    TOKEN_LINK = 286,
    TOKEN_FONT = 287,
    TOKEN_TABLE = 288,
    TOKEN_INDEX = 289,
    TOKEN_IMG = 290,
    TOKEN_QUOTE = 291,
    TOKEN_FOOT = 292,
    TOKEN_ENTER = 293,
    TOKEN_DATE_FORMAT = 294,
    TOKEN_LINEBREAK = 295,
    TOKEN_IMG_PATH = 296,
    TOKEN_NEW_PAGE = 297,
    TOKEN_BEGIN = 298,
    TOKEN_END = 299,
    TOKEN_UNDEFINED = 300
    }
token_t;


//Turn TOKEN into string

inline const char* to_str(token_t t)
{
    switch (t)
    {
        case TOKEN_TEXT: return "TEXT";
        case TOKEN_BOLD_TEXT: return "BOLD_TEXT";
        case TOKEN_ITALIC_TEXT: return "ITALIC_TEXT";
        case TOKEN_UNDERLINE_TEXT: return "UNDRLINE_TEXT";
        case TOKEN_DEF: return "DEF";
        case TOKEN_L_TAG: return "L_TAG";
        case TOKEN_R_TAG: return "R_TAG";
        case TOKEN_L_PAREN: return "L_PAREN";
        case TOKEN_R_PAREN: return "R_PAREN";
        case TOKEN_L_BRACE: return "L_BRACE";
        case TOKEN_R_BRACE: return "R_BRACE";
        case TOKEN_NUMBER: return "NUMBER";
        case TOKEN_COMMA: return "COMMA";
        case TOKEN_AT: return "AT";
        case TOKEN_UNDERSCORE: return "UNDERSCORE";
        case TOKEN_HYPHEN: return "HYPHEN";
        case TOKEN_SLASH: return "SLASH";
        case TOKEN_WAVE: return "WAVE";        
        case TOKEN_WILDCARD: return "WILDCARD";
        case TOKEN_SCAPE: return "SCAPE";
        case TOKEN_PARAGRAPH: return "PARAGRAPH";
        case TOKEN_TITLE: return "TITLE";
        case TOKEN_DATE: return "DATE";
        case TOKEN_SUBTITLE: return "SUBTITLE";
        case TOKEN_CHAPTER: return "CHAPTER";
        case TOKEN_ABSTRACT: return "ABSTRACT";
        case TOKEN_AUTHOR: return "AUTHOR";
        case TOKEN_LIST: return "LIST";
        case TOKEN_LINK: return "LINK";
        case TOKEN_FONT: return "FONT";
        case TOKEN_TABLE: return "TABLE";
        case TOKEN_INDEX: return "INDEX";
        case TOKEN_IMG: return "IMG";
        case TOKEN_QUOTE: return "QUOTE";
        case TOKEN_ENTER: return "ENTER";
        case TOKEN_DATE_FORMAT: return "DATE_FORMAT";
        case TOKEN_LINEBREAK: return "LINEBREAK";
        case TOKEN_FOOT: return "FOOT";
        case TOKEN_IMG_PATH: return "IMG_PATH";
        case TOKEN_NEW_PAGE: return "NEW_PAGE";
        case TOKEN_BEGIN: return "BEGIN";
        case TOKEN_END: return "END";
    }
}