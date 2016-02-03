from random import *
def generate_a_gene(l, path):
    fd = open(path, 'w')
    for i in range(l):
        a = int(random() * 3)
        if a == 0 : fd.write('A')
        elif a == 1 : fd.write('T')
        elif a == 2 : fd.write('C')
        elif a == 3 : fd.write('G')
    fd.close()

def print_fasta_sequences(path,p = 0):
    fd = open(path, 'r')
    c = fd.read(1)
    strs = []
    names = []
    while c != '':
        if c == '>':
            name = ''
            c = fd.read(1)
            while c != '\n':
                name += c
                c = fd.read(1)
            c = fd.read(1)
            names += [name]
            str = ''
            while c != '' and c != '>':
                if c != '\n':
                    str += c
                c = fd.read(1)
            strs += [str]
    fd.close()
    if p == 0 : print(''.join(strs))
    elif p == 1 : return ''.join(strs)
    elif p == 2 : return [names,strs]

def print_fasta_stats(path):
    g = readGene(path,2)
    for i in range(len(g[0])):
        print(g[0][i] + ' ' + str(len(g[1][i])))

def list_kmers(l,path, p = 0):
    str = print_fasta_sequences(path, 1)
    a = 0
    kmers = []
    str2 = ''
    for i in str:
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

def common_kmers(l, path1, path2, p = 0):
    kmers1 = list_kmers(l, path1, 1)
    kmers2 = list_kmers(l, path2, 1)
    a = 0
    for i in kmers1:
        if i in kmers2 :
            if p == 0 : print(i)
            a += 1
    if p == 1 : return a

def ratio_common_kmers(l, path1, path2, p = 0):
    a = common_kmers(l, path1, path2, 1)/len(list_kmers(l, path1, 1))
    if p == 0 : print(a)
    elif p == 1 : return a