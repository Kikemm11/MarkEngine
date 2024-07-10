%{
#include "token.h"
%}

TEXT       [a-zA-Z0-9 \t\n+¿\?&¡!]+
UNDEFINED  .

%%
{TEXT}       { return TOKEN_TEXT; }
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
"\""         { return TOKEN_QUOTATION_MARK; }
"~"          { return TOKEN_WAVE; }
"\\"         { return TOKEN_SCAPE; }
{UNDEFINED}  { return TOKEN_UNDEFINED; }


%%

int yywrap() { return 1; }