#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'QAQAutoMaton'

import sys,random
name=sys.argv[1]
# name="2.in"
data=[]
with open(name,'r') as f:
    T=int(f.readline())
    print(T)
    for i in range(T):
        n=int(f.readline())
        s1=f.readline()[:-1]
        s2=f.readline()[:-1]
        data.append((s1,s2))
    random.shuffle(data)
with open(name,'w') as f:
    print(T,file=f)
    for i in range(T):
        print(len(data[i][0]),file=f)
        print(data[i][0],file=f)
        print(data[i][1],file=f)
