#include <iostream>
#include "calculator.h"
#include <stdio.h>
using namespace std;

int main()
{
    Calculator<double> cal;
    char Infix[MAX_EXP_LEN], Postfix[MAX_EXP_LEN];
    gets_s(Infix);
    double sum;

    cal.Infix2Postfix(Infix, Postfix);
    sum = cal.Calculation(Postfix);
    printf("���ռ�����Ϊ��%f\n\n", sum);
    return 0;
}