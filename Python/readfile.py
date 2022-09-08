try:
    fstream=open("Input.txt",'r')
except:
    print('File not Found')
    exit()

for line in fstream:
    if (not line.startswith("Hello")):
        print(line.rstrip(),end='')