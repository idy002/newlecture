#!/usr/bin/python

from random import *

prob = "split"

cases = [   
            (10,1),
            (20,1),
            (30,30),
            (100,1),
            (100000,1),
            (100000,100000),
            (100000,1000000),
            (100000,90000000),
            (100000,10000000),
            (100000,98988999),
            (100000,88888332),
        ]
cur = 0
for (q,s) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d\n" % q
    for i in range(s,s+q) :
        cout += "%d\n" % i

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
