/*��Ŀ��������n�����ĺ�
  ������������һ��һ������n
            ������һ��n������
  ����������������ĺ�
  �������룺4
            1 2 3 4
  ���������10
  ���ݷ�Χ����ʾ��n<=100���������ĺ�<=231-1*/

#include<cstdio> 
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;
int main()
{
	int n,m,s,i;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++)
	{scanf("%d",&m);
	 s=s+m;
	}
	printf("%d",s);
	
	return 0;
}

