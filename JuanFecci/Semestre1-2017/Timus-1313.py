n = int(input())
lis = []
ind = []
for i in range(n):
	x = [lis.append(int(n)) for n in input().split()]

for i in range(2*n-1):
	if i>=n:
		ind = i-n+1 + n*(n-1)
		aux = n- (i-n+1) -1
	else:
		ind = i*n
		aux = i

	print(lis[ind], end=' ')

	for t in range(aux):
		ind = ind-n+1
		print (lis[ind], end=' ')

print()