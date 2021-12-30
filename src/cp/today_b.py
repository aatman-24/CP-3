from math import ceil

def biggest_num(n):
    a = '9'
    if n == 1:
        return int(a)
    else:
        ans = '9'
        for _ in range(n-1):
            ans += a
        return int(ans)

def smallest_num(n):
    a = '1'
    if n == 1:
        return int(a)
    else:
        ans = '1'
        for _ in range(n-1):
            ans += a
        return int(ans)


t = int(input())
for _ in range(t):
    n = int(input())
    num_of_8 = ceil(n/4)
    bigges_n = biggest_num(n)
    smallest_n = smallest_num(num_of_8)
    print(bigges_n-smallest_n)

