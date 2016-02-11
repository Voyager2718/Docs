from random import *
def generate_a_gene(l, path):
    """
A function that can generate a sequence of gene(Generate ATCG randomly, need to add ">" yourself).
Complexity: n
    """
    fd = open(path, 'w')
    for i in range(l):
        a = int(random() * 3)
        if a == 0 : fd.write('A')
        elif a == 1 : fd.write('T')
        elif a == 2 : fd.write('C')
        elif a == 3 : fd.write('G')
    fd.close()

def print_fasta_sequences(path,p = 0):
    """
print_fasta_sequences('gene.fasta')
Complexity: n
    """
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
    """
print_fasta_stats('gene.fasta')
Complexity: n
    """
    g = print_fasta_sequences(path,2)
    for i in range(len(g[0])):
        print(g[0][i] + ' ' + str(len(g[1][i])))

def list_kmers(l,path, p = 0):
    """
list_kmers(4,'gene.fasta')
Complexity: 2 * n
    """
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
    """
common_kmers(4,'gene1.fasta', 'gene2.fasta')
Complexity: n1 * n2
    """
    kmers1 = list_kmers(l, path1, 1)
    kmers2 = list_kmers(l, path2, 1)
    a = 0
    for i in kmers1:
        if i in kmers2 :
            if p == 0 : print(i)
            a += 1
    if p == 1 : return a

def ratio_common_kmers(l, path1, path2, p = 0):
    """
Compare a.fasta(which is the first one of those 3 links) and b.fasta(2nd one), we found that for triplet, 0.9999381494309748 of their gene are the same. (ratio_common_kmers(3, 'a.fasta', 'b.fasta'))
>>> ratio_common_kmers(3, 'a.fasta', 'b.fasta')
0.9999381494309748
>>> ratio_common_kmers(6, 'a.fasta', 'b.fasta')
0.5091538842157348
>>> ratio_common_kmers(10, 'a.fasta', 'b.fasta')
0.0016491445062873633
>>> ratio_common_kmers(15, 'a.fasta', 'b.fasta')
0.0
>>> ratio_common_kmers(12, 'a.fasta', 'b.fasta')
0.0
ratio_common_kmers(4,'gene1.fasta', 'gene2.fasta')
Complexity: n1 * n2
    """
    a = common_kmers(l, path1, path2, 1)/len(list_kmers(l, path1, 1))
    if p == 0 : print(a)
    elif p == 1 : return a

class NumberError(Exception):
    pass

def string_to_list(str):
    """
'abcdef' -> ['a','b','c','d','e','f']
    """
    return [str[i] for i in range(len(str))]

def shuffle_gene():
    a = int(random() * 4)
    if a == 0 : return 'A'
    if a == 1 : return 'T'
    if a == 2 : return 'C'
    if a == 3 : return 'G'

def print_list(list):
    for i in list : print(i, end = '')
    print()

def random_mutations(t, path, p = 0):
    """
random_mutations(3, 'gene.fasta')
before: ATCGA
after : CTACA
    """
    str = print_fasta_sequences(path, 1)
    assert (t <= len(str))
    shuffled = []
    str = string_to_list(str)
    for i in range(t):
        a = int(random() * len(str))
        while a in shuffled:
            a = int(random() * t)
        shuffled += [a]
        b = str[a]
        str[a] = shuffle_gene()
        while str[a] == b : str[a] = shuffle_gene()
    if p == 0 : print_list(str)
    return ''.join(str)

def main():
    print('Parce qu\'on écrire en Python, veuillez importer et demarrer chaque fonction(les \'-\' sont remplacer par \'_\')')

if __name__ == '__main__':
    main()