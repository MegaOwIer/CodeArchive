#include<bits/stdc++.h>
using namespace std;

int n,opt,x,now;
stack<int> s;
queue<int> q;
priority_queue<int> pq;
bool isq,iss,ispq;

int main()
{
	while(~scanf("%d",&n))
	{
		isq=iss=ispq=1;
		while(!s.empty())s.pop();
		while(!q.empty())q.pop();
		while(!pq.empty())pq.pop();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&opt,&x);
			if(iss)
			{
				if(opt&1)s.push(x);
				else if(s.empty())iss=0;
				else
				{
					now=s.top(),s.pop();
					if(now!=x)iss=0;
				}
			}
			if(isq)
			{
				if(opt&1)q.push(x);
				else if(q.empty())isq=0;
				else
				{
					now=q.front(),q.pop();
					if(now!=x)isq=0;
				}
			}
			if(ispq)
			{
				if(opt&1)pq.push(x);
				else if(pq.empty())ispq=0;
				else
				{
					now=pq.top(),pq.pop();
					if(now!=x)ispq=0;
				}
			}
		}
		if(!iss&&!isq&&!ispq)puts("impossible");
		else if(iss&&!isq&&!ispq)puts("stack");
		else if(!iss&&isq&&!ispq)puts("queue");
		else if(!iss&&!isq&&ispq)puts("priority queue");
		else puts("not sure");
	}
	return 0;
}
