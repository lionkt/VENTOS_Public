/****************************************************************************/
/// @file    ApplV_03_System.h
/// @author  Dylan Smith <dilsmith@ucdavis.edu>
/// @author  Mani Amoozadeh <maniam@ucdavis.edu>
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

#include "ApplV_03_System.h"

namespace VENTOS {

Define_Module(VENTOS::ApplVSystem);

ApplVSystem::~ApplVSystem()
{

}


void ApplVSystem::initialize(int stage)
{
    ApplVBeacon::initialize(stage);

    if(SUMOvType == "TypeDummy")
        requestRoutes = false;
    else
        requestRoutes = par("requestRoutes").boolValue();

    //If this vehicle is not supposed to send system messages
    if(!requestRoutes)
        return;
}


void ApplVSystem::finish()
{
    ApplVBeacon::finish();
}

void ApplVSystem::handleSelfMsg(cMessage* msg)  //Internal messages to self
{
    ApplVBeacon::handleSelfMsg(msg);    //Pass it down
}


void ApplVSystem::receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj) //Ran upon receiving signals
{

}


// is called, every time the position of vehicle changes
void ApplVSystem::handlePositionUpdate(cObject* obj)
{
    ApplVBeacon::handlePositionUpdate(obj);
}

}
