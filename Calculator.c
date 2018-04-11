#include "Calculator.h"
#include "LinkedStack.h"

void Cal_Input(char cal[]){ // ������ �Է� �޴� �Լ�
    gets(cal);
}

int Cal_Priority(char opt){ // �켱���� �Ű��ֱ�
    switch (opt){
        case '(' : return 1;
        case '+' :
        case '-' : return 2;
        case '*' :
        case '/' : return 3;
    }
}

void Cal_Change(char cal[], char postfix[]){ // ����ǥ������� ��ȯ�ϴ� �Լ�

    int tmp=1; // ���� ���ڸ� ���ڷ� ��ȯ�� �� ���δ�
    int i,postfix_index=0; // ����ǥ��� �迭�� ���� �迭�� �ε����� ���� ����

    SInit_CHAR(); // ������ ���� �ʱ�ȭ
    SInit_DOUBLE(); // ���� ���� ���� �ʱ�ȭ

    for(i=0; cal[i]!='\0'; i++){
        // �����̸� ����ǥ��� �迭�� �ٷ� �ѱ��
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
                            // (���� �ȿ� �ִ� ������ > ���� ���� ������) �� ������
                            // ���� �ȿ� �ִ� ������ ����ǥ��� �迭�� �ѱ��
                            while(Cal_Priority(SPeek_CHAR(top_CHAR)) > Cal_Priority(cal[i])){
                                postfix[postfix_index] = SPop_CHAR(top_CHAR);
                                postfix_index++;
                            }
                            // �ƴϸ� ������ ���ÿ� �ִ´�
                            SPush_CHAR(top_CHAR,cal[i]);
                            break;
                case '(' :
                            // ������ ���ÿ� �ִ´�
                            SPush_CHAR(top_CHAR,cal[i]);
                            break;
                case ')' :
                            // '(' ���� �ִ� ��� �����ڸ� ����ǥ��� �迭�� �ѱ��
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
    while(SPeek_CHAR(top_CHAR) != -1){ // ���� �� �˻��ϰ�, ������ ���ÿ� �����ִ� ���� ����ǥ������� �����
        postfix[postfix_index] = SPop_CHAR(top_CHAR);
        postfix_index++;
    }
}

void Cal_Result(char postfix[]){ // ����ǥ��� ����ϱ�
    int i,j;
    double tmp;
    double a,b; // �ǿ����� �� ��
    for(i=0;postfix[i]!='\0';i++){
        tmp=0;
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            for(j=i;postfix[j] >= '0' && postfix[j] <= '9';j++){
                tmp*=10;
                tmp+=postfix[j]-'0';
            }
            i=j-1;
            // �ǿ������̸� ���ÿ� �ִ´�
            SPush_DOUBLE(top_DOUBLE,tmp);
        } else if(postfix[i] != ' '){
            // �����ڶ�� �ǿ����� �� ���� ������ �����Ѵ�
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
