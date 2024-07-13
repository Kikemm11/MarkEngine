%{
#include "token.h"
#include <stdio.h>

 int counter = 1;

//Sanitize TOKEN_TEXT removing its single quotes and keep track of the linebreaks inside

void clean_TOKEN_TEXT(char* token, int leng, int* counter)
{
    for (int i = 1; i < leng - 1; ++i)
    {
        if (token[i] == '\n')
        {
            ++(*counter);
        }
        token[i - 1] = token[i];
    }
    token[leng - 2] = '\0';
}

%}

 
TEXT       \'[a-zA-Z0-9 \n\t+¿\?&¡!\"]*\'
IDENTIFIER [a-zA-Z0-9]+
LINEBREAK  \n
SPACE      [\t ]+
UNDEFINED  .

%%

{TEXT}       { clean_TOKEN_TEXT(yytext, yyleng, &counter);
               return TOKEN_TEXT; 
             }
{IDENTIFIER} { return TOKEN_IDENTIFIER; }
{LINEBREAK}  { ++counter;}
{SPACE}      {}
":"          { return TOKEN_DEF; }
"<"          { return TOKEN_L_TAG; }
">"          { return TOKEN_R_TAG; }
"("          { return TOKEN_L_PAREN; }
")"          { return TOKEN_R_PAREN; }
"{"          { return TOKEN_L_BRACE; }
"}"          { return TOKEN_R_BRACE; }
"."          { return TOKEN_DOT; }
","          { return TOKEN_COMMA; }
"@"          { return TOKEN_AT; }
"_"          { return TOKEN_UNDERSCORE; }
"-"          { return TOKEN_HYPHEN; }
"/"          { return TOKEN_SLASH; }
"*"          { return TOKEN_WILDCARD; }
"~"          { return TOKEN_WAVE; }
"\\"         { return TOKEN_SCAPE; }
{UNDEFINED}  { printf("Unexpected token '%s' at line: %d\n",yytext, counter); }

%%

int yywrap() { return 1; }