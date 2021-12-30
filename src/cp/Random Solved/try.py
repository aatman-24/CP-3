# 

def pairs(k, arr):
    arr = sorted(arr)
    i = 0
    j = 0
    count = 0
    while j < len(arr):
        differnce = arr[j] - arr[i]
        if k == differnce:
            j += 1
            count += 1
        elif k > differnce:
            j += 1
        else:
            i += 1
    return count


arr = [1,3,4,5,2]
k = 2
print(pairs(k,arr))