#include "Calculator.h"
#include "LinkedStack.h"

void Cal_Input(char cal[]){ // 계산식을 입력 받는 함수
    gets(cal);
}

int Cal_Priority(char opt){ // 우선순위 매겨주기
    switch (opt){
        case '(' : return 1;
        case '+' :
        case '-' : return 2;
        case '*' :
        case '/' : return 3;
    }
}

void Cal_Change(char cal[], char postfix[]){ // 후위표기법으로 변환하는 함수

    int tmp=1; // 숫자 문자를 숫자로 변환할 때 쓰인다
    int i,postfix_index=0; // 후위표기법 배열은 계산식 배열과 인덱스를 따로 쓴다

    SInit_CHAR(); // 연산자 스택 초기화
    SInit_DOUBLE(); // 후위 연산 스택 초기화

    for(i=0; cal[i]!='\0'; i++){
        // 숫자이면 후위표기법 배열로 바로 넘긴다
        if(cal[i] >= '0' && cal[i] <= '9'){
            postfix[postfix_index] = cal[i];
            postfix_index++;
        } else {
            postfix[postfix_index] = ' ';
            postfix_index++;
            switch(cal[i]){
                case '+' :
                case '-' :
                case '*' :
                case '/' :
                            // (스택 안에 있는 연산자 > 지금 받은 연산자) 일 때까지
                            // 스택 안에 있는 연산자 후위표기법 배열로 넘긴다
                            while(Cal_Priority(SPeek_CHAR(top_CHAR)) > Cal_Priority(cal[i])){
                                postfix[postfix_index] = SPop_CHAR(top_CHAR);
                                postfix_index++;
                            }
                            // 아니면 연산자 스택에 넣는다
                            SPush_CHAR(top_CHAR,cal[i]);
                            break;
                case '(' :
                            // 연산자 스택에 넣는다
                            SPush_CHAR(top_CHAR,cal[i]);
                            break;
                case ')' :
                            // '(' 까지 있는 모든 연산자를 후위표기법 배열로 넘긴다
                            while(SPeek_CHAR(top_CHAR) != '('){
                                postfix[postfix_index] = SPop_CHAR(top_CHAR);
                                postfix_index++;
                            }
                            SPop_CHAR(top_CHAR);
                            break;
            }
        }
    }
    postfix[postfix_index] = ' ';
    postfix_index++;
    while(SPeek_CHAR(top_CHAR) != -1){ // 계산식 다 검사하고, 연산자 스택에 남아있는 것을 후위표기식으로 만든다
        postfix[postfix_index] = SPop_CHAR(top_CHAR);
        postfix_index++;
    }
}

void Cal_Result(char postfix[]){ // 후위표기법 계산하기
    int i,j;
    double tmp;
    double a,b; // 피연산자 두 개
    for(i=0;postfix[i]!='\0';i++){
        tmp=0;
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            for(j=i;postfix[j] >= '0' && postfix[j] <= '9';j++){
                tmp*=10;
                tmp+=postfix[j]-'0';
            }
            i=j-1;
            // 피연산자이면 스택에 넣는다
            SPush_DOUBLE(top_DOUBLE,tmp);
        } else if(postfix[i] != ' '){
            // 연산자라면 피연산자 두 개를 꺼내서 연산한다
            a = SPop_DOUBLE(top_DOUBLE);
            b = SPop_DOUBLE(top_DOUBLE);
            switch(postfix[i]){
                case '+' : SPush_DOUBLE(top_DOUBLE,b+a); break;
                case '-' : SPush_DOUBLE(top_DOUBLE,b-a); break;
                case '*' : SPush_DOUBLE(top_DOUBLE,b*a); break;
                case '/' : SPush_DOUBLE(top_DOUBLE,b/a); break;
            }
        }
    }
    printf("%.3lf",SPop_DOUBLE(top_DOUBLE));
}
