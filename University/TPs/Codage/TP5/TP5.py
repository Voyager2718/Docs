#Question 1
#-log(1/256) = 8
#Les fichiers qui ont 256 caract¨¨res.

#Question 2
#

#Question 4
#cigale.txt 4.507422 bits
#codage.bmp 4.447328 bits
#codage.png 7.986496 bits
#entropy_skeleton.py 4.715577 bits
#morse.mp3 7.956906 bits
#morse.wav 7.445079 bits
#sonnet18.txt 4.397370 bits
#entropy.zip 7.520252 bits
#chinese.txt 6.537162 bits

#Question 5
#

#Question 7
#cigale.txt 43.657228%
#codage.bmp 44.408397%
#codage.png 0.168798%
#entropy_skeleton.py 41.055283%
#morse.mp3 0.538673%
#morse.wav 6.936509%
#sonnet18.txt 45.032877%
#entropy.zip 5.996844%
#chinese.txt 18.285473%

#Question 8
def symbol_occurrences(strObj):
    ch = strObj.read(1)
    dict = {}
    while(ch != ''):
        if(ch in dict):
            dict[ch] += 1
        else:
            dict[ch] = 1
            ch = strObj.read(1)
    return dict

