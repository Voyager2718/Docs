#TP3 de Codage

#Binome :
#Khammar
#Senoussi


#Question 4
BASE64_SYMBOLS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                  'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                  'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
                  '8', '9', '+', '/']

#Question 5
def bytes_to_symbols(l):
    """
    Takes(at most) three bytes of data in input and returns the corresponding base64 symbols.

    :param data: a list of at most three bytes
    :type data: list
    :return: four base64 symbols corresponding to the data given in input
    :type return: str
    :UC: len(data)<=3
    :Examples:
    >>> bytes_to_symbols([5])
    'BQ=='
    >>> bytes_to_symbols([4, 163])
    'BKM='
    >>> bytes_to_symbols([28, 89, 101])
    'HFll'
    >>> bytes_to_symbols([])
    ''
    
    """
    #on recupere les octets et on les transforme en octet codé en binaire
    l_octet_bin=[]
    for by in l:
        l_octet_bin.append(byte_to_binary(by))
    #On verifie le nombre d'octet lu et on initialise e au nombre correspondant au nombre de '=' a rajouter a la fin
    if len(l_octet_bin)==1:
        e=2
    elif len(l_octet_bin)==2:
        e=1
    else :
        e=0
    #on met tout les bits dans une chaine de caractere
    chaine=''
    for octet_bin in l_octet_bin:
        chaine+=octet_bin
    #On prepare la chaine pour qu'elle correspond soit divisible par groupe de 6
    while len(chaine)%6!=0:
        chaine+='0'
    #On resepare les bits de sortes a avoir une liste de sextet
    l_sextet=[]
    for i in range (int(len(chaine)/6)):
        l_sextet.append(chaine[:6])
        chaine=chaine[6:]
    #On retrouve la valeur decimale correspondant a chaque sextet
    l_val_sextet=[]
    for sextet in l_sextet:
        l_val_sextet.append(int(sextet,2))
    #On prepare la chaine qui va etre renvoyer
    res=''
    for s in l_val_sextet:
        res+=BASE64_SYMBOLS[s]
        #On rajoute les '=' manquant

    for i in range(0,e):
        res+='='
    return res

#Question 7
def base64_encode(source):
    """
    Encode a file in base64 and outputs the result on standard output.

    :param source: the source file name
    :type source: str
    """
    input = open(source,'rb')
    data = input.read(3)
    nb=0
    #
    l=''
    #
    while len(data)>0:
        #print (bytes_to_symbols(data), end='')
        l+=bytes_to_symbols(data)
        data = input.read(3)
    #print()
    input.close();
    #On cree une liste qui va contenir chaque ligne de taille 76
    l1=[]
    for i in range(len(l)//76):
        l1.append(l[0:76])
        l=l[76:]
    l1.append(l[0:])#on rajoute les caracteres restants mais ne pouvant composer une ligne d'au moins 76 caracteres
    #Affiche toute les lignes
    for ligne in l1:
        print(ligne)
#TEST
#base64_encode('cigale-UTF-8.txt')

        
#Question 8

def decode_base64_symbol(symbol):
    """
    :Parameters: symbol
    :Returns: the integers corresponding to the base64 symbol
    :Return type: int
    :CU: the symbol is part of the base64 symbols
    :Examples:
    >>> decode_base64_symbol('a')
    26
    >>> decode_base64_symbol('z')
    51
    >>> decode_base64_symbol('12')
    Traceback (most recent call last):
    File "<pyshell#17>", line 1, in <module>
    decode_base64_symbol('12')
    File "/tmp/ahlam.khammar/tpcodage/base64.py", line 23, in decode_base64_symbol
    assert d in BASE64_SYMBOLS, 'the symbol is not part of base64'
    AssertionError: the symbol is not part of base64
    """
    assert symbol in BASE64_SYMBOLS, 'the symbol is not part of base64'
    return(BASE64_SYMBOLS.index(symbol))


#Question 9
def symbols_to_bytes(symbols):
    """
    Convert base64 symbols to bytes

    :param symbols: a string of four base64 symbols(plus the =)
    :type symbols: str
    :return: a list of one to 3 bytes whose values correspond to the base64 symbols
    :type return: list
    :UC: len(symbols)==4
    """
    #on recupere la chaine de caractere

    #On retrouve la valeur decimal correspondant a chaque sextet
    liste_decimal=[]
    count=0
    for symbol in symbols:
        if symbol=='=':
            count+=1
        else :
            liste_decimal.append(BASE64_SYMBOLS.index(symbol))
    #On recreer les sextets
    bin_str=''
    for by in liste_decimal:
        tmp=integer_to_binary_str(by)
        while len(tmp)!=6:
            tmp='0'+tmp
        bin_str+=tmp
    #on recupere une chaine de caractere contenant tout les sextets concatené
    if count == 0:#si il n'y a pas de '=' dans le parametre symbols , on a donc 24 bit et on peut directement regrouper en octets
        return binary_to_bytes(bin_str)
    elif count == 1:#jai 3 caracteres
        return binary_to_bytes(bin_str[:-2])
    elif count == 2:#J'ai 2 caracteres
        return binary_to_bytes(bin_str[:-4])

#Question 10

def process_base64_line(line):
    """
    Process a line from a base64 input and writes the conversion on the output

    :param line: a line of a base64 output
    :type line: str
    :UC: len(line)%4==0 and the line only contains base64 symbols
    """
    assert len(line)%4 ==0
    #On stocke tout les octets de chaque symboles  dans 'content'
    content=[]
    for i in range(int(len(line)/4)):
        tmp=line[:4]
        by=symbols_to_bytes(tmp)
        line=line[4:]
        content.append(by)
    #On va ecrire en binaire dans un fichier temporaire les octets recupérés
    file_tmp=open('tmp','ab')#on ouvre le fichier 'tmp' en mode append pour ajouter du contenu sans supprimer
    for octet in content:
        file_tmp.write(bytes(octet))
    file_tmp.close()

#process_base64_line('TGEgQ2lnYWxlIGV0IGxhIEZvdXJtaQoKTGEgQ'[:16])
import os
#Question 11
def base64_decode(source):
    """"
    Decode a source file encoded in base64 and output the result

    :param source: the filename of the base64 file to decode
    :type source: str
    """
    #on ouvre le fichier en base64 a decoder
    file64=open(source,'r')
    #On stocke le contenu du fichier dans une variable
    all_txt=file64.readlines()
    file64.close()
    #On va decoder ligne par ligne le contenu du fichier
    for li in all_txt:
        process_base64_line(li[:-1])
    #le process_base64_line ecrit dans un fichier 'tmp' le contenu decoder
    #on va le recuperer
    file_tmp=open('tmp','r')
    a=file_tmp.readlines()
    #pour chaque ligne decoder dans 'tmp' on l'imprime a l'ecran
    for line in a :
        print(line)
    reinit.close()
    os.remove('tmp')#permet de supprimer le fichier 'tmp'
    
#base64_decode('cigale.b64')


#######################################################################
#Fonction du TP precedent mais reutilisé ici
def est_pair(n):
    """
    Verifie si un entier est pair ou non avec des operateurs logiques

    :param n: l'entier a verifier
    :type n: int
    :UC: None
    :Exemple:
    >>> est_pair(2)
    True
    >>> est_pair(1)
    False
    """
    if n&1==0:
        return True
    if n&1==1:
        return False

def  integer_to_binary_str(n):
    """
    renvoie l’écriture binaire
    (sous forme de chaîne de caractère) de l’entier passé en paramètre.

    :param n: entier a ecrire en binaire
    :type n: int
    :UC: None
    :Exemple:
    >>> integer_to_binary_str(10)
    '1010'
    """
    l=''
    if n==0:
            return '0'
    while n !=0:
        if est_pair(n)==True:
            n=n>>1
            l='0'+l
        else:
            n=n>>1
            l='1'+l
    return l

def byte_to_binary(o):
    """
    prend en paramètre un octet et renvoie sa représentation binaire sur 8 bits.

    :param o: byte
    :type o: int
    :UC: None
    """
    a=integer_to_binary_str(o)
    while len(a)<8:
        a='0'+a
    return a

def binary_to_bytes(binary):
    """
    prend une chaîne binaire en entrée et qui la convertit,
    8 bits par 8 bits, en une liste d’entiers.

    :param binary: chaine de caractere binaire
    :type binary: chaine str
    :UC :None
    :Exemple:
    >>> binary_to_bytes('110101101101011111011000')
    [214, 215, 216]
    >>> binary_to_bytes('110101101101011111011011')
    [214, 215, 219]
    """
    if len(binary)%8!=0:
        while len(binary)%8 != 0:
            binary='0'+binary
    l=[]
    while len(binary)!=0:
        l.append(binary_str_to_integer(binary[:8]))
        binary=binary[8:]
    return l
def binary_str_to_integer(b):
    """
    A partir d’une écriture binaire renvoie l’entier qui lui correspond.

    :param b: chaine de caractere binaire qu'il faut convertir
    :type b: str
    :UC: None
    :Exemple:
    >>> binary_str_to_integer('1010')
    10
    """
    p=len(b)-1
    ind=0
    en=0
    for i in range (len(b)):
        en+=int(b[ind])*2**p
        p-=1
        ind+=1
    return en

#########################################################################

