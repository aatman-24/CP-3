def search(n,elements_array,k):
    counter = 0
    for i in range(n):
        counter += 1
        if elements_array[i] == k:
            return n,counter
    return n,0

def Search_for_participant(number_of_quries,quriess):
    participant_counter = 0
    announymus_counter = 0
    for i in range(number_of_quries):
        total,result = search(size_of_array,elements_array,quries[i])
        participant_counter += result
        announymus_counter += (total - result + 1)
    return participant_counter,announymus_counter


if __name__ == '__main__':
    size_of_array = int(input())
    elements_array = list(map(int, input().rstrip().split()))
    number_of_quries = int(input())
    quries = list(map(int,input().rstrip().split()))

    vasya_counter,petya_counter = Search_for_participant(number_of_quries,quries)

    print(vasya_counter,petya_counter)
