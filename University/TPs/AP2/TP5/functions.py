#Version 0.91
def read_competitors(path):
    fp = open(path,"r")
    fp.readline()
    res = []
    line = fp.readline()[:-1]
    i = 1
    while(line):
            res+=[{'num':str(i),'surname':str.split(line,';')[0],'name':str.split(line,';')[1],'gender':str.split(line,';')[2],'date':str.split(line,';')[3],'perf':None}]
            line = fp.readline()[:-1]
            i += 1
    fp.close()
    return res

def read_performances(path):
    fp = open(path,"r")
    fp.readline()
    res = []
    line = fp.readline()[:-1]
    while(line):
            res+=[{'number':str.split(line,';')[0],'hours':str.split(line,';')[1],'minutes':str.split(line,';')[2],'seconds':str.split(line,';')[3]}]
            line = fp.readline()[:-1]
    fp.close()
    return res

def set_performances(cand, perf):
    def findPerformance(number,perf):
        for i in range(len(perf)):
            if(perf[i]['number']==str(number)):
                return perf[i]
        return ''
    fp = open('results.csv','w')
    fp.write('Prenoms;Noms;Sexes;Date naiss.;hours;minutes;seconds\n')
    for i in range(len(cand)):
        fp.write(cand[i]['surname']+';'+cand[i]['name']+';'+cand[i]['gender']+';'+cand[i]['date'])
        if(findPerformance(i+1,perf)):
            fp.write(';'+findPerformance(i+1,perf)['hours']+';'+findPerformance(i+1,perf)['minutes']+';'+findPerformance(i+1,perf)['seconds'])
        fp.write('\n')
    fp.close()

#How to use :
#quicksort(a list that should be sorted, the column that you want to consider.)
def quicksort(arr,column):
    less = []
    pivotList = []
    more = []
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        for i in arr:
            if i[column] < pivot[column]:
                less.append(i)
            elif i[column] > pivot[column]:
                more.append(i)
            else:
                pivotList.append(i)
        less = quicksort(less,column)
        more = quicksort(more,column)
        return less + pivotList + more

def print_results(cand):
    print('{0:15}{1:15}{2:6}{3:6}{4:20}'.format('Prenom','Nom','Sex','Num.','Performance'))
    for c in cand:
        print('{0:15}{1:15}{2:6}{3:6}'.format(c['surname'],c['name'],c['gender'],c['num']),end='')
        if(c['perf']!=None):
            print('{4:20}'.format(c['perf']['hours']+':'+c['perf']['minutes']+':'+c['perf']['seconds']),end='')
        print()

def save_results(cand,path):
    """
	A function to save result to a file
	Parameters
	----
	cand : Candidates list.
	path : The path of the file.
	"""
    def to2(n):
        if(len(n)==1):
            return "0"+n
        elif(len(n)==2):
            return n
        return ''
    fp = open(path,'w')
    fp.write('Prenoms;Noms;Sexes;Date naiss.;Performance\n')
    for c in cand:
        fp.write(c['surname']+';'+c['name']+';'+c['gender']+';'+c['date'])
        if(c['perf'] != None):
            fp.write(to2(c['perf']['hours'])+':'+to2(c['perf']['minutes'])+':'+to2(c['perf']['seconds']))
        fp.write('\n')
    fp.close()