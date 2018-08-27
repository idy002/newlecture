#!/usr/bin/python

from random import *

prob = "year"

cases = [   
            (20,10),
            (20,10),
            (20,10),
            (20,10),
            (100000,10),
            (100000,10),
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

    head = "0122016662091670"
    init = [(3,4), (1,14), (4,15)]

    s = head + "".join([choice("20167679999") for j in range(n - len(head))])
    cout += "%s\n" % s
    cout += "%d\n" % q
    for (a,b) in init :
        cout += "%d %d\n" % (a,b)
    for i in range(q - len(init)) :
        if randint(0,1) == 0 :
            l = randint(1,min(100,n/2))
        else :
            l = randint(1,n)
        a = randint(1,n-l+1)
        b = a + l - 1
        cout += "%d %d\n" % (a, b)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
