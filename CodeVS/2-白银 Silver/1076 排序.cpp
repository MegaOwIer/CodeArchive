/*��Ŀ����:����n��n��������ϣ�����С�������������
  ��������:��һ��һ��������n,�ڶ���n���ÿո����������
  �������:�����һ�У���С�������n���ÿո����������
  ��������:3
           3 1 2
  �������:1 2 3
  ���ݷ�Χ����ʾ:1<=n<=100000*/

#include<cstdio>
#include<algorithm>

using namespace std;

bool com(int a,int b)
{
     return a<b;
}

int main()
{
    int a[100000],n,i;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)  scanf("%d",&a[i]);
    sort(a,a+n,com);
    for(i=0;i<=n-1;i++)  printf("%d ",a[i]);

    return 0;
}
