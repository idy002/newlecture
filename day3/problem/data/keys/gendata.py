#!/usr/bin/python

from random import *

prob = "keys"

cases = [   
        (100,200),
        (100,200),
        (100,200),
        (100,200),
        (5000,10000),
        (5000,10000),
        (5000,10000),
        (5000,10000),
        (5000,10000),
        (5000,10000),
        (5000,10000)
        ]
cur = 0
for (n,k) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d %d\n" % (n, k, randint(1,10**9))
    for i in range(n) :
        cout += "%d " % randint(1, 10**9)
    cout += "\n"
    for i in range(k) :
        cout += "%d " % randint(1, 10**9)
    cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
