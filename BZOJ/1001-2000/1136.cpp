#include<bits/stdc++.h>
using namespace std;
const int MAX_K=1000000,MAX_N=15000000,MAX_A=1000000000,maxn=1000005;
#define unlikely(x) __builtin_expect(!!(x),0)

static int init=1,lib_n,con_k,N,K,A,TYP,PAR,bre,len_sub,bou,is_end;
static int r2sta=198402041;

static inline int rand2(int a,int b)
{
  	r2sta=r2sta*1103515245+12345;
  	int x=r2sta;
  	if(x<0)x=-x;x>>=1;
 	return x=a+x%(b-a+1);
}
static inline int decreasing_test()
{
    int tmp;
    if(bre==0)bre=rand2(0,N-lib_n+1-len_sub),tmp=A,A-=rand2(0,(A-1)/len_sub),len_sub--;
    else bre--,tmp=rand2(1,A);
    return tmp;
}
int inicjuj()
{
    scanf("%d",&K);
    if(K>0)
    {
        TYP=0,N=MAX_N+2;
        return K;
    }
    int magic_begin,magic_end;
    scanf("%d%d%d%d%d%d%d",&magic_begin,&TYP,&N,&K,&A,&PAR,&magic_end);
    con_k=lib_n=is_end=0;
    if(TYP==2||TYP==3)len_sub=PAR,bre=0;
    if(TYP==2)bou=A--;
    return K;
}
int wczytaj()
{
    if(unlikely(lib_n==N))return 0;
    lib_n++;
    switch(TYP)
    {
        case 0:
            scanf("%d",&A);
            if(A == 0)is_end=1;
            return A;
            break;
        case 1:return rand2(1,A);break;
        case 2:return bou-decreasing_test();break;
        case 3:return decreasing_test();break;
    }
    return -1;
}
//-------------------------------------------//

int k,sta[maxn],top,u;
queue<int> q;

int main()
{
	k=inicjuj();
	for(int i=1;i<=k;i++)u=wczytaj(),q.push(u);
	while(u=wczytaj())
	{
		q.push(u),u=q.front(),q.pop();
		while(top&&sta[top]<u)top--;
		if(top>=k)continue;
		sta[++top]=u;
	}
	for(int i=1;i<=k;i++)
	{
		u=q.front(),q.pop();
		while(top>=i&&sta[top]<u)top--;
		if(top<=k)sta[++top]=u;
		printf("%d\n",sta[i]);
	}
	return 0;
}
