n1 = input()
n2 = input()
n11 = int(n1[0])*1000 + int(n1[1])*100 + int(n1[2])*10 + int(n1[3])
n21 = int(n2[0])*1000 + int(n2[1])*100 + int(n2[2])*10 + int(n2[3])

if n11%2 == 0 or n21%2 == 1: print ('yes')
else: print('no')