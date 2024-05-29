#include"declaration.h"
#include<time.h>

/*
field: ID EQUAL assignRValue { $$ = make_field($1, $3); }
    ;
*/

field make_field(string name, assignRValue value)
{
    field f = checked_malloc(sizeof(*f));
    f->id = name;
    f->value = value;
    return f;
}

/*
field_list: field               { $$ = make_field_list($1, NULL); }
    | field_list COMMA field    { $$ = make_field_list($3, $1); }
    ;
field_list_opt: field_list      { $$ = $1; }
    |                           { $$ = NULL; }
    ;
*/

field_list make_field_list(field head, field_list tail)
{
    field_list fl = checked_malloc(sizeof(*fl));
    fl->head = head;
    fl->tail = tail;
    return fl;
}

/*
assignRValue: algorithmExp          { $$ = make_algorithmExp($1); }
    | ID LBRACKET numberExp RBRACKET OF assignRValue { $$ = make_arrayExp($1, $3, $6); }
    | ID LBRACE field_list_opt RBRACE { $$ = make_fieldList($1, $3); }
    ;
*/

assignRValue make_algorithmExp(tree_node algorithmExp)
{
    assignRValue arv = checked_malloc(sizeof(*arv));
    arv->kind = ALGORITHMEXP;
    arv->algorithmExp = algorithmExp;
    return arv;
}

assignRValue make_arrayExp(char *id, tree_node numberExp, assignRValue rValue)
{
    assignRValue arv = checked_malloc(sizeof(*arv));
    arv->kind = ARRAYEXP;
    arv->arrayExp.id = id;
    arv->arrayExp.numberExp = numberExp;
    arv->arrayExp.rValue = rValue;
    return arv;
}

assignRValue make_fieldList(char *id, field_list fields)
{
    assignRValue arv = checked_malloc(sizeof(*arv));
    arv->kind = FIELDLIST;
    arv->fieldList.id = id;
    arv->fieldList.fields = fields;
    return arv;
}

/*
variable_declaration: VAR ID ASSIGN assignRValue { $$ = make_variable_declaration($2, NULL,$4); }
    | VAR ID COLON ID ASSIGN assignRValue       { $$ = make_variable_declaration($2, $4, $6); }
    | VAR ID COLON ID ASSIGN NIL                { $$ = make_variable_declaration($2, $4, make_nil()); }
    ;
*/

assignRValue make_nil()
{
    assignRValue arv = checked_malloc(sizeof(*arv));
    arv->kind = VAULE_NIL;
    return arv;
}

variable_declaration make_variable_declaration(char *id, char *type, assignRValue value)
{
    variable_declaration vd = checked_malloc(sizeof(*vd));
    vd->id = id;
    vd->type = type;
    vd->value = value;
    return vd;
}

/*
type_field: ID COLON ID { $$ = make_type_field($1, $3); }
    ;
*/

type_field make_type_field(char *id, char *type)
{
    type_field tf = checked_malloc(sizeof(*tf));
    tf->id = id;
    tf->type = type;
    return tf;
}

/*
type_fields: type_field             { $$ = make_type_fields($1, NULL); }
    | type_fields COMMA type_field  { $$ = make_type_fields($3, $1); }
    ;
*/

type_fields make_type_fields(type_field field, type_fields next)
{
    type_fields tfs = checked_malloc(sizeof(*tfs));
    tfs->field = field;
    tfs->next = next;
    return tfs;
}

/*
type_fields_opt: type_fields        { $$ = $1; }
    |                               { $$ = NULL; }
    ;
*/

/*
type: ID                             { $$ = make_type_id($1); }              
    | LBRACE type_fields_opt RBRACE  { $$ = make_type_struct($2); }
    | ARRAY OF ID                   { $$ = make_type_array($3); }
    ;
*/

type_inf make_type_id(char *id)
{
    type_inf t = checked_malloc(sizeof(*t));
    t->kind = TYPE_ID;
    t->id = id;
    return t;
}

type_inf make_type_struct(type_fields fields)
{
    type_inf t = checked_malloc(sizeof(*t));
    t->kind = TYPE_STRUCT;
    t->fields = fields;
    return t;
}

type_inf make_type_array(char *id)
{
    type_inf t = checked_malloc(sizeof(*t));
    t->kind = TYPE_ARRAY;
    t->arrayType = id;
    return t;
}

/*
type_declaration: TYPE ID EQUAL type        { $$ = make_type_declaration($2, $4); }
    ;
*/

type_declaration make_type_declaration(char *id, type_inf type)
{
    type_declaration td = checked_malloc(sizeof(*td));
    td->id = id;
    td->type = type;
    return td;
}

/*
function_declaration: FUNCTION ID LPAREN type_fields_opt RPAREN EQUAL stm { $$ = make_function_declaration($2, $4, NULL, $7); }
    | FUNCTION ID LPAREN type_fields_opt RPAREN COLON ID EQUAL stm          { $$ = make_function_declaration($2, $4, $7, $9); }
    ;
*/

function_declaration make_function_declaration(char *id, type_fields parameters, char *returnType, tree_node stm)
{
    function_declaration fd = checked_malloc(sizeof(*fd));
    fd->id = id;
    fd->parameters = parameters;
    fd->returnType = returnType;
    fd->stm = stm;
    return fd;
}

/*
declaration: type_declaration       { $$ = make_declaration_type($1);}
    | variable_declaration          { $$ = make_declaration_variable($1); }
    | function_declaration          { $$ = make_declaration_function($1); }
    ;
*/

declaration make_declaration_type(type_declaration td)
{
    declaration d = checked_malloc(sizeof(*d));
    d->kind = TYPE_DECLARATION;
    d->typeDeclaration = td;
    return d;
}

declaration make_declaration_variable(variable_declaration vd)
{
    declaration d = checked_malloc(sizeof(*d));
    d->kind = VARIABLE_DECLARATION;
    d->variableDeclaration = vd;
    return d;
}

declaration make_declaration_function(function_declaration fd)
{
    declaration d = checked_malloc(sizeof(*d));
    d->kind = FUNCTION_DECLARATION;
    d->functionDeclaration = fd;
    return d;
}

/*
declaration_list: declaration           { $$ = make_declaration_list($1, NULL); }
    | declaration_list declaration      { $$ = make_declaration_list($2, $1); }
    ;
*/

declaration_list make_declaration_list(declaration head, declaration_list tail)
{
    declaration_list dl = checked_malloc(sizeof(*dl));
    dl->head = head;
    dl->tail = tail;
    return dl;
}

void generateDotFileForDec(declaration_list dl, const char *filename){
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    fprintf(file, "digraph G {\n");

    // 生成 DOT 文件
    fprintf(file, "node%p [label = \"declaration list\"];\n", dl);
    print_declaration_list(file, dl,dl);

    fprintf(file, "}\n");
    fclose(file);
}

void print_declaration_list(FILE *file, declaration_list dl,declaration_list root){
    if(dl == NULL){
        return;
    }
    declaration d = dl->head;
    switch (d->kind)
    {
    case TYPE_DECLARATION:
        print_type_declaration(file, d->typeDeclaration);
        fprintf(file, "node%p -> node%p ;\n", root, d->typeDeclaration);
        break;
    case VARIABLE_DECLARATION:
        print_variable_declaration(file, d->variableDeclaration);
        fprintf(file, "node%p -> node%p ;\n", root, d->variableDeclaration);
        break;
    case FUNCTION_DECLARATION:
        print_function_declaration(file, d->functionDeclaration);
        fprintf(file, "node%p -> node%p ;\n", root, d->functionDeclaration);
        break;
    default:
        break;
    }
    print_declaration_list(file, dl->tail,root);
}

void print_type_declaration(FILE *file, type_declaration td){
    if (td == NULL)
    {
        return;
    }
    fprintf(file, "node%p [label = \"typeDec name: %s\"];\n", td, td->id);
    print_type_inf(file, td->type);
    fprintf(file, "node%p -> node%p [lable = \"type\"];\n", td, td->type);
}

void print_variable_declaration(FILE *file, variable_declaration vd){
    fprintf(file, "node%p [label = \"varDec name: %s\"];\n", vd, vd->id);
    if(vd->type != NULL){
        fprintf(file, "node%p [label = \"type: %s\"];\n", vd, vd->type);
    }
    print_assignRValue(file, vd->value);
    fprintf(file, "node%p -> node%p [lable = \"value\"];\n", vd, vd->value);
}

void print_function_declaration(FILE *file, function_declaration fd){
    fprintf(file, "node%p [label = \"funcDec name: %s\"];\n", fd, fd->id);
    if(fd->returnType != NULL){
        fprintf(file, "node%p [label = \" returnType: %s\"];\n", fd, fd->returnType);
    }
    if(fd->parameters){
        print_type_fields(file, fd->parameters);
        fprintf(file, "node%p -> node%p [lable = \"parameters\"];\n", fd, fd->parameters);
    }
    print_tree_node(file, fd->stm);
    fprintf(file, "node%p -> node%p [lable = \"stm\"];\n", fd, fd->stm);
}

void print_type_inf(FILE *file, type_inf t){
    switch (t->kind)
    {
    case TYPE_ID:
        fprintf(file, "node%p [label = \"type id: %s\"];\n", t, t->id);
        break;
    case TYPE_STRUCT:
        fprintf(file, "node%p [label = \"type struct\"];\n", t);
        print_type_fields(file, t->fields);
        fprintf(file, "node%p -> node%p [lable = \"fields\"];\n", t, t->fields);
        break;
    case TYPE_ARRAY:
        fprintf(file, "node%p [label = \"type array: %s\"];\n", t, t->arrayType);
        break;
    default:
        break;
    }
}

void print_type_fields(FILE *file, type_fields tf){
    if(tf == NULL){
        return;
    }
    type_field t = tf->field;
    fprintf(file, "node%p [label = \"type field: %s\"];\n", t, t->id);
    fprintf(file, "node%p [label = \"type: %s\"];\n", t, t->type);
    print_type_fields(file, tf->next);
    fprintf(file, "node%p -> node%p [lable = \"next\"];\n", tf, tf->next);
}

void print_assignRValue(FILE *file, assignRValue arv){
    switch (arv->kind)
    {
    case ALGORITHMEXP:
        fprintf(file, "node%p [label = \"algorithmExp\"];\n", arv);
        print_tree_node(file, arv->algorithmExp);
        fprintf(file, "node%p -> node%p [lable = \"algorithmExp\"];\n", arv, arv->algorithmExp);
        break;
    case ARRAYEXP:
        fprintf(file, "node%p [label = \"arrayExp\"];\n", arv);
        fprintf(file, "node%p [label = \"id: %s\"];\n", arv, arv->arrayExp.id);
        print_tree_node(file, arv->arrayExp.numberExp);
        fprintf(file, "node%p -> node%p [lable = \"number\"];\n", arv, arv->arrayExp.numberExp);
        print_assignRValue(file, arv->arrayExp.rValue);
        fprintf(file, "node%p -> node%p [lable = \"rValue\"];\n", arv, arv->arrayExp.rValue);
        break;
    case FIELDLIST:
        fprintf(file, "node%p [label = \"fieldList\"];\n", arv);
        fprintf(file, "node%p [label = \"id: %s\"];\n", arv, arv->fieldList.id);
        print_field_list(file, arv->fieldList.fields);
        fprintf(file, "node%p -> node%p [lable = \"fields\"];\n", arv, arv->fieldList.fields);
        break;
    case VAULE_NIL:
        fprintf(file, "node%p [label = \"nil\"];\n", arv);
        break;
    default:
        break;
    }
}

void print_field_list(FILE *file, field_list fl){
    if(fl == NULL){
        return;
    }
    field f = fl->head;
    fprintf(file, "node%p [label = \"field: %s\"];\n", f, f->id);
    print_assignRValue(file, f->value);
    fprintf(file, "node%p -> node%p [lable = \"value\"];\n", f, f->value);
    print_field_list(file, fl->tail);
    fprintf(file, "node%p -> node%p [lable = \"tail\"];\n", fl, fl->tail);
}