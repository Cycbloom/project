/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "tiger.y"

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


#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 249 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ARRAY = 3,                      /* ARRAY  */
  YYSYMBOL_BREAK = 4,                      /* BREAK  */
  YYSYMBOL_DO = 5,                         /* DO  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_END = 7,                        /* END  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_FUNCTION = 9,                   /* FUNCTION  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_IN = 11,                        /* IN  */
  YYSYMBOL_LET = 12,                       /* LET  */
  YYSYMBOL_NIL = 13,                       /* NIL  */
  YYSYMBOL_OF = 14,                        /* OF  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_TO = 16,                        /* TO  */
  YYSYMBOL_TYPE = 17,                      /* TYPE  */
  YYSYMBOL_VAR = 18,                       /* VAR  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_COLON = 21,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 23,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 24,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 25,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 26,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 27,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 28,                    /* RBRACE  */
  YYSYMBOL_DOT = 29,                       /* DOT  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MINUS = 31,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 32,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 33,                    /* DIVIDE  */
  YYSYMBOL_EQUAL = 34,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 35,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 36,                 /* LESS_THAN  */
  YYSYMBOL_LESS_THAN_OR_EQUAL = 37,        /* LESS_THAN_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN = 38,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_THAN_OR_EQUAL = 39,     /* GREATER_THAN_OR_EQUAL  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_ASSIGN = 42,                    /* ASSIGN  */
  YYSYMBOL_INVALID_TOKEN = 43,             /* INVALID_TOKEN  */
  YYSYMBOL_END_OF_FILE = 44,               /* END_OF_FILE  */
  YYSYMBOL_UNARY_MINUS = 45,               /* UNARY_MINUS  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_INTEGER_CONSTANT = 47,          /* INTEGER_CONSTANT  */
  YYSYMBOL_STRING_CONSTANT = 48,           /* STRING_CONSTANT  */
  YYSYMBOL_LOWER_THAN_ELSE = 49,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_prog = 51,                      /* prog  */
  YYSYMBOL_stmBlock_opt = 52,              /* stmBlock_opt  */
  YYSYMBOL_stmBlock = 53,                  /* stmBlock  */
  YYSYMBOL_stm = 54,                       /* stm  */
  YYSYMBOL_assignStm = 55,                 /* assignStm  */
  YYSYMBOL_conditionStm = 56,              /* conditionStm  */
  YYSYMBOL_whileStm = 57,                  /* whileStm  */
  YYSYMBOL_forStm = 58,                    /* forStm  */
  YYSYMBOL_letStm = 59,                    /* letStm  */
  YYSYMBOL_functionCallStm = 60,           /* functionCallStm  */
  YYSYMBOL_call_list_opt = 61,             /* call_list_opt  */
  YYSYMBOL_call_list = 62,                 /* call_list  */
  YYSYMBOL_call_paramater = 63,            /* call_paramater  */
  YYSYMBOL_lvalue = 64,                    /* lvalue  */
  YYSYMBOL_relationExp = 65,               /* relationExp  */
  YYSYMBOL_relationExpOR = 66,             /* relationExpOR  */
  YYSYMBOL_relationExpAND = 67,            /* relationExpAND  */
  YYSYMBOL_relationExpItem = 68,           /* relationExpItem  */
  YYSYMBOL_algorithmExp = 69,              /* algorithmExp  */
  YYSYMBOL_stringExp = 70,                 /* stringExp  */
  YYSYMBOL_numberExp = 71,                 /* numberExp  */
  YYSYMBOL_numberItem = 72,                /* numberItem  */
  YYSYMBOL_numberFrator = 73,              /* numberFrator  */
  YYSYMBOL_relationOp = 74,                /* relationOp  */
  YYSYMBOL_declaration_list = 75,          /* declaration_list  */
  YYSYMBOL_declaration = 76,               /* declaration  */
  YYSYMBOL_type_declaration = 77,          /* type_declaration  */
  YYSYMBOL_type = 78,                      /* type  */
  YYSYMBOL_type_fields_opt = 79,           /* type_fields_opt  */
  YYSYMBOL_type_fields = 80,               /* type_fields  */
  YYSYMBOL_type_field = 81,                /* type_field  */
  YYSYMBOL_variable_declaration = 82,      /* variable_declaration  */
  YYSYMBOL_assignRValue = 83,              /* assignRValue  */
  YYSYMBOL_field_list_opt = 84,            /* field_list_opt  */
  YYSYMBOL_field_list = 85,                /* field_list  */
  YYSYMBOL_field = 86,                     /* field  */
  YYSYMBOL_function_declaration = 87       /* function_declaration  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    59,    60,    63,    64,    67,    68,    69,
      70,    71,    72,    73,    77,    78,    81,    82,    85,    88,
      91,    94,    97,    98,   101,   102,   105,   106,   109,   110,
     111,   114,   117,   118,   121,   122,   125,   126,   127,   128,
     131,   132,   135,   138,   139,   140,   143,   144,   145,   148,
     149,   150,   151,   154,   155,   156,   157,   158,   159,   162,
     163,   166,   167,   168,   171,   174,   175,   176,   179,   180,
     183,   184,   187,   190,   191,   192,   195,   196,   197,   200,
     201,   204,   205,   208,   211,   212
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ARRAY", "BREAK", "DO",
  "ELSE", "END", "FOR", "FUNCTION", "IF", "IN", "LET", "NIL", "OF", "THEN",
  "TO", "TYPE", "VAR", "WHILE", "COMMA", "COLON", "SEMICOLON", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "DOT", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "EQUAL", "NOT_EQUAL", "LESS_THAN",
  "LESS_THAN_OR_EQUAL", "GREATER_THAN", "GREATER_THAN_OR_EQUAL", "AND",
  "OR", "ASSIGN", "INVALID_TOKEN", "END_OF_FILE", "UNARY_MINUS", "ID",
  "INTEGER_CONSTANT", "STRING_CONSTANT", "LOWER_THAN_ELSE", "$accept",
  "prog", "stmBlock_opt", "stmBlock", "stm", "assignStm", "conditionStm",
  "whileStm", "forStm", "letStm", "functionCallStm", "call_list_opt",
  "call_list", "call_paramater", "lvalue", "relationExp", "relationExpOR",
  "relationExpAND", "relationExpItem", "algorithmExp", "stringExp",
  "numberExp", "numberItem", "numberFrator", "relationOp",
  "declaration_list", "declaration", "type_declaration", "type",
  "type_fields_opt", "type_fields", "type_field", "variable_declaration",
  "assignRValue", "field_list_opt", "field_list", "field",
  "function_declaration", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -32,    12,    79,    12,     1,    -1,    25,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,    41,   -12,    48,    48,   -42,
     -42,   -42,    22,    34,    42,   -42,    68,   -42,    14,    23,
     -42,    44,    53,    70,    63,   -42,   -42,   -42,   -42,   104,
      93,    96,   -42,    38,   -42,    48,    74,    -8,    48,   -14,
     -42,     1,    12,    12,   106,   108,   -42,   -42,   -42,   -42,
      12,    48,    48,    48,    48,    99,    89,     0,     1,   -42,
       1,   -42,     1,    -1,   -42,   100,   105,   -42,   -42,    47,
     -42,   -42,   -42,    -4,   -42,   121,    42,   -42,   -42,   -42,
     -42,    23,    23,   -42,   -42,    82,     4,    85,    45,   123,
     -42,   -42,   -42,    38,   -42,    48,     1,   111,   109,   114,
     -42,   122,    82,   -42,   -42,    97,    73,   -42,   -42,   -42,
     -42,     3,   -42,    92,    20,    82,    94,   107,     5,    48,
      95,     1,   -42,    98,     1,   -42,   -42,   -42,   -42,   -42,
      84,   112,   115,   125,   -42,   -42,   116,   -42,   128,    12,
     -42,    95,     1,    48,   -42,   -42,   -42,    14
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,    28,     0,     2,     7,
       8,     9,    10,    11,    13,     0,     0,     0,     0,    50,
      51,    42,     0,    31,    32,    34,    37,    41,    40,    43,
      46,     0,     0,     0,     0,    59,    61,    62,    63,     0,
       0,     3,     5,    23,     1,     0,     0,     0,     0,     0,
      49,     0,     0,     0,    53,    54,    56,    58,    55,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
       0,    12,     0,    50,    27,     0,    22,    24,    26,     0,
      29,    15,    14,     0,    52,    16,    33,    35,    39,    38,
      36,    44,    45,    47,    48,    69,     0,     0,     0,     0,
      18,     6,    21,     0,    30,     0,     0,     0,     0,    68,
      70,     0,    69,    65,    64,     0,    50,    76,    73,    20,
      25,     0,    17,     0,     0,     0,     0,     0,     0,     0,
      80,     0,    72,     0,     0,    71,    67,    66,    75,    74,
       0,     0,     0,    79,    81,    19,     0,    84,     0,     0,
      78,     0,     0,     0,    83,    82,    85,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   -42,   -42,    -5,   -42,   -42,   -42,   -42,   -42,
     -39,   -42,   -42,    46,   -42,   144,   -42,   101,   102,   -41,
     -42,   -16,    50,   -15,   -42,   -42,   117,   -42,   -42,    40,
     -42,    29,   -42,    28,   -42,   -42,     6,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,    40,    41,     8,     9,    10,    11,    12,    13,
      14,    75,    76,    77,    15,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    60,    34,    35,    36,   114,   108,
     109,   110,    37,   118,   142,   143,   144,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    49,    78,    50,    74,    81,    82,   111,   131,     1,
      84,     2,   105,     3,    16,    17,    61,    62,   138,    90,
       4,    97,    43,    18,     5,    44,    61,    62,    17,    79,
      48,   112,    83,    61,    62,    17,    18,    51,    19,    20,
      21,   133,    98,    18,    61,    62,    85,     6,    93,    94,
     113,   116,    20,    21,   134,    63,    64,   117,    19,    20,
      21,    17,    78,    99,    74,   100,    45,   101,    17,    18,
      46,    17,    31,   104,    68,    52,    18,    61,    62,    18,
      32,    33,    53,    47,    73,    20,    21,   117,    31,   121,
      65,   116,    20,    21,    19,    20,    32,    33,   129,    66,
     130,   122,    54,    55,    56,    57,    58,    59,   154,    70,
     148,    91,    92,   140,    61,    62,    67,    71,    72,    88,
      80,    89,    95,    96,   102,   103,   145,   106,   107,   147,
     119,   115,   123,   124,   125,   137,   126,   157,   132,   128,
     136,   141,   153,   150,   146,   151,   149,   156,    39,   120,
     152,    69,   127,    86,   135,    87,   139,   155
};

static const yytype_uint8 yycheck[] =
{
       5,    17,    43,    18,    43,    13,    47,     3,     5,     8,
      24,    10,    16,    12,    46,    23,    30,    31,    13,    60,
      19,    21,    23,    31,    23,     0,    30,    31,    23,    45,
      42,    27,    48,    30,    31,    23,    31,    15,    46,    47,
      48,    21,    42,    31,    30,    31,    51,    46,    63,    64,
      46,    46,    47,    48,    34,    32,    33,    98,    46,    47,
      48,    23,   103,    68,   103,    70,    25,    72,    23,    31,
      29,    23,     9,    26,    11,    41,    31,    30,    31,    31,
      17,    18,    40,    42,    46,    47,    48,   128,     9,   105,
      46,    46,    47,    48,    46,    47,    17,    18,    25,    46,
      27,   106,    34,    35,    36,    37,    38,    39,   149,     5,
      26,    61,    62,   129,    30,    31,    46,    24,    22,    13,
      46,    13,    23,    34,    24,    20,   131,     6,    46,   134,
       7,    46,    21,    24,    20,    28,    14,   153,    46,    42,
      46,    46,    14,    28,    46,    20,    34,   152,     4,   103,
      34,    34,   112,    52,   125,    53,   128,   151
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    12,    19,    23,    46,    51,    54,    55,
      56,    57,    58,    59,    60,    64,    46,    23,    31,    46,
      47,    48,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     9,    17,    18,    75,    76,    77,    82,    87,    65,
      52,    53,    54,    23,     0,    25,    29,    42,    42,    71,
      73,    15,    41,    40,    34,    35,    36,    37,    38,    39,
      74,    30,    31,    32,    33,    46,    46,    46,    11,    76,
       5,    24,    22,    46,    60,    61,    62,    63,    69,    71,
      46,    13,    69,    71,    24,    54,    67,    68,    13,    13,
      69,    72,    72,    73,    73,    23,    34,    21,    42,    54,
      54,    54,    24,    20,    26,    16,     6,    46,    79,    80,
      81,     3,    27,    46,    78,    46,    46,    69,    83,     7,
      63,    71,    54,    21,    24,    20,    14,    79,    42,    25,
      27,     5,    46,    21,    34,    81,    46,    28,    13,    83,
      71,    46,    84,    85,    86,    54,    46,    54,    26,    34,
      28,    20,    34,    14,    69,    86,    54,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    57,    58,
      59,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    65,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    71,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    77,    78,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    83,    83,    83,    84,
      84,    85,    85,    86,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     4,     6,     4,     8,
       5,     4,     1,     0,     1,     3,     1,     1,     1,     3,
       4,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     4,     1,     3,     3,     1,     0,
       1,     3,     3,     4,     6,     6,     1,     6,     4,     1,
       0,     1,     3,     3,     7,     9
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: stm  */
#line 56 "tiger.y"
                {printf("语法分析成功！\n"); program = prog((yyvsp[0].node));print_tree_node(program);}
#line 1426 "y.tab.c"
    break;

  case 3: /* stmBlock_opt: stmBlock  */
#line 59 "tiger.y"
                       { (yyval.node) = stmBlock_opt((yyvsp[0].node)); }
#line 1432 "y.tab.c"
    break;

  case 4: /* stmBlock_opt: %empty  */
#line 60 "tiger.y"
                        { (yyval.node) = NULL; }
#line 1438 "y.tab.c"
    break;

  case 5: /* stmBlock: stm  */
#line 63 "tiger.y"
                                { (yyval.node) = stmBlock_stm((yyvsp[0].node)); }
#line 1444 "y.tab.c"
    break;

  case 6: /* stmBlock: stmBlock SEMICOLON stm  */
#line 64 "tiger.y"
                                { (yyval.node) = stmBlock_SEMICOLON_stm((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1450 "y.tab.c"
    break;

  case 7: /* stm: assignStm  */
#line 67 "tiger.y"
                                    { (yyval.node) = stm_assignStm((yyvsp[0].node)); }
#line 1456 "y.tab.c"
    break;

  case 8: /* stm: conditionStm  */
#line 68 "tiger.y"
                                    { (yyval.node) = stm_conditionStm((yyvsp[0].node)); }
#line 1462 "y.tab.c"
    break;

  case 9: /* stm: whileStm  */
#line 69 "tiger.y"
                                    { (yyval.node) = stm_whileStm((yyvsp[0].node)); }
#line 1468 "y.tab.c"
    break;

  case 10: /* stm: forStm  */
#line 70 "tiger.y"
                                    { (yyval.node) = stm_forStm((yyvsp[0].node)); }
#line 1474 "y.tab.c"
    break;

  case 11: /* stm: letStm  */
#line 71 "tiger.y"
                                    { (yyval.node) = stm_letStm((yyvsp[0].node)); }
#line 1480 "y.tab.c"
    break;

  case 12: /* stm: LPAREN stmBlock_opt RPAREN  */
#line 72 "tiger.y"
                                    { (yyval.node) = stm_LPAREN_stmBlock_opt_RPAREN((yyvsp[-1].node)); }
#line 1486 "y.tab.c"
    break;

  case 13: /* stm: functionCallStm  */
#line 73 "tiger.y"
                                    { (yyval.node) = stm_functionCallStm((yyvsp[0].node)); }
#line 1492 "y.tab.c"
    break;

  case 14: /* assignStm: lvalue ASSIGN algorithmExp  */
#line 77 "tiger.y"
                                            { (yyval.node) = assignStm((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1498 "y.tab.c"
    break;

  case 15: /* assignStm: lvalue ASSIGN NIL  */
#line 78 "tiger.y"
                                            { (yyval.node) = assignStm_NIL((yyvsp[-2].node)); }
#line 1504 "y.tab.c"
    break;

  case 16: /* conditionStm: IF relationExp THEN stm  */
#line 81 "tiger.y"
                                                            { (yyval.node) = conditionStm_IF_THEN((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1510 "y.tab.c"
    break;

  case 17: /* conditionStm: IF relationExp THEN stm ELSE stm  */
#line 82 "tiger.y"
                                       { (yyval.node) = conditionStm_IF_THEN_ELSE((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1516 "y.tab.c"
    break;

  case 18: /* whileStm: WHILE relationExp DO stm  */
#line 85 "tiger.y"
                                                    { (yyval.node) = whileStm((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1522 "y.tab.c"
    break;

  case 19: /* forStm: FOR ID ASSIGN numberExp TO numberExp DO stm  */
#line 88 "tiger.y"
                                                    { (yyval.node) = forStm((yyvsp[-6].id), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1528 "y.tab.c"
    break;

  case 20: /* letStm: LET declaration_list IN stm END  */
#line 91 "tiger.y"
                                                    { (yyval.node) = letStm(NULL, (yyvsp[-1].node)); }
#line 1534 "y.tab.c"
    break;

  case 21: /* functionCallStm: ID LPAREN call_list_opt RPAREN  */
#line 94 "tiger.y"
                                                    { (yyval.node) = functionCallStm((yyvsp[-3].id), (yyvsp[-1].node_list)); }
#line 1540 "y.tab.c"
    break;

  case 22: /* call_list_opt: call_list  */
#line 97 "tiger.y"
                                    { (yyval.node_list) = call_list_opt((yyvsp[0].node_list)); }
#line 1546 "y.tab.c"
    break;

  case 23: /* call_list_opt: %empty  */
#line 98 "tiger.y"
                                    { (yyval.node_list) = NULL; }
#line 1552 "y.tab.c"
    break;

  case 24: /* call_list: call_paramater  */
#line 101 "tiger.y"
                                        { (yyval.node_list) = call_list_first((yyvsp[0].node)); }
#line 1558 "y.tab.c"
    break;

  case 25: /* call_list: call_list COMMA call_paramater  */
#line 102 "tiger.y"
                                        { (yyval.node_list) = call_list((yyvsp[-2].node_list), (yyvsp[0].node)); }
#line 1564 "y.tab.c"
    break;

  case 26: /* call_paramater: algorithmExp  */
#line 105 "tiger.y"
                                    { (yyval.node) = call_paramater_algorithmExp((yyvsp[0].node)); }
#line 1570 "y.tab.c"
    break;

  case 27: /* call_paramater: functionCallStm  */
#line 106 "tiger.y"
                                    { (yyval.node) = call_paramater_functionCallStm((yyvsp[0].node)); }
#line 1576 "y.tab.c"
    break;

  case 28: /* lvalue: ID  */
#line 109 "tiger.y"
                                                    { (yyval.node) = lvalue_ID((yyvsp[0].id)); }
#line 1582 "y.tab.c"
    break;

  case 29: /* lvalue: lvalue DOT ID  */
#line 110 "tiger.y"
                                                    { (yyval.node) = lvalue_DOT((yyvsp[-2].node), (yyvsp[0].id)); }
#line 1588 "y.tab.c"
    break;

  case 30: /* lvalue: lvalue LBRACKET numberExp RBRACKET  */
#line 111 "tiger.y"
                                                    { (yyval.node) = lvalue_LBRACKET((yyvsp[-3].node), (yyvsp[-1].node));}
#line 1594 "y.tab.c"
    break;

  case 31: /* relationExp: relationExpOR  */
#line 114 "tiger.y"
                                { (yyval.node) = relationExp((yyvsp[0].node)); }
#line 1600 "y.tab.c"
    break;

  case 32: /* relationExpOR: relationExpAND  */
#line 117 "tiger.y"
                                        { (yyval.node) = relationExpOR_relationExpAND((yyvsp[0].node)); }
#line 1606 "y.tab.c"
    break;

  case 33: /* relationExpOR: relationExpOR OR relationExpAND  */
#line 118 "tiger.y"
                                        { (yyval.node) = relationExpOR_OR((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1612 "y.tab.c"
    break;

  case 34: /* relationExpAND: relationExpItem  */
#line 121 "tiger.y"
                                                { (yyval.node) = relationExpAND_relationExpItem((yyvsp[0].node));}
#line 1618 "y.tab.c"
    break;

  case 35: /* relationExpAND: relationExpAND AND relationExpItem  */
#line 122 "tiger.y"
                                                { (yyval.node) = relationExpAND_AND((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1624 "y.tab.c"
    break;

  case 36: /* relationExpItem: algorithmExp relationOp algorithmExp  */
#line 125 "tiger.y"
                                                        { (yyval.node) = relationExpItem_algorithmExp_relationOp_algorithmExp((yyvsp[-2].node), (yyvsp[-1].reOp), (yyvsp[0].node)); }
#line 1630 "y.tab.c"
    break;

  case 37: /* relationExpItem: algorithmExp  */
#line 126 "tiger.y"
                                                        { (yyval.node) = relationExpItem_algorithmExp((yyvsp[0].node)); }
#line 1636 "y.tab.c"
    break;

  case 38: /* relationExpItem: algorithmExp NOT_EQUAL NIL  */
#line 127 "tiger.y"
                                                        { (yyval.node) = relationExpItem_algorithmExp_NOT_EQUAL_NIL((yyvsp[-2].node)); }
#line 1642 "y.tab.c"
    break;

  case 39: /* relationExpItem: algorithmExp EQUAL NIL  */
#line 128 "tiger.y"
                                                        { (yyval.node) = relationExpItem_algorithmExp_EQUAL_NIL((yyvsp[-2].node)); }
#line 1648 "y.tab.c"
    break;

  case 40: /* algorithmExp: numberExp  */
#line 131 "tiger.y"
                            { (yyval.node) = algorithmExp_numberExp((yyvsp[0].node)); }
#line 1654 "y.tab.c"
    break;

  case 41: /* algorithmExp: stringExp  */
#line 132 "tiger.y"
                            { (yyval.node) = algorithmExp_stringExp((yyvsp[0].node)); }
#line 1660 "y.tab.c"
    break;

  case 42: /* stringExp: STRING_CONSTANT  */
#line 135 "tiger.y"
                            { (yyval.node) = stringExp_STRING_CONSTANT((yyvsp[0].sval)); }
#line 1666 "y.tab.c"
    break;

  case 43: /* numberExp: numberItem  */
#line 138 "tiger.y"
                                    { (yyval.node) = numberExp_numberItem((yyvsp[0].node));}
#line 1672 "y.tab.c"
    break;

  case 44: /* numberExp: numberExp PLUS numberItem  */
#line 139 "tiger.y"
                                    { (yyval.node) = numberExp_PLUS((yyvsp[-2].node), (yyvsp[0].node));}
#line 1678 "y.tab.c"
    break;

  case 45: /* numberExp: numberExp MINUS numberItem  */
#line 140 "tiger.y"
                                    { (yyval.node) = numberExp_MINUS((yyvsp[-2].node), (yyvsp[0].node));}
#line 1684 "y.tab.c"
    break;

  case 46: /* numberItem: numberFrator  */
#line 143 "tiger.y"
                                       { (yyval.node) = numberItem_numberFrator((yyvsp[0].node)); }
#line 1690 "y.tab.c"
    break;

  case 47: /* numberItem: numberItem MULTIPLY numberFrator  */
#line 144 "tiger.y"
                                       { (yyval.node) = numberItem_MULTIPLY((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1696 "y.tab.c"
    break;

  case 48: /* numberItem: numberItem DIVIDE numberFrator  */
#line 145 "tiger.y"
                                       { (yyval.node) = numberItem_DIVIDE((yyvsp[-2].node), (yyvsp[0].node));}
#line 1702 "y.tab.c"
    break;

  case 49: /* numberFrator: MINUS numberFrator  */
#line 148 "tiger.y"
                                     { (yyval.node) = numberFrator_MINUS((yyvsp[0].node));}
#line 1708 "y.tab.c"
    break;

  case 50: /* numberFrator: ID  */
#line 149 "tiger.y"
                                     { (yyval.node) = numberFrator_ID((yyvsp[0].id));}
#line 1714 "y.tab.c"
    break;

  case 51: /* numberFrator: INTEGER_CONSTANT  */
#line 150 "tiger.y"
                                     { (yyval.node) = numberFrator_INTERGER_CONSTANT((yyvsp[0].ival));}
#line 1720 "y.tab.c"
    break;

  case 52: /* numberFrator: LPAREN numberExp RPAREN  */
#line 151 "tiger.y"
                                     { (yyval.node) = numberFrator_LPAREN((yyvsp[-1].node));}
#line 1726 "y.tab.c"
    break;

  case 53: /* relationOp: EQUAL  */
#line 154 "tiger.y"
                            { (yyval.reOp) = relationOp_EQUAL(); }
#line 1732 "y.tab.c"
    break;

  case 54: /* relationOp: NOT_EQUAL  */
#line 155 "tiger.y"
                            { (yyval.reOp) = relationOp_NOT_EQUAL(); }
#line 1738 "y.tab.c"
    break;

  case 55: /* relationOp: GREATER_THAN  */
#line 156 "tiger.y"
                            { (yyval.reOp) = relationOp_GREATER_THAN(); }
#line 1744 "y.tab.c"
    break;

  case 56: /* relationOp: LESS_THAN  */
#line 157 "tiger.y"
                            { (yyval.reOp) = relationOp_LESS_THAN(); }
#line 1750 "y.tab.c"
    break;

  case 57: /* relationOp: GREATER_THAN_OR_EQUAL  */
#line 158 "tiger.y"
                            { (yyval.reOp) = relationOp_GREATER_THAN_OR_EQUAL(); }
#line 1756 "y.tab.c"
    break;

  case 58: /* relationOp: LESS_THAN_OR_EQUAL  */
#line 159 "tiger.y"
                            { (yyval.reOp) = relationOp_LESS_THAN_OR_EQUAL(); }
#line 1762 "y.tab.c"
    break;


#line 1766 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 215 "tiger.y"


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
