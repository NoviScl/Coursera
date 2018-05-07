import csv

with open('mpg.csv') as csvfile:
	mpg = list(csv.DictReader(csvfile))	#list of dictionaries

mpg[:3] #first 3 dictionaries in the list

len(mpg) #number of dicts, each dict is one row of data

mpg[0].keys()

#average 'cty' value
sum(float(d['cty']) for d in mpg)/len(mpg)

sum(float(d['hwy']) for d in mpg)/len(mpg)

#unique values for cylinders
cylinders = set(d['cyl'] for d in mpg)


import datetime as dt 
import time as tm 

tm.time() #current time in sec
#convert to datetime
dtnow = dt.datetime.fromtimestamp(tm.time())
dtnow = dt.datetime.fromtimestamp(tm.time())
dtnow.year, dtnow.month, dtnow.day, dtnow.hour, dtnow.minute, dtnow.second

delta = dt.timedelta(days=100)
today = dt.date.today()
today - delta  #100 days ago