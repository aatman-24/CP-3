from random import choice
def searching(s,k,o,new_list=[]):
    if o == len(new_list):
        return new_list
    pivot = choice(s)
    less_element = []
    equal_element = []
    grater_element = []
    for i in s:
        if i < pivot:
            less_element.append(i)
        elif i == pivot:
            equal_element.append(i)
        else:
            grater_element.append(i)
    if k <= len(grater_element):
        if  k == len(grater_element):
            new_list.extend(grater_element)
            return new_list
        return searching(grater_element,k,o,new_list)
    elif k <= len(grater_element) + len(equal_element):
        new_list.extend(grater_element)
        remaining = k - len(grater_element)
        for _ in range(remaining):
            new_list.append(equal_element[0])
        return new_list
    else:
        new_list.extend(grater_element)
        new_list.extend(equal_element)
        j = k - len(grater_element) - len(equal_element)
        return searching(less_element,j,o,new_list)



test_case = int(input())
for _ in range(test_case):
    temp = list(map(int,input().split()))
    n ,k = temp[0],temp[1]
    numbers = list(map(int,input().split()))
    new_list = searching(numbers,k,k,[])
    new_list.sort(reverse=True)
    for i in range(k):
        print(new_list[i],end=' ')
    print()




