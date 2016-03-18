from TP1 import *
from TP2 import *
from TP3 import *

from time import *

def search_fasta_naive(file, seq, p = True):
    """
@file : path of a file.
@seq  : Sequence needs to be searched.
@p    : determine print or not.
    """
    gene = print_fasta_sequences(file, 1)
    for i in range(len(gene)):
        if gene[i:i+len(seq)] == seq:
            if p : print(i)
            return i

def suffix_array(file):
    """
@file : the path of a file.
I found that there's a relevance between the length of a surfixe and its order. So we just need to construct a list with all the surfixes then sort it, and print its length.
    """
    t = time()
    gene = print_fasta_sequences(file, 1)
    suffixes = []
    for i in range (len(gene)):
        suffixes += [gene[i:]]
        suffixes = sorted(suffixes)
    for s in suffixes:
        print(len(gene)-1-len(s), end='')
    print()
    print(time()-t,'s')

'''
def suffix_array(gene):
 t = time()
 suffixes = []
 for i in range (len(gene)):
  suffixes += [gene[i:]]
 suffixes = sorted(suffixes)
 for s in suffixes:
  print(len(gene)-len(s), end=' ')
 print()
 print(time()-t,'s')
'''


