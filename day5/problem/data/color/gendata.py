#!/usr/bin/python

from random import *

prob = "color"

cases = [   
            (10,10,10,0),
            (10,10,10,1),
            (10,10,10,-1),
            (10,10,10,0),
            (100,100000,1000,1),
            (100,100000,1000,-1),
            (100,100000,1000,5),
            (100,100000,1000,-5),
            (100,100000,1000,0),
            (100,100000,1000,0),
            (100,100000,1000,0)
        ]
cur = 0
for (T,n1,n2,tp) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data
    
    cout += "%d\n" % T
    for t in range(T) :
        n = n1 if t == 0 else n2
        cout += "%d\n" % n
        cout += " ".join([choice("01") for j in range(n)])
        cout += "\n"
        for i in range(2,n+1) :
            p = None
            if tp < 0 :
                p = randint(max(1,i + tp), i-1)
            elif tp > 0 :
                p = randint(1, min(tp,i-1))
            else :
                p = randint(1,i-1)
            cout += "%d %d\n" % (p, i)
        tp = choice([-3, -2, -1, 0, 0, 0, 1, 2, 3])

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
