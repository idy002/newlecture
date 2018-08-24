#!/usr/bin/python

from random import *

prob = "evolution"

cases = [   
            (100,100),
            (100,100),
            (500,500),
            (1000,1000),
            (100000,100000),
            (100000,100000),
            (100000,100000),
            (100000,100000),
            (100000,100000),
            (100000,100000),
            (100000,100000)
        ]
cur = 0
for (n,q) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%s\n" % "".join([choice("AGCT") for i in range(n)])
    cout += "%d\n" % q
    for i in range(q) :
        opt = choice([1, 2])
        if opt == 1 :
            x = randint(1,n)
            c = choice("AGCT")
            cout += "%d %d %s\n" % (opt, x, c)
        else :
            l = randint(1,n)
            r = randint(l,n)
            e = "".join([choice("AGCT") for j in range(randint(1,10))])
            cout += "%d %d %d %s\n" % (opt, l, r, e)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
