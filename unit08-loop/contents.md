# Unit8-迴圈

## I. while loop statement

### *以計數方式設計的while迴圈*
----

    int i = 10;
    while (i > 0){
        printf("i = %d\n", i);
        i--;
    }
### *以條件+break形式設計的迴圈*
----

    int j = 10;
    while (true){
        if (j == 5){
            break;
        }
        printf("j = %d\n", j);
        j--;
    }

## II. for loop statement

### *以計數方式設計的for迴圈*  
----
for(宣告變量陳述; 條件判斷陳述; 變量調整運算式)

    for(int i = 0; i < 10; i++){
        printf("i = %d\n", i);
    }

