from mpi4py import MPI
from numpy import *
import time 

def filtro(arr):
    if(len(arr)==len(set(arr))):
        
        return True
    else:
        
        return False

def doWork(arr):
    escolha = array([1,2,3,4])
    win = 0
    for i in arr:
        if(array_equal(i,escolha)):
            win = win + 1
    return win

start = 0
comm = MPI.COMM_WORLD
size = comm.Get_size()
rank = comm.Get_rank()
if(rank == 0):
    start = time.time()
#fazendo os sorteios 
n = 100000
sorteado = random.randint(1,21,(n,4)) 
sorteado = sort(sorteado) 
filtrado = filter(filtro,sorteado)
sorteado2 = array(list(filtrado))
sorteado2 = sort(sorteado2)
jogos = sorteado2.size/4 
data = array_split(sorteado2,size)

#espalhando os jogos para os workers     
data = comm.scatter(data, root=0)
#contando o numero de vitorias 
num = doWork(data)

#somando o numero de vitorias 
soma = comm.reduce(num,op=MPI.SUM,root=0)

if(rank == 0 ):
    end = time.time()
    print('Valor da soma de vitorias = ',soma)
    print('Probabilidade de vitoria = ',soma/jogos*100)
    print('Tempo total de execução do código {} segundos'.format(end-start))