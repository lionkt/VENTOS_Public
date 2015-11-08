/****************************************************************************/
/// @file    ApplV_03a_crypto.cc
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

#include "ApplV_03a_crypto.h"

namespace VENTOS {

Define_Module(VENTOS::ApplV_Crypto);

ApplV_Crypto::~ApplV_Crypto()
{

}

// initialization code when starting
void ApplV_Crypto::initialize(int stage)
{
    ApplVSystem::initialize(stage);

	if (stage == 0)
	{

	}
}

// finishing code before simulation ending
void ApplV_Crypto::finish()
{
    ApplVSystem::finish();
}

// handle my own SelfMsg (timers, etc)
void ApplV_Crypto::handleSelfMsg(cMessage* msg)
{
    ApplVSystem::handleSelfMsg(msg);
}

// received a new beacon from vehicle
void ApplV_Crypto::onBeaconVehicle(BeaconVehicle* wsm)
{
    // no need to pass this down
}

// received a new beacon from RSU
void ApplV_Crypto::onBeaconRSU(BeaconRSU* wsm)
{
    // no need to pass this down
}

// received a new data from platoon
void ApplV_Crypto::onData(PlatoonMsg* wsm)
{
    // no need to pass this down

}

// is called, every time the position of vehicle changes
void ApplV_Crypto::handlePositionUpdate(cObject* obj)
{
    ApplVSystem::handlePositionUpdate(obj);
}

}

