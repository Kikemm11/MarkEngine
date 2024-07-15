#pragma once

//Def token types

typedef enum
{
    TOKEN_EOF = 0,
    TOKEN_TEXT = 258,
    TOKEN_PARAMETER = 259,
    TOKEN_DEF = 260,
    TOKEN_L_TAG = 261,
    TOKEN_R_TAG = 262,
    TOKEN_L_PAREN = 263,
    TOKEN_R_PAREN = 264,
    TOKEN_L_BRACE = 265,
    TOKEN_R_BRACE = 266,
    TOKEN_DOT = 267,
    TOKEN_COMMA = 268,
    TOKEN_AT = 269,
    TOKEN_UNDERSCORE = 270,
    TOKEN_HYPHEN = 271,
    TOKEN_SLASH = 272,
    TOKEN_WILDCARD = 273,
    TOKEN_WAVE = 274,
    TOKEN_SCAPE = 275,
    TOKEN_UNDEFINED = 276,
    TOKEN_PARAGRAPH = 277,
    TOKEN_TITLES = 278,
    TOKEN_DATE = 279,
    TOKEN_SUBTITLES = 280,
    TOKEN_HEADINGS = 281, 
    TOKEN_CHAPTER = 282,
    TOKEN_ABSTRACT = 283,
    TOKEN_AUTHOR = 284,
    TOKEN_LIST = 285,
    TOKEN_LINK = 286,
    TOKEN_FONT = 287,
    TOKEN_TABLE = 288,
    TOKEN_DIAGRAM = 289,
    }
token_t;


//Turn TOKEN into string

inline const char* to_str(token_t t)
{
    switch (t)
    {
        case TOKEN_TEXT: return "TEXT";
        case TOKEN_PARAMETER: return "PARAMETER";
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
        case TOKEN_PARAGRAPH: return "PARAGRAPH";
        case TOKEN_TITLES: return "TITLES";
        case TOKEN_DATE: return "DATE";
        case TOKEN_SUBTITLES: return "SUBTITLES";
        case TOKEN_HEADINGS: return "HEADINGS";
        case TOKEN_CHAPTER: return "CHAPTER";
        case TOKEN_ABSTRACT: return "ABSTRACT";
        case TOKEN_AUTHOR: return "AUTHOR";
        case TOKEN_LIST: return "LIST";
        case TOKEN_LINK: return "LINK";
        case TOKEN_FONT: return "FONT";
        case TOKEN_TABLE: return "TABLE";
        case TOKEN_DIAGRAM: return "DIAGRAM";

    }
}
