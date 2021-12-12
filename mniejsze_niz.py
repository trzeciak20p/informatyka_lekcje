'''
Dany jest multizbiór A złożony z n liczb naturalnych. Mając liczbę naturalną i wyznacz, ile jest w multizbiorze A liczb od niej mniejszych.

Wejście
W pierwszym wierszu podane jest n<106, czyli liczba elementów A. Następnie kolejne n wierszy zawiera elementy A. Są to liczby naturalne z zakresu [1..1030-1].

Następnie podana jest liczba k<106 oraz w kolejnych k wierszach podawane są liczby naturalne i1,..., ik z zakresu [1..1030-1].

Wyjście
Dla każdej liczby is należy podać ile elementów w A jest mniejszych od is.
'''
import random
import math

zakres = math.pow(10, 30) - 1
n = int(input("Podaj ilość: "))
while n < 0 or n > zakres:
    n = input("Podaj ilość (n musi być naturalne): ")

A = [n]

while n > 0:
    A.append(random.randrange(1, zakres))

    n -= 1

k = int(input("Podaj k: "))
B = []

while k > 0:
    B.append(random.randrange(1, zakres))
    k -= 1

i = 0
while i < len(B):
    j = 0
    suma = 0
    while j < len(B):
        j += 1 
        if B[i] > A[j+1]:    # +1 bo n jest pierwsze w zbiorze A
            suma += 1

    print("Dla", B[i], suma, "liczb jest mniejszych")
    i += 1

