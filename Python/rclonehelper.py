from sys import argv
from os import system

def root(path,known):
    path = path.split('/')
    if path[0] not in known:return 0
    return known[path[0]]+'/'+"".join(path[1:])

def main(remote,parent,known):
    alen = len(argv)
    if alen==1:
        x = f'rclone lsf {remote}:"{parent}"'
        system(x)
        return
    elif alen==2:
        x = root(str(argv[1]),known)
        if not x:return
        x = f'rclone lsf {remote}:"{parent}/{x}"'
        system(x)
        return
    elif alen==3:
        x = root(str(argv[2]),known)
        if not x:return
        x = f'rclone {str(argv[1])} {remote}:"{parent}/{x}"'
        system(x)
        return

    src=str(argv[-2])
    des=str(argv[-1])

    x = root(src,known)
    comm = " ".join(argv[1:alen-2])

    if x:
        comm=f'rclone {comm} {remote}:"{parent}/{x}" "{des}"'
        print(f'running {comm}')
        system(comm)
    else:
        x = root(des,known)
        if not x:return
        comm = f'rclone {comm} "{src}" {remote}:"{parent}/{x}"'
        print(f'running {comm}')
        system(comm)
