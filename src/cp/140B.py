def binary_search(arr,e,start,end):
    if end >= start:
        mid = (start+end)//2
        if arr[mid] > e: return binary_search(arr,e,0,mid-1)
        elif arr[mid] == e: return mid
        else:
            return binary_search(arr,e,mid+1,len(arr)-1)
    else:
        return -1


size_of_array = int(input())
array_element = list(map(int,input().split()))
number_of_quries = int(input())
for _ in range(number_of_quries):
    quries = list(map(int,input().split()))
c_vasoya = 0
c_petya = 0
for i in range(number_of_quries):
    vasoya

    