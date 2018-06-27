import json
from subprocess import call

with open('derr.json') as f:
	data=json.load(f)

x= data['Dependencies']

notinstalled=[]
for k,v in x.iteritems():
	s=k+"=="+v
	a=call(["pip", "install", s])
	if a!=0:
		notinstalled.append(s)

if len(notinstalled)==0:
	print "Sucess"
else:
	print "The following packages were not installed",notinstalled