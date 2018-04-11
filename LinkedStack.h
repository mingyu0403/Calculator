
// CHAR LinkedStack
// ����ǥ��� ���� �� ������ ��� ����
typedef struct LinkedStack_CHAR{
    char opt;
    struct LinkedStack_CHAR *link_CHAR;
}Stack_CHAR;

Stack_CHAR *top_CHAR;

void SInit_CHAR();
void SPush_CHAR(Stack_CHAR *sp, char opt);
char SPop_CHAR(Stack_CHAR *sp);
char SPeek_CHAR(Stack_CHAR *sp);


// DOUBLE LinkedStack
// ����ǥ��� ����� �� �ǿ����� ��� ����
typedef struct LinkedStack_DOUBLE{
    double data;
    struct LinkedStack_DOUBLE *link_DOUBLE;
}Stack_DOUBLE;

Stack_DOUBLE *top_DOUBLE;

void SInit_DOUBLE();
void SPush_DOUBLE(Stack_DOUBLE *sp, double data);
double SPop_DOUBLE(Stack_DOUBLE *sp);
double SPeek_DOUBLE(Stack_DOUBLE *sp);
