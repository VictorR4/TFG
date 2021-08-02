//
// Copyright (C) 2020 OpenSim Ltd.
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

#ifndef __INET_PACKETSCHEDULER_H
#define __INET_PACKETSCHEDULER_H

#include "inet/queueing/base/PacketSchedulerBase.h"
#include "inet/queueing/contract/IPacketSchedulerFunction.h"

namespace inet {
namespace queueing {

class INET_API PacketScheduler : public PacketSchedulerBase
{
  protected:
    IPacketSchedulerFunction *packetSchedulerFunction = nullptr;

  protected:
    virtual void initialize(int stage) override;
    virtual IPacketSchedulerFunction *createSchedulerFunction(const char *schedulerClass) const;
    virtual int schedulePacket() override;

  public:
    virtual ~PacketScheduler() { delete packetSchedulerFunction; }
};

} // namespace queueing
} // namespace inet

#endif

