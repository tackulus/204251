//
// Assignment03.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct polyNode* polyPtr;
typedef struct polyNode{
    int coef;
    int deg;
    polyPtr desc;
} polyNode;

bool isEmpty(polyPtr Pn)
{
    return (Pn == NULL);
}

polyPtr generateMonomial(int coef, int deg)
{
    polyPtr newTerm = (polyPtr) malloc(sizeof(polyNode));
    newTerm->coef = coef;
    newTerm->deg = deg;
    newTerm->desc = NULL;
    return newTerm;
}

polyPtr getLocateTerm(polyPtr Pn, int deg)
{
    // null polynomial or monomial
    if (isEmpty(Pn))
        return Pn;

    polyPtr prev = Pn;
    polyPtr cur = prev->desc;

    while (cur != NULL)
    {
        if (cur->deg < deg)
            return prev;
        prev = cur;
        cur = cur->desc;
    }

    return prev;
}

polyPtr generatePolynomial()
{
    int coef, deg, n, i;
    
    polyPtr Pn = NULL;
    
    polyPtr new, prev;
    
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d %d", &coef, &deg);
        prev = getLocateTerm(Pn, deg);

        if (isEmpty(Pn))
        {
            Pn = generateMonomial(coef, deg);
        }

        else if (prev->deg == deg)
            prev->coef = coef;

        else
        {
            new = generateMonomial(coef, deg);

            // redirect polyPtr
            if (Pn->deg < deg)
            {
                Pn = new;
                new->desc = prev;
            }
            else
            {
                new->desc = prev->desc;
                prev->desc = new;
            }
        }
    }
    return Pn;
}

void displayPolynomial(polyPtr Pn)
{
    polyPtr cur=Pn;
    while (cur != NULL)
    {
        printf("%dx^{%d} ", cur->coef, cur->deg);
        cur = cur->desc;
    }
    printf("\n");
}

polyPtr calculatePolynomial(polyPtr P1, polyPtr P2, int num)
{
    int coef1, coef2, deg1, deg2, deg;
    polyPtr cur1 = P1, cur2 = P2, cur3, new,  P3 = NULL;

    while (cur1 != NULL | cur2 != NULL)
    {
        if (cur1 == NULL)
        {
            coef1 = 0;
            coef2 = cur2->coef;
            deg1 = -1;
            deg2 = cur2->deg;
        }
        else if (cur2 == NULL)
        {   
            coef1 = cur1->coef;
            coef2 = 0;
            deg1 = cur1->deg;
            deg2 = -1;
        }
        else
        {
            coef1 = cur1->coef;
            coef2 = cur2->coef;
            deg1 = cur1->deg;
            deg2 = cur2->deg;
        }
        
        
        if (deg1 < deg2)
        {
            coef1 = 0;
            deg = deg2;
            cur2 = cur2->desc;
        }
        else if (deg1 > deg2)
        {
            coef2 = 0;
            deg = deg1;
            cur1 = cur1->desc;
        }
        else
        {
            deg = deg1;
            cur1 = cur1->desc;
            cur2 = cur2->desc;
        }
        
        if (num == 1)
            new = generateMonomial(coef1 + coef2, deg);
        else if (num == 2)
            new = generateMonomial(coef1 - coef2, deg);

        if (new->coef == 0)
            continue;
        else if (isEmpty(P3))
            P3 = cur3 = new;
        else
        {
            cur3->desc = new;
            cur3 = cur3->desc;
        }
    }

    return P3;
}

int main()
{
    int num;
    polyPtr P1, P2, P3;
    scanf("%d", &num);
    P1 = generatePolynomial();
    P2 = generatePolynomial();
    P3 = calculatePolynomial(P1, P2, num);
    displayPolynomial(P3);
    return 0;
}