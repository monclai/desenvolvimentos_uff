from mpi4py import MPI
import numpy as np
from datetime import datetime

#Initialization of MPI
#---------------------
comm = MPI.COMM_WORLD
size = comm.Get_size()
rank = comm.Get_rank()
#----------------------

def add_values(values):
    sum_values = 0
    for val in values:
        if val == 1:
            sum_values = sum_values + 1
    
    return sum_values


def main():
    #initialization
    #--------------
    master = 0

    if(rank == master):
        #time startup
        start = 0
        start = datetime.now()
    
    #------------------
    
    #array complete with one
    values = np.ones(16)
    #separation with number of threads
    data = np.array_split(values, size)
    #split for each thread
    data = comm.scatter(data, root=master)
    #task perfome by each thread
    num = add_values(data)
    #union of results making a product
    result = comm.reduce(num, op=MPI.PROD, root=master)


    #display of the result in the master
    if(rank == master):
        end = datetime.now()
        final_time = end - start
        print('Number of threads: {}'.format(size))
        print('Product of sum in each thread: {}'.format(result))
        print('Final run time: {}'.format(final_time))


if __name__ == "__main__":
    main()


    