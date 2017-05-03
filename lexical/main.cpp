#include <bits/stdc++.h>
using namespace std;

//1-10关键字
//11 标识符
//12 整型常数
//13-29 算符和界符

char *gjz[10]= {"begin","end","if","then","while","do","const","var","call","procedure"};
char sfhjf[10]= {'+','-','*','.','=','(',')',',','.',';'};
char s[1010],tem[100];
char ch=' ';
int line,p,t,sign;
double sum,dian;

void sca()
{
    memset(tem,0,sizeof tem);
    ch=s[p++];
    while(ch==' '||ch=='\t')
        ch=s[p++];
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        t=0;
        while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
        {
            tem[t++]=ch;
            ch=s[p++];
        }
        p--;
        sign=11;
        for(int i=0; i<10; i++)
            if(!strcmp(tem,gjz[i]))
            {
                sign=i+1;
                break;
            }
        if(!strcmp(tem,"odd"))
            sign=23;
    }
    else
    {
        if(ch>='0'&&ch<='9')
        {
            sum=0;
            while(ch>='0'&&ch<='9')
            {
                sum=sum*10+ch-'0';
                ch=s[p++];
            }
            if(ch=='.')
            {
                dian=0.1;
                ch=s[p++];
                while(ch>='0'&&ch<='9')
                {
                    sum+=(ch-'0')*dian;
                    dian*=0.1;
                    ch=s[p++];
                }
            }
            p--;
            sign=12;
        }
        else
        {
            int flag=0;
            for(int i=0; i<10; i++)
            {
                if(ch==sfhjf[i])
                {
                    tem[0]=ch;
                    sign=i+13;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                switch(ch)
                {
                case '<':
                    t=0;
                    tem[t++]=ch;
                    ch=s[p++];
                    if(ch=='>')
                    {
                        sign=24;
                        tem[t++]=ch;
                    }
                    else if(ch=='=')
                    {
                        sign=25;
                        tem[t++]=ch;
                    }
                    else
                    {
                        sign=26;
                        p--;
                    }
                    break;
                case '>':
                    t=0;
                    tem[t++]=ch;
                    ch=s[p++];
                    if(ch=='=')
                    {
                        sign=27;
                        tem[t++]=ch;
                    }
                    else
                    {
                        sign=28;
                        p--;
                    }
                    break;
                case ':':
                    t=0;
                    tem[t++]=ch;
                    ch=s[p++];
                    if(ch=='=')
                    {
                        sign=29;
                        tem[t++]=ch;
                    }
                    else
                    {
                        sign=-1;
                        p--;
                    }
                    break;
                case '#':
                    sign=0;
                    break;
                case '\n':
                    sign=-2;
                    break;
                default:
                    sign=-1;
                }
            }
        }
    }
}

void pri()
{
    if(sign==-1)
        printf("Error in line %d.\n",line);
    if(sign==-2)
        line++;
    if(sign>0&&sign<11)
        printf("( %d\t, %s\t, 关键字)\n",sign,tem);
    if(sign==11)
        printf("( %d\t, %s\t, 标识符)\n",sign,tem);
    if(sign==12)
        printf("( %d\t, %.2lf\t, 常数)\n",sign,sum);
    if(sign>12&&sign<30)
        printf("( %d\t, %s\t, 算符和界符)\n",sign,tem);
}

int main()
{
    freopen("c:\\st\\code\\input.txt","r",stdin);
    printf("Result:\n");
    p=0;
    line=1;
    sign=-3;
    while(ch!='#')
    {
        cin.get(ch);
        s[p++]=ch;
    }
    p=0;

    while(sign!=0)
    {
        sca();
        pri();
    }
    printf("ac\n");
    return 0;
}
