#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

typedef struct assignRValue_ *assignRValue;
typedef struct TypeField *type_field;
typedef struct TypeFields *type_fields;


// 定义 type 结构体
typedef struct TypeInf {
    enum { TYPE_ID, TYPE_STRUCT, TYPE_ARRAY } kind;
    union {
        char *id;  // 对应 type: ID
        type_fields fields;  // 对应 type: LBRACE type_fields_opt RBRACE
        char *arrayType;  // 对应 type: ARRAY OF ID
    };
} TypeInf, *type_inf;


// 定义 type_declaration 结构体
typedef struct TypeDeclaration {
    char *id;
    type_inf type;
} TypeDeclaration, *type_declaration;

// 定义 type_field 结构体
typedef struct TypeField {
    char *id;
    char *type;
} TypeField, *type_field;

// 定义 Field 结构体
typedef struct Field {
    char *id;
    assignRValue value;
} Field, *field;

// 定义 field_list 结构体
typedef struct FieldList {
    field head;
    struct FieldList *tail;
} FieldList, *field_list;

// 定义 variable_declaration 结构体
typedef struct VariableDeclaration {
    char *id;
    char *type;
    assignRValue value;
} VariableDeclaration, *variable_declaration;

// 定义 function_declaration 结构体
typedef struct FunctionDeclaration {
    char *id;
    char *returnType;
    type_fields parameters;
    tree_node stm;
} FunctionDeclaration, *function_declaration;


// 定义 type_fields 结构体
typedef struct TypeFields {
    TypeField *field;
    struct TypeFields *next;
} TypeFields, *type_fields;

typedef struct Declaration{
    enum { TYPE_DECLARATION, VARIABLE_DECLARATION, FUNCTION_DECLARATION } kind;
    union {
        TypeDeclaration *typeDeclaration;  // 对应 declaration: type_declaration
        VariableDeclaration *variableDeclaration;  // 对应 declaration: variable_declaration
        FunctionDeclaration *functionDeclaration;  // 对应 declaration: function_declaration
    };
} Declaration, *declaration;

// 定义 type_declaration_list 结构体
typedef struct DeclarationList {
    declaration head;
    struct DeclarationList *tail;
} DeclarationList , *declaration_list;

struct assignRValue_
{
    enum {ALGORITHMEXP, ARRAYEXP, FIELDLIST, VAULE_NIL} kind;
    union
    {
        tree_node algorithmExp;
        struct {char *id; tree_node numberExp;assignRValue rValue;} arrayExp;
        struct {char *id; field_list fields;} fieldList;
    };
};

field make_field(string name, assignRValue value);
field_list make_field_list(field head, field_list tail);
assignRValue make_algorithmExp(tree_node algorithmExp);
assignRValue make_arrayExp(char *id, tree_node numberExp, assignRValue rValue);
assignRValue make_fieldList(char *id, field_list fields);
assignRValue make_nil();
variable_declaration make_variable_declaration(char *id, char *type, assignRValue value);
type_field make_type_field(char *id, char *type);
type_fields make_type_fields(type_field field, type_fields next);
TypeInf* make_type_id(char *id);
TypeInf* make_type_struct(type_fields fields);
TypeInf* make_type_array(char *id);
type_declaration make_type_declaration(char *id, TypeInf* type);
function_declaration make_function_declaration(char *id, type_fields parameters, char *returnType, tree_node stm);
declaration make_declaration_type(type_declaration td);
declaration make_declaration_variable(variable_declaration vd);
declaration make_declaration_function(function_declaration fd);
declaration_list make_declaration_list(declaration head, declaration_list tail);

void generateDotFileForDec(declaration_list root, const char *filename);
void print_declaration_list(FILE *file, declaration_list dl,declaration_list root);
void print_type_declaration(FILE *file, type_declaration td);
void print_variable_declaration(FILE *file, variable_declaration vd);
void print_function_declaration(FILE *file, function_declaration fd);
void print_type_inf(FILE *file, type_inf t);
void print_type_fields(FILE *file, type_fields tf);
void print_assignRValue(FILE *file, assignRValue arv);
void print_field_list(FILE *file, field_list fl);