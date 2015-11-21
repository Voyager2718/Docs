#Version 0.95.1
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

def set_performances2(cand, perf):
    def findPerformance(number,perf):
        for i in range(len(perf)):
            if(perf[i]['number']==str(number)):
                return perf[i]
        return ''
    for i in range(len(cand)):
        if(findPerformance(i+1,perf)):
            p = {'hours':int(findPerformance(i+1,perf)['hours']),'minutes':int(findPerformance(i+1,perf)['minutes']),'seconds':int(findPerformance(i+1,perf)['seconds'])}
            cand[i]['perf'] = p

#How to use :
#quicksort(a list that should be sorted, the column that you want to consider.)
def quicksort(arr,func):
    less = []
    pivotList = []
    more = []
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        for i in arr:
            if func(i,pivot) == -1:
                less.append(i)
            elif func(i,pivot) == 1:
                more.append(i)
            else:
                pivotList.append(i)
        less = quicksort(less,func)
        more = quicksort(more,func)
        return less + pivotList + more

def compare_name(a,b):
    if(a['name']>b['name']):return 1
    if(a['name']<b['name']):return -1
    return 0

def compare_performance(a,b):
    if(a['perf']==None and b['perf']==None):
        return 0
    if(a['perf']==None):
        return 1
    if(b['perf']==None):
        return -1
    if(a['perf']['hours']<b['perf']['hours']):
        return -1
    elif(a['perf']['hours']>b['perf']['hours']):
        return 1
    if(a['perf']['minutes']<b['perf']['minutes']):
        return -1
    elif(a['perf']['minutes']>b['perf']['minutes']):
        return 1
    if(a['perf']['seconds']<b['perf']['seconds']):
        return -1
    elif(a['perf']['seconds']>b['perf']['seconds']):
        return 1
    return 0

def print_results(cand):
    def to2(n):
        if(n<10):
            return '0'+str(n)
        return str(n)
    print('{0:15}{1:15}{2:6}{3:6}{4:20}'.format('Prenom','Nom','Sex','Num.','Performance'))
    for c in cand:
        print('{0:15}{1:15}{2:6}{3:6}'.format(c['surname'],c['name'],c['gender'],c['num']),end='')
        if(c['perf']!=None):
            print('{0:20}'.format(to2(c['perf']['hours'])+':'+to2(c['perf']['minutes'])+':'+to2(c['perf']['seconds'])),end='')
        print()

def save_results(cand,path):
    """
	A function to save result to a file
	Parameters
	----
	cand : Candidates list.
	path : The path of the file.
	"""
    fp = open(path,'w')
    fp.write('Prenoms;Noms;Sexes;Date naiss.;Performance\n')
    for c in cand:
        fp.write(c['surname']+';'+c['name']+';'+c['gender']+';'+c['date'])
        if(c['perf'] != None):
            fp.write(str(c['perf']['hours'])+':'+str(c['perf']['minutes'])+':'+str(c['perf']['seconds']))
        fp.write('\n')
    fp.close()
