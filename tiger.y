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
%token <id> IDENTIFIER
%token <i> INTEGER_CONSTANT

%%


prog : IDENTIFIER SEMICOLON subprog	{printf("语法分析成功！\n");}
	;
subprog : IDENTIFIER PLUS IDENTIFIER

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
