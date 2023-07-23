import os 
import random 

with open("in.txt", "w") as fp:
    fp.write(' '.join([str(random.randint(1, 10000)) for i in range(200000)]))