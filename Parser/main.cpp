#include <bits/stdc++.h>
using namespace std;

void E();  //E->TE_;
void E_(); //E_->+TE_|-TE_|e
void T();  //T->FT_
void T_(); //T_->*FT_|/FT_|e
void F();  //F->(E)|id|num
char s[100],ch;
int q;

bool check(char s[])
{
    stack<char> flag;
    int f1=0,f2=0;
    while(!flag.empty())
        flag.pop();

    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]=='(')
        {
            if(f1+1==i)
                return false;
            f2=i;
            flag.push('(');
        }
        if(s[i]==')')
        {
            if(flag.empty())
                return false;
            if(f2+1==i)
                return false;
            f1=i;
            flag.pop();
        }
    }
    if(flag.empty())
        return true;
    return false;
}

void sca()
{
    ch=s[q++];
    while(ch==' '||ch=='\t')
        ch=s[q++];
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
            ch=s[q++];
        q--;
    }
    else
    {
        if(ch>='0'&&ch<='9')
        {
            while(ch>='0'&&ch<='9')
                ch=s[q++];
            if(ch=='.')
            {
                ch=s[q++];
                while(ch>='0'&&ch<='9')
                    ch=s[q++];
            }
            q--;
        }
        else
        {
            printf("WA\n");
            exit(0);
        }
    }
}

int main()
{
    memset(s,0,sizeof s);
    q=0;
    printf("Please input string:\n");
    scanf("%s",s);
    if(check(s))
    {
        E();
        printf("AC\n");
    }
    else
        printf("WA: ().\n");
    return 0;
}

void E()
{
    T();
    E_();
}

void E_()
{
    if(s[q]=='+')
    {
        q++;
        T();
        E_();
    }
    if(s[q]=='-')
    {
        q++;
        T();
        E_();
    }
}

void T()
{
    F();
    T_();
}

void T_()
{
    if(s[q]=='*')
    {
        q++;
        F();
        T_();
    }
    if(s[q]=='/')
    {
        q++;
        F();
        T_();
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
        sca();
}
