%{
#include <stdio.h>
void yyerror(char *);
/* 定义计数器 */
int comment_count = 0;

%}

%option noyywrap

/* 定义状态 */
%x COMMENT


%%

"/*"               { if(comment_count == 0) BEGIN(COMMENT); comment_count++; /* 进入注释模式并增加计数器 */ }
<COMMENT>"/*"      { comment_count++; /* 增加嵌套注释的计数器 */ }
<COMMENT>"*/"      { comment_count--; /* 减少计数器 */ if(comment_count == 0) BEGIN(INITIAL); /* 如果计数器为0，则退出注释模式 */ }
<COMMENT>.         { /* 在注释模式下，忽略所有字符 */ }
"array"            { printf("ARRAY\n"); }
"break"            { printf("BREAK\n"); }
"do"               { printf("DO\n"); }
"else"             { printf("ELSE\n"); }
"end"              { printf("END\n"); }
"for"              { printf("FOR\n"); }
"function"         { printf("FUNCTION\n"); }
"if"               { printf("IF\n"); }
"in"               { printf("IN\n"); }
"let"              { printf("LET\n"); }
"nil"              { printf("NIL\n"); }
"of"               { printf("OF\n"); }
"then"             { printf("THEN\n"); }
"to"               { printf("TO\n"); }
"type"             { printf("TYPE\n"); }
"var"              { printf("VAR\n"); }
"while"            { printf("WHILE\n"); }
","                { printf("COMMA\n"); }
":"                { printf("COLON\n"); }
";"                { printf("SEMICOLON\n"); }
"("                { printf("LPAREN\n"); }
")"                { printf("RPAREN\n"); }
"["                { printf("LBRACKET\n"); }
"]"                { printf("RBRACKET\n"); }
"{"                { printf("LBRACE\n"); }
"}"                { printf("RBRACE\n"); }
"."                { printf("DOT\n"); }
"+"                { printf("PLUS\n"); }
"-"                { printf("MINUS\n"); }
"*"                { printf("MULTIPLY\n"); }
"/"                { printf("DIVIDE\n"); }
"="                { printf("EQUAL\n"); }
"<>"               { printf("NOT_EQUAL\n"); }
"<"                { printf("LESS_THAN\n"); }
"<="               { printf("LESS_THAN_OR_EQUAL\n"); }
">"                { printf("GREATER_THAN\n"); }
">="               { printf("GREATER_THAN_OR_EQUAL\n"); }
"&"                { printf("AND\n"); }
"|"                { printf("OR\n"); }
":="               { printf("ASSIGN\n"); }
[a-zA-Z][a-zA-Z0-9_]* { printf("IDENTIFIER\n"); }
[0-9]+             { printf("INTEGER_CONSTANT\n"); }
\"([^\\\"]|\\.)*\" { printf("STRING_CONSTANT\n"); }
\n                 { /* 忽略换行符 */ }
[ \t\r\f]+         { /* 忽略空白符 */ }
.                  { /* 匹配其他字符，但不做任何操作 */ }

%%

int main() {
    yylex();
    return 0;
}
