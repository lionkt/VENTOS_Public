
package c3po.ned;

import org.car2x.veins.base.modules.*;
import org.car2x.veins.modules.nic.Nic80211p;

module RSU
{
    parameters:
         string mobilityType; //type of the mobility module

    gates:
        input radioIn; // gate for sendDirect
        
    submodules:
        appl: ApplRSUManager {
            parameters:
                @display("p=60,50");
        }

        nic: Nic80211p_Mod {
            parameters:
                @display("p=60,166");
        }
        
        mobility: <mobilityType> like IMobility {
            parameters:
                @display("p=130,172;i=block/cogwheel");
        }

    connections:
        nic.upperLayerOut --> appl.lowerLayerIn;
        nic.upperLayerIn <-- appl.lowerLayerOut;
        nic.upperControlOut --> appl.lowerControlIn;
        nic.upperControlIn <-- appl.lowerControlOut;

        radioIn --> nic.radioIn;
}
