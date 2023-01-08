import random

line = []

def rand():
  rand = random.randint(0,100)
  if rand < 5:
    return "1"
  else:
    return "0"
  
for i in range(25):
  line = ""
  for j in range(80):
    line+= " " + rand()
  print(line)
