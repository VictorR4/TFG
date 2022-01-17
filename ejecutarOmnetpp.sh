#!/bin/bash
#
directorio=`pwd`
opp_run -m -u Cmdenv -n $directorio:/home/vr4/omnetpp-6.0pre11/samples/inet/src/:/home/vr4/omnetpp-6.0pre11/samples/inet/tutorials/:/home/vr4/omnetpp-6.0pre11/samples/inet/showcases/ -l /home/vr4/omnetpp-6.0pre11/samples/inet/src/INET omnetpp.ini

