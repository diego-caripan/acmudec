dat = [int(n) for n in input().split()]
elem = [int(n) for n in input().split()]

cont = 0
for n in elem:
	cont += n - dat[0]
	if cont < 0: cont = 0

if cont < 0: print(0)
else: print (cont)