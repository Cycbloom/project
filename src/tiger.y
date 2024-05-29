%{
#include "ast.h"
#include"declaration.h"
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "errormsg.h"
#define YYDEBUG 1 

extern FILE *yyin;

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

    field field;
    field_list field_list;
    assignRValue assignRValue;
    variable_declaration variable_declaration;
    type_field type_field;
    type_fields type_fields;
    type_inf type_inf;
    type_declaration type_declaration;
    function_declaration function_declaration;
    declaration declaration;
    declaration_list declaration_list;
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
              stringExp numberExp numberItem numberFrator relationItemLeft relationItemRight
%type <node_list> call_list_opt call_list
%type <reOp> relationOp

%type <field> field
%type <field_list> field_list field_list_opt
%type <assignRValue> assignRValue
%type <variable_declaration> variable_declaration
%type <type_field> type_field
%type <type_fields> type_fields type_fields_opt
%type <type_inf> type_inf
%type <type_declaration> type_declaration
%type <function_declaration> function_declaration
%type <declaration> declaration
%type <declaration_list> declaration_list


%right ASSIGN
%nonassoc EQUAL NOT_EQUAL GREATER_THAN GREATER_THAN_OR_EQUAL LESS_THAN LESS_THAN_OR_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left UNARY_MINUS
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE



%%

prog : stm	{printf("语法分析成功！\n"); program = prog($1);
            generateDotFile(program,"tree.dot");
            }
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

letStm: LET declaration_list IN stm END             { $$ = letStm($2, $4); }
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

relationItemLeft: lvalue DOT ID                     { $$ = lvalue_DOT($1, $3); }
    | lvalue LBRACKET numberExp RBRACKET            { $$ = lvalue_LBRACKET($1, $3);}
    | algorithmExp                                  { $$ = $1;}
    ;

relationItemRight: lvalue DOT ID                     { $$ = lvalue_DOT($1, $3); }
    | lvalue LBRACKET numberExp RBRACKET            { $$ = lvalue_LBRACKET($1, $3);}
    | algorithmExp                                  { $$ = $1;}
    | NIL                                           { $$ = Lable("nil");}
    ;

relationExpItem: relationItemLeft relationOp relationItemRight  { $$ = relationExpItem_algorithmExp_relationOp_algorithmExp($1, $2, $3); }
    | algorithmExp                                      { $$ = relationExpItem_algorithmExp($1); }
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

declaration_list: declaration           { $$ = make_declaration_list($1, NULL); }
    | declaration_list declaration      { $$ = make_declaration_list($2, $1); }
    ;

declaration: type_declaration       { $$ = make_declaration_type($1);}
    | variable_declaration          { $$ = make_declaration_variable($1); }
    | function_declaration          { $$ = make_declaration_function($1); }
    ;

type_declaration: TYPE ID EQUAL type_inf       { $$ = make_type_declaration($2, $4); }
    ;

type_inf: ID                             { $$ = make_type_id($1); }              
    | LBRACE type_fields_opt RBRACE  { $$ = make_type_struct($2); }
    | ARRAY OF ID                    { $$ = make_type_array($3); }
    ;

type_fields_opt: type_fields        { $$ = $1; }
    |                               { $$ = NULL; }
    ;

type_fields: type_field             { $$ = make_type_fields($1, NULL); }
    | type_fields COMMA type_field  { $$ = make_type_fields($3, $1); }
    ;

type_field: ID COLON ID                         { $$ = make_type_field($1, $3); }
    ;

variable_declaration: VAR ID ASSIGN assignRValue { $$ = make_variable_declaration($2, NULL,$4); }
    | VAR ID COLON ID ASSIGN assignRValue       { $$ = make_variable_declaration($2, $4, $6); }
    | VAR ID COLON ID ASSIGN NIL                { $$ = make_variable_declaration($2, $4, make_nil()); }
    ;

assignRValue: algorithmExp          { $$ = make_algorithmExp($1); }
    | ID LBRACKET numberExp RBRACKET OF assignRValue { $$ = make_arrayExp($1, $3, $6); }
    | ID LBRACE field_list_opt RBRACE { $$ = make_fieldList($1, $3); }
    ;

field_list_opt: field_list      { $$ = $1; }
    |                           { $$ = NULL; }
    ;

field_list: field               { $$ = make_field_list($1, NULL); }
    | field_list COMMA field    { $$ = make_field_list($3, $1); }
    ;

field: ID EQUAL assignRValue { $$ = make_field($1, $3); }
    ;

function_declaration: FUNCTION ID LPAREN type_fields_opt RPAREN EQUAL stm { $$ = make_function_declaration($2, $4, NULL, $7); }
    | FUNCTION ID LPAREN type_fields_opt RPAREN COLON ID EQUAL stm          { $$ = make_function_declaration($2, $4, $7, $9); }
    ;

%%

void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

int yywrap(){
    charPos=1;
    return 1;
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("fopen");
        return 1;
    }
    yyin = file;
    yyparse();
    fclose(file);
    return 0;
}