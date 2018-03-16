#Juan Fecci
#Resuelto Propio

n = int(input())
while(n != 0):
	coord = [int(n) for n in input().split()]
	X = True
	Y = True
	for i in range(n):
		resp = [int(n) for n in input().split()]
		if resp[0] == coord[0] or resp[1] == coord[1]:
			print ("divisa")
		else:
			X = resp[0] > coord[0]
			Y = resp[1] > coord[1]
			if X and Y: print("NE")
			elif X and not Y: print("SE")
			elif not X  and Y: print("NO")
			else: print("SO")
	n = int(input())
