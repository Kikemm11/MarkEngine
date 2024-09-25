%{
#include "token.h"
%}


TEXT       [a-zA-Z0-9 \n\t+¿\?&¡!\"]+
LINEBREAK  \n
SPACE      [\t ]+
UNDEFINED  .


%%

"paragraph"       { return TOKEN_PARAGRAPH; }
"title"           {return TOKEN_TITLE; }
"date"             {return TOKEN_DATE; }
"subtitle"        {return TOKEN_SUBTITLE; }
"heading"         {return TOKEN_HEADING; }
"chapter"          {return TOKEN_CHAPTER; }
"abstract"         {return TOKEN_ABSTRACT; }
"author"           {return TOKEN_AUTHOR; }
"list"             {return TOKEN_LIST; }
"link"             {return TOKEN_LINK; }
"font"             {return TOKEN_FONT; }
"table"            {return TOKEN_TABLE; }
"diagram"          {return TOKEN_DIAGRAM; }


{TEXT}             { return TOKEN_TEXT; }
":"                { return TOKEN_DEF; }
"<"                { return TOKEN_L_TAG; }
">"                { return TOKEN_R_TAG; }
"("                { return TOKEN_L_PAREN; }
")"                { return TOKEN_R_PAREN; }
"{"                { return TOKEN_L_BRACE; }
"}"                { return TOKEN_R_BRACE; }
"."                { return TOKEN_DOT; }
","                { return TOKEN_COMMA; }
"@"                { return TOKEN_AT; }
"_"                { return TOKEN_UNDERSCORE; }
"-"                { return TOKEN_HYPHEN; }
"/"                { return TOKEN_SLASH; }
"*"                { return TOKEN_WILDCARD; }
"~"                { return TOKEN_WAVE; }
"\\"               { return TOKEN_SCAPE; }

{UNDEFINED}  { printf("Unexpected token '%s'",yytext); }

%%

int yywrap() { return 1; }

