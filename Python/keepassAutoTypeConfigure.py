from pykeepass import PyKeePass
from getpass import getpass
from re import sub
prefix = {"www","app","apps","accounts"}

def parse(s):
    s = sub(r'.*//',r'',str(s))
    x = s.split('.')
    ind = x[0] in prefix
    return x[ind]

def main(fullpath):
    password=getpass()
    try:
        db = PyKeePass(fullpath,password)
    except:
        print("Wrong path/password")
        return

    for entry in db.entries:
        entry.title=parse(entry.url)

    db.save() 

print("Provide full path to dabase:")
fullpath = str(input())

main(fullpath)
