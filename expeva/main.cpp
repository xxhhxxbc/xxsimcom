#include <bits/stdc++.h>
using namespace std;

struct Result
{
    double res;
    bool sign;
    char fa;
};

char fh[7]= {'+','-','*','/','(',')','='};

char mapn[8][8]=
{
    {' ','+','-','*','/','(',')','='},
    {'+','>','>','<','<','<','>','>'},
    {'-','>','>','<','<','<','>','>'},
    {'*','>','>','>','>','<','>','>'},
    {'/','>','>','>','>','<','>','>'},
    {'(','<','<','<','<','<','=',' '},
    {')','>','>','>','>',' ',' ','>'},
    {'=','<','<','<','<','<',' ','='}
};

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

char cz(char a,char b)
{
    int x,y;
    for(int i=0; i<8; i++)
        if(mapn[i][0]==b)
        {
            x=i;
            break;
        }
    for(int i=0; i<8; i++)
        if(mapn[0][i]==a)
        {
            y=i;
            break;
        }
    return mapn[x][y];
}

Result cal(double a,char c,double b)
{
    Result re;
    re.fa=' ';
    re.res=0;
    re.sign=true;
    switch(c)
    {
    case '+':
        re.res=a+b;
        break;
    case '-':
        re.res=a-b;
        break;
    case '*':
        re.res=a*b;
        break;
    case '/':
        if(b==0)
        {
            re.sign=false;
            re.fa='/';
        }
        else
            re.res=a/b;
        break;
    }
    return re;
}

Result calcu(char s[])
{
    Result re;
    re.res=0;
    re.sign=false;
    re.fa=' ';
    int i=0;
    double a,b,num;
    char c;

    stack<double> nu;
    stack<char> sf;
    while(!nu.empty())
        nu.pop();
    while(!sf.empty())
        sf.pop();

    sf.push('=');

    while(s[i]!='='||sf.top()!='=')
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            num = s[i++]-'0';
            while(s[i]>='0'&&s[i]<='9')
            {
                num*=10;
                num+=s[i++]-'0';
            }
            nu.push(num);
        }
        else
        {
            bool che=false;
            for(int j=0; j<7; j++)
                if(s[i]==fh[j])
                {
                    che = true;
                    break;
                }
            if(che)
            {
                switch(cz(s[i],sf.top()))
                {
                case '<':
                    sf.push(s[i++]);
                    break;
                case '=':
                    sf.pop();
                    i++;
                    break;
                case '>':
                    c = sf.top();
                    sf.pop();
                    a = nu.top();
                    nu.pop();
                    b = nu.top();
                    nu.pop();
                    Result tans = cal(b,c,a);
                    if(tans.sign)
                        nu.push(tans.res);
                    else
                        return tans;
                    break;
                }
            }
            else
            {
                re.fa=s[i];
                return re;
            }
        }
    }
    re.res = nu.top();
    re.sign = true;
    return re;
}

int main()
{
    char s1[100],s2[100];
    while(true)
    {
        memset(s1,0,sizeof s1);
        memset(s2,0,sizeof s2);
        printf("Please input the formula:\n");
        gets(s1);
        int k=0;
        for(int i=0; i<strlen(s1); i++)
        {
            if(s1[i]==' ')
                continue;
            s2[k++]=s1[i];
        }
        s2[k++]='=';

        if(check(s2))
        {
            Result ans = calcu(s2);
            if(ans.sign)
                printf("Result: %.2lf\n",ans.res);
            else
                printf("WA: %c\n",ans.fa);
        }
        else
            printf("WA: ().\n");
    }
    return 0;
}
