def getHash(s):
	ans = 1
	for i in range(s.__len__()):
		ans *= ord(s[i]) - ord('A') + 1
	return ans % 47

if __name__ == '__main__':
	s1 = input()
	s2 = input()
	if getHash(s1) == getHash(s2):
		print("GO")
	else:
		print("STAY")
