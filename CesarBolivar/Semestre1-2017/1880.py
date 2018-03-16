#!/usr/bin/env python
# coding=utf-8
# César Bolívar Severino
# resuelto propio

p1 = int(input())
e1 = input().split(' ')
p2 = int(input())
e2 = input().split(' ')
p3 = int(input())
e3 = input().split(' ')

# para que iterar si podemos intersectar conjuntos :v
eigenvalues = set(e1) & set(e2) & set(e3)
print(len(eigenvalues))
