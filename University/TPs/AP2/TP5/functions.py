#Version 0.9
def read_competitors(path):
    fp = open(path,"r")
    fp.readline()
    res = []
    line = fp.readline()[:-1]
    i = 1
    while(line):
            res+=[{'num':i,'surname':str.split(line,';')[0],'name':str.split(line,';')[1],'gender':str.split(line,';')[2],'date':str.split(line,';')[3]}]
            line = fp.readline()[:-1]
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
#list_sort(a list that should be sorted, the column that you want to consider.)
def list_sort(arr,column):
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
        less = list_sort(less,column)
        more = list_sort(more,column)
        return less + pivotList + more

#def 