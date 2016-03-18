from TP1 import *
from TP2 import *
from operator import *

def decoupe(l,gene, p = 0):
    """
decoupe(4,gene)
Complexity: 2 * n
    """
    a = 0
    kmers = []
    str2 = ''
    for i in gene:
        if a % l == 0 and a != 0:
            kmers += [str2]
            str2 = ''
            if p == 0 : print()
        if p == 0 : print(i,end = '')
        str2 += i
        a += 1
    kmers += [str2]
    if p == 0 : print()
    elif p == 1 : return kmers

def best_matches(n, g, path1, path2, p = True):
    genes0 = print_fasta_sequences(path1, 2)
    genes1 = print_fasta_sequences(path2, 2)
    dupl = {genes1[0][i] : 0 for i in range(len(genes1[0]))}
    dcp0 = decoupe(g, genes0[1][0], 1)
    for i in range(len(genes1[1])):
        dcp1 = decoupe(g, genes1[1][i], 1)
        for j in range(len(dcp0)):
            if dcp0[j] in dcp1:
                dupl[genes1[0][i]] += 1
    sorted_g = sorted(dupl.items(), key = itemgetter(0))
    sorted_g.sort(reverse = True, key = lambda dup : dup[1])
    if p :
        for i in range(n):
            try:
                print(sorted_g[i][0],':', sorted_g[i][1])
            except IndexError:
                break
    return sorted_g