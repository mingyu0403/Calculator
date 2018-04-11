#include <stdio.h>
#include "Calculator.h"

int main(){

    char cal[100] = ""; // 계산식이 들어갈 배열
    char postfix[100] = ""; // 후위표기법이 들어갈 배열

    Cal_Input(cal); // 계산식 입력 받기

    Cal_Change(cal,postfix); // 수식을 후위표기법으로 변환하기

    Cal_Result(postfix); // 계산하고 답 출력하기

    return 0;

}
