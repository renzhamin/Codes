from __future__ import print_function
import os.path,re
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
from routine import classlist


# If modifying these scopes, delete the file token.json.
SCOPES = ['https://www.googleapis.com/auth/classroom.courses.readonly','https://www.googleapis.com/auth/classroom.announcements.readonly']

creds = None
if os.path.exists('token.json'):
    creds = Credentials.from_authorized_user_file('token.json', SCOPES)
if not creds or not creds.valid:
    if creds and creds.expired and creds.refresh_token:
        creds.refresh(Request())
    else:
        flow = InstalledAppFlow.from_client_secrets_file(
                'credentials.json', SCOPES)
        creds = flow.run_local_server(port=0)
    with open('token.json', 'w') as token:
        token.write(creds.to_json())

service = build('classroom', 'v1', credentials=creds)


s = '''
Assalamu Alaikum 
Dear students,
Welcome to this course.

The zoom link for today's class at 10:50 am is given below.


more junk
'''



def parse(text):
    x = re.findall(r'(https.*zoom\S+)',text)
    return x

def link(id):
    results = service.courses().announcements().list(courseId=id).execute()
    y = results.get('announcements',[])
    for i in y:
        x = parse(i['text'])
        if x: return x
    return None




for i in classlist:
    x = link(i.inf.id)
    if x: i.inf.link = "".join(x[0])
    print(f'{i.inf.name}\nFrom {i.starth}:{i.startm} to {i.hour}:{i.minutes}\n{i.inf.link}\n')
