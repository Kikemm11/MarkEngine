%{
/*
Authors:
- Iván Maldonado (Kikemaldonado11@gmail.com)
- Maria José Vera (nandadevi97816@gmail.com)

Developed at: November 2024
*/

#include "token.h"
%}

NUMBER      [0-9]+
IMG_PATH   [a-zA-Z0-9_/]+\.[a-z]+
DATE_FORMAT [0-9]{2}-[0-9]{2}-[0-9]{4} 
BOLD_TEXT   \*[a-zA-Z0-9 +¿?&¡!".;]+\*
ITALIC_TEXT _[a-zA-Z0-9 +¿?&¡!".;]+_
UNDERLINE_TEXT ~[a-zA-Z0-9 +¿?&¡!".;]+~
TEXT        [a-zA-Z0-9+¿?&¡!".;]{1}[a-zA-Z0-9 +¿?&¡!".;]*
LINEBREAK   [\n\r]+
SPACE       [\t ]+
UNDEFINED   .


%%

"@paragraph:"       { return TOKEN_PARAGRAPH; }
"@title:"            {return TOKEN_TITLE; }
"@date:"             {return TOKEN_DATE; }
"@subtitle:"         {return TOKEN_SUBTITLE; }
"@chapter:"          {return TOKEN_CHAPTER; }
"@abstract:"         {return TOKEN_ABSTRACT; }
"@author:"           {return TOKEN_AUTHOR; }
"@list:"             {return TOKEN_LIST; }
"@link:"             {return TOKEN_LINK; }
"@font:"             {return TOKEN_FONT; }
"@table:"            {return TOKEN_TABLE; }
"@diagram:"          {return TOKEN_DIAGRAM; }
"@index:"            {return TOKEN_INDEX; }
"@img:"              {return TOKEN_IMG; }
"@quote:"            {return TOKEN_QUOTE; }
"@foot:"             {return TOKEN_FOOT; }
"@linebreak"         {return TOKEN_LINEBREAK; }   
"@new_page:"         {return TOKEN_NEW_PAGE; }
"\\\\"              {return TOKEN_ENTER; }
{DATE_FORMAT}       {return TOKEN_DATE_FORMAT; }

{LINEBREAK}        {}
{SPACE}            {}
{NUMBER}           { return TOKEN_NUMBER; }
{IMG_PATH}         { return TOKEN_IMG_PATH;}
"@"                 { return TOKEN_AT; }
","                { return TOKEN_COMMA; }
":"                { return TOKEN_DEF; }
"<"                { return TOKEN_L_TAG; }
">"                { return TOKEN_R_TAG; }
"("                { return TOKEN_L_PAREN; }
")"                { return TOKEN_R_PAREN; }
"{"                { return TOKEN_L_BRACE; }
"}"                { return TOKEN_R_BRACE; }
"_"                { return TOKEN_UNDERSCORE; }
"-"                { return TOKEN_HYPHEN; }
"/"                { return TOKEN_SLASH; }
"*"                { return TOKEN_WILDCARD; }
"~"                { return TOKEN_WAVE; }

{BOLD_TEXT}        { return TOKEN_BOLD_TEXT; }
{ITALIC_TEXT}      { return TOKEN_ITALIC_TEXT; }
{UNDERLINE_TEXT}   { return TOKEN_UNDERLINE_TEXT; }
{TEXT}             { return TOKEN_TEXT; }

{UNDEFINED}  { printf("Unexpected token '%s'\n",yytext); }

%%

int yywrap() { return 1; }