#!/bin/python3
from sys import argv
from pathlib import Path

def main():
    if len(argv)>1:
        if not Path(argv[1]).is_file():
            print("Invalid file")
            return
        fname = argv[1]
    else:
        fname = str(Path.home())+"/.config/spectrwm/spectrwm.conf"

    left = 50
    if len(argv)>2:
        left = int(argv[2])

    f = open(fname)
    for x in f.readlines():
        y = x.split('=')
        if len(y)==2: 
            x=f"{y[0].ljust(left)}= {y[1]}"
        print(x,end="")
        
main()

