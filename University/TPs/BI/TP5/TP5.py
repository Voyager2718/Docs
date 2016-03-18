from TP1 import *
from TP2 import *
from TP3 import *

from time import *

def changePlace(s):
    return s[1:]+s[0]

def addDollar(genes):
    for i in range(len(genes)):
        genes[i] = genes[i][:len(genes) - i - 1] + '$' + genes[i][len(genes) - i - 1:]
    return genes

def bwt(path, p = True):
    t = time()
    gene = print_fasta_sequences(path, 1)
    genes = [gene]
    last = gene
    for i in range(len(gene)):
        last = changePlace(last)
        genes += [last]
    genes = addDollar(genes)
    genes.sort()
    g = ''
    for i in genes:
        g += i[len(genes) - 1]
    if p : print(g)
    print(time()-t,'s')
    return g

def bwt(gene, p = True):
    t = time()
    genes = [gene]
    last = gene
    for i in range(len(gene)):
        last = changePlace(last)
        genes += [last]
    genes = addDollar(genes)
    genes.sort()
    g = ''
    for i in genes:
        g += i[len(genes) - 1]
    if p : print(g)
    print(time()-t,'s')
    return g

'''
bwt('GGCCATCCTTCCTGACCATTTCCATCATTCCAGTCGAACT') => 'TGGACCCCCCCCTCTTGATTTACCCTG$ACATTTAGCATCA'
'''

def unbwt(gene, p = True):
    s = list(gene)
    for i in range(len(gene)):
        s = s.sort()
        
    for i in s
