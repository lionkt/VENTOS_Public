/****************************************************************************/
/// @file    ApplV_05_PlatoonFormed.cc
/// @author  Mani Amoozadeh <maniam@ucdavis.edu>
/// @author  second author name
/// @date    August 2013
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

#include "ApplV_05_PlatoonFormed.h"

namespace VENTOS {

Define_Module(VENTOS::ApplVPlatoonFormed);

ApplVPlatoonFormed::~ApplVPlatoonFormed()
{

}


void ApplVPlatoonFormed::initialize(int stage)
{
    ApplV_AID::initialize(stage);

	if (stage == 0)
	{
        plnMode = par("plnMode").longValue();

	    if(plnMode != platoonFormed)
	        return;

        if(!VANETenabled)
            error("This vehicle is not VANET-enabled!");

	    preDefinedPlatoonID = par("preDefinedPlatoonID").stringValue();

	    // I am the platoon leader.
	    if(SUMOvID == preDefinedPlatoonID)
	    {
	        // we only set these two!
	        plnID = SUMOvID;
	        myPlnDepth = 0;
	    }
	}
}


void ApplVPlatoonFormed::finish()
{
    ApplV_AID::finish();
}


void ApplVPlatoonFormed::handleSelfMsg(cMessage* msg)
{
    // pass it down!
    ApplV_AID::handleSelfMsg(msg);
}


void ApplVPlatoonFormed::onBeaconVehicle(BeaconVehicle* wsm)
{
    // pass it down!
    ApplV_AID::onBeaconVehicle(wsm);

    if(plnMode != platoonFormed)
        return;

    // I am not part of any platoon yet!
    if(plnID == "")
    {
        if( std::string(wsm->getPlatoonID()) != "" && wsm->getPlatoonDepth() == 0 )
        {
            EV << "This beacon is from a platoon leader. I will join ..." << endl;
            plnID = wsm->getPlatoonID();

            // change the color to blue
            TraCIColor newColor = TraCIColor::fromTkColor("blue");
            TraCI->vehicleSetColor(SUMOvID, newColor);
        }
    }
    // platoonID != "" which means I am already part of a platoon
    // if the beacon is from my platoon leader
    else if( isBeaconFromMyPlatoonLeader(wsm) )
    {
        // do nothing!
        EV << "This beacon is from my platoon leader ..." << endl;
    }
    // I received a beacon from another platoon
    else if( std::string(wsm->getPlatoonID()) != plnID )
    {
        // ignore the beacon msg
    }
}


void ApplVPlatoonFormed::onBeaconRSU(BeaconRSU* wsm)
{
    // pass it down!
    ApplV_AID::onBeaconRSU(wsm);
}


void ApplVPlatoonFormed::onData(PlatoonMsg* wsm)
{
    // pass it down!
    ApplV_AID::onData(wsm);
}


// is called, every time the position of vehicle changes
void ApplVPlatoonFormed::handlePositionUpdate(cObject* obj)
{
    // pass it down!
    ApplV_AID::handlePositionUpdate(obj);
}

}

