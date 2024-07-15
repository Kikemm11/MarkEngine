%{
#include "token.h"
#include <stdio.h>

 int counter = 1;

//Sanitize TOKEN_TEXT removing its single quotes and keep track of the linebreaks inside



%}


TEXT       [a-zA-Z0-9 \n\t+¿\?&¡!\"]*
PARAMETER [a-zA-Z0-9]+
LINEBREAK  \n
SPACE      [\t ]+
UNDEFINED  .


%%

"paragraphs"       { return TOKEN_PARAGRAPH; }
"titles"           {return TOKEN_TITLES; }
"date"             {return TOKEN_DATE; }
"subtitles"        {return TOKEN_SUBTITLES; }
"headings"         {return TOKEN_HEADINGS; }
"chapter"          {return TOKEN_CHAPTER; }
"abstract"         {return TOKEN_ABSTRACT; }
"author"           {return TOKEN_AUTHOR; }
"list"             {return TOKEN_LIST; }
"link"             {return TOKEN_LINK; }
"font"             {return TOKEN_FONT; }
"table"            {return TOKEN_TABLE; }
"diagram"          {return TOKEN_DIAGRAM; }


{PARAMETER}  { return TOKEN_PARAMETER; }
{TEXT}       { 
               return TOKEN_TEXT; 
             }
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

