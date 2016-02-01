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