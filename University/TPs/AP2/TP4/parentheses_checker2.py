import sys
import builtins
def bracket(str):
    dict = {'(':')','{':'}','[':']'}
    ouv = []
    fer = []
    ouvLines = []
    ferLines = []
    ouvChars = []
    ferChars = []
    line = 1
    char = 0
    for i in range(len(str)):
        if(str[i]=="\n"):
            line += 1
            char = 0
        char += 1
        if(str[i]=='(' or str[i]=='[' or str[i]=='{'):
            ouv+=[str[i]]
            ouvLines+=[line]
            ouvChars+=[char]
        elif(str[i]==")" or str[i]=="]" or str[i]=='}'):
            fer+=[str[i]]
            ferLines+=[line]
            ferChars+=[char]
            if(len(ouv)!=0):
                o = ouv.pop()
                f = fer.pop()
                ol = ouvLines.pop()
                fl = ferLines.pop()
                oc = ouvChars.pop()
                fc = ferChars.pop()
            else:
                f = fer.pop()
                fl = ferLines.pop()
                fc = ferChars.pop()
                return "No open parenthese matching parenthese "+f+" at line "+builtins.str(fl)+" char "+builtins.str(fc)+"."
            if(dict[o]!=f):
                return "Closed parenthese "+f+" at line "+builtins.str(fl)+" char "+builtins.str(fc)+" don't match the open parenthese "+o+" at line "+builtins.str(ol)+" char "+builtins.str(oc)+"."
    if(len(ouv)!=0 and len(fer)==0):
        o = ouv.pop()
        ol = ouvLines.pop()
        oc = ouvChars.pop()
        return "Parenthese "+o+" at line "+builtins.str(ol)+" char "+builtins.str(oc)+" has no matching closed parenthese."
    return "Well parenthesed."

if __name__ == "__main__":
    path = sys.argv[1]
    fp = open(path,"r")
    str=""
    while(True):
        tmp=fp.readline()
        str += tmp
        if(tmp==""):
            break
    print(bracket(str))