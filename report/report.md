# Compile Principle 编译原理期末项目报告

3210106185 金杭伟

## 题目要求

用lex写出一个tiger语言或者类C或者类PASCAL某个语言的词法分析器，用YACC的分析方法完成对某一个的语法分析，并生成语法树和中间代码（如果生成目标代码：可加分）。 (15分)

## 背景知识

### tiger文法

这部分的内容来自 *Tiger Language Reference Manual*

#### Lexical Aspects

1. 标识符由字母、数字和下划线组成，以字母开头，区分大小写。

2. 可以在标记之间使用空白字符或注释，这些将被忽略。注释以 /\* 开始，以 \*/ 结束，并支持嵌套。

3. 整数常量由一个或多个十进制数字组成，不支持负整数常量；可以通过一元运算符 - 对整数常量进行取反得到负数。

4. 字符串常量由双引号 " 包围，可以包含可打印字符、空格或转义序列。转义序列以反斜杠 \ 开头，表示特定的字符序列，例如 \n 表示换行符。

5. 预留关键字包括 array break do else end for function if in let nil of then to type var while。

6. 标点符号包括 , : ; ( ) [ ] { } . + - * / = <> < <= > >= & | :=。

#### Expressions

A Tiger program is a single expr.

```txt
expr:
    string-constant
    integer-constant
    nil
    lvalue
    - expr
    expr binary-operator expr
    lvalue := expr
    id ( expr-listopt )
    ( expr-seqopt )
    type-id { field-listopt }
    type-id [ expr ] of expr
    if expr then expr
    if expr then expr else expr
    while expr do expr
    for id := expr to expr do expr
    break
    let declaration-list in expr-seqopt end
expr-seq:
    expr
    expr-seq ; expr
expr-list:
    expr
    expr-list , expr
field-list:
    id = expr
    field-list , id = expr
```

* Lvalues

    ```txt
    lvalue:
        id
        lvalue . id
        lvalue [ expr ]
    ```

    Lvalues（左值）表示可以赋值的存储位置，包括变量、参数、记录字段和数组元素。

* Return values

    返回值：过程调用、赋值、if-then、while、break以及有时的if-then-else语句不产生值，不能出现在需要值的地方。空的let表达式返回无值。用括号括起来的零个或多个表达式通过分号分隔，在括号内按顺序求值，并返回最后一个表达式的值（如果有）。

* Record and Array Literals

    记录和数组字面量：type-id { field-listopt } 创建类型为type-id的新记录实例；type-id [ expr ] of expr创建大小由中括号内的表达式给出的type-id新数组，初始时由of后的表达式给出的值填充。

* Function Calls

    函数调用：函数应用是一个表达式id(expr-listopt)，其中有零个或多个用逗号分隔的表达式参数。在函数调用时，实际参数的值从左到右求值，并根据常规的静态作用域规则绑定到函数的形式参数上。

* Operators

    1. 二元运算符包括 +、-、*、/、=、<>、<、>、<=、>=、& 和 |。
    1. 括号按照通常方式分组表达式。
    领先的减号表示对整数表达式取反。
    1. +、-、* 和 / 需要整数操作数，并返回整数结果。
    1. 比较运算符对其操作数进行比较，如果比较成立则返回否则返回0。
    1. 逻辑运算符 & 和 | 是整数的惰性逻辑运算符。

* Assignment

    1. 赋值表达式 lvalue := expr 将表达式的值绑定到 lvalue 的内容。
    1. 数组和记录的赋值是按引用而非数值进行的。
    1. 记录或数组值从创建至程序结束都持续存在。

* nil

    1. 空值（nil）表示可以分配给任何记录类型的值。
    1. 从空值记录中访问字段会导致运行时错误。

* 流程控制

    1. if-then-else：计算第一个表达式，如果结果非零，则计算第二个表达式并返回其结果；否则，计算第三个表达式并返回其结果。第二和第三个表达式必须是相同类型或都不返回值。
    1. if-then：计算第一个表达式，如果结果非零，则计算第二个表达式，该表达式不得返回值。if-then表达式不返回值。
    1. while-do：计算第一个表达式，如果结果非零，则计算第二个表达式，该表达式不得返回值，并重新计算while-do表达式。
    1. for：计算第一和第二个表达式（循环界限），然后对于这两个表达式值之间的每个整数（包括两端），计算第三个表达式，其中由id命名的整型变量绑定到循环索引。此变量的作用域限于第三个表达式，且不可被赋值。如果循环的上界小于下界，则此表达式可能不产生结果且不被执行。
    1. break：终止最内层的while或for表达式，该表达式必须与break在同一函数/过程中。在此外使用break是非法的。

* Let

    let declaration-list in expr-seq-opt end：计算声明，将类型、变量和函数绑定到表达式序列的作用域内。结果是最后一个表达式的结果，如果没有表达式则为无。

#### 声明

1. Types

    declaration-list:
        declaration
        declaration-list declaration
    declaration:
        type-declaration
        variable-declaration
        function-declaration
    type-declaration:
        type type-id = type
    type:
        type-id
        { type-fieldsopt }
        array of type-id
    type-fields:
        type-field
        type-fields , type-field
    type-field:
        id : type-id

    * Tiger语言有两种预定义类型：int和string。新类型可以通过以下方式定义或重新定义现有类型。

    * 类型表达式（例如，fx:intg、array of ty）创建不同的类型，因此具有相同基础的两个数组类型或具有相同字段的两个记录是不同的。Type a=b是别名。

    * 一系列类型声明（即，没有中间变量或函数声明）可以是相互递归的。这样的序列中没有两个定义的类型可以具有相同的名称。每个递归循环必须通过一个记录或数组类型。在let ... type-declaration ... in expr-seqopt end中，类型声明的作用域从它所属的类型声明序列的开始（可能是单个元素）到结束。

    * 类型名称有自己的命名空间。

2. Variables

    variable-declaration:
        var id := expr
        var id : type-id := expr

    如果没有指定类型，则变量的类型来自表达式。在let ... variable-declaration ... in expr-seqopt end中，变量声明的作用域从声明之后开始，到结束为止。变量在其作用域内一直存在。变量和函数共享相同的命名空间。

3. Functions

    function-declaration:
        function id ( type-fieldsopt ) = expr
        function id ( type-fieldsopt ) : type-id = expr

    函数返回指定类型的值，而过程仅用于其副作用。两种形式都允许指定零个或多个带类型的参数，这些参数按值传递。这些参数的作用域是expr。

    expr是函数或过程的主体。一系列函数声明（即，没有中间变量或类型声明）可以是相互递归的。这样的序列中没有两个函数可以具有相同的名称。在let ... function-declaration ... in expr-seqopt end中，函数声明的作用域从它所属的函数声明序列的开始（可能是单个元素）到结束。

## 词法实现

1. token：读入对应关键字即返回对应的token

    ![alt text](image-1.png)

1. 解析时同时返回值：使用yytext和yylval保存解析的内容

    ![alt text](image-2.png)

    值得注意的是，这里的sval和ival变量需要在tiger.y文件的union模块中定义：

    ![alt text](image-3.png)

1. 嵌套注释：针对这个情况，我特意在lex中设计了COMMENT模式和对应的嵌套次数计数器，这样可以完美解决嵌套注释的问题。

    ![alt text](image.png)

## 文法实现

1. 文法实现是一个大工程，使用yacc完成文法分析后实际上得到的就是一个AST(抽象文法树)，那么就可以直接将这个抽象文法树转换成中间代码形式。

1. 初始的symbol是一个stm

    ![alt text](image-5.png)

1. stm可以派生出的语句如下：

    ![alt text](image-4.png)

1. 为了体现加减乘除和取负之间的优先级关系，在这里将number表达式分成了不同的level，这样，通过不同level之间的分离，可以很好地确保算式的计算顺序和我们预先设定的相同。

    ![alt text](image-6.png)

1. 同理对relationOp也有对应的考虑，首先是OR语句，再是AND语句；同时我也考虑到了relationItem中出现NIL的情况，并特殊考虑了。

    ![alt text](image-7.png)

1. for语句的else需要特殊考虑，对对应的优先级进行了处理。

    ![alt text](image-8.png)

1. functionCallStm：特殊考虑了哈数调用作为参数的情况。这里的参数可选relationItemLeft主要是为了引入数组和结构体的情况，直接就用了现成的symbol.

    ![alt text](image-9.png)

1. 其余的函数声明的部分的文法和第一部分中给出的文法类似，此处省略。

## 生成中间代码

1. 参照教科书中的中间代码形式，我给出了类似的中间代码结构。可见CONST,CONSTSTRING, NAME, TEMP, BINOP, MEM, CALL, ESEQ, MOVE, EXP, JUMP, CJUMP, SEQ, LABLE语句和教科书中的大致相似。

    ![alt text](image-10.png)

1. 不同之处：

    在本中间代码中的CJUMP和JUMP语句的true和false的地方不是标签值，而是tree_node的地址，亦即直接指向对应的节点。

    加入了LET_STM即Let语句对应的节点，这是为了方便统合declaration和in_block的树结构，方便输出中间代码结果。

1. 中间代码生成过程：在本程序中，中间代码生成类似模拟计算机如何执行这些指令，如whileStm先赋值，在加begin标签，再判断，在加begin_body标签，在这个结构体的末尾加上jump语句和end标签。其余的代码生成是类似的。

    ![alt text](image-11.png)

1. truelist和falselist的回填

    在处理CJUMP时，一开始我们不知道正确标签和错误标签的填法，需要处理到后面才能回填。

    具体而言，对于AND语句，计算到下一个时，就能回填上一个的true_lable,直到遇见OR语句，即剩下一个truelable没填。

    ![alt text](image-12.png)

    对于OR语句，则可以将积累的falselable全部填完，

    ![alt text](image-13.png)

    对于总的whileStm,由于此时都知道了truelable和falselable的去向，将所有累计的truelist和falselist全部填完即可。

    ![alt text](image-14.png)

1. declaration语句：

    declaration分为type,variable和function三类。这一部分的代码比较繁琐，但是基本上只是重构抽象文法树，在这个部分，我没有完成类型判断，主要是太麻烦了。

    ![alt text](image-15.png)

    对应特殊的function declaration, 本程序同样将它的代码块的中间表示也生成了。

1. 最终的中间代码展示：

    为了更好地可视化，我们引入了Graphviz模块生成中间代码的图示。dot文件的格式比较简单，包括节点名字内容和对应的边信息就行了，生成dot文件的generateDotFile()函数基本上是一个递归调用的过程。

    ![alt text](image-16.png)

## 测试结果

1. testcase1:简单赋值语句

    ![alt text](image-17.png)

    ![alt text](testcase1_tree.png)

1. testcase2:简单if语句

    ![alt text](image-18.png)

    ![alt text](testcase2_tree.png)

1. testcase3:复杂if语句

    ![alt text](image-19.png)

    ![alt text](testcase3_tree.png)

1. testcase4:while语句

    ![alt text](image-20.png)

    ![alt text](testcase4_tree.png)

1. testcase5: for语句

    ![alt text](image-21.png)

    ![alt text](testcase5_tree.png)

1. testcase6: 复杂let语句

    ![alt text](image-22.png)

    ![alt text](testcase6_tree.png)

1. testcase7: 复杂let语句(2)

    ![alt text](image-23.png)

    ![alt text](testcase7_tree.png)

1. testcase8: let语句

    ![alt text](image-24.png)

    ![alt text](testcase8_tree.png)