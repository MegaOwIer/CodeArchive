/*��������:һ��������n(1<=n<=1000000)
  �������:n���ڵ�����(����n),ÿ��һ��
  ��������:233
  �������:��*/ 

#include<iostream>
#include<cmath>
using namespace std;

int n;
bool prime(int);

int main()
{
	cin>>n;
	cout<<"2"<<endl;
	for(int i=3;i<n;i+=2)  if(prime(i))  cout<<i<<endl;
	return 0;
}
bool prime(int v)
{
	if(v%2==0)  return 0;
	int m=sqrt(v);
	for(int i=3;i<=m;i+=2)  if(v%i==0)  return 0;
	return 1;
}
