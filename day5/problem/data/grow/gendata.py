#!/usr/bin/python

from random import *

prob = "grow"

cases = [   
            (5,0),
            (10,1),
            (10,5),
            (10,0),
            (30,1),
            (30,5),
            (30,0),
            (30,5),
            (30,0),
            (30,0),
            (30,0)
        ]
cur = 0
for (n,v) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d\n" % n
    for i in range(n) :
        u = randint(1,5) if v == 0 else v
        cout += "%d " % u
    cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
