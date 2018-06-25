/*题目描述:有一个一元三次方程,给出该方程中各项的系数(a，b，c，d  均为实数)，并约定该方程存在三个不同实根(根的范围在-100至100之间)，且根与根之差的绝对值>=1。
           要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后2位。
		   提示：记方程f(x)=0，若存在2个数x1和x2，且x1<x2，f(x1)*f(x2)<0，则在(x1，x2)之间一定有一个根。
  输入描述:一个三次方程的各项系数
  输出描述:三个解
  样例输入:1 -5 -4 20
  样例输出:-2.00 2.00 5.00*/

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
