a=input();a=int(a)
if(a<=150):
	ans=a*0.4463
elif(a<=400):
	ans=150*0.4463+(a-150)*0.4663
else:
	ans=150*0.4463+250*0.4663+(a-400)*0.5663
print("%.1f"%(ans))