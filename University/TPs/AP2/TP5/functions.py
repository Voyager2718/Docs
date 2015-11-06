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
        if(number >= len(perf)):
            return ''
        for i in range(len(perf)):
            if(perf[i]['number']==str(number)):
                return perf[i]
        return ''
    comp = read_competitors('inscrits.csv')
    fp = open('inscrits1.csv','w')
    fp.write('Prenoms;Noms;Sexes;Date naiss.;hours;minutes;seconds\n')
    for i in range(len(comp)):
        fp.write(comp[i]['surname']+';'+comp[i]['name']+';'+comp[i]['gender']+';'+comp[i]['date'])
        if(findPerformance(i,perf)):
            fp.write(';'+perf[i]['hours']+';'+perf[i]['minutes']+';'+perf[i]['seconds'])
        fp.write('\n')
    fp.close()
	