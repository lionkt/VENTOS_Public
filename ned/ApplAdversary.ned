
package c3po.ned;

import org.car2x.veins.base.modules.IBaseApplLayer;

simple ApplAdversary like IBaseApplLayer
{
    parameters:
        @class(VENTOS::ApplAdversary);
        
        int headerLength = default(88bit) @unit(bit); // header length of the application   
        bool on = default(false); 
        double AttackT;
        bool falsificationAttack = default(false);  
        bool replayAttack = default(false); 
        bool jammingAttack = default(false);  

    gates:
        input lowerLayerIn;    // from mac layer
        output lowerLayerOut;  // to mac layer
        input lowerControlIn;
        output lowerControlOut;
}
