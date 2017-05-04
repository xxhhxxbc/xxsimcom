#include <bits/stdc++.h>
using namespace std;

double E(); //E->F+E|F-E|F
double F(); //F->T*F|T/F|T
double T(); //T->(E)|num

char s[100];
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

bool flag;
char sfhjf[6]= {'+','-','*','/','(',')'};
int l;

double sca()
{
    while(s[q]==' '||s[q]=='\t')
        q++;
    if(s[q]>='0'&&s[q]<='9')
    {
        double sum=0,dian;
        while(s[q]>='0'&&s[q]<='9')
            sum=sum*10+s[q++]-'0';
        if(s[q]=='.')
        {
            dian=0.1;
            q++;
            while(s[q]>='0'&&s[q]<='9')
            {
                sum+=(s[q++]-'0')*dian;
                dian*=0.1;
            }
        }
        else
        {
            if(q!=l)
            {
                flag=false;
                for(int i=0; i<6; i++)
                    if(s[q]==sfhjf[i])
                    {
                        flag=true;
                        break;
                    }
                if(!flag)
                {
                    printf("WA: scaf\n");
                    exit(0);
                }
            }

        }
        return sum;
    }
    else
    {
        printf("WA: scan\n");
        exit(0);
    }
}

int main()
{
    memset(s,0,sizeof s);
    printf("Please input string:\n");
    scanf("%s",s);
    l=strlen(s);
    if(!check(s))
        printf("WA: ()\n");
    q=0;
    printf("%.2lf\nAC\n",E());
    return 0;
}

double E()
{
    double x = F(),y;
    while(true)
    {
        if(s[q]=='+')
        {
            q++;
            y = F();
            x +=y;
        }
        else if(s[q]=='-')
        {
            q++;
            y = F();
            x-=y;
        }
        else
        {
            if(s[q]==')')
                q++;
            return x;
        }
    }
}

double F()
{
    double a=T(),b;
    while(true)
    {
        if(s[q]=='*')
        {
            q++;
            b = T();
            a *=b;
        }
        else if(s[q]=='/')
        {
            q++;
            b = T();
            a/=b;
        }
        else
            return a;
    }
}

double T()
{
    if(s[q]=='(')
    {
        q++;
        return E();
    }
    else
        return sca();
}
