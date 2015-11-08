/****************************************************************************/
/// @file    ApplRSU_01a_crypto.cc
/// @author  Mani Amoozadeh <maniam@ucdavis.edu>
/// @author  second author name
/// @date    Nov 2015
///
/****************************************************************************/
// VENTOS, Vehicular Network Open Simulator; see http:?
// Copyright (C) 2013-2015
/****************************************************************************/
//
// This file is part of VENTOS.
// VENTOS is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "ApplRSU_02_AID.h"
#include <boost/tokenizer.hpp>

namespace VENTOS {

Define_Module(VENTOS::ApplRSUCRYPTO);

ApplRSUCRYPTO::~ApplRSUCRYPTO()
{

}


void ApplRSUCRYPTO::initialize(int stage)
{
    ApplRSUBase::initialize(stage);

    if (stage==0)
    {

    }
}


void ApplRSUCRYPTO::finish()
{
    ApplRSUBase::finish();
}


void ApplRSUCRYPTO::handleSelfMsg(cMessage* msg)
{
    ApplRSUBase::handleSelfMsg(msg);
}


void ApplRSUCRYPTO::executeEachTimeStep(bool simulationDone)
{
    ApplRSUBase::executeEachTimeStep(simulationDone);


}


void ApplRSUCRYPTO::onBeaconVehicle(BeaconVehicle* wsm)
{
    // no passing down!
}


void ApplRSUCRYPTO::onBeaconBicycle(BeaconBicycle* wsm)
{
    // no passing down!
}


void ApplRSUCRYPTO::onBeaconPedestrian(BeaconPedestrian* wsm)
{
    // no passing down!
}


void ApplRSUCRYPTO::onBeaconRSU(BeaconRSU* wsm)
{
    // no passing down!
}


void ApplRSUCRYPTO::onData(LaneChangeMsg* wsm)
{
    // no passing down!

}

}

