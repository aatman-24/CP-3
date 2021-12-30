t = int(input())
test_case = list()
for i in range(t):
    test_case.append(int(input()))

def all_number(num):
    answer = list()
    counter = 0
    for i in range(1,1001,2):
        if counter != num:
            answer.append(i)
            counter += 1
        else:
            return answer

for num in test_case:
    c = all_number(num)
    for i in c:
        print(i,end=' ')
    print()
    


    
