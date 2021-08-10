from mpi4py import MPI
import numpy as np
from datetime import datetime

comm = MPI.COMM_WORLD
world = comm.size
rank = comm.Get_rank()

a = np.random.randint(10, size=(5, 5))

if rank == 0:
    b = np.random.randint(10, size=(5, 5))
    start = datetime.now()
else:
    b = None

b = comm.bcast(b, root=0)

if world == 1:
    result = np.dot(a, b)
else:
    if rank == 0:
        a_row = a.shape[0]
        if a_row >= world:
            split = np.array_split(a, world, axis=0)
    else:
        split = None

    split = comm.scatter(split, root=0)
    
    split = np.dot(split, b)
    
    data = comm.gather(split, root=0)

    if rank == 0:    
        result = np.vstack(data)

if rank == 0:
    
    end = datetime.now()

    delta = end - start

    print(f"Tempo de execução: {delta}")

    print(f'{a} \n x \n {b} \n=\n {result}')
