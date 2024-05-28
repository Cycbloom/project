/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ARRAY = 258,                   /* ARRAY  */
    BREAK = 259,                   /* BREAK  */
    DO = 260,                      /* DO  */
    ELSE = 261,                    /* ELSE  */
    END = 262,                     /* END  */
    FOR = 263,                     /* FOR  */
    FUNCTION = 264,                /* FUNCTION  */
    IF = 265,                      /* IF  */
    IN = 266,                      /* IN  */
    LET = 267,                     /* LET  */
    NIL = 268,                     /* NIL  */
    OF = 269,                      /* OF  */
    THEN = 270,                    /* THEN  */
    TO = 271,                      /* TO  */
    TYPE = 272,                    /* TYPE  */
    VAR = 273,                     /* VAR  */
    WHILE = 274,                   /* WHILE  */
    COMMA = 275,                   /* COMMA  */
    COLON = 276,                   /* COLON  */
    SEMICOLON = 277,               /* SEMICOLON  */
    LPAREN = 278,                  /* LPAREN  */
    RPAREN = 279,                  /* RPAREN  */
    LBRACKET = 280,                /* LBRACKET  */
    RBRACKET = 281,                /* RBRACKET  */
    LBRACE = 282,                  /* LBRACE  */
    RBRACE = 283,                  /* RBRACE  */
    DOT = 284,                     /* DOT  */
    PLUS = 285,                    /* PLUS  */
    MINUS = 286,                   /* MINUS  */
    MULTIPLY = 287,                /* MULTIPLY  */
    DIVIDE = 288,                  /* DIVIDE  */
    EQUAL = 289,                   /* EQUAL  */
    NOT_EQUAL = 290,               /* NOT_EQUAL  */
    LESS_THAN = 291,               /* LESS_THAN  */
    LESS_THAN_OR_EQUAL = 292,      /* LESS_THAN_OR_EQUAL  */
    GREATER_THAN = 293,            /* GREATER_THAN  */
    GREATER_THAN_OR_EQUAL = 294,   /* GREATER_THAN_OR_EQUAL  */
    AND = 295,                     /* AND  */
    OR = 296,                      /* OR  */
    ASSIGN = 297,                  /* ASSIGN  */
    INVALID_TOKEN = 298,           /* INVALID_TOKEN  */
    END_OF_FILE = 299,             /* END_OF_FILE  */
    UNARY_MINUS = 300,             /* UNARY_MINUS  */
    ID = 301,                      /* ID  */
    INTEGER_CONSTANT = 302,        /* INTEGER_CONSTANT  */
    STRING_CONSTANT = 303,         /* STRING_CONSTANT  */
    LOWER_THAN_ELSE = 304          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ARRAY 258
#define BREAK 259
#define DO 260
#define ELSE 261
#define END 262
#define FOR 263
#define FUNCTION 264
#define IF 265
#define IN 266
#define LET 267
#define NIL 268
#define OF 269
#define THEN 270
#define TO 271
#define TYPE 272
#define VAR 273
#define WHILE 274
#define COMMA 275
#define COLON 276
#define SEMICOLON 277
#define LPAREN 278
#define RPAREN 279
#define LBRACKET 280
#define RBRACKET 281
#define LBRACE 282
#define RBRACE 283
#define DOT 284
#define PLUS 285
#define MINUS 286
#define MULTIPLY 287
#define DIVIDE 288
#define EQUAL 289
#define NOT_EQUAL 290
#define LESS_THAN 291
#define LESS_THAN_OR_EQUAL 292
#define GREATER_THAN 293
#define GREATER_THAN_OR_EQUAL 294
#define AND 295
#define OR 296
#define ASSIGN 297
#define INVALID_TOKEN 298
#define END_OF_FILE 299
#define UNARY_MINUS 300
#define ID 301
#define INTEGER_CONSTANT 302
#define STRING_CONSTANT 303
#define LOWER_THAN_ELSE 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "tiger.y"

    char* sval;
    int ival;

	char* id;
    tree_node node;
    tree_node_list node_list;
    enum relop reOp;

#line 175 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
