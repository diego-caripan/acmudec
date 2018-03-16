while True:
	#N, B, H, W
	try: start = [int(n) for n in input().split()]
	except EOFError: break

	lis = []
	mont = -1
	for i in range(start[2]):
		price = int(input())
		lis = [int(n) for n in input().split()]
		verif = False
		for elem in lis:
			if elem >= start[0]:
				verif = True
				break
		if verif: 
			res= price*start[0]
			if res < start[1] and ( mont > res or mont==-1):
				mont=res

	if mont==-1:
		print("stay home")
	else:
		print(mont)