import datetime
import pytz

utc_now = pytz.utc.localize(datetime.datetime.utcnow())
pst_now = utc_now.astimezone(pytz.timezone("Asia/Dhaka"))

day = pst_now.today()

print(utc_now)
print(pst_now)
print(utc_now==pst_now)
