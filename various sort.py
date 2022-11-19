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
    loopnum=0
    isinsert=False
    for idxB in range(sizeB):
        sizeA=len(after)
        count=0
        for idxA in range(sizeA):
            loopnum+=1
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
    print("loopCount : ",loopnum)
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
            print(Mid, "True")
            return Mid, True
    print(Mid, "False")
    return Mid, False

def ModifySort(before):
    import copy
    after=[copy.deepcopy(before[0])]
    count=0
    idxB=0
    StartP=0
    EndP=0
    Mid=0
    loopnum=0
    isInsert=False
    sizeB=len(before)
    sizeA=0
    for idxB in range(1,sizeB):
        isInsert=False
        sizeA=len(after)
        StartP=0
        EndP=sizeA-1
        print(after)
        while (StartP<EndP) :
            loopnum+=1
            Mid = (StartP+EndP) // 2
            if(before[idxB] > after[Mid]):
                StartP = Mid+1
            elif(before[idxB] < after[Mid]):
                EndP = Mid-1
            elif(before[idxB] == after[Mid]):
                count = Mid
                isInsert=True
                break
        if(isInsert==False):
            count=Mid

        after.insert(count,copy.deepcopy(before[idxB]))
    print("LoopCount : ",loopnum)
    return after

def SortTestA( N=20 ):
    import copy
    
    global arrBefore, arrAfter
    arr=[0]*N
    for k in range( 0, N ):
        arr[N-k-1] = k
    print( "Before", arr)
    arrBefore = copy.deepcopy( arr )
    arr = ModifySort(arr)
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

def SortTest_loopcount():
    import copy
    global arrbefore, arrAfter
    arr01=[0]*20
    #arr02=[0]*20
    arr03=[0]*20
    for i in  range(0,20):
        arr01[i]=random.randrange(0,20)
    print( "Before", arr01 )
    arrBefore = copy.deepcopy( arr01 )
    #arr02 = InsertSort(arr01)
    arr03 = ModifySort(arr01)
    #print( "InsertSort After", arr02 )
    print( "ModifySort After", arr03 )
    arrAfter=copy.deepcopy(arr03)
    print( "result : ",arrBefore == arrAfter )

def Bsearchtest():
    BinarySearch([1,3,5,7], 0)

def main():
    #CLS()
    #SortTest()
    #SortTest_loopcount()
    Bsearchtest()
    
if ( __name__ == "__main__" ):
    main()