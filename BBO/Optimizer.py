import pandas as pd
import myBBO
from benchmark_functions import *


def rounder(lst):
    return [round(x, 5) for x in lst]

pop_size = 30
mutation_probability = 0.01
search_params = {F1:[-100, 100, 30], F4 : [-100, 100, 30]}

for function in search_params.keys():
    result = myBBO.BBO(function, 1000,pop_size,mutation_probability, search_params[function])
    fitness = result[0]
    params  = rounder(result[1])
