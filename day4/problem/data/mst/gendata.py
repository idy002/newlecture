#!/usr/bin/python

from random import *

prob = "mst"

cases = [   
            (500,500,500),
            (500,500,500),
            (500,500,500),
            (500,500,500),
            (10000,100000,10**9),
            (30000,100000,10**9),
            (50000,100000,10**9),
            (70000,100000,10**9),
            (80000,100000,10**9),
            (90000,100000,10**9),
            (100000,100000,10**9)
        ]
cur = 0
for (n,m,cmax) in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    cout += "%d %d\n" % (n, m)
    st = set()
    for i in range(2,n+1) :
        p = randint(1,i-1)
        st.add((p,i))
        cout += "%d %d %d\n" % (p, i, randint(1,cmax))
    for i in range(m - n + 1) :
        u = randint(1,n-1)
        v = randint(u+1,n)
        while (u,v) in st or (v,u) in st :
            u = randint(1,n-1)
            v = randint(u+1,n)
        st.add((u,v))
        cout += "%d %d %d\n" % (u, v, randint(1,cmax))
    
##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
