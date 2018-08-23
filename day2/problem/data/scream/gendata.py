#!/usr/bin/python

from random import *

prob = "scream"

cases = [
            (100,5,20,1,10),
            (1000,20,30,1,30),
            (1000,30,40,1,50),
            (1000,40,50,1,100),
            (20000,30,50,1,100),
            (20000,30,50,1,25),
            (20000,30,50,1,50),
            (20000,30,50,1,100),
            (20000,30,50,1,200),
            (20000,30,50,1,500),
            (20000,30,50,1,1000)
        ]
cur = 0
for  (n, mmin, mmax, amin, amax) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    m = randint(mmin, mmax)
    cout += "%d %d\n" % (n, m)
    cout += " ".join([str(randint(amin,amax)) for i in range(n)])
    cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
