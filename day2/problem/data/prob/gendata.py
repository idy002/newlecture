#!/usr/bin/python

from random import *

prob = "prob"

cases = [   
        0,
        1,
        1,
        1,
        2,
        2,
        2,
        2,
        2,
        2,
        2,
        ]
cur = 0
for ctype in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    T = 100
    lst = []
    if ctype == 0 :
        lst = [1] + [2]*10 + [3]*20
    elif ctype == 1 :
        lst = [1] + [2]*10 
    else :
        lst = [1] + [2]*10 + [3]*20 + [4]*30
    cout += "%d\n" % T
    for t in range(T) :
        n = None
        if t == T - 1 :
            n = 100000
        else :
            n = randint(1,50)
        k = choice(lst)
        cout += "%d %d\n" % (n, k)
        for i in range(n) :
            bits = []
            for j in range(k) :
                if randint(1,100) <= t or randint(1,10) <= 8:
                    bits.append("1")
                else :
                    bits.append("0")
            cout += "%s\n" % " ".join(bits)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
