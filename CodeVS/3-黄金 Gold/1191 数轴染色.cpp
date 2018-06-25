/*��Ŀ����:��һ����������N����,�ֱ���1~N.һ��ʼ���еĵ㶼��Ⱦ�ɺ�ɫ.�������ǽ���M�β���,��i�β�����[Li,Ri]��Щ��Ⱦ�ɰ�ɫ.
           �����ÿ������ִ�к�ʣ���ɫ��ĸ�����
  ��������:����һ��ΪN��M.����M��ÿ��������Li,Ri
  �������:���M��,Ϊÿ�β�����ʣ���ɫ��ĸ���
  ��������:10 3
           3 3
		   5 7
		   2 8
  �������:9
           6
		   3
  ���ݷ�Χ����ʾ:��30%������,��1<=N<=2000,1<=M<=2000
                 ��100%����,��1<=Li<=Ri<=N<=200000,1<=M<=200000*/
                 
#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
struct node
{
    int lt,rt;
    bool num;
}p[600000];
void build(int l,int r,int num)
{
    p[num].lt=l;
    p[num].rt=r;
    if(l==r)  return;
    int mid=(l+r)/2;
    build(l,mid,num*2);
    build(mid+1,r,num*2+1);
}
void insert(int l,int r,int step)
{
    if(p[step].num)  return;
    if(l==p[step].lt&&r==p[step].rt)  {p[step].num=1;  return;}
    int mid=(p[step].lt+p[step].rt)/2;
    if(r<=mid)  insert(l,r,step*2);
    else  if(l>mid)  insert(l,r,step*2+1);
          else  {insert(l,mid,step*2);  insert(mid+1,r,step*2+1);}
}
int con(int l,int r,int step)
{
    int ans=0;
    if(p[step].num)  {ans+=r-l+1;  return ans;}
    if(p[step].lt==p[step].rt)  return ans;
    int mid=(p[step].lt+p[step].rt)/2;
    if(mid>=r)  ans+=con(l,r,step*2);
    else  if(mid<l)  ans+=con(l,r,step*2+1);
          else  ans+=con(l,mid,step*2)+con(mid+1,r,step*2+1);
    return ans;
}

int main()
{
    cin>>n>>m;
    build(1,n,1);
    for(int i=1,l,r;i<=m;i++)
    {
        scanf("%d%d",&l,&r);
        insert(l,r,1);
        printf("%d\n",n-con(1,n,1));
    }
    return 0;
}
