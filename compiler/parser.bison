%{
/*
Authors:
- Iván Maldonado (Kikemaldonado11@gmail.com)
- Maria José Vera (nandadevi97816@gmail.com)

Developed at: November 2024
*/

#include <stdio.h>
#include <expression.hpp>
#include <string>
#include <vector>

#define YYSTYPE Expression*

extern int yylex();
extern char* yytext;
int yyerror(const char*);

Expression* parser_result{nullptr};
%}

%token TOKEN_PARAGRAPH
%token TOKEN_TITLE
%token TOKEN_DATE
%token TOKEN_SUBTITLE
%token TOKEN_CHAPTER
%token TOKEN_ABSTRACT
%token TOKEN_AUTHOR
%token TOKEN_LIST
%token TOKEN_TABLE
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

program : head TOKEN_BEGIN expr_list TOKEN_END              {parser_result = new Program($1, $3);} 
        |                                                   {parser_result = new Text("");}
        ;


head : title author date                                    {$$ = new Head($1, $2, $3);}
     | title                                                {$$ = new Head($1, new Text(""), new Text(""));}
     | title author                                         {$$ = new Head($1, $2, new Text(""));}
     | title date                                           {$$ = new Head($1, new Text(""), $2);}
     ;


expr_list : expr                                            {$$ = $1;}
          | expr_list expr                                  {$$ = new ExpressionList($1, $2);}
          ;

expr : subtitle                                             {$$ = $1;}
     | chapter                                              {$$ = $1;}
     | abstract                                             {$$ = $1;}
     | index                                                {$$ = $1;}
     | paragraph                                            {$$ = $1;}
     | list                                                 {$$ = $1;}
     | table                                                {$$ = $1;}
     | image                                                {$$ = $1;}
     | quote                                                {$$ = $1;}
     | foot                                                 {$$ = $1;}
     | linebreak                                            {$$ = $1;}
     | new_page                                             {$$ = $1;}          
     ;

title : TOKEN_TITLE text_list                               {$$ = new Title($2);}
      ;                                                

author : TOKEN_AUTHOR text_list                             {$$ = new Author($2);}
       ; 

date : TOKEN_DATE TOKEN_DATE_FORMAT                         {$$ = new Date(new Text(yytext));}
     ;

subtitle : TOKEN_SUBTITLE text_list                         {$$ = new Subtitle($2);}
         ; 

chapter : TOKEN_CHAPTER text_list                           {$$ = new Chapter($2);}
        ;

abstract : TOKEN_ABSTRACT text_list                         {$$ = new Abstract($2);}
         ; 

index : TOKEN_INDEX                                         {$$ = new Index();}
      ;

paragraph : TOKEN_PARAGRAPH text_list                       {$$ = new Paragraph($2);}
          ; 

list : TOKEN_LIST text_list                                 {$$ = new List($2);}
     ;

image : TOKEN_IMG TOKEN_IMG_PATH                            {$$ = new Image(yytext);}                                          
      ; 

quote : TOKEN_QUOTE TOKEN_L_BRACE text_list TOKEN_SLASH text_list TOKEN_SLASH number TOKEN_R_BRACE            {$$ = new Quote($3,$5, $7);}
      ; 

foot : TOKEN_FOOT text_list                                                     {$$ = new Foot($2);}
     ;

table : TOKEN_TABLE TOKEN_L_TAG text_list TOKEN_R_TAG rows TOKEN_AT             {$$ = new Table($3, $5);}        
      ; 

linebreak : TOKEN_LINEBREAK TOKEN_L_PAREN number TOKEN_R_PAREN       {$$ = new LineBreak($3);}
          ;

new_page : TOKEN_NEW_PAGE                                             {$$ = new NewPage();}
         ;



text_list : text                                            {$$ = new String( new Text(""), $1);}
     | text_list text                                       {$$ = new String( $1, $2);}
     ;

text : TOKEN_TEXT                                           {$$ = new Text(yytext);}
     | TOKEN_ENTER                                          {$$ = new Text(yytext);}
     | TOKEN_AT                                             {$$ = new Text(yytext);}
     | TOKEN_COMMA                                          {$$ = new Text(yytext);}
     | TOKEN_DEF                                            {$$ = new Text(yytext);}
     | TOKEN_BOLD_TEXT                                      {$$ = new Bold(yytext);}
     | TOKEN_ITALIC_TEXT                                    {$$ = new Italic(yytext);}
     | TOKEN_UNDERLINE_TEXT                                 {$$ = new Underline(yytext);}
     ;


number : TOKEN_NUMBER                                       {$$ = new Text(yytext);}
       ;


rows : row                                                  {$$ = new RowList( new Text(""), $1);}
     | rows row                                             {$$ = new RowList( $1, $2);}
     ;

row : TOKEN_L_PAREN text_list TOKEN_R_PAREN                 {$$ = new Row($2);}
    ;                                                        

%%


int yyerror(const char* s)
{
    printf("Parse error: %s\n", s);
    return 1;
}