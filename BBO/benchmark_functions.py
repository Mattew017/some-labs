import math


def F1(x):
    result = 0
    for i in range(len(x)):
        result += x[i]**2
    return result


def F2(x):
    return max([abs(a) for a in x])


def F3(x):
    summa = 0
    multi = 1
    for a in x:
        summa += abs(a)
        multi *= abs(a)
    return summa + multi 


def F4(x):
    multi = 1
    summa = 0
    i = 1
    for a in x:
        summa += a**2
        multi *= math.cos(a/math.sqrt(i))
    return summa/4000 - multi + 1


def F5(x):
    dimention = len(x)
    sum_of_squares = 0
    sum_of_cos = 0
    for param in x:
        sum_of_squares += param**2
        sum_of_cos += math.cos(math.pi*param*2)
    sum_of_squares /= dimention
    sum_of_cos /= dimention
    return -20*math.exp(-0.2*math.sqrt(sum_of_squares)) - math.exp(sum_of_cos) + 20 + math.exp(1)

