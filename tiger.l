%{
#include <stdio.h>
#include"y.tab.h"
void yyerror(char *);

int comment_count = 0;/* 定义计数器 */
%}

%option noyywrap

/* 定义状态 */
%x COMMENT

%%

"/*"               { if(comment_count == 0) BEGIN(COMMENT); comment_count++; /* 进入注释模式并增加计数器 */ }
<COMMENT>"/*"      { comment_count++; /* 增加嵌套注释的计数器 */ }
<COMMENT>"*/"      { comment_count--; /* 减少计数器 */ if(comment_count == 0) BEGIN(INITIAL); /* 如果计数器为0，则退出注释模式 */ }
<COMMENT>.         { /* 在注释模式下，忽略所有字符 */ }
"array"            { return ARRAY; }
"break"            { return BREAK; }
"do"               { return DO; }
"else"             { return ELSE; }
"end"              { return END; }
"for"              { return FOR; }
"function"         { return FUNCTION; }
"if"               { return IF; }
"in"               { return IN; }
"let"              { return LET; }
"nil"              { return NIL; }
"of"               { return OF; }
"then"             { return THEN; }
"to"               { return TO; }
"type"             { return TYPE; }
"var"              { return VAR; }
"while"            { return WHILE; }
","                { return COMMA; }
":"                { return COLON; }
";"                { return SEMICOLON; }
"("                { return LPAREN; }
")"                { return RPAREN; }
"["                { return LBRACKET; }
"]"                { return RBRACKET; }
"{"                { return LBRACE; }
"}"                { return RBRACE; }
"."                { return DOT; }
"+"                { return PLUS; }
"-"                { return MINUS; }
"*"                { return MULTIPLY; }
"/"                { return DIVIDE; }
"="                { return EQUAL; }
"<>"               { return NOT_EQUAL; }
"<"                { return LESS_THAN; }
"<="               { return LESS_THAN_OR_EQUAL; }
">"                { return GREATER_THAN; }
">="               { return GREATER_THAN_OR_EQUAL; }
"&"                { return AND; }
"|"                { return OR; }
":="               { return ASSIGN; }
[a-zA-Z][a-zA-Z0-9_]* { return ID; }
[0-9]+             { return INTEGER_CONSTANT; }
\"([^\\\"]|\\.)*\" { return STRING_CONSTANT; }
\n                 { /* 忽略换行符 */ }
[ \t\r\f]+         { /* 忽略空白符 */ }
.                  { /* 匹配其他字符，但不做任何操作 */ }

%%
