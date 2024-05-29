%{
#include"ast.h"
#include"declaration.h"
#include <stdio.h>
#include"y.tab.h"
#include"errormsg.h"
void yyerror(char *);

int comment_count = 0;/* 定义计数器 */
int charPos=1;
int EM_tokPos=0;

void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

%option noyywrap

/* 定义状态 */
%x COMMENT

%%

"/*"               { adjust();if(comment_count == 0) BEGIN(COMMENT); comment_count++; /* 进入注释模式并增加计数器 */ }
<COMMENT>"/*"      { adjust();comment_count++; /* 增加嵌套注释的计数器 */ }
<COMMENT>"*/"      { adjust();comment_count--; /* 减少计数器 */ if(comment_count == 0) BEGIN(INITIAL); /* 如果计数器为0，则退出注释模式 */ }
<COMMENT>.         { adjust();/* 在注释模式下，忽略所有字符 */ }
"array"            { adjust();return ARRAY; }
"break"            { adjust();return BREAK; }
"do"               { adjust();return DO; }
"else"             { adjust();return ELSE; }
"end"              { adjust();return END; }
"for"              { adjust();return FOR; }
"function"         { adjust();return FUNCTION; }
"if"               { adjust();return IF; }
"in"               { adjust();return IN; }
"let"              { adjust();return LET; }
"nil"              { adjust();return NIL; }
"of"               { adjust();return OF; }
"then"             { adjust();return THEN; }
"to"               { adjust();return TO; }
"type"             { adjust();return TYPE; }
"var"              { adjust();return VAR; }
"while"            { adjust();return WHILE; }
","                { adjust();return COMMA; }
":"                { adjust();return COLON; }
";"                { adjust();return SEMICOLON; }
"("                { adjust();return LPAREN; }
")"                { adjust();return RPAREN; }
"["                { adjust();return LBRACKET; }
"]"                { adjust();return RBRACKET; }
"{"                { adjust();return LBRACE; }
"}"                { adjust();return RBRACE; }
"."                { adjust();return DOT; }
"+"                { adjust();return PLUS; }
"-"                { adjust();return MINUS; }
"*"                { adjust();return MULTIPLY; }
"/"                { adjust();return DIVIDE; }
"="                { adjust();return EQUAL; }
"<>"               { adjust();return NOT_EQUAL; }
"<"                { adjust();return LESS_THAN; }
"<="               { adjust();return LESS_THAN_OR_EQUAL; }
">"                { adjust();return GREATER_THAN; }
">="               { adjust();return GREATER_THAN_OR_EQUAL; }
"&"                { adjust();return AND; }
"|"                { adjust();return OR; }
":="               { adjust();return ASSIGN; }
[a-zA-Z][a-zA-Z0-9_]* { adjust();yylval.sval = strdup(yytext);return ID; }
[0-9]+             { adjust(); yylval.ival = atoi(yytext);return INTEGER_CONSTANT; }
\"([^\\\"]|\\.)*\" { adjust();
                     char* temp = strdup(yytext);
                     temp[strlen(temp)-1] = '\0'; // 去除双引号
                     yylval.sval = temp+1;
                     return STRING_CONSTANT; 
                    }
\n                 { adjust();/* 忽略换行符 */ }
[ \t\r\f]+         { adjust();/* 忽略空白符 */ }
.                  { adjust();/* 匹配其他字符，但不做任何操作 */ }

%%
