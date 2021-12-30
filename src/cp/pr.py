def find_kmp(t,p):
    n,m = len(t),len(p)
    if m == 0: return 0
    fail = compute_kmp_fail(p)
    j = 0
    k = 0
    T = list(t)
    P = list(p)
    while j < n:
        text = ''.join(i for i in T)
        if T[j] == P[k]:
            if k == m - 1:
                print("Yes")
                print(text)
                return j - m + 1
            j += 1
            k += 1
        elif k > 0 and T[j] != '?':
            k = fail[k-1]
        else:
            if T[j] == "?":
                T[j] = p[k]
                k += 1
            j += 1
    text = ''.join(i for i in T)
    pattern =  ''.join(i for i in P)
    if pattern in text:
        print('Yes')
        print(text)
    else:
        print("No")

def compute_kmp_fail(P):
    m = len(p)
    fail = [0]*m
    j = 1
    k = 0
    while j < m:
        if P[j] == P[k]:
            fail[j] = k + 1
            j += 1
            k += 1
        elif k > 0:
            k = fail[k-1]
        else:
            j += 1
    return fail



test_case = int(input())
for _ in range(test_case):
    n = int(input())
    t = input()
    p = "abacaba"
    find_kmp(t,p)