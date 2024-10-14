#pragma once

//Def token types

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
    TOKEN_NUMBER = 266,
    TOKEN_COMMA = 267,
    TOKEN_AT = 268,
    TOKEN_UNDERSCORE = 269,
    TOKEN_HYPHEN = 270,
    TOKEN_SLASH = 271,
    TOKEN_WILDCARD = 272,
    TOKEN_WAVE = 273,
    TOKEN_SCAPE = 274,
    TOKEN_PARAGRAPH = 275,
    TOKEN_TITLE = 276,
    TOKEN_DATE = 277,
    TOKEN_SUBTITLE = 278,
    TOKEN_CHAPTER = 279,
    TOKEN_ABSTRACT = 280,
    TOKEN_AUTHOR = 281,
    TOKEN_LIST = 282,
    TOKEN_LINK = 283,
    TOKEN_FONT = 284,
    TOKEN_TABLE = 285,
    TOKEN_DIAGRAM = 286,
    TOKEN_INDEX = 287,
    TOKEN_IMG = 288,
    TOKEN_QUOTE = 289,
    TOKEN_FOOT = 290,
    TOKEN_ENTER = 291,
    TOKEN_DATE_FORMAT = 292,
    TOKEN_LINEBREAK = 293,
    TOKEN_IMG_PATH = 294,
    TOKEN_UNDEFINED = 295
    }
token_t;


//Turn TOKEN into string

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
        case TOKEN_DIAGRAM: return "DIAGRAM";
        case TOKEN_INDEX: return "INDEX";
        case TOKEN_IMG: return "IMG";
        case TOKEN_QUOTE: return "QUOTE";
        case TOKEN_ENTER: return "ENTER";
        case TOKEN_DATE_FORMAT: return "DATE_FORMAT";
        case TOKEN_LINEBREAK: return "LINEBREAK";
        case TOKEN_FOOT: return "FOOT";
        case TOKEN_IMG_PATH: return "IMG_PATH";
    }
}