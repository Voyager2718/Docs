#YANG Zhipeng
#OUAAKA Marouane
#Question 1.
source_alphabet = ['a', 'b', 'c']
code = ['010', '100', '110']
my_coding = create(source_alphabet, code)

#Question 2.
code0 = my_coding.code('a')
code1 = my_coding.code('b')
codec = my_coding.code('c')

#Question 3.
a = my_coding.decode('010')
b = my_coding.decode('00')
c = my_coding.decode('110')

#Question 4.
#La fonction renvoie une exception Not_codable_symbol.

#Question 5.
#La fonction renvoie une exception Undecodable_word.

#Question 6.
source_alphabet = \
['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ']
code1 = [ "00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11111" ]

code2 = [".-/", "-.../", "-.-./", "-../", "./", "..-./", "--./", "..../", "../", ".---/", "-.-/", ".-../", "--/", "-./", "---/", ".--./", "--.-/", ".-./", ".../", "-/", "..-/", "...-/", ".--/", "-..-/", "-.--/", "--../", "---./"]

code3 = ["1010", "0010011", "01001", "01110", "110", "0111100", "0111110", "0010010", "1000", "011111110", "011111111001", "0001", "00101", "1001", "0000", "01000", "0111101", "0101", "1011", "0110", "0011", "001000", "011111111000", "01111110", "0111111111", "01111111101", "111"]
coding1 =  create(source_alphabet, code1)
coding2 =  create(source_alphabet, code2)
coding3 =  create(source_alphabet, code3)

#Question 7.
coding1.code('A') #'00000'
coding2.code('A') #'.-/'
coding3.code('A') #'1010'

#Question 8.
def code_word(word, coding):
    str = ''
    i = 0
    while(i < len(word)):
            str += coding.code(word[i])
            i += 1
    return str

#Question 9.
#>>> code_word('CODAGE',coding1)
#'000100111000011000000011000100'
#>>> code_word('CODAGE',coding2)
#'-.-./---/-../.-/--././'
#>>> code_word('CODAGE',coding3)
#'0100100000111010100111110110'

#Question 10.
len(coding1.code('A'))

def decode_fixed_length_word(word, coding):
    str = ''
    i = 0
    length = len(coding.code('A'))
    while(i < len(word)):
        str += coding.decode(word[i:i+length])
        i += length
    return str

#Question 11.
def decode_fixed_length_word(word, coding):
    str = ''
    i = 0
    length = len(coding.code('A'))
    while(i < len(word)):
        try:
            str += coding.decode(word[i:i+length])
        except Undecodable_word:
            raise Undecodable_word('decode_fixed_length_word: undecodable word')
        i += length
    return str

#Question 12.
#>>> decode_fixed_length_word('000100111000011000000011000100', coding1)
#'CODAGE'

#Question 13.
#>>> decode_fixed_length_word('0101100000111110111100111010000101100000011011001100111100010111001111010000010011111000110010011111010111111101110101001010110001010000010010001111110001000111000001000101111001000110110011010000010010001', coding1)
#'LA PHILANTHROPIE DE L OUVRIER CHARPENTIER'

#Question 14.
def decode_comma_word(word, comma, coding):
    res = ''
    i = 0
    while(i < len(word)-1):
        i_comma = str.find(word[i:],comma)
        res += coding.decode(word[i:i+i_comma+1])
        i = i + i_comma + 1
    return res

#Question 15.
def decode_comma_word(word, comma, coding):
    res = ''
    i = 0
    while(i < len(word)-1):
        i_comma = str.find(word[i:],comma)
        try:
            res += coding.decode(word[i:i+i_comma+1])
        except Undecodable_word:
            raise Undecodable_word('decode_comma_word: comma not found, cannot decode the word')
        i = i + i_comma + 1
    return res

#Question 16.
#>>> decode_comma_word(word,comma,coding2)
#'POUR LA FRANCE D EN BAS DES NOUILLES ENCORE'

#Question 17.
def decode_prefix_letter(word, coding):
    word_length = len(word)
    for i in range(1,word_length+1):
        try:
            prefix = coding.decode(word[:i])
            return (prefix, i)
        except:
            pass
    raise Undecodable_word

def decode_prefix_word(word, coding):
    res = ''
    while(word):
            res += decode_prefix_letter(word, coding)[0]
            word = word[decode_prefix_letter(word, coding)[1]:]
    return res

#Question 18.
def decode_prefix_word(word, coding):
    res = ''
    while(word):
        try:
            res += decode_prefix_letter(word, coding)[0]
        except Undecodable_word:
            raise Undecodable_word('decode_comma_word: comma not found, cannot decode the word')
        word = word[decode_prefix_letter(word, coding)[1]:]
    return res

#Question 19.
#>>> decode_prefix_word('0110001001010100001110101111111010110110111011000000011011111110000000110101101111110101110111100101010000101110',coding3)
#'THALES EST TOUJOURS A FAIRE'

#Question 20.
#AB

#Question 21.
def complete_byte(b):
    assert len(b)<8,'I cannot complete a completed byte!'
    b+='1'
    i = len(b)
    while(i<8):
        b+='0'
        i = len(b)
    return b

#Question 22.

#Question 23.
def uncomplete_byte(b):
    assert len(b)==8,'I can only uncomplete a byte'
    ind = str.find(b,'11')
    if(ind != -1):
        return b[:ind+1]
    return ''

