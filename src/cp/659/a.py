from random import randint
alpha = [chr(i) for i in range(97,123)]

def make_func(i,a,b,number,j):
    if len(a) == len(b) == 0 and (i != 0):
        while(len(b) != i):
            randomnumber = randint(0,24)
            a += alpha[randomnumber]
            b += alpha[randomnumber]
        return a,b
    elif i == 0 and number[min(j,len(number)-1)] == 0:
        a = ''
        b = ''
        while(len(a) != 5):
            randomnumber = randint(0,24)
            a += alpha[randomnumber]
            # b += alpha[randomnumber]
        b = a[0:3]
        return a,b
    else:
        c = len(a)
        if i <= c and number[min(j,len(number)-1)] < i:
            b = a[0:i]
            return a,b
        else:
            b = a[0:min(i,c)]
            while (len(b) != i) and len(b) <= number[min(j,len(number)-1)]:
                randomnumber = randint(0,24)
                a += alpha[randomnumber]
                b += alpha[randomnumber]
            return a,b

test_case = int(input())
for _ in range(test_case):
    k = int(input())
    number = list(map(int,input().split(' ')))
    a = ""
    b = ""
    for i in range(len(number)):
        pre_num = number[i]
        a,b = make_func(pre_num,a,b,number,i)
        if (i == len(number)-1) and number[i] == 0:
            print(a)
            print("uips")
        elif (i == len(number)-1) and number[i] != 0:
            print(a)
            print(b)
        else:
            print(a)
        a = b
        b = ""

