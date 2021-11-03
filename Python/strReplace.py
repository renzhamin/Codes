def str_replace(str,i,x):
    return str[0:i]+x+str[i+1:]

str="Lucky you"
str=str_replace(str,0,'F')
print (str)