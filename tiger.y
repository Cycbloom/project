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

%left UNARY_MINUS
%right ASSIGN
%nonassoc EQUAL NOT_EQUAL GREATER_THAN GREATER_THAN_OR_EQUAL LESS_THAN LESS_THAN_OR_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%


prog : expr	{printf("语法分析成功！\n");}
	;

expr: STRING_CONSTANT
    | INTEGER_CONSTANT
    | NIL
    | MINUS expr %prec UNARY_MINUS
    | lvalue
    | expr binary_operator expr
    | assignStm
    | ID LPAREN expr_list_opt RPAREN
    | LPAREN expr_seq_opt RPAREN
    | ID LBRACE field_list_opt RBRACE
    | ID LBRACKET expr RBRACKET OF expr
    | IF expr THEN expr %prec LOWER_THAN_ELSE
    | IF expr THEN expr ELSE expr
    | WHILE expr DO expr
    | FOR ID ASSIGN expr TO expr DO expr
    | BREAK
    | LET declaration_list IN expr_seq_opt END
    ;

assignStm: lvalue ASSIGN expr
    ;

expr_seq: expr
    | expr_seq SEMICOLON expr
    ;

expr_list: expr
    | expr_list COMMA expr
    ;

field_list: ID EQUAL expr
    | field_list COMMA ID EQUAL expr
    ;

expr_list_opt: expr_list
    | 
    ;
expr_seq_opt: expr_seq
    |
    ;

field_list_opt: field_list
    |
    ;

lvalue: ID
    | lvalue DOT ID
    | lvalue LBRACKET expr RBRACKET
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

variable_declaration: VAR ID ASSIGN expr
    | VAR ID COLON ID ASSIGN expr
    ;

function_declaration: FUNCTION ID LPAREN type_fields_opt RPAREN EQUAL expr
    | FUNCTION ID LPAREN type_fields_opt RPAREN COLON ID EQUAL expr
    ;

relationExp: algorithmExp relationOp algorithmExp
    /*| STRING_CONSTANT relationOp STRING_CONSTANT*/
    ;

relationOp: EQUAL
    | NOT_EQUAL
    | GREATER_THAN
    | LESS_THAN
    | GREATER_THAN_OR_EQUAL
    | LESS_THAN_OR_EQUAL
    ;
    
binaryOp: PLUS
    | MINUS
    | MULTIPLY
    | DIVIDE
    | EQUAL
    | NOT_EQUAL
    | GREATER_THAN
    | LESS_THAN
    | GREATER_THAN_OR_EQUAL
    | LESS_THAN_OR_EQUAL
    | AND
    | OR
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
