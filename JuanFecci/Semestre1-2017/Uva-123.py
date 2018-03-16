pal = []
while True:
	cosa = input()
	if cosa == "::": break
	pal.append(cosa)

dicc = []
ora = []
indi = 0

while True:
	try: seg = input()
	except EOFError: break

	seg = seg.lower().strip().split()
	ora.append(seg)

	for pali in range(len(seg)):
		if seg[pali] not in pal:
			dicc.append([seg[pali],indi,pali])

	indi += 1

dicc.sort()
for elem in dicc:
	aux = ora[elem[1]]
	for pali in range(len(aux)):
		if pali == elem[2]:
			print(aux[pali].upper(), end="")
		else:
			print(aux[pali], end="")
		if pali != len(aux)-1:
			print(" ", end="")
	print()