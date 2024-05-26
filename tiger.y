%{
    #include <stdio.h>
    #include <string.h>
	int yylex(void);
	void yyerror(char* s);      
%}

%union {
	int i;
	char* id;
}

%token ARRAY BREAK DO ELSE END FOR FUNCTION IF IN LET NIL OF THEN TO
       TYPE VAR WHILE COMMA COLON SEMICOLON LPAREN RPAREN LBRACKET RBRACKET
       LBRACE RBRACE DOT PLUS MINUS MULTIPLY DIVIDE EQUAL NOT_EQUAL LESS_THAN
       LESS_THAN_OR_EQUAL GREATER_THAN GREATER_THAN_OR_EQUAL AND OR ASSIGN
       STRING_CONSTANT INVALID_TOKEN END_OF_FILE
%token UNARY_MINUS
%token <id> ID
%token <i> INTEGER_CONSTANT

%right ASSIGN
%nonassoc EQUAL NOT_EQUAL GREATER_THAN GREATER_THAN_OR_EQUAL LESS_THAN LESS_THAN_OR_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left UNARY_MINUS
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

prog : stm	{printf("语法分析成功！\n");}
	;

stmBlock_opt: stmBlock
    |
    ;

stmBlock: stm
    | stmBlock SEMICOLON stm
    ;

stm : assignStm
    | conditionStm
    | whileStm
    | forStm
    | letStm
    | LPAREN stmBlock_opt RPAREN
    ;

assignStm: lvalue ASSIGN algorithmExp
    ;

conditionStm: IF relationExp THEN stm %prec LOWER_THAN_ELSE
    | IF relationExp THEN stm ELSE stm
    ;

whileStm: WHILE relationExp DO stm
    ;

forStm: FOR ID ASSIGN algorithmExp TO algorithmExp DO stm
    ;

letStm: LET declaration_list IN stm END
    ;

lvalue: ID
    | lvalue DOT ID
    | lvalue LBRACKET algorithmExp RBRACKET
    ;

relationExp: relationExpItem
    | relationExp AND relationExpItem
    | relationExp OR relationExpItem
    ;

relationExpItem: algorithmExp relationOp algorithmExp
    | algorithmExp
    /*TODO:string?*/
    ;

algorithmExp: item
    | algorithmExp PLUS item
    | algorithmExp MINUS item
    ;

item: frator 
    | item MULTIPLY frator
    | item DIVIDE frator
    ;

frator: ID
    | INTEGER_CONSTANT
    | LPAREN algorithmExp RPAREN
    | MINUS frator 
    ;

relationOp: EQUAL
    | NOT_EQUAL
    | GREATER_THAN
    | LESS_THAN
    | GREATER_THAN_OR_EQUAL
    | LESS_THAN_OR_EQUAL
    ;

declaration_list: declaration
    | declaration_list declaration
    ;

declaration: type_declaration
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


%%

void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

int yywrap(){
    return 1;
}
int main()
{
    yyparse();
}
