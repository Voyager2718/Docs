'''
   Compute the entropy on files.

   @author FIL - IEEA - Univ. Lille 1 (oct 2010, août 2015)
'''

import sys

# IMPORTS A COMPLETER


def entropy(filename): 
    '''
    Computes the entropy of the file called `filename`.

    :param filename: Input file name.
    :type filename: str
    :return: A tuple whose first element is an integer: the number of bytes read\
    and the second element is a float: the entropy of the file's content
    :rtype: tuple
    '''
    counters = {}
    '''
    Dictionary that will store the number of occurrences of each byte.
    '''
    total_sum = 0
    nb_bytes = 0
    # Read the file to count occurrences of each byte
    infile = open(filename, 'rb')
    str = infile.read()
    tlen = len(str)
    # A COMPLETER
    import math
    log2 = lambda x:math.log(x)/math.log(2)
    exr = {}
    infoc = 0
    for each in str:
        try:
            exr[each] += 1
        except:
            exr[each] = 1
    for k,v in exr.items():
        freq  =  1.0*v/tlen
        infoc += freq*log2(freq)
    infoc *= -1
    return (tlen, infoc, -log2(1/256))
    # Calcul de l'entropie à partir des effectifs des octets.
    # A COMPLETER


def usage():
    print ("Usage: %s <filename>" % sys.argv[0])
    print ("\t<filename>: filename for which we want to compute the entropy.\n")
    exit(1)

def main():
    if len(sys.argv) != 2:
        usage()
    (nb_bytes, entro, m) = entropy(sys.argv[1])
    print ("%d bytes read." % nb_bytes)
    print ("Entropy = %f bits per byte." % entro)
    print ("An optimal coding would reduce this file size by %f" % (100-entro/m*100))
    
if __name__ == '__main__':
    main()