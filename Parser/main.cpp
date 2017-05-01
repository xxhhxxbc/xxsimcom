#include <bits/stdc++.h>
using namespace std;

void E(); //E->TX;
void X(); //X->+TX|-TX|e
void T(); //T->FY
void Y(); //Y->*FY|/FY|e
void F(); //F->(E)|id|num

char s[100];
int q;

int main()
{
    memset(s,0,sizeof s);
    q=0;
    printf("Please input string:\n");
    scanf("%s",s);
    E();
    printf("AC\n");
    return 0;
}

void E()
{
    T();
    X();
}

void X()
{
    if(s[q]=='+')
    {
        q++;
        T();
        X();
    }
    if(s[q]=='-')
    {
        q++;
        T();
        X();
    }
}

void T()
{
    F();
    Y();
}

void Y()
{
    if(s[q]=='*')
    {
        q++;
        F();
        Y();
    }
    if(s[q]=='/')
    {
        q++;
        F();
        Y();
    }
}

void F()
{
    if(s[q]=='(')
    {
        q++;
        E();
        if(s[q]==')')
            q++;
        else
        {
            printf("WA\n");
            exit(0);
        }
    }
    else
    {
        if(s[q]=='i'&&s[q+1]=='d')
            q+=2;
        else
        {
            if(s[q]=='n'&&s[q+1]=='u'&&s[q+2]=='m')
                q+=3;
            else
            {
                printf("WA\n");
                exit(0);
            }
        }
    }
}
