#include"ast.h"
#include<stdlib.h>

tree_node_list true_call_list = NULL;
tree_node_list false_call_list = NULL;

tree_node_list Tree_node_list(tree_node h, tree_node_list t)
{
    tree_node_list p = checked_malloc(sizeof(*p));
    p->head = h;
    p->tail = t;
    return p;
}

tree_node Tree_node_list_get(tree_node_list l)
{
    return l->head;
}

tree_node_list Tree_node_list_pop(tree_node_list l)
{
    tree_node_list t = l->tail;
    free(l);
    return t;
}

tree_node Const(int i)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = CONST;
    t->u.consti = i;
    return t;
}

tree_node ConstString(string s)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = CONSTSTRING;
    t->u.cstring = s;
    return t;
}

tree_node Name(string n)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = NAME;
    t->u.name = n;
    return t;
}

tree_node Temp(tree_node t)
{
    tree_node p = checked_malloc(sizeof(*p));
    p->kind = TEMP;
    p->u.temp = t;
    return p;
}

tree_node Binop(enum BINOP op, tree_node l, tree_node r)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = BINOP;
    t->u.binop.op = op;
    t->u.binop.left = l;
    t->u.binop.right = r;
    return t;
}

tree_node Mem(tree_node m)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = MEM;
    t->u.mem = m;
    return t;
}

tree_node Call(tree_node f, tree_node_list a)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = CALL;
    t->u.call.func = f;
    t->u.call.args = a;
    return t;
}

tree_node Eseq(tree_node s, tree_node e)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = ESEQ;
    t->u.eseq.stm = s;
    t->u.eseq.exp = e;
    return t;
}

tree_node Move(tree_node d, tree_node s)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = MOVE;
    t->u.move.dst = d;
    t->u.move.src = s;
    return t;
}

tree_node Exp(tree_node e)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = EXP;
    t->u.exp = e;
    return t;
}

tree_node Jump(tree_node j)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = JUMP;
    t->u.jump = j;
    return t;
}

tree_node Cjump(enum relop op, tree_node l, tree_node r, tree_node t, tree_node f)
{
    tree_node temp = checked_malloc(sizeof(*t));
    temp->kind = CJUMP;
    temp->u.cjump.op = op;
    temp->u.cjump.left = l;
    temp->u.cjump.right = r;
    temp->u.cjump.t = t;
    temp->u.cjump.f = f;
    return temp;
}

tree_node Seq(tree_node l, tree_node r)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = SEQ;
    t->u.seq.left = l;
    t->u.seq.right = r;
    return t;
}

tree_node Lable(string l)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = LABLE;
    t->u.lable = l;
    return t;
}

tree_node Let_stm(declaration_list l, tree_node s)
{
    tree_node t = checked_malloc(sizeof(*t));
    t->kind = LET_STM;
    t->u.let_stm.l = l;
    t->u.let_stm.s = s;
    return t;
}

void generateDotFile(tree_node root, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    fprintf(file, "digraph G {\n");

    // 生成 DOT 文件
    print_tree_node(file, root);

    fprintf(file, "}\n");
    fclose(file);
}

void print_tree_node(FILE *file, tree_node node){
    if (node == NULL) {
        return;
    }

    // 输出当前节点
    switch (node->kind) {
        case CONST:
            fprintf(file, "node%p [label=\"CONST %d\"];\n", node, node->u.consti);
            break;
        case CONSTSTRING:
            fprintf(file, "node%p [label=\"CONST_STR %s\"];\n", node, node->u.cstring);
            break;
        case NAME:
            fprintf(file, "node%p [label=\"NAME %s\"];\n", node, node->u.name);
            break;
        case TEMP:
            fprintf(file, "node%p [label=\"TEMP\"];\n", node);
            break;
        case BINOP:
            fprintf(file, "node%p [label=\"BINOP %s\"];\n", node, binop_to_string(node->u.binop.op));
            break;
        case MEM:
            fprintf(file, "node%p [label=\"MEM\"];\n", node);
            break;
        case CALL:
            fprintf(file, "node%p [label=\"CALL\"];\n", node);
            break;
        case ESEQ:
            fprintf(file, "node%p [label=\"ESEQ\"];\n", node);
            break;
        case MOVE:
            fprintf(file, "node%p [label=\"MOVE\"];\n", node);
            break;
        case EXP:
            fprintf(file, "node%p [label=\"EXP\"];\n", node);
            break;
        case JUMP:
            fprintf(file, "node%p [label=\"JUMP\"];\n", node);
            break;
        case CJUMP:
            fprintf(file, "node%p [label=\"CJUMP %s\"];\n", node, relop_to_string(node->u.cjump.op));
            break;
        case SEQ:
            fprintf(file, "node%p [label=\"SEQ\"];\n", node);
            break;
        case LABLE:
            fprintf(file, "node%p [label=\"LABLE %s\"];\n", node, node->u.lable);
            break;
        case LET_STM:
            fprintf(file, "node%p [label=\"LET_STM\"];\n", node);
            break;
        default:
            fprintf(file, "node%p [label=\"UNKNOWN\"];\n", node);
            break;
    }

    // 递归处理子节点
    if (node->kind == BINOP) {
        print_tree_node(file, node->u.binop.left);
        print_tree_node(file, node->u.binop.right);
        fprintf(file, "node%p -> node%p;\n", node, node->u.binop.left);
        fprintf(file, "node%p -> node%p;\n", node, node->u.binop.right);
    } else if (node->kind == MEM) {
        print_tree_node(file, node->u.mem);
        fprintf(file, "node%p -> node%p;\n", node, node->u.mem);
    } else if (node->kind == CALL) {
        print_tree_node(file, node->u.call.func);
        fprintf(file, "node%p -> node%p [label=\"func\"];\n", node, node->u.call.func);
        tree_node_list args = node->u.call.args;
        while (args != NULL) {
            print_tree_node(file, args->head);
            fprintf(file, "node%p -> node%p [label=\"args\"];\n", node, args->head);
            args = args->tail;
        }
    } else if (node->kind == ESEQ) {
        print_tree_node(file, node->u.eseq.stm);
        print_tree_node(file, node->u.eseq.exp);
        fprintf(file, "node%p -> node%p [label=\"stm\"];\n", node, node->u.eseq.stm);
        fprintf(file, "node%p -> node%p [label=\"exp\"];\n", node, node->u.eseq.exp);
    } else if (node->kind == MOVE) {
        print_tree_node(file, node->u.move.dst);
        print_tree_node(file, node->u.move.src);
        fprintf(file, "node%p -> node%p [label=\"dst\"];\n", node, node->u.move.dst);
        fprintf(file, "node%p -> node%p [label=\"src\"];\n", node, node->u.move.src);
    } else if (node->kind == EXP) {
        print_tree_node(file, node->u.exp);
        fprintf(file, "node%p -> node%p;\n", node, node->u.exp);
    } else if (node->kind == JUMP) {
        print_tree_node(file, node->u.jump);
        fprintf(file, "node%p -> node%p [label=\"dst\"];\n", node, node->u.jump);
    } else if (node->kind == CJUMP) {
        print_tree_node(file, node->u.cjump.left);
        print_tree_node(file, node->u.cjump.right);
        print_tree_node(file, node->u.cjump.t);
        print_tree_node(file, node->u.cjump.f);
        fprintf(file, "node%p -> node%p [label=\"left\"];\n", node, node->u.cjump.left);
        fprintf(file, "node%p -> node%p [label=\"right\"];\n", node, node->u.cjump.right);
        fprintf(file, "node%p -> node%p [label=\"true \"];\n", node, node->u.cjump.t);
        fprintf(file, "node%p -> node%p [label=\"false\"];\n", node, node->u.cjump.f);
    } else if (node->kind == SEQ) {
        print_tree_node(file, node->u.seq.left);
        print_tree_node(file, node->u.seq.right);
        fprintf(file, "node%p -> node%p [label=\"left\"];\n", node, node->u.seq.left);
        fprintf(file, "node%p -> node%p [label=\"right\"];\n", node, node->u.seq.right);
    } else if(node->kind == LET_STM) {
        fprintf(file, "node%p [label = \"declaration list\"];\n", node->u.let_stm.l);
        print_declaration_list(file, node->u.let_stm.l, node->u.let_stm.l);
        print_tree_node(file, node->u.let_stm.s);
        fprintf(file, "node%p -> node%p [label=\"declaration\"];\n", node, node->u.let_stm.l);
        fprintf(file, "node%p -> node%p [label=\"statement\"];\n", node, node->u.let_stm.s);
    }

}

const char* binop_to_string(enum BINOP op) {
    switch (op) {
        case BINOP_PLUS:
            return "PLUS";
        case BINOP_MINUS:
            return "MINUS";
        case BINOP_MUL:
            return "MUL";
        case BINOP_DIV:
            return "DIV";
        case BINOP_AND:
            return "AND";
        case BINOP_OR:
            return "OR";
        case BINOP_LSHIFT:
            return "LSHIFT";
        case BINOP_RSHIFT:
            return "RSHIFT";
        case BINOP_ARSHIFT:
            return "ARSHIFT";
        case BINOP_XOR:
            return "XOR";
        default:
            return "UNKNOWN_BINOP";
    }
}

const char* relop_to_string(enum relop op) {
    switch (op) {
        case EQ:
            return "EQ";
        case NE:
            return "NE";
        case LT:
            return "LT";
        case GT:
            return "GT";
        case LE:
            return "LE";
        case GE:
            return "GE";
        case ULT:
            return "ULT";
        case ULE:
            return "ULE";
        case UGT:
            return "UGT";
        case UGE:
            return "UGE";
        default:
            return "UNKNOWN_RELOP";
    }
}

/*
numberFrator: MINUS numberFrator     { $$ = numberFrator_MINUS($2);}
    | ID                             { $$ = numberFrator_ID($1);}       
    | INTEGER_CONSTANT               { $$ = numberFrator_INTERGER_CONSTANT($1);}
    | LPAREN numberExp RPAREN        { $$ = numberFrator_LPAREN($2);}     
    ;
*/
tree_node numberFrator_MINUS(tree_node t)
{
    return Binop(BINOP_MINUS, Const(0), t);
}

tree_node numberFrator_ID(string id)
{
    return Name(id);
}

tree_node numberFrator_INTERGER_CONSTANT(int i)
{
    return Const(i);
}

tree_node numberFrator_LPAREN(tree_node t)
{
    return t;
}

/*
numberItem: numberFrator               { $$ = numberItem_numberFrator($1); }
    | numberItem MULTIPLY numberFrator { $$ = numberItem_MULTIPLY($1, $3); }
    | numberItem DIVIDE numberFrator   { $$ = numberItem_DIVIDE($1, $3);}
    ;
*/

tree_node numberItem_numberFrator(tree_node t)
{
    return t;
}

tree_node numberItem_MULTIPLY(tree_node l, tree_node r)
{
    return Binop(BINOP_MUL, l, r);
}

tree_node numberItem_DIVIDE(tree_node l, tree_node r)
{
    return Binop(BINOP_DIV, l, r);
}

/*
numberExp: numberItem               { $$ = numberExp_numberItem($1);}
    | numberExp PLUS numberItem     { $$ = numberExp_PLUS($1, $3);}
    | numberExp MINUS numberItem    { $$ = numberExp_MINUS($1, $3);}
    ;
*/

tree_node numberExp_numberItem(tree_node t)
{
    return t;
}

tree_node numberExp_PLUS(tree_node l, tree_node r)
{
    return Binop(BINOP_PLUS, l, r);
}

tree_node numberExp_MINUS(tree_node l, tree_node r)
{
    return Binop(BINOP_MINUS, l, r);
}

/*
relationOp: EQUAL           { $$ = relationOp_EQUAL(); }
    | NOT_EQUAL             { $$ = relationOp_NOT_EQUAL(); }
    | GREATER_THAN          { $$ = relationOp_GREATER_THAN(); }
    | LESS_THAN             { $$ = relationOp_LESS_THAN(); }
    | GREATER_THAN_OR_EQUAL { $$ = relationOp_GREATER_THAN_OR_EQUAL(); }
    | LESS_THAN_OR_EQUAL    { $$ = relationOp_LESS_THAN_OR_EQUAL(); }
    ;
*/

enum relop relationOp_EQUAL()
{
    return EQ;
}

enum relop relationOp_NOT_EQUAL()
{
    return NE;
}

enum relop relationOp_GREATER_THAN()
{
    return GT;
}

enum relop relationOp_LESS_THAN()
{
    return LT;
}

enum relop relationOp_GREATER_THAN_OR_EQUAL()
{
    return GE;
}

enum relop relationOp_LESS_THAN_OR_EQUAL()
{
    return LE;
}

/*
stringExp: STRING_CONSTANT  { $$ = stringExp_STRING_CONSTANT($1); }
    ;
*/

tree_node stringExp_STRING_CONSTANT(string s)
{
    return ConstString(s);
}

/*
algorithmExp: numberExp     { $$ = algorithmExp_numberExp($1); }                   
    | stringExp             { $$ = algorithmExp_stringExp($1); }
    ;
*/

tree_node algorithmExp_numberExp(tree_node t)
{
    return t;
}

tree_node algorithmExp_stringExp(tree_node t)
{
    return t;
}

/*
relationExpItem: algorithmExp relationOp algorithmExp   { $$ = relationExpItem_algorithmExp_relationOp_algorithmExp($1, $2, $3); }
    | algorithmExp                                      { $$ = relationExpItem_algorithmExp($1); }
    | algorithmExp NOT_EQUAL NIL                        { $$ = relationExpItem_algorithmExp_NOT_EQUAL_NIL($1); }
    | algorithmExp EQUAL NIL                            { $$ = relationExpItem_algorithmExp_EQUAL_NIL($1); }
    ;
*/

tree_node relationExpItem_algorithmExp_relationOp_algorithmExp(tree_node l, enum relop op, tree_node r)
{
    tree_node t = Cjump(op, l, r, NULL, NULL);
    true_call_list = Tree_node_list(t, true_call_list);
    false_call_list = Tree_node_list(t, false_call_list);
    return t;
}

tree_node relationExpItem_algorithmExp(tree_node t)
{
    tree_node f = Lable("empty");
    tree_node r = Cjump(NE, t, f, NULL, NULL);
    true_call_list = Tree_node_list(r, true_call_list);
    false_call_list = Tree_node_list(r, false_call_list);
    return r;
}

tree_node relationExpItem_algorithmExp_NOT_EQUAL_NIL(tree_node t)
{
    tree_node f = Lable("nil");
    tree_node r = Cjump(NE, t, f, NULL, NULL);
    true_call_list = Tree_node_list(r, true_call_list);
    false_call_list = Tree_node_list(r, false_call_list);
    return r;
}

tree_node relationExpItem_algorithmExp_EQUAL_NIL(tree_node t)
{
    tree_node f = Lable("nil");
    tree_node r = Cjump(EQ, t, f, NULL, NULL);
    true_call_list = Tree_node_list(r, true_call_list);
    false_call_list = Tree_node_list(r, false_call_list);
    return r;
}

/*
relationExpAND: relationExpItem                 { $$ = relationExpAND_relationExpItem($1);}
    | relationExpAND AND relationExpItem        { $$ = relationExpAND_AND($1, $3); }
    ;
*/

tree_node relationExpAND_relationExpItem(tree_node t)
{
    return t;
}

tree_node relationExpAND_AND(tree_node l, tree_node r)
{
    tree_node true_label = Lable("true");
    tree_node temp = Seq(l, true_label);
    temp = Seq(temp, r);

    tree_node true_call_node_save = Tree_node_list_get(true_call_list);//this is r
    true_call_list = Tree_node_list_pop(true_call_list);

    tree_node true_call_node = Tree_node_list_get(true_call_list); //this is l's right end node
    true_call_node->u.cjump.t = true_label;
    true_call_list = Tree_node_list_pop(true_call_list);

    true_call_list = Tree_node_list(true_call_node_save, true_call_list);
    return temp;
}

/*
relationExpOR: relationExpAND           { $$ = relationExpOR_relationExpAND($1); }
    | relationExpOR OR relationExpAND   { $$ = relationExpOR_OR($1, $3); }
    ;
*/

tree_node relationExpOR_relationExpAND(tree_node t)
{
    return t;
}

tree_node relationExpOR_OR(tree_node l, tree_node r)
{
    tree_node false_label = Lable("false");
    tree_node temp = Seq(l, false_label);
    temp = Seq(temp, r);

    tree_node false_call_node_save = Tree_node_list_get(false_call_list);//this is r
    false_call_list = Tree_node_list_pop(false_call_list);
    while(false_call_list != NULL)
    {
        tree_node false_call_node = Tree_node_list_get(false_call_list);
        false_call_node->u.cjump.f = false_label;
        false_call_list = Tree_node_list_pop(false_call_list);
    }
    false_call_list = Tree_node_list(false_call_node_save, false_call_list);
    return temp;
}

/*
relationExp: relationExpOR      { $$ = relationExp($1); }
    ;
*/

tree_node relationExp(tree_node t)
{
    return t;
}

/*
whileStm: WHILE relationExp DO stm { $$ = whileStm($2, $4); }
    ;
*/

tree_node whileStm(tree_node r, tree_node s)
{
    tree_node begin_label = Lable("begin");
    tree_node begin_body = Lable("begin_body");
    tree_node end_label = Lable("end");
    tree_node temp = Seq(begin_label, r);
    temp = Seq(temp, begin_body);
    temp = Seq(temp, s);
    temp = Seq(temp, Jump(begin_label));
    temp = Seq(temp, end_label);
    while(true_call_list != NULL)
    {
        tree_node true_call_node = Tree_node_list_get(true_call_list);
        true_call_node->u.cjump.t = begin_body;
        true_call_list = Tree_node_list_pop(true_call_list);
    }
    while(false_call_list != NULL)
    {
        tree_node false_call_node = Tree_node_list_get(false_call_list);
        false_call_node->u.cjump.f = end_label;
        false_call_list = Tree_node_list_pop(false_call_list);
    }
    return temp;
}

/*
forStm: FOR ID ASSIGN numberExp TO numberExp DO stm { $$ = forStm($2, $4, $6, $8); }
    ;
*/

tree_node forStm(string id, tree_node l, tree_node r, tree_node s)
{
    tree_node begin_label = Lable("begin");
    tree_node begin_body = Lable("begin_body");
    tree_node end_label = Lable("end");
    tree_node temp = Move(Name(id), l);
    temp = Seq(temp, begin_label);
    temp = Seq(temp, Cjump(LE, Name(id), r, begin_body, end_label));
    temp = Seq(temp, begin_body);
    temp = Seq(temp, s);
    temp = Seq(temp, Move(Name(id), Binop(BINOP_PLUS, Name(id), Const(1))));
    temp = Seq(temp, Jump(begin_label));
    temp = Seq(temp, end_label);
    return temp;
}

/*
conditionStm: IF relationExp THEN stm %prec LOWER_THAN_ELSE { $$ = conditionStm_IF_THEN($2, $4); }
    | IF relationExp THEN stm ELSE stm { $$ = conditionStm_IF_THEN_ELSE($2, $4, $6); }
    ;
*/

tree_node conditionStm_IF_THEN(tree_node r, tree_node s)
{
    tree_node begin_label = Lable("begin");
    tree_node end_label = Lable("end");
    tree_node temp = Seq(r,begin_label);
    temp = Seq(temp, s);
    temp = Seq(temp, end_label);
    while(true_call_list != NULL)
    {
        tree_node true_call_node = Tree_node_list_get(true_call_list);
        true_call_node->u.cjump.t = begin_label;
        true_call_list = Tree_node_list_pop(true_call_list);
    }
    while(false_call_list != NULL)
    {
        tree_node false_call_node = Tree_node_list_get(false_call_list);
        false_call_node->u.cjump.f = end_label;
        false_call_list = Tree_node_list_pop(false_call_list);
    }
    return temp;
}

tree_node conditionStm_IF_THEN_ELSE(tree_node r, tree_node s1, tree_node s2)
{
    tree_node begin_label = Lable("begin");
    tree_node else_label = Lable("else");
    tree_node end_label = Lable("end");
    tree_node temp = Seq(r,begin_label);
    temp = Seq(temp, s1);
    temp = Seq(temp, Jump(end_label));
    temp = Seq(temp, else_label);
    temp = Seq(temp, s2);
    temp = Seq(temp, end_label);
    while(true_call_list != NULL)
    {
        tree_node true_call_node = Tree_node_list_get(true_call_list);
        true_call_node->u.cjump.t = begin_label;
        true_call_list = Tree_node_list_pop(true_call_list);
    }
    while(false_call_list != NULL)
    {
        tree_node false_call_node = Tree_node_list_get(false_call_list);
        false_call_node->u.cjump.f = else_label;
        false_call_list = Tree_node_list_pop(false_call_list);
    }
    return temp;
}


/*
lvalue: ID                                          { $$ = lvalue_ID($1); }    
    | lvalue DOT ID                                 { $$ = lvalue_DOT($1, $3); }
    | lvalue LBRACKET numberExp RBRACKET            { $$ = lvalue_LBRACKET($1, $3);}
    ;
*/

tree_node lvalue_ID(string id)
{
    return Name(id);
}

tree_node lvalue_DOT(tree_node l, string id)
{   
    //int offset = lookup(l, id); find the offset of id in struct 
    int offset = 0;
    return Mem(Binop(BINOP_PLUS, l, Const(offset)));
}

tree_node lvalue_LBRACKET(tree_node l, tree_node r)
{
    return Mem(Binop(BINOP_PLUS, l, r));
}

/*
assignStm: lvalue ASSIGN algorithmExp       { $$ = assignStm($1, $3); }
    | lvalue ASSIGN NIL                     { $$ = assignStm_NIL($1); }
    ;
*/

tree_node assignStm(tree_node l, tree_node r)
{
    return Move(l, r);
}

tree_node assignStm_NIL(tree_node l)
{
    return Move(l, Lable("nil"));
}

/*
stmBlock_opt: stmBlock { $$ = stmBlock_opt($1); }
    |                   { $$ = NULL; } 
    ;
*/

tree_node stmBlock_opt(tree_node t)
{
    return t;
}

/*
stmBlock: stm                   { $$ = stmBlock_stm($1); }
    | stmBlock SEMICOLON stm    { $$ = stmBlock_SEMICOLON_stm($1, $3); }
    ;
*/

tree_node stmBlock_stm(tree_node t)
{
    return t;
}

tree_node stmBlock_SEMICOLON_stm(tree_node l, tree_node r)
{
    return Seq(l, r);
}

/*
stm : assignStm                     { $$ = stm_assignStm($1); }
    | conditionStm                  { $$ = stm_conditionStm($1); }
    | whileStm                      { $$ = stm_whileStm($1); }
    | forStm                        { $$ = stm_forStm($1); }
    | letStm                        { $$ = stm_letStm($1); }
    | LPAREN stmBlock_opt RPAREN    { $$ = stm_LPAREN_stmBlock_opt_RPAREN($2); }
    | functionCallStm               { $$ = stm_functionCallStm($1); }
    ;
*/

tree_node stm_assignStm(tree_node t)
{
    return t;
}

tree_node stm_conditionStm(tree_node t)
{
    return t;
}

tree_node stm_whileStm(tree_node t)
{
    return t;
}

tree_node stm_forStm(tree_node t)
{
    return t;
}

tree_node stm_letStm(tree_node t)
{
    return t;
}

tree_node stm_LPAREN_stmBlock_opt_RPAREN(tree_node t)
{
    return t;
}

tree_node stm_functionCallStm(tree_node t)
{
    return t;
}

/*
prog : stm	{printf("语法分析成功！\n"); $$ = prog($1);}
	;
*/

tree_node prog(tree_node t)
{
    return t;
}


/*
call_paramater: algorithmExp        { $$ = call_paramater_algorithmExp($1); }
    | functionCallStm               { $$ = call_paramater_functionCallStm($1); }
    ;
*/

tree_node call_paramater_algorithmExp(tree_node t)
{
    return t;
}

tree_node call_paramater_functionCallStm(tree_node t)
{
    return t;
}

/*
call_list: call_paramater               { $$ = call_list_first($1); }
    | call_list COMMA call_paramater    { $$ = call_list($1, $3); }
    ;
*/

tree_node_list call_list_first(tree_node t)
{
    return Tree_node_list(t, NULL);
}

tree_node_list call_list(tree_node_list l, tree_node t)
{
    return Tree_node_list(t, l);
}

/*
call_list_opt: call_list            { $$ = call_list_opt($1); }
    |                               { $$ = NULL; }
    ;
*/

tree_node_list call_list_opt(tree_node_list l)
{
    return l;
}

/*
functionCallStm: ID LPAREN call_list_opt RPAREN     { $$ = functionCallStm($1, $3); }
    ;
*/

tree_node functionCallStm(string id, tree_node_list l)
{
    return Call(Name(id), l);
}

/*
letStm: LET declaration_list IN stm END             { $$ = letStm($2, $4); }
    ;
*/

tree_node letStm(declaration_list l, tree_node s)
{
    return Let_stm(l, s);
}


