a,b,c,d=input().split()
a=int(a);b=int(b);c=int(c);d=int(d)
c=c-a;d=d-b;
if(d<0):
	d=d+60;c=c-1
if(d>59):
	d=d-60;c=c+1
print(c,d)
