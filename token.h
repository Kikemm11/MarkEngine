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
    TOKEN_DOT = 266,
    TOKEN_COMMA = 267,
    TOKEN_AT = 268,
    TOKEN_UNDERSCORE = 269,
    TOKEN_HYPHEN = 270,
    TOKEN_SLASH = 271,
    TOKEN_WILDCARD = 272,
    TOKEN_WAVE = 273,
    TOKEN_SCAPE = 274,
    TOKEN_PARAGRAPH = 275,
    TOKEN_TITLES = 276,
    TOKEN_DATE = 277,
    TOKEN_SUBTITLES = 278,
    TOKEN_HEADINGS = 279, 
    TOKEN_CHAPTER = 280,
    TOKEN_ABSTRACT = 281,
    TOKEN_AUTHOR = 282,
    TOKEN_LIST = 283,
    TOKEN_LINK = 284,
    TOKEN_FONT = 285,
    TOKEN_TABLE = 286,
    TOKEN_DIAGRAM = 287,
    TOKEN_UNDEFINED = 288
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