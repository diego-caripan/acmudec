n = int(input())
lista = []
for i in range(n):
	pal = input().strip().split()
	pal[1] = int(pal[1])
	pal[2] = int(pal[2])
	pal[3] = int(pal[3])
	pal.reverse()
	lista.append(pal)

lista.sort()
print(lista[len(lista)-1][3] + "\n" + lista[0][3])