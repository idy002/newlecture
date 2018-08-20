#!/usr/bin/python

from random import *

prob = "cross"

defpts = [
            (4, 3),
            (4, 0),
            (0, -1),
            (-2, 4),
            (3, 4),
            (-1, 1),
            (-3, -2),
            (-2, 0),
            (-1, 2),
            (3, -4),
            (-3, 2),
            (1, -4),
            (-4, -4),
            (2, -1),
            (1, -2),
            (1, -1),
            (1, 2),
            (3, 0),
            (-2, 1),
            (3, -3),
            (-4, -2),
            (2, -4),
            (1, 3),
            (3, -1),
            (-2, 2),
            (0, -4),
            (-2, 3),
            (-4, 2),
            (-1, 3),
            (3, 2)
        ]

cases = [   
        30,
        12,
        12,
        12,
        100000,
        100000,
        100000,
        100000,
        100000,
        100000,
        100000
        ]
cur = 0
for n in cases :
    cout = ""
    print "make %d..." % cur
##-----
#TODO generate the data

    st = set()
    xbase = randint(-10**8,10**8)
    ybase = randint(-10**8,10**8)
    for i in range(n) :
        x = 0
        y = 0
        if i < len(defpts) and randint(0,1) == 0:
            x = xbase + defpts[i][0]
            y = ybase + defpts[i][1]
        else :
            x = xbase + randint(1,n)
            y = ybase + randint(1,n)
        st.add((x,y))
    cout += "%d\n" % (len(st))
    for (u,v) in st :
        cout += "%d %d\n" % (u, v)

##-----
    f = file( prob + str(cur) + ".in", "w" )
    cur += 1
    f.write( cout )
    f.close()
