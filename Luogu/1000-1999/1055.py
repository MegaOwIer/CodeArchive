def getVal(str):
	ans = 0
	for i in range(9):
		ans += (i + 1) * (ord(str[i]) - 48)
	return ans % 11

if __name__ == '__main__':
	s = input()
	tmp = s[0] + s[2:5] + s[6:11]
	val = getVal(tmp)
	if s[12] == 'X':
		s = s[:12] + chr(58)
	if val == ord(s[12]) - 48:
		print("Right")
	elif val == 10:
		print(s[:12] + 'X')
	else:
		print(s[:12] + str(val))