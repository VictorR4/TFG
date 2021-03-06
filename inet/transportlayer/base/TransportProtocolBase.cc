//
// Copyright (C) 2013 OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include "inet/transportlayer/base/TransportProtocolBase.h"

namespace inet {

bool TransportProtocolBase::isUpperMessage(cMessage *msg)
{
    return msg->arrivedOn("appIn");
}

bool TransportProtocolBase::isLowerMessage(cMessage *msg)
{
    if(msg->arrivedOn("ipIn"))
        return msg->arrivedOn("ipIn");
    else return msg->arrivedOn("lowerLayerIn");
}

bool TransportProtocolBase::isInitializeStage(int stage)
{
    return stage == INITSTAGE_TRANSPORT_LAYER;
}

bool TransportProtocolBase::isModuleStartStage(int stage)
{
    return stage == ModuleStartOperation::STAGE_TRANSPORT_LAYER;
}

bool TransportProtocolBase::isModuleStopStage(int stage)
{
    return stage == ModuleStopOperation::STAGE_TRANSPORT_LAYER;
}

} // namespace inet

