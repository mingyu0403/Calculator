#include "LinkedStack.h"

void SInit_CHAR(){
    top_CHAR = 0;
}
void SPush_CHAR(Stack_CHAR *sp, char opt){
    Stack_CHAR *tmp = (Stack_CHAR *)malloc(sizeof(Stack_CHAR));
    tmp -> opt = opt;
    tmp -> link_CHAR = sp;
    top_CHAR = tmp;
}
char SPop_CHAR(Stack_CHAR *sp){
    if(!top_CHAR){
        return -1;
    }
    char temp = top_CHAR -> opt;
    top_CHAR = top_CHAR->link_CHAR;
    free(sp);
    return temp;
}
char SPeek_CHAR(Stack_CHAR *sp){
    if(!top_CHAR){
        return -1;
    }
    return sp->opt;
}



void SInit_DOUBLE(){
    top_DOUBLE = 0;
}
void SPush_DOUBLE(Stack_DOUBLE *sp, double data){
    Stack_DOUBLE *tmp = (Stack_DOUBLE *)malloc(sizeof(Stack_DOUBLE));
    tmp -> data = data;
    tmp -> link_DOUBLE = sp;
    top_DOUBLE = tmp;
}
double SPop_DOUBLE(Stack_DOUBLE *sp){
    if(!top_DOUBLE){
        return -1;
    }
    double temp = top_DOUBLE -> data;
    top_DOUBLE = top_DOUBLE->link_DOUBLE;
    free(sp);
    return temp;
}
double SPeek_DOUBLE(Stack_DOUBLE *sp){
    if(!top_DOUBLE){
        return -1;
    }
    return sp->data;
}
