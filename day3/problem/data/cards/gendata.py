#!/usr/bin/python

from random import *

prob = "cards"

cases = [   
        (100),
        (5000),
        (5000),
        (5000),
        (100000),
        (100000),
        (100000),
        (100000),
        (100000),
        (100000),
        (100000)
        ]
cur = 0
for n in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d\n" % n
    lst = []
    for i in range(n/2) :
        lst.append(n/2 - i)
    for i in range(n/2) :
        lst.append(randint(1,n/10))
    for a in lst :
        cout += "%d " % a
    cout += "\n"

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
