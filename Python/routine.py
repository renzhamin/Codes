from datetime import datetime

class classinfo:
    def __init__(self,name,id,link=""):
        self.name=name
        self.link=link
        self.id=id


class Class:
    def __init__(self,inf,starth,startm,hour,minutes):
        self.inf=inf
        self.minutes=minutes
        self.hour=hour
        self.starth=starth
        self.startm=startm


DS =  classinfo("Data Structures","325364815331","https://bdren.zoom.us/j/67706040993")
# DS_Lab =  classinfo("Data Structures Lab","","https://bdren.zoom.us/j/67706040993")
COA =  classinfo("Mafia","324285830041","https://bdren.zoom.us/j/68527456083")
LA =  classinfo("Linear Algebra","317352830971","404")
EEE =  classinfo("EEE","317485508357","https://bdren.zoom.us/j/63868590746")
EEE_Lab =  classinfo("EEE_Lab","318097402722","404")
DBMS =  classinfo("DBMS","318065155365","http://meet.google.com/ohp-mqxh-ndf")
DBMS_Lab =  classinfo("DBMS_Lab","317309193831","http://meet.google.com/ohp-mqxh-ndf")
OOP =  classinfo("OOP","317199070205","https://bdren.zoom.us/j/63140826789?pwd=cVFhL0p2a0lXSW5vQW9zRXhiYnQ0UT09")
# OOP_Lab =  classinfo("OOP Lab","404")



Monday = [ 
    Class(DS,10,50,11,50),
    Class(LA,12,0,13,0),
    Class(EEE,13,30,14,30)
]


Tuesday=[
   Class(COA,9,40,10,40),
   Class(DS,10,50,11,50),
   Class(DBMS,12,0,13,0),
   Class(EEE_Lab,13,30,14,30)
]

Wednesday=[
#    Class(DS_Lab,9,40,10,40),
   Class(DBMS_Lab,9,40,10,40),
   Class(DBMS,12,0,13,0),
   Class(EEE,13,30,14,30)
]

Thursday=[
   Class(COA,9,40,10,40),
   Class(OOP,12,0,13,0),
#    Class(OOP_Lab,15,50,16,50)
]

Friday=[
   Class(DBMS_Lab,9,40,10,40),
#    Class(DS_Lab,9,40,10,40),
   Class(LA,12,0,13,0),
   Class(OOP,13,30,14,30),
#    Class(OOP_Lab,15,50,16,50)
]

routine = [
   Monday,Tuesday,Wednesday,Thursday,Friday
]

today = datetime.today().weekday()

classlist = routine[0]
