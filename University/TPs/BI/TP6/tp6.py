from TP1 import *
from TP2 import *
from TP3 import *
from TP4 import *
from TP5 import *

from time import *

def addIndex(gnomes):
    ret = []
    for i in range(1,1+len(gnomes)):
        ret += [[gnomes[i-1],i]]
    return ret

def getReal(gnomes,gnomes2):
    s = ''
    for i in range(len(gnomes2)):
        if gnomes2[i][1] - 1 == 0:
            s += '$'
        else:
            s += str(gnomes[gnomes2 [i][1] - 2][0])
    return s

def bwt(path, p = True, r = True):
    t = time()
    gene = print_fasta_sequences(path, 1)
    gnomes = [i for i in gene]
    gnomes += ['$']
    gnomes = addIndex(gnomes)
    gnomes2 = gnomes
    gnomes2 = sorted(gnomes2)
    ret = getReal(gnomes,gnomes2)
    t = time() - t
    if p : print(ret)
    print(t,'s')
    if r : return ret