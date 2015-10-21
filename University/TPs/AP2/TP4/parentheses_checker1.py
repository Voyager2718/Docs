import sys
def bracket(str):
    dict = {'(':')','{':'}','[':']'}
    ouv = []
    fer = []
    for i in range(len(str)):
        if(str[i]=='(' or str[i]=='[' or str[i]=='{'):
                ouv+=[str[i]]
        elif(str[i]==")" or str[i]=="]" or str[i]=='}'):
            fer+=[str[i]]
            if(dict[ouv.pop()]!=fer.pop()):
                return False
    if(len(ouv)!=0 or len(fer)!=0):
        return False
    return True

if __name__ == "__main__":
    path = sys.argv[1]
    fp = open(path,"r")
    str=""
    while(True):
        tmp=fp.readline()
        str += tmp
        if(tmp==""):
            break
    if(bracket(str)):
        print("Well parenthesed.")
    else:
        print("Bad parenthesed.")