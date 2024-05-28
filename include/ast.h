#pragma once
#include "util.h"
#include <stdio.h>

typedef struct tree_node_ *tree_node;
typedef struct tree_node_list_ *tree_node_list;

enum BINOP {
    BINOP_PLUS, 
    BINOP_MINUS, 
    BINOP_MUL, 
    BINOP_DIV, 
    BINOP_AND, 
    BINOP_OR, 
    BINOP_LSHIFT, 
    BINOP_RSHIFT, 
    BINOP_ARSHIFT, 
    BINOP_XOR
};
enum relop { EQ, NE, LT, GT, LE, GE, ULT, ULE, UGT, UGE};

struct tree_node_
{
    enum { CONST, NAME, TEMP, BINOP, MEM, CALL, ESEQ, MOVE, EXP, JUMP, CJUMP, SEQ, LABLE} kind;
    union {
        int consti;
        string name;
        tree_node temp;
        struct {enum BINOP op; tree_node left, right;} binop;
        tree_node mem;
        struct {tree_node func; tree_node_list args;} call;
        struct {tree_node stm; tree_node exp;} eseq;
        struct {tree_node dst, src;} move;
        tree_node exp;
        tree_node jump;
        struct {enum relop op; tree_node left, right; tree_node t, f;} cjump;
        struct {tree_node left, right;} seq;
        string lable;
    } u;
};

struct tree_node_list_
{
    tree_node head;
    tree_node_list tail;
};

tree_node Const(int i);
tree_node Name(string n);
tree_node Temp(tree_node t);
tree_node Binop(enum BINOP op, tree_node l, tree_node r);
tree_node Mem(tree_node m);
tree_node Call(tree_node f, tree_node_list a);
tree_node Eseq(tree_node s, tree_node e);
tree_node Move(tree_node d, tree_node s);
tree_node Exp(tree_node e);
tree_node Jump(tree_node j);
tree_node Cjump(enum relop op, tree_node l, tree_node r, tree_node t, tree_node f);
tree_node Seq(tree_node l, tree_node r);
tree_node Lable(string l);

void generateDotFile(tree_node root, const char *filename);
void print_tree_node(FILE *file, tree_node t);
const char* binop_to_string(enum BINOP op);
const char* relop_to_string(enum relop op);

tree_node_list Tree_node_list(tree_node h, tree_node_list t);
tree_node Tree_node_list_get(tree_node_list l);
tree_node_list Tree_node_list_pop(tree_node_list l);


tree_node numberFrator_MINUS(tree_node t);
tree_node numberFrator_ID(string id);
tree_node numberFrator_INTERGER_CONSTANT(int i);
tree_node numberFrator_LPAREN(tree_node t);
tree_node numberItem_numberFrator(tree_node t);
tree_node numberItem_MULTIPLY(tree_node l, tree_node r);
tree_node numberItem_DIVIDE(tree_node l, tree_node r);
tree_node numberExp_numberItem(tree_node t);
tree_node numberExp_PLUS(tree_node l, tree_node r);
tree_node numberExp_MINUS(tree_node l, tree_node r);
enum relop relationOp_EQUAL();
enum relop relationOp_NOT_EQUAL();
enum relop relationOp_GREATER_THAN();
enum relop relationOp_LESS_THAN();
enum relop relationOp_GREATER_THAN_OR_EQUAL();
enum relop relationOp_LESS_THAN_OR_EQUAL();
tree_node stringExp_STRING_CONSTANT(string s);
tree_node algorithmExp_numberExp(tree_node t);
tree_node algorithmExp_stringExp(tree_node t);
tree_node relationExpItem_algorithmExp_relationOp_algorithmExp(tree_node l, enum relop op, tree_node r);
tree_node relationExpItem_algorithmExp(tree_node t);
tree_node relationExpItem_algorithmExp_NOT_EQUAL_NIL(tree_node t);
tree_node relationExpItem_algorithmExp_EQUAL_NIL(tree_node t);
tree_node relationExpAND_relationExpItem(tree_node t);
tree_node relationExpAND_AND(tree_node l, tree_node r);
tree_node relationExpOR_relationExpAND(tree_node t);
tree_node relationExpOR_OR(tree_node l, tree_node r);
tree_node relationExp(tree_node t);
tree_node whileStm(tree_node r, tree_node s);
tree_node forStm(string id, tree_node l, tree_node r, tree_node s);
tree_node conditionStm_IF_THEN(tree_node r, tree_node s);
tree_node conditionStm_IF_THEN_ELSE(tree_node r, tree_node s1, tree_node s2);
tree_node lvalue_ID(string id);
tree_node lvalue_DOT(tree_node l, string id);
tree_node lvalue_LBRACKET(tree_node l, tree_node r);
tree_node assignStm(tree_node l, tree_node r);
tree_node assignStm_NIL(tree_node l);
tree_node stmBlock_opt(tree_node t);
tree_node stmBlock_stm(tree_node t);
tree_node stmBlock_SEMICOLON_stm(tree_node l, tree_node r);
tree_node stm_assignStm(tree_node t);
tree_node stm_conditionStm(tree_node t);
tree_node stm_whileStm(tree_node t);
tree_node stm_forStm(tree_node t);
tree_node stm_letStm(tree_node t);
tree_node stm_LPAREN_stmBlock_opt_RPAREN(tree_node t);
tree_node stm_functionCallStm(tree_node t);
tree_node prog(tree_node t);
tree_node call_paramater_algorithmExp(tree_node t);
tree_node call_paramater_functionCallStm(tree_node t);
tree_node_list call_list_first(tree_node t);
tree_node_list call_list(tree_node_list l, tree_node t);
tree_node_list call_list_opt(tree_node_list l);
tree_node functionCallStm(string id, tree_node_list l);
tree_node letStm(tree_node_list l, tree_node s);
