n = int(input())
for i in range(1,n+1):
	lis = [int(n) for n in input().split()]
	lis.sort()
	print ("Case "+str(i)+": "+str(lis[1]))