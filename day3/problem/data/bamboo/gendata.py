#!/usr/bin/python

from random import *

prob = "bamboo"

cases = [   
            (100,100),
            (100,100),
            (100,100),
            (100,100),
            (10**9, 10**9),
            (10**9, 10**9),
            (10**9, 10**9),
            (10**9, 10**9),
            (10**9, 10**9),
            (10**9, 10**9),
            (10**9, 10**9)
        ]
cur = 0
for (amax,kmax) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    n = 100
    cout += "%d %d\n" % (n, (int)(uniform(0.7,1.3) * kmax))
    for i in range(n) :
        cout += "%d " % randint(1,amax)
    cout += "\n"
    


##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
