# Unit7-選擇

## if statement
    int a = 10;
    int b = 5;

    if (a > b){
        cout << "a is bigger than b" << endl;
    }
    else if (a == b){
        cout << "a is equal to b" << end;
    }
    else{
        cout << "a is smaller to b" << endl;
    }

## switch statement
    int selection = 3;
    switch(selection){
        case 0:
            printf("select 0\n");
            break;
        case 1:
            printf("select 1\n");
            break;
        case 2:
            printf("select 2\n");
            break;
        case 3:
            printf("select 3\n");
            break;
        default:
            printf("No selection.\n");
            break;
    }
default 如同 else 一樣，負責接case以外的常數值。