/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKEN_H_INCLUDED
# define YY_YY_TOKEN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_PARAGRAPH = 258,         /* TOKEN_PARAGRAPH  */
    TOKEN_TITLE = 259,             /* TOKEN_TITLE  */
    TOKEN_DATE = 260,              /* TOKEN_DATE  */
    TOKEN_SUBTITLE = 261,          /* TOKEN_SUBTITLE  */
    TOKEN_CHAPTER = 262,           /* TOKEN_CHAPTER  */
    TOKEN_ABSTRACT = 263,          /* TOKEN_ABSTRACT  */
    TOKEN_AUTHOR = 264,            /* TOKEN_AUTHOR  */
    TOKEN_LIST = 265,              /* TOKEN_LIST  */
    TOKEN_LINK = 266,              /* TOKEN_LINK  */
    TOKEN_FONT = 267,              /* TOKEN_FONT  */
    TOKEN_TABLE = 268,             /* TOKEN_TABLE  */
    TOKEN_DIAGRAM = 269,           /* TOKEN_DIAGRAM  */
    TOKEN_INDEX = 270,             /* TOKEN_INDEX  */
    TOKEN_IMG = 271,               /* TOKEN_IMG  */
    TOKEN_QUOTE = 272,             /* TOKEN_QUOTE  */
    TOKEN_FOOT = 273,              /* TOKEN_FOOT  */
    TOKEN_TEXT = 274,              /* TOKEN_TEXT  */
    TOKEN_DEF = 275,               /* TOKEN_DEF  */
    TOKEN_L_TAG = 276,             /* TOKEN_L_TAG  */
    TOKEN_R_TAG = 277,             /* TOKEN_R_TAG  */
    TOKEN_L_PAREN = 278,           /* TOKEN_L_PAREN  */
    TOKEN_R_PAREN = 279,           /* TOKEN_R_PAREN  */
    TOKEN_L_BRACE = 280,           /* TOKEN_L_BRACE  */
    TOKEN_R_BRACE = 281,           /* TOKEN_R_BRACE  */
    TOKEN_NUMBER = 282,            /* TOKEN_NUMBER  */
    TOKEN_IMG_PATH = 283,          /* TOKEN_IMG_PATH  */
    TOKEN_COMMA = 284,             /* TOKEN_COMMA  */
    TOKEN_AT = 285,                /* TOKEN_AT  */
    TOKEN_UNDERSCORE = 286,        /* TOKEN_UNDERSCORE  */
    TOKEN_HYPHEN = 287,            /* TOKEN_HYPHEN  */
    TOKEN_SLASH = 288,             /* TOKEN_SLASH  */
    TOKEN_WILDCARD = 289,          /* TOKEN_WILDCARD  */
    TOKEN_WAVE = 290,              /* TOKEN_WAVE  */
    TOKEN_ENTER = 291,             /* TOKEN_ENTER  */
    TOKEN_LINEBREAK = 292,         /* TOKEN_LINEBREAK  */
    TOKEN_DATE_FORMAT = 293        /* TOKEN_DATE_FORMAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKEN_H_INCLUDED  */
