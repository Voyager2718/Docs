from math import *
from TP1  import *
def windows(l, s, path):
    seq = print_fasta_sequences(path, 1)
    for i in range(ceil(len(seq)/(l-s)-1)):
        for j in range(ceil(i*(l-s)), ceil(i*(l-s)+l)):
            try:
                print(seq[j], end = '')
            except IndexError:
                break
        print()

def formule(n, l, s):
    return floor(n/(l+s))

def mapper_windows_kmers(lw, sw, lk, sk, r, g):
    assert type(sk) == float and sk < 1 and sk > 0
    raise Exception('Je ne comprend pas la question.')
    
def list_spaced_kmers(g, path, p = True):
    """
if p == False, this function will NOT print result
    """
    seq = print_fasta_sequences(path, 1)
    space = ''
    spaces = []
    for i in range(ceil(len(seq)/len(g)) + 1):
        for j in range(len(g) + 1):
            try:
                if(g[j] == '#') :
                    if(i == 0):
                        if p : print(seq[i * ceil(len(seq)/len(g)) + j], end = '')
                        space += seq[i * ceil(len(seq)/len(g)) + j]
                    else:
                        if p : print(seq[i * ceil(len(seq)/len(g)) + j + 1], end = '')
                        space += seq[i * ceil(len(seq)/len(g)) + j + 1]
            except IndexError:
                break
        spaces += [space]
        space = ''
        if p : print()
    return spaces

def common_spaced_kmers(g, path1, path2, p = True):
    spaces1 = list_spaced_kmers(g, path1, False)
    spaces2 = list_spaced_kmers(g, path2, False)
    common = []
    for i in spaces1:
        if i in spaces2:
            if p : 
                print(i)
                common += [i]
    return common

def ratio_common_spaced_kmers(g, path1, path2, p = True):
    c = common_spaced_kmers(g, path1, path2)
    r = len(c)/len(list_spaced_kmers(g,path1, False))
    if p :print(r)
    return r