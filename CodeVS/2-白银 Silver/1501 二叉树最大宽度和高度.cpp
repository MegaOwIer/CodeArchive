/*��Ŀ����:����һ���������������������Ⱥ͸߶ȡ�
  ��������:��һ��һ������n.����n��ÿ����������,���ڵ�i�е�������,������Ϊi�Ľڵ������ӵ��������Ҷ��ӵı��.���û��ĳ������Ϊ��,��Ϊ0.
  �������:�����һ�У����������������Ⱥ͸߶ȣ���һ���ո������
  ��������:5
           2 3
		   4 5
		   0 0
		   0 0
		   0 0
  �������:2 3
  ���ݷ�Χ����ʾ:n<16*/

#include<iostream>
#include<algorithm>
using namespace std;

int root[20],zuo[20],you[20],n,fa[20],h=1,w[20],f[20];

int main()
{
	cin>>n;
	f[1]=1; 
	for(int i=1;i<=n;i++)  
	{
	    root[i]=i;
		cin>>zuo[i]>>you[i];
		if(zuo[i]!=0)  {fa[zuo[i]]=i;  f[zuo[i]]=f[i]+1;}
		if(you[i]!=0)  {fa[you[i]]=i;  f[you[i]]=f[i]+1;}
	}
	sort(f+1,f+n+1,greater<int>());
    for(int i=1;i<=n;i++)  w[f[i]]++;
    sort(w+1,w+n+1,greater<int>());
    cout<<w[1]<<' '<<f[1];
    
    return 0;
}
