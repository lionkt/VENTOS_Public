/****************************************************************************/
/// @file    ApplAdversary.h
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

#ifndef APPLADVERSARY_H_
#define APPLADVERSARY_H_

#include <BaseApplLayer.h>
#include <ChannelAccess.h>
#include <WaveAppToMac1609_4Interface.h>

#include "Appl.h"
#include "TraCI_Extend.h"


namespace VENTOS {

class ApplAdversary : public BaseApplLayer
{
	public:
		~ApplAdversary();
		virtual void initialize(int stage);
		virtual void finish();
		virtual void receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj);

	protected:
		virtual void handleLowerMsg(cMessage* msg);
		virtual void handleSelfMsg(cMessage* msg);
		virtual void handlePositionUpdate(cObject* obj);

	private:
        void DoFalsificationAttack(BeaconVehicle * wsm);
        void DoReplayAttack(BeaconVehicle * wsm);
        void DoJammingAttack();

        DummyMsg* CreateDummyMessage();

	protected:
		// NED variables
	    cModule *nodePtr;   // pointer to the Node
        WaveAppToMac1609_4Interface* myMac;
        mutable TraCI_Extend* TraCI;

        // NED variables
        double AttackT;
        bool falsificationAttack;
        bool replayAttack;
        bool jammingAttack;

        // Class variables
        static const simsignalwrap_t mobilityStateChangedSignal;
        int myId;
		const char *myFullId;
        Coord curPosition;  // current position from mobility module (not from sumo)
        cMessage* JammingEvt;
};

}

#endif
