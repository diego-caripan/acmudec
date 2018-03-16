from math import *

numbers = [int(n) for n in input().split()]

if numbers[0] < numbers[1]: print (2)
else:
	if 2*numbers[0]%numbers[1] != 0 :
		print(str(int((2*numbers[0]/numbers[1]))+1))
	else:
		print(str(int(2*numbers[0]/numbers[1]))) 