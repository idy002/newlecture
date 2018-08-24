#!/usr/bin/python

from random import *

prob = "shortway"

cases = [   
            (50,100,2,50),
            (50,100,2,2),
            (50,100,2,2),
            (50,100,2,2),
            (50000,100000,2,10),
            (50000,100000,20,100),
            (50000,100000,200,1000),
            (50000,100000,2000,10000),
            (50000,100000,20000,100000),
            (50000,100000,2,100000),
            (50000,100000,2,100000)
        ]
cur = 0
for (nmin,nmax,kmin,kmax) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    n = randint(nmin,nmax)
    k = randint(kmin, min(n-1,kmax))

    cout += "%d %d\n" % (n, k)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
