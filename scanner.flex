%{
#include "token.h"
#include <stdio.h>

int counter = 0;
%}

LINEBREAK  \n
SPACE      [\t ]+ 
TEXT       \'[a-zA-Z0-9 \n\t+¿\?&¡!\"]+\'
IDENTIFIER [a-zA-Z0-9 ]+
UNDEFINED  .

%%

{TEXT}       { return TOKEN_TEXT; }
{IDENTIFIER} {return TOKEN_IDENTIFIER;}
{LINEBREAK}  {++counter;}
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
{UNDEFINED}  {  printf("Unexpected token at line: %d", counter);
                return TOKEN_UNDEFINED; }


%%

int yywrap() { return 1; }