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
%token TOKEN_NUMBER
%token TOKEN_IMG_PATH
%token TOKEN_COMMA
%token TOKEN_AT
%token TOKEN_UNDERSCORE
%token TOKEN_HYPHEN
%token TOKEN_SLASH
%token TOKEN_WILDCARD
%token TOKEN_WAVE
%token TOKEN_SCAPE


%%

program : expr_list
        |
        ;

expr_list : expr
          | expr_list expr
          ;

expr : title
     | author
     | date
     | subtitle
     | chapter
     | abstract
     | index
     | paragraph
     | list
     | table
     | diagram
     | image
     | quote
     | foot
     ;

title : TOKEN_AT TOKEN_TITLE TOKEN_DEF text_list;

author : TOKEN_AT TOKEN_AUTHOR TOKEN_DEF text_list; 

date : TOKEN_AT TOKEN_DATE TOKEN_DEF TOKEN_NUMBER TOKEN_HYPHEN TOKEN_NUMBER TOKEN_HYPHEN TOKEN_NUMBER;

subtitle : TOKEN_AT TOKEN_SUBTITLE TOKEN_DEF text_list; 

chapter : TOKEN_AT TOKEN_CHAPTER TOKEN_DEF text_list;

abstract : TOKEN_AT TOKEN_ABSTRACT TOKEN_DEF text_list; 

index : TOKEN_AT TOKEN_INDEX TOKEN_DEF;

paragraph : TOKEN_AT TOKEN_PARAGRAPH TOKEN_DEF text_list; 

list : TOKEN_AT TOKEN_LIST TOKEN_DEF text_list;

image : TOKEN_AT TOKEN_IMG TOKEN_DEF TOKEN_IMG_PATH; 

quote : TOKEN_AT TOKEN_QUOTE TOKEN_DEF TOKEN_L_BRACE text_list TOKEN_SLASH text_list TOKEN_SLASH text_list TOKEN_R_BRACE; 

foot : TOKEN_AT TOKEN_FOOT TOKEN_DEF text_list;

table : TOKEN_AT TOKEN_TABLE TOKEN_DEF TOKEN_L_TAG text_list TOKEN_R_TAG rows TOKEN_AT;

diagram : TOKEN_AT TOKEN_DIAGRAM TOKEN_DEF items TOKEN_AT



text_list : text
     | text_list text
     ;

text : TOKEN_TEXT
     | bold
     | italic
     | underline
     ;

bold : TOKEN_WILDCARD TOKEN_TEXT TOKEN_WILDCARD;

italic : TOKEN_UNDERSCORE TOKEN_TEXT TOKEN_UNDERSCORE;

underline : TOKEN_WAVE TOKEN_TEXT TOKEN_WAVE;



rows : row 
     | rows row
     ;

row : TOKEN_L_PAREN text TOKEN_R_PAREN;



items : item
      | items item
      ;  

item : text TOKEN_HYPHEN TOKEN_R_TAG text TOKEN_L_PAREN text TOKEN_R_PAREN
     | text TOKEN_HYPHEN TOKEN_R_TAG text
     ;

%%


int yyerror(const char* s)
{
    printf("Parse error: %s\n", s);
    return 1;
}