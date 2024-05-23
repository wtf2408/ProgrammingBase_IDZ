#include<stdio.h>
#include<iostream>
using namespace std;


/*
Описать процедуру, которая строит многочлен p - сумму многочленов  q и r. 
Пример :
Первый полином |        2x^3 + 4x^2 + 1x^1 + 5, в виде списка -   2 4 1 5
Второй полином | 9x^4 + 5x^3 + 4x^2 + 1x^1 + 2, в виде списка - 9 5 4 1 2
Результат      | 9x^4 + 7x^3 + 8x^2 + 2x^1 + 7, в виде списка - 9 7 8 2 7
*/

struct Monomial
{
    int coefficient;
    Monomial *next;
};

int fillPolinomial(Monomial* el);
void printPolynomial(Monomial *m, int pow);

int main()
{
    bool start = true; // для заполнения результирующего списка

    Monomial* firstPolinom = new Monomial;
    int firstPolinomLen = fillPolinomial(firstPolinom);
    printPolynomial(firstPolinom, firstPolinomLen);


    Monomial* secondPolinom;
    int secondPolinomLen = fillPolinomial(secondPolinom);
    printPolynomial(secondPolinom, secondPolinomLen);


    Monomial* resultPolinom = new Monomial;
    Monomial* result = resultPolinom;

    int dLen = firstPolinomLen - secondPolinomLen;
    if (dLen > 0) // если в первом больще эл. то добавляем в результат эл. первого, чтобы уровнять длину
    {
        for (int i = 0; i < dLen; i++)
        {
            if (!start)
            {
                resultPolinom->next = new Monomial;
                resultPolinom = resultPolinom->next;
            }
            start = false;
            resultPolinom->coefficient = firstPolinom->coefficient;
            firstPolinom = firstPolinom->next;
        }
    }
    else if (dLen < 0) // если во втором больще эл. то добавляем в результат эл. второго, чтобы уровнять длину
    {
        for (int i = 0; i < abs(dLen); i++)
        {
            if (!start)
            {
                resultPolinom->next = new Monomial;
                resultPolinom = resultPolinom->next;
            }
            start = false;
            resultPolinom->coefficient = secondPolinom->coefficient;
            secondPolinom = secondPolinom->next;
        }
    }
    while (firstPolinom != nullptr) // теперь длины равны или были и так равны, и можно суммировать
    {
        if (!start)
        {
                resultPolinom->next = new Monomial;
                resultPolinom = resultPolinom->next;
        }
        start = false;
        resultPolinom->coefficient = firstPolinom->coefficient + secondPolinom->coefficient;
        resultPolinom->next = nullptr;
        firstPolinom = firstPolinom->next;
        secondPolinom = secondPolinom->next;

    }
    
    printPolynomial(result, (firstPolinomLen >= secondPolinomLen) ? firstPolinomLen : secondPolinomLen);

    return 0;
}

int fillPolinomial(Monomial* el)
{
    bool start = true;
    int coef, len = -1;
    printf("Enter coefficients first polynomial, sequence need end with zero : ");
    cin >> coef;
    while (coef)
    {
        if (start) {
            el->coefficient = coef;
            start = !start;
        }
        else {
            el->next = new Monomial;
            el = el->next;
            el->coefficient = coef;
        }
        el->next = nullptr;
        cin >> coef;
        len++;
    }
    return len;
}
void printPolynomial(Monomial *m, int pow)
{
    if (pow == 0) printf("%d\n", m->coefficient, pow);
    else printf("%dx^%d + ", m->coefficient, pow);
    if (m->next != nullptr)  printPolynomial(m->next, --pow);
}