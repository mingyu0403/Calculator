
// 계산식을 문자열로 입력받기
void Cal_Input(char cal[]);

// 계산식을 후위표기법으로 변환하기
void Cal_Change(char cal[], char postfix[]);

// 우선순위 매겨주기
int Cal_Priority(char opt);

// 계산하고 답 출력하기
void Cal_Result(char postfix[]);
