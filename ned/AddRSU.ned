
package c3po.ned;

simple AddRSU
{
    parameters:
        @class(VENTOS::AddRSU);
        @display("i=block/network2");
        
        bool on = default(false);
        string RSUfile = default("");
        int mode;  
}

