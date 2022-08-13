# 基本內建型態與物件

## Primitive Builtin Type and Arithmetic Type

### Primitive Builtin Type (Common)

| Type | Keyword | Size | Range |
| :---- | :---- | :---- | :----: |
| 布林 | bool | True, False |  |
| 字元 | char | 1 byte |  |
| 寬字元 | wchar_t | 2 byte |  |
| 短整數 | short | 2 byte | -32768 ~ 32767 |
| 整數 | int | 4 byte | -2147483648 〜 2147483647 |
| 長整數 | long | 4 byte | -2147483648 〜 2147483647 |
| 浮點數 | float | 4 byte |  |
| 浮點數 | double | 8 byte |  |
| 浮點數 | long double | 12 or 16 byte |  |
| UTF-16 字元 | char16_t |  |  |
| UTF-32 字元 | char32_t |  |  |
| 超長整數 | long long | 8 byte | 不重要了 |

    Hint:
    1 byte = 8 bit
    1 bit represents 0 or 1
    1 byte can represent 2 ** 8 = 256 values;
    2 byte ... 256 * 256 = 65,536 values;
    .
    .
    .

Example

    bool a = true;
    char b = '2';
    int c = 2;
    double d = 2.0;