/*��Ŀ����:��һ��һԪ���η���,�����÷����и����ϵ��(a��b��c��d  ��Ϊʵ��)����Լ���÷��̴���������ͬʵ��(���ķ�Χ��-100��100֮��)���Ҹ����֮��ľ���ֵ>=1��
           Ҫ����С����������ͬһ�����������ʵ��(�����֮�����пո�)������ȷ��С�����2λ��
		   ��ʾ���Ƿ���f(x)=0��������2����x1��x2����x1<x2��f(x1)*f(x2)<0������(x1��x2)֮��һ����һ������
  ��������:һ�����η��̵ĸ���ϵ��
  �������:������
  ��������:1 -5 -4 20
  �������:-2.00 2.00 5.00*/

#include<iostream>
#include<cstdio>
using namespace std;

double a,b,c,d,lt,rt;
double f(double);
void search(double,double);

int main()
{
	cin>>a>>b>>c>>d;
	if(a<0)  {a=-a;  b=-b;  c=-c;  d=-d;}
	lt=-100;  rt=-99;  while(f(rt)<0)  {rt++;  lt++;}  search(lt,rt);
	rt++;  lt++;  while(f(rt)>0)  {rt++;  lt++;}  search(lt,rt);
	rt++;  lt++;  while(f(rt)<0)  {rt++;  lt++;}  search(lt,rt);
	return 0;
}

double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
void search(double lt,double rt)
{
    double mid=(lt+rt)/2.0;
	if(rt-lt<0.01||f(mid)==0)  {printf("%.2lf ",mid);  return;}
	if(f(mid)*f(lt)>=0)  search(mid,rt);
	else  if(f(mid)*f(lt)<=0)  search(lt,mid);
}
