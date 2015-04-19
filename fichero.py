#!/usr/bin/python
import re
import sys
from datetime import *

def fecha(fecha):
	if fecha[1] == "Jan":
		fecha[1] = "01"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Feb":
		fecha[1] = "02"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Mar":
		fecha[1] = "03"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Apr":
		fecha[1] = "04"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "May":
		fecha[1] = "05"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Jun":
		fecha[1] = "06"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Jul":
		fecha[1] = "07"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Aug":
		fecha[1] = "08"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Sep":
		fecha[1] = "09"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Oct":
		fecha[1] = "10"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	elif fecha[1] == "Nov":
		fecha[1] = "11"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]
	else:
		fecha[1] = "12"
		aux1 = fecha[2] + "/" + fecha[1] + "/" + fecha[0]

	return aux1


regex = '([(\d\.)]+) - - \[(.*?)\] "(.*?)" (\d+) - "(.*?)" "(.*?)"'

fo = open("access.log", "r")
ini = open("access.txt", "w")
i = 0
formato = "%Y/%m/%d"

#print "Arg: ", sys.argv[1]
desde = datetime.strptime(sys.argv[1], formato)
hasta = datetime.strptime(sys.argv[2], formato)

#desde1 = desde[0:10].replace("-", "/")
#hasta1 = hasta[0:10].replace("-", "/")



#print desde1
#print hasta1

for line in fo:
	parsing = map(''.join, re.findall(r'\"(.*?)\"|\[(.*?)\]|(\S+)', line))
	f = str(parsing[3][0:11]).split("/")
	fecha_access = datetime.strptime(fecha(f), formato)

	if fecha_access >= desde or fecha_access <= hasta:
		datos = parsing[5] + " " + parsing[8]
		ini.write(datos + "\n")

	#print fecha_access

	#if desde >= fecha_access:
	#	print "EUREKA"
	#print fecha_access



	#print fecha_access

	#if fechainicio in parsing[3]:
	#	datos = parsing[5] + ";" + parsing[8]
	#	ini.write(datos + "\n")


fo.close()
ini.close()




#fechainicio = sys.argv[1].split("/")
#if fechainicio[1] == "03":
	#fechainicio[1] = "Mar"
#fechainicio = fechainicio[2] + "/" +  fechainicio[1] + "/" + fechainicio[0]
#print fechainicio