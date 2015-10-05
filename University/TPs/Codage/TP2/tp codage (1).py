#khaldoune Anass

from math import *
from struct import *

def integer_to_digit(n):
    """
    Convert an integer in a hexadecimal digit
    :Parameters:	integer (int) –
    :Returns:	the character representing the hexadecimal digit
    :Return type:	str
    :CU:	integer >= 0 and integer < 16
    :Example:
    
    >>> integer_to_digit(7)
    '7'
    >>> integer_to_digit(14)
    'E'
    >>> integer_to_digit(-1)
    Traceback (most recent call last):
  
    >>> integer_to_digit(18)
    Traceback (most recent call last):

    """
    assert(type(n)==int and 0<n<16)
    if 0<n<9:
        return chr(ord('0') + n)
    else:
        return chr(ord('7') + n)


def integer_to_string(n,b):

    """
    Gives the representation in base base of the integer integer.

    :param n: the integer
    :param b: base
    
    Example:
    
    >>> integer_to_string(1331, 2)
    '10100110011'
    >>> integer_to_string(1331, 8)
    '2463'
    >>> integer_to_string(1331, 16)
    '533'
    >>> integer_to_string(250, 16)
    'FA'
    >>> integer_to_string(250, 10)
    '250'
    >>> integer_to_string(1, 10)
    '1'
    >>> integer_to_string(0, 2)
    '0'
    """
    
    convertString = "0123456789ABCDEF"
    
    if n < b:
        return convertString[n]
    else:
        return integer_to_string(n//b,b) + convertString[n%b]

for i in range(20):
    print(('%d'% i)+': '+ integer_to_string(i,2)+' '+integer_to_string(i,8)+' '+integer_to_string(i,16))

def power_two(n):
    '''
    '''
    if n==0:
        return 1
    else:
        return 2<<n-1

def integer_to_binary_str(n):
    '''
    '''
    return ''.join(str(1 & int(n) >> i) for i in range(int(log(n,2))+1)[::-1])


def binary(s):
    l=list(s)
    l.reverse()
    st=0
    #l=[int(i) for i in l]
    for i in range(len(l)):
        st+=int(l[i])*power_two(i)
    return st

def byte_to_binary(n):
    '''
    '''
    return ''.join(str(1 & int(n) >> i) for i in range(8)[::-1])


        
        
    
    
    
