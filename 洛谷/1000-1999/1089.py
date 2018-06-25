save=0
left=0
for i in range(1,13):
	a=input();a=int(a)
	left+=300-a
	if(left<0):
		left=-i
		break
	save+=left//100*100
	left%=100
if(left>0):
	left+=int(save*1.2)
print(left)
