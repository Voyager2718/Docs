import sys
import builtins
import stack
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
    inComment = False
    inString = False
    for i in range(len(str)):
        if(inComment and str[i]!="\n"):
            continue
        elif(inComment and str[i]=="\n"):
            inComment = False
        if(str[i]=="\n"):
            line += 1
            char = 0
        if(str[i]=="#"):
            inComment = True
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
                o = stack.pop(ouv)
                f = stack.pop(fer)
                ol = stack.pop(ouvLines)
                fl = stack.pop(ferLines)
                oc = stack.pop(ouvChars)
                fc = stack.pop(ferChars)
            else:
                f = stack.pop(fer)
                fl = stack.pop(ferLines)
                fc = stack.pop(ferChars)
                return "No open parenthese matching parenthese "+f+" at line "+builtins.str(fl)+" char "+builtins.str(fc)+"."
            if(dict[o]!=f):
                return "Closed parenthese "+f+" at line "+builtins.str(fl)+" char "+builtins.str(fc)+" don't match the open parenthese "+o+" at line "+builtins.str(ol)+" char "+builtins.str(oc)+"."
    if(len(ouv)!=0 and len(fer)==0):
        o = stack.pop(ouv)
        ol = stack.pop(ouvLines)
        oc = stack.pop(ouvChars)
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