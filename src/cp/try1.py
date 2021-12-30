from random import randint

with open("data.txt","w") as file:
    for _ in range(4000):
        file.write(str(randint(1,4000)) + " ")