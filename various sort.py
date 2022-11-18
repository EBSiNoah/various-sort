# -*- coding: utf-8 -*-
"""
Created on Sun Nov 13 11:59:25 2022

@author: NOPE
"""

import random

def CLS() :
    print( "\014" )

def commonSort(before):
    restore=0
    idx=0
    after=0
    size=len(before)
    for idx in size:
        after=idx+1
        for after in size:
            if(before[idx]>before[after]):
                restore=before[idx]
                before[idx]=before[after]
                before[after]=restore

    return before

def InsertSort(before):
    sizeB=len(before)
    after=[]
    count=0
    idxB=0
    idxA=0
    isinsert=False
    for idxB in range(sizeB):
        sizeA=len(after)
        count=0
        for idxA in range(sizeA):
            if(before[idxB]<=after[idxA]):
                print(count, end=": " )
                after.insert(count,before[idxB])
                isinsert=True
                break
            else:
                isinsert=False
                count+=1
                continue
        if(isinsert==False):            
            print( idxA, end=": " )
            after.append(before[idxB])
        print( after )
            
    return after

def BinarySearch(Adata, Value):
    N = len(Adata)
    Mid = N // 2
    StartP = 0
    EndP = N-1
    while (StartP<EndP) :
        Mid = (StartP+EndP) // 2
        if(Value > Adata[Mid]):
            StartP = Mid+1
        elif(Value < Adata[Mid]):
            EndP = Mid-1
        else:
            return Mid, True

    return Mid, False

def ModifySort(before):
    after=[before[0]]
    count=0
    idxB=0
    idxA=0
    isinsert=False
    sizeB=len(before)
    sizeA=0
    for idxB in sizeB:
        sizeA=len(after)
        for idxA in sizeA:
            if(before[idxB]<=after[idxA]):
                after.insert(count,before[idxB])
                isinsert=True
                break
            else:
                isinsert=False
                count+=1
                continue
        if(isinsert==False):
            after[sizeA+1]=before[idxB]
        
            
    return after

def SortTestA( N=20 ):
    import copy
    
    global arrBefore, arrAfter
    arr=[0]*N
    for k in range( 0, N ):
        arr[N-k-1] = k
    print( "Before", arr)
    arrBefore = copy.deepcopy( arr )
    arr = InsertSort(arr)
    print( "After", arr)
    arrAfter = copy.deepcopy( arr )
    print( "result : ", arrBefore == arrAfter )
    
    return arr

def SortTestB ( N=20 ):
    import copy
    
    global arrBefore, arrAfter
    arr=[0]*N
    for k in range( 0, N//2 ):
        arr[k] = k
    # print( arr )
    for k in range( N//2, N ):
        arr[N-k-1 + N//2 ] = k
    # print( arr )

    print( "Before", arr)
    arrBefore = copy.deepcopy( arr )
    arr = InsertSort(arr)
    arrAfter = copy.deepcopy( arr )
    print( "result : ", arrBefore == arrAfter )
    print( "After", arr)
    
    return arr


def SortTest():
    import copy
    
    global arrBefore, arrAfter
    arr=[0]*20
    for i in range(0,20):
        arr[i]=random.randrange(0,20)
    print( "Before", arr)
    arrBefore = copy.deepcopy( arr )
    arr=InsertSort(arr)
    print( "After", arr)
    arrAfter = copy.deepcopy( arr )
    print( "result : ", arrBefore == arrAfter )

def main():
    CLS()
    # SortTestB()
    SortTest()
    
if ( __name__ == "__main__" ):
    main()