#!/usr/bin/python

from random import *

prob = "pizza"

cases = [   
        (1000,10,100,1000),
        (1000,10,100,1000),
        (1000,10,100,1000),
        (1000,10,100,1000),
        (100000,10000,10000,100000),
        (100000,10000,10000,100000),
        (100000,10000,10000,100000),
        (100000,10000,10000,100000),
        (100000,10000,10000,100000),
        (100000,10000,10000,100000),
        (100000,10000,10000,100000)
        ]
cur = 0
for (n, smax, Smin, Smax) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    S = randint(Smin, Smax)
    cout += "%d %d\n" % (n, S)
    for i in range(n) :
        s = randint(1,smax)
        a = randint(1,100000)
        b = randint(1,100000)
        cout += "%d %d %d\n" % (s, a, b)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
