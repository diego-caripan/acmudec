n = int(input())
input()

for i in range(n):
	num = [[0,0,n] for n in range(100)]
	dic = [{} for n in range(100)]
	while True:
		try: pal = input().strip().split()
		except EOFError: break
		if len(pal) == 0: break
		if pal[3] == "C":
			if int(pal[1])-1 in dic[int(pal[0])]: 
				suma = dic[int(pal[0])][int(pal[1])-1] + int(pal[2])
			else:
				suma = int(pal[2]) 
			num[int(pal[0])][0], num[int(pal[0])][1] = num[int(pal[0])][0]+1, num[int(pal[0])][1] + suma
		elif pal[3] == "I":
			if int(pal[1])-1 in dic[int(pal[0])]: 
				dic[int(pal[0])][int(pal[1])-1] += 20
			else:
				dic[int(pal[0])][int(pal[1])-1] = 20

	num.sort()
	for j in  range(99,-1,-1):
		if num[j][0] == 0 and num[j][1] == 0
		cosa = str(num[j][2]+1) 
		print(cosa + " " + str(num[j][0]) + " " + str(num[j][1])

