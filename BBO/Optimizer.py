import pandas as pd
import numpy as np
import time
import myBBO
from benchmark_functions import *


def rounder(lst):
    return [round(x, 5) for x in lst]



search_params = {
    F1:[-100, 100, 30], F2 : [-100, 100, 30],
    F3: [-10, 10, 30], F4: [-600, 600, 30], F5:[-100, 100, 30]
    }

result = {
    "function": None,
    "count of iters": None,
    "population size": None,
    "mutation probability": None,
    "F(X)": None,
    "X": None,
    "time": None
}

def test_function(function, search_params):
    data_frame = pd.DataFrame(columns=result.keys())
    start = time.time()
    for count_of_iter in [1000, 10000]:
        for pop_size in [10, 20, 30]:
            for m_p in np.arange(0, 0.05, 0.01):
                start_time = time.time()
                answer = myBBO.BBO(function, count_of_iter,pop_size,m_p, search_params)
                total_time = round(time.time() - start_time, 5)
                fitness = answer[0]
                params  = rounder(answer[1])

                result["function"] = function.__name__
                result["count of iters"] = count_of_iter
                result["population size"] = pop_size
                result["mutation probability"] = m_p
                result["F(X)"] = fitness
                result["X"] = params
                result["time"] = total_time

                data_frame = data_frame.append(result, ignore_index = True)
    #data_frame.to_csv(f'{function.__name__}.csv')
    data_frame.to_excel(f'{function.__name__}.xlsx')
    print(f'Total time of benchmarking {function.__name__}: {time.time() - start}')


def main():
    for function in search_params.keys():
        test_function(function, search_params[function])

if __name__ == "__main__":
    main()