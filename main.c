#include <stdio.h>
#include "Calculator.h"

int main(){

    char cal[100] = ""; // ������ �� �迭
    char postfix[100] = ""; // ����ǥ����� �� �迭

    Cal_Input(cal); // ���� �Է� �ޱ�

    Cal_Change(cal,postfix); // ������ ����ǥ������� ��ȯ�ϱ�

    Cal_Result(postfix); // ����ϰ� �� ����ϱ�

    return 0;

}
