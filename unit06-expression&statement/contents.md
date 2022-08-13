# Unit6-運算式與陳述

## I. 運算式 expression

運算式(expression)由運算元(operand)與運算子(operator)所組成
可被簡單分為下列三種

    operand_A
    operand_A operator operand_B
    operand_A ? operand_B : operand_C

### *運算元 Operand*
----
單一運算元就構成一個運算式，運算元可以是變量、字面常數、函數或成員  

    // 以變量當運算元
    a;
    // 以字面常數當運算元
    3;
    // 呼叫 print_prompt() 當運算元
    print_prompt();

### *單元運算子 Unary Operator*
----
| 運算子 | 功能 | 範例 |
| :-: | :- | :- |
| + | 正 | +a |
| - | 負 | -a |
| ++ | 遞增 | ++a, a++ |
| -- | 遞減 | --a, a-- |
| ! | 邏輯補數運算子 | !a |


    int a = -1;
    int b = +a;  // b == -1
    int c = -a;  // c == 1
    int d = a++;  // d == 0
    int e = a--;  // e == -2

邏輯補數運算子是用作處理布林值，會將true轉false，false轉true

    bool a = true;
    bool b = !a;  // b == false
    bool c = !b;  // c == true

### *算術運算子 Arithmetic Operator*
----
結合兩個運算元作計算的運算子  

| 運算子 | 功能 | 範例 |
| :-: | :- | :- |
| + | 加 | a + b |
| - | 減 | a - b |
| * | 乘 | a * b |
| / | 除 | a / b |
| % | 取餘數 | a % b |

    int a = 10;
    int b = a + 1;  // b == 11
    int c = a - 1;  // c == 9
    int d = a * 2;  // d == 20
    int e = a / 2;  // e == 5
    int f = a % 3;  // f == 1

### *相等性及關係運算子 Equality and Relational Operator*
----
用於整數、浮點數或布林值的關係比較，返回布林值

| 運算子 | 功能 | 範例 |
| :-: | :- | :- |
| == | 等於 | a == b |
| != | 不等於 | a != b |
| > | 大於 | a > b |
| >= | 大於等於 | a >= b |
| < | 小於 | a < b |
| <= | 小於等於 | a <= b |

    int a = 1;
    int b = 2;

    bool c = a == b;  // c == false
    bool d = a != b;  // d == true
    bool e = a > b;  // e == false
    bool f = a < b;  // f == true

### *指派運算子 Assignment Operator*
----
設值指令

| 運算子 | 功能 | 範例 |
| :-: | :- | :- |
| = | 指派 | a = b |
| += | 相加後指派 | a += b |
| -= | 相減後指派 | a -= b |
| *= | 相乘後指派 | a *= b |
| /= | 相除後指派 | a /= b |
| %= | 取餘後指派 | a %= b |

    int a = 10;
    int b = 2;

    a += b;  // a == 12, b == 2
    a -= b;  // a == 10, b == 2
    a *= b;  // a == 20, b == 2
    a /= b;  // a == 10, b == 2
    a %= b;  // a == 0, b == 2


## II. 陳述 Statement

運算式加上分號就是程式中獨立的陳述(statement)，陳述為C++程式最基本的執行單位，每個C++程式都是從main()中由前而後，一個陳述一個陳述來執行。

陳述也有好幾種，最簡單的陳述就是單一個分號

    ;  // 什麼也不做的陳述