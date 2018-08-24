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

    kk = randint(n, k)
    mid = (1 + 10**9) / 2
    cout += "%d %d %d\n" % (n, kk, mid + randint(-3 * n, 3 * n))
    for i in range(n) :
        cout += "%d " % (mid + randint(-3 * n, 3 * n))
    cout += "\n"
    b = choice( [ 0, 2 ])
    for i in range(kk) :
        cout += "%d " % randint(1,10**9)
    cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
