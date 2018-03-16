n = int(input())
nombre = []
for i in range(n):
	dep = input()
	while True:
		try: pal = input().strip().split(',')
		except EOFError: break
		if len(pal) == 7:
			a = pal[2]
			b = pal[1]
			c = pal[0]
			pal[0], pal[1], pal[2] = a, b, c
			pal.append(dep)
			nombre.append(pal)
		else: break

nombre.sort()

for i in nombre:
	print ("----------------------------------------")
	print(i[2] + " " + i[1] + " " + i[0])
	print(i[3])
	print("Department: " + i[7])
	print("Home Phone: " + i[4])
	print("Work Phone: " + i[5])
	print("Campus Box: " + i[6])