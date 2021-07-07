/*
 * CLOS.cc
 *
 *  Created on: Mar 10, 2021
 *      Author: vr4
 */


#include <omnetpp.h>

using namespace omnetpp; //llama y usa todas la librerias omnetapp

class Host: public cSimpleModule, cDatarateChannel
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

Define_Module(Host); //Registramos la clase con Omnett++

void My_Node::initialize()
{
    if(strcmp("computer2", getName()) == 0){
        cMessage *msg = new cMessage("Hey you!");

        send(msg, "ethg");//out es el nombre del puerto
    }
}

void My_Node::handleMessage(cMessage *msg){
    send(msg, "ethg");//out es el nombre del puerto
}
