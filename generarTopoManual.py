#!/usr/bin/python3
#
#

import math
import sys

if len(sys.argv) != 4:
        print('El formato de ejecución debe ser ./generarTopo.py host_por_switch num_switches_externos num_switches_internos')

host_switch = int(sys.argv[1]) #Numero de host por switch de la primera etapa
num_switches_externos = int(sys.argv[2]) #Numero de switches en la primera etapa
num_switches_internos = int(sys.argv[3]) #Numero de switches en la segunda etapa

if num_switches_internos != 0:
    puertos_switches_externos = host_switch + num_switches_internos
else:
    puertos_switches_externos = host_switch + num_switches_externos
    
puertos_switches_internos = num_switches_externos * 2
host_nivel = host_switch*num_switches_externos*2

print('types:')
print('        channel cable extends DatarateChannel')
print('        {')
print('		   double retardoRed @unit(us);')
print('            datarate = 40Gbps;')
print('            delay = retardoRed;')
print('        }')

print('submodules:')

sw = 0
for h in range(0, host_nivel): 
    print('        H_' + str(h) + ': RdmaHost{};')
    if h < host_nivel/2:
        grupo = 1
    else:
        grupo = 2
    
    if ((h + 1) % host_switch) == 0:
        sw += 1
        if sw == num_switches_externos + 1:
            sw = 1
        print('        SW_' + str(grupo) + '_' + str(sw) + ': EthernetSwitch {gates: ethg[' + str(int(puertos_switches_externos)) +'];};')

for sw3 in range(1, num_switches_internos + 1):
     print('        SW_3_' + str(sw3) + ': EthernetSwitch {gates: ethg[' + str(int(puertos_switches_internos)) +'];};')
     
#########################################################################
#Conexiones
p_sw = 0
sw = 1
print('connections:')
for h in range(0,host_nivel):
    if h < host_nivel/2:
        grupo = 1
    else:
        grupo = 2
    print('        H_' + str(h) + '.ethg++ <--> cable <--> SW_' + str(grupo) + '_' + str(sw) + '.ethg[' + str(p_sw)+ '];')
    p_sw += 1
    if ((h + 1) % host_switch) == 0:
        sw += 1
        p_sw = 0
        if sw == num_switches_externos+ 1:
            sw = 1

if num_switches_internos != 0:            
#Conexiones con nivel intermedio
    for internos in range(0, num_switches_internos):
        for nivel in range(1, 3):
            for externos in range(0, num_switches_externos):
               print('        SW_3_' +  str(internos + 1) + '.ethg[' + str(externos+(nivel-1)*num_switches_externos) + '] <--> cable <-->' + 
' SW_' + str(nivel) + '_' + str(externos + 1) + ".ethg[" + str(internos + num_switches_externos) + '];') 

else:
    for externos in range(0, num_switches_externos):
        for externos2 in range(0, num_switches_externos):
            print('        SW_1_' +  str(externos2 + 1) + '.ethg[' + str((externos) + host_switch)+ '] <--> cable <--> ' + 'SW_2_' + str(externos + 1) + '.ethg[' + str((externos2) + host_switch) + '];') 
