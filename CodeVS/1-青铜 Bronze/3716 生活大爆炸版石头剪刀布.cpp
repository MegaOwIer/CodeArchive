/*题目描述:石头剪刀布是常见的猜拳游戏：石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。
           在《生活大爆炸》第二季第8集中出现了一种石头剪刀布的升级版游戏。升级版游戏在传统的石头剪刀布游戏的基础上，增加了两个新手势： 
		   斯波克：《星际迷航》主角之一。 蜥蜴人：《星际迷航》中的反面角色。  
		   现在，小A和小B尝试玩这种升级版的猜拳游戏。已知他们的出拳都是有周期性规律的，但周期长度不一定相等。
		   已知小A和小B一共进行N次猜拳。每一次赢的人得1分，输的得0分；平局两人都得0分。现请你统计N次猜拳结束之后两人的得分。
  输入描述:第一行包含三个整数：N，NA，NB，分别表示共进行N次猜拳、小A出拳的周期长度，小B出拳的周期长度。数与数之间以一个空格分隔。 
           第二行包含NA个整数，表示小A出拳的规律，第三行包含NB个整数，表示小B出拳的规律。
		   其中，0表示“剪刀”，1表示“石头”，2表示“布”，3表示“蜥蜴人”，  4表示“斯波克”。数与数之间以一个空格分隔。
  输出描述:输出一行，  包含两个整数，以一个空格分隔，分别表示小A、小B的得分。
  数据范围及提示:对于100%的数据,0<N<=200,0<NA<=200,0<NB<=200.*/

#include<iostream>
using namespace std;

int a[205],b[205],ta,tb,rd,sca,scb;

int main()
{
	cin>>rd>>ta>>tb;
	for(int i=1;i<=ta;i++)  cin>>a[i];
	for(int i=1;i<=tb;i++)  cin>>b[i];
	for(int i=1;i<=rd;i++)
	{
		int m=a[(i-1)%ta+1],n=b[(i-1)%tb+1];
		if(m==n)  continue;
		switch(m)
		{
			case 0:{if(n==2||n==3)  sca++;  else  scb++;  continue;}
			case 1:{if(n==0||n==3)  sca++;  else  scb++;  continue;}
			case 2:{if(n==1||n==4)  sca++;  else  scb++;  continue;}
			case 3:{if(n==2||n==4)  sca++;  else  scb++;  continue;}
			case 4:{if(n==0||n==1)  sca++;  else  scb++;  continue;}
		}
    }
    cout<<sca<<' '<<scb;
    
    return 0;
}
