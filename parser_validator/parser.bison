%{
/*
Authors:
- Iván Maldonado (Kikemaldonado11@gmail.com)
- Maria José Vera (nandadevi97816@gmail.com)

Developed at: November 2024
*/

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
%token TOKEN_BOLD_TEXT
%token TOKEN_ITALIC_TEXT
%token TOKEN_UNDERLINE_TEXT   
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
%token TOKEN_ENTER
%token TOKEN_LINEBREAK
%token TOKEN_DATE_FORMAT
%token TOKEN_NEW_PAGE
%token TOKEN_BEGIN
%token TOKEN_END


%%

program : head TOKEN_BEGIN expr_list TOKEN_END
        |
        ;

head : title author date
     ;

expr_list : expr
          | expr_list expr
          ;

expr : subtitle
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
     | linebreak
     | new_page
     ;

title : TOKEN_TITLE text_list;

author : TOKEN_AUTHOR text_list; 

date : TOKEN_DATE TOKEN_DATE_FORMAT;

subtitle : TOKEN_SUBTITLE text_list; 

chapter : TOKEN_CHAPTER text_list;

abstract : TOKEN_ABSTRACT text_list; 

index : TOKEN_INDEX;

paragraph : TOKEN_PARAGRAPH text_list; 

list : TOKEN_LIST text_list;

image : TOKEN_IMG TOKEN_IMG_PATH; 

quote : TOKEN_QUOTE TOKEN_L_BRACE text_list TOKEN_SLASH text_list TOKEN_SLASH TOKEN_NUMBER TOKEN_R_BRACE; 

foot : TOKEN_FOOT text_list;

table : TOKEN_TABLE TOKEN_L_TAG text_list TOKEN_R_TAG rows TOKEN_AT;

diagram : TOKEN_DIAGRAM items TOKEN_AT; 

linebreak : TOKEN_LINEBREAK TOKEN_L_PAREN number TOKEN_R_PAREN;

new_page : TOKEN_NEW_PAGE;



text_list : text
     | text_list text
     ;

text : TOKEN_TEXT
     | TOKEN_ENTER
     | TOKEN_AT
     | TOKEN_COMMA
     | TOKEN_DEF
     | TOKEN_BOLD_TEXT 
     | TOKEN_ITALIC_TEXT
     | TOKEN_UNDERLINE_TEXT
     ;


number : TOKEN_NUMBER;


rows : row 
     | rows row
     ;

row : TOKEN_L_PAREN text_list TOKEN_R_PAREN;



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