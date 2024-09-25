%{
#include <stdio.h>

extern int yylex();
int yyerror(const char*);
%}

%token TOKEN_PARAGRAPH
%token TOKEN_TITLE
%token TOKEN_DATE
%token TOKEN_SUBTITLE
%token TOKEN_CHAPTER
%token TOKEN_ABSTRACT
%token TOKEN_AUTHOR
%token TOKEN_LIST
%token TOKEN_LINK
%token TOKEN_FONT
%token TOKEN_TABLE
%token TOKEN_DIAGRAM
%token TOKEN_INDEX 
%token TOKEN_IMG 
%token TOKEN_QUOTE 
%token TOKEN_FOOT    
%token TOKEN_TEXT
%token TOKEN_DEF
%token TOKEN_L_TAG
%token TOKEN_R_TAG
%token TOKEN_L_PAREN
%token TOKEN_R_PAREN
%token TOKEN_L_BRACE
%token TOKEN_R_BRACE
%token TOKEN_COMMA
%token TOKEN_AT
%token TOKEN_UNDERSCORE
%token TOKEN_HYPHEN
%token TOKEN_SLASH
%token TOKEN_WILDCARD
%token TOKEN_WAVE
%token TOKEN_SCAPE


%%
program : expr;

expr : expr expr
     | title
     | author
     | date
     | subtitle
     | chapter
     | abstract
     | index
     | paragraph
     | list
     | image
     | quote
     | foot
     ;

title : TOKEN_AT TOKEN_TITLE TOKEN_DEF TOKEN_TEXT;

author : TOKEN_AT TOKEN_AUTHOR TOKEN_DEF TOKEN_TEXT; 

date : TOKEN_AT TOKEN_DATE TOKEN_DEF TOKEN_TEXT;

subtitle : TOKEN_AT TOKEN_SUBTITLE TOKEN_DEF TOKEN_TEXT; 

chapter : TOKEN_AT TOKEN_CHAPTER TOKEN_DEF TOKEN_TEXT;

abstract : TOKEN_AT TOKEN_ABSTRACT TOKEN_DEF TOKEN_TEXT; 

index : TOKEN_AT TOKEN_INDEX TOKEN_DEF;

paragraph : TOKEN_AT TOKEN_PARAGRAPH TOKEN_DEF TOKEN_TEXT; 

list : TOKEN_AT TOKEN_LIST TOKEN_DEF TOKEN_TEXT;

image : TOKEN_AT TOKEN_IMG TOKEN_DEF TOKEN_TEXT; 

quote : TOKEN_AT TOKEN_QUOTE TOKEN_DEF TOKEN_L_BRACE TOKEN_TEXT TOKEN_COMMA TOKEN_TEXT TOKEN_COMMA TOKEN_TEXT TOKEN_R_BRACE; 

foot : TOKEN_AT TOKEN_FOOT TOKEN_DEF TOKEN_TEXT;

%%


int yyerror(const char* s)
{
    printf("Parse error: %s\n", s);
    return 1;
}