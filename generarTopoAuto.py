#!/usr/bin/python3
# hTotales = número de host totales

import math
import sys

if len(sys.argv) != 2:
	print('El formato de ejecución debe ser ./generarTopo.py num_host_totales')

hTotales = int(sys.argv[1])
print('types:')
print('        channel cable extends DatarateChannel')
print('        {')
print('		   double retardoRed @unit(us);')
print('            datarate = 40Gbps;')
print('            delay = retardoRed;')
print('        }')

#Declaración host y switches
print('submodules:')
puertos_switch = math.sqrt(hTotales/2)
if '.0' in str(puertos_switch):
    puertos_switch = int(puertos_switch)

else:
    puertos_switch = int(puertos_switch) + 1

contadorH = 0
contadorSw = 0

#puertos_switch = math.sqrt(hTotales/2)
swTotales = (hTotales/(2*puertos_switch))

for h in range(0, hTotales): 
    print('        H_' + str(h) + ': RdmaHost{};')

    if h < hTotales/2:
        contador = 1
    else:
        contador = 2

    contadorH += 1

    if contadorH == puertos_switch:
        contadorH = 0
        contadorSw += 1
        if contadorSw == puertos_switch + 1:
            contadorSw = 1
        print('        SW_' + str(contador) + '_' + str(contadorSw) + ': EthernetSwitch {gates: ethg[' + str(int(puertos_switch*2)) +'];};')

#####################
#Declaración switches capa intermedia
for s in range(1,puertos_switch+1):

    print('        SW_3' + '_' + str(s) + ': EthernetSwitch {gates: ethg[' + str(int(puertos_switch*2)) +'];}')


#######################################
##Conexiones
contadorSw = 1 
p_sw = 0
print('connections:')

for h in range(0, hTotales): 
    if h < hTotales/2:
        contador = 1
    else:
        contador = 2

    contadorH += 1
    print('        H_' + str(h) + '.ethg++ <--> cable <--> SW_' + str(contador) + '_' + str(contadorSw) + '.ethg[' + str(p_sw)+ '];')
    p_sw += 1
    if contadorH == puertos_switch:
        contadorH = 0
        contadorSw += 1
        p_sw =0
        if contadorSw == puertos_switch + 1:
            contadorSw = 1
##############################################
##Conexiones con los switches de la capa intermedia
#for num_switch_interno in range(0, puertos_switch):
 #   for nivel in range(1, 3):
  #      for num_switch_externo in range(0, puertos_switch):
   #         print('        SW_3_' +  str(num_switch_interno + 1) + '.ethg[' + str(num_switch_interno + puertos_switch) + '] <--> cable <-->' + 
#		' SW_' + str(nivel) + '_' + str(num_switch_externo + 1) + ".ethg[" + str(num_switch_interno + puertos_switch) + '];')   
for internos in range(0, puertos_switch):
	for nivel in range(1, 3):
            for externos in range(0, puertos_switch):
               print('        SW_3_' +  str(internos + 1) + '.ethg[' + str(externos+(nivel-1)*puertos_switch) + '] <--> cable <-->' + 
		' SW_' + str(nivel) + '_' + str(externos + 1) + ".ethg[" + str(internos + puertos_switch) + '];') 
