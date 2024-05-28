%{
#include "ast.h"
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "errormsg.h"
#define YYDEBUG 1 

int yylex(void);
void yyerror(char* s); 

extern int charPos; 

tree_node program = NULL;

%}

%union {
    char* sval;
    int ival;

	char* id;
    tree_node node;
    tree_node_list node_list;
    enum relop reOp;
}

%token ARRAY BREAK DO ELSE END FOR FUNCTION IF IN LET NIL OF THEN TO
       TYPE VAR WHILE COMMA COLON SEMICOLON LPAREN RPAREN LBRACKET RBRACKET
       LBRACE RBRACE DOT PLUS MINUS MULTIPLY DIVIDE EQUAL NOT_EQUAL LESS_THAN
       LESS_THAN_OR_EQUAL GREATER_THAN GREATER_THAN_OR_EQUAL AND OR ASSIGN
        INVALID_TOKEN END_OF_FILE
%token UNARY_MINUS
%token <id> ID
%token <ival> INTEGER_CONSTANT
%token <sval> STRING_CONSTANT
%type <node>  stmBlock_opt stmBlock stm assignStm conditionStm whileStm
              forStm letStm functionCallStm call_paramater lvalue relationExp
              relationExpOR relationExpAND relationExpItem algorithmExp 
              stringExp numberExp numberItem numberFrator
%type <node_list> call_list_opt call_list
%type <reOp> relationOp

%right ASSIGN
%nonassoc EQUAL NOT_EQUAL GREATER_THAN GREATER_THAN_OR_EQUAL LESS_THAN LESS_THAN_OR_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left UNARY_MINUS
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE



%%

prog : stm	{printf("语法分析成功！\n"); program = prog($1);print_tree_node(program);}
	;

stmBlock_opt: stmBlock { $$ = stmBlock_opt($1); }
    |                   { $$ = NULL; } 
    ;

stmBlock: stm                   { $$ = stmBlock_stm($1); }
    | stmBlock SEMICOLON stm    { $$ = stmBlock_SEMICOLON_stm($1, $3); }
    ;

stm : assignStm                     { $$ = stm_assignStm($1); }
    | conditionStm                  { $$ = stm_conditionStm($1); }
    | whileStm                      { $$ = stm_whileStm($1); }
    | forStm                        { $$ = stm_forStm($1); }
    | letStm                        { $$ = stm_letStm($1); }
    | LPAREN stmBlock_opt RPAREN    { $$ = stm_LPAREN_stmBlock_opt_RPAREN($2); }
    | functionCallStm               { $$ = stm_functionCallStm($1); }
    ;


assignStm: lvalue ASSIGN algorithmExp       { $$ = assignStm($1, $3); }
    | lvalue ASSIGN NIL                     { $$ = assignStm_NIL($1); }
    ;

conditionStm: IF relationExp THEN stm %prec LOWER_THAN_ELSE { $$ = conditionStm_IF_THEN($2, $4); }
    | IF relationExp THEN stm ELSE stm { $$ = conditionStm_IF_THEN_ELSE($2, $4, $6); }
    ;

whileStm: WHILE relationExp DO stm                  { $$ = whileStm($2, $4); }
    ;

forStm: FOR ID ASSIGN numberExp TO numberExp DO stm { $$ = forStm($2, $4, $6, $8); }
    ;

letStm: LET declaration_list IN stm END             { $$ = letStm(NULL, $4); }
    ;

functionCallStm: ID LPAREN call_list_opt RPAREN     { $$ = functionCallStm($1, $3); }
    ;

call_list_opt: call_list            { $$ = call_list_opt($1); }
    |                               { $$ = NULL; }
    ;

call_list: call_paramater               { $$ = call_list_first($1); }
    | call_list COMMA call_paramater    { $$ = call_list($1, $3); }
    ;

call_paramater: algorithmExp        { $$ = call_paramater_algorithmExp($1); }
    | functionCallStm               { $$ = call_paramater_functionCallStm($1); }
    ;

lvalue: ID                                          { $$ = lvalue_ID($1); }    
    | lvalue DOT ID                                 { $$ = lvalue_DOT($1, $3); }
    | lvalue LBRACKET numberExp RBRACKET            { $$ = lvalue_LBRACKET($1, $3);}
    ;

relationExp: relationExpOR      { $$ = relationExp($1); }
    ;

relationExpOR: relationExpAND           { $$ = relationExpOR_relationExpAND($1); }
    | relationExpOR OR relationExpAND   { $$ = relationExpOR_OR($1, $3); }
    ;

relationExpAND: relationExpItem                 { $$ = relationExpAND_relationExpItem($1);}
    | relationExpAND AND relationExpItem        { $$ = relationExpAND_AND($1, $3); }
    ;

relationExpItem: algorithmExp relationOp algorithmExp   { $$ = relationExpItem_algorithmExp_relationOp_algorithmExp($1, $2, $3); }
    | algorithmExp                                      { $$ = relationExpItem_algorithmExp($1); }
    | algorithmExp NOT_EQUAL NIL                        { $$ = relationExpItem_algorithmExp_NOT_EQUAL_NIL($1); }
    | algorithmExp EQUAL NIL                            { $$ = relationExpItem_algorithmExp_EQUAL_NIL($1); }
    ;

algorithmExp: numberExp     { $$ = algorithmExp_numberExp($1); }                   
    | stringExp             { $$ = algorithmExp_stringExp($1); }
    ;

stringExp: STRING_CONSTANT  { $$ = stringExp_STRING_CONSTANT($1); }
    ;

numberExp: numberItem               { $$ = numberExp_numberItem($1);}
    | numberExp PLUS numberItem     { $$ = numberExp_PLUS($1, $3);}
    | numberExp MINUS numberItem    { $$ = numberExp_MINUS($1, $3);}
    ;

numberItem: numberFrator               { $$ = numberItem_numberFrator($1); }
    | numberItem MULTIPLY numberFrator { $$ = numberItem_MULTIPLY($1, $3); }
    | numberItem DIVIDE numberFrator   { $$ = numberItem_DIVIDE($1, $3);}
    ;

numberFrator: MINUS numberFrator     { $$ = numberFrator_MINUS($2);}
    | ID                             { $$ = numberFrator_ID($1);}       
    | INTEGER_CONSTANT               { $$ = numberFrator_INTERGER_CONSTANT($1);}
    | LPAREN numberExp RPAREN        { $$ = numberFrator_LPAREN($2);}   
    ;

relationOp: EQUAL           { $$ = relationOp_EQUAL(); }
    | NOT_EQUAL             { $$ = relationOp_NOT_EQUAL(); }
    | GREATER_THAN          { $$ = relationOp_GREATER_THAN(); }
    | LESS_THAN             { $$ = relationOp_LESS_THAN(); }
    | GREATER_THAN_OR_EQUAL { $$ = relationOp_GREATER_THAN_OR_EQUAL(); }
    | LESS_THAN_OR_EQUAL    { $$ = relationOp_LESS_THAN_OR_EQUAL(); }
    ;

declaration_list: declaration
    | declaration_list declaration
    ;

declaration: type_declaration
    | variable_declaration
    | function_declaration
    ;

type_declaration: TYPE ID EQUAL type
    ;

type: ID                                           
    | LBRACE type_fields_opt RBRACE
    | ARRAY OF ID
    ;

type_fields_opt: type_fields
    |
    ;

type_fields: type_field
    | type_fields COMMA type_field
    ;

type_field: ID COLON ID
    ;

variable_declaration: VAR ID ASSIGN assignRValue
    | VAR ID COLON ID ASSIGN assignRValue
    | VAR ID COLON ID ASSIGN NIL
    ;

assignRValue: algorithmExp
    | ID LBRACKET numberExp RBRACKET OF numberExp
    | ID LBRACE field_list_opt RBRACE
    ;

field_list_opt: field_list
    |
    ;

field_list: field
    | field_list COMMA field
    ;

field: ID EQUAL algorithmExp
    ;

function_declaration: FUNCTION ID LPAREN type_fields_opt RPAREN EQUAL stm
    | FUNCTION ID LPAREN type_fields_opt RPAREN COLON ID EQUAL stm
    ;

%%

void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

int yywrap(){
    charPos=1;
    return 1;
}
int main()
{
    yyparse();
}
