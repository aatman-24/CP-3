
def oneNum(a):
    if a >= 0 and a <= 9:
        return True
    else:
        return False

def checkPal(a,b):
    if oneNum(a):
        return a == b % 10

    if ((checkPal(int(a/10),b)) == False):
        return -1

    b = int(b/10)
    return (a % 10) == (b % 10)

def ispal(num):
    b = num
    return checkPal(num,b)


print(ispal(121))