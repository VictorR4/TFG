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
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package src;

import inet.node.bgp.BgpRouter;
import inet.node.ethernet.EtherSwitch;
import inet.node.ethernet.EtherHost;
import ned.DatarateChannel;
// TODO documentation

channel cable extends DatarateChannel
{
}

network Clos128
{
    @display("bgb=21000,10000;i=block/network2");

    submodules:
        host1: EtherHost {
            @display("p=259.8231,168.40385");
        }
        host2: EtherHost {
            @display("p=550.44,162.63");
        }
        host3: EtherHost {
            @display("p=869.445,162.63");
        }
        host4: EtherHost {
            @display("p=1169.685,162.63");
        }
        host5: EtherHost {
            @display("p=1469.925,175.14");
        }
        host6: EtherHost {
            @display("p=1751.4,175.14");
        }
        host7: EtherHost {
            @display("p=2039.13,175.14");
        }
        host8: EtherHost {
            @display("p=2339.37,175.14");
        }

        switch1: EtherSwitch {
            @display("p=1268.5139,1839.3452");
            gates:
                ethg[16];
        }
        switch2: EtherSwitch {
            @display("p=3911.2512,1839.3452");
            gates:
                ethg[16];
        }
        switch3: EtherSwitch {
            @display("p=6353.1406,1839.3452");
            gates:
                ethg[16];
        }
        switch4: EtherSwitch {
            @display("p=9175.584,1839.3452");
            gates:
                ethg[16];
        }
        switch5: EtherSwitch {
            @display("p=11913.46,1839.3452");
            gates:
                ethg[16];
        }
        switch6: EtherSwitch {
            @display("p=14302.494,1839.3452");
            gates:
                ethg[16];
        }
        switch7: EtherSwitch {
            @display("p=16902.947,1839.3452");
            gates:
                ethg[16];
        }
        switch8: EtherSwitch {
            @display("p=19418.834,1839.3452");
            gates:
                ethg[16];
        }
        switch9: EtherSwitch {
            @display("p=1247.3721,5909.1606");
            gates:
                ethg[16];
        }
        switch10: EtherSwitch {
            @display("p=3890.1094,5909.1606");
            gates:
                ethg[16];
        }
        switch11: EtherSwitch {
            @display("p=6437.708,6036.012");
            gates:
                ethg[16];
        }
        switch12: EtherSwitch {
            @display("p=9143.871,6036.012");
            gates:
                ethg[16];
        }
        switch13: EtherSwitch {
            @display("p=11892.318,6036.012");
            gates:
                ethg[16];
        }
        switch14: EtherSwitch {
            @display("p=14302.494,6036.012");
            gates:
                ethg[16];
        }
        switch15: EtherSwitch {
            @display("p=16902.947,6036.012");
            gates:
                ethg[16];
        }
        switch16: EtherSwitch {
            @display("p=19418.834,6036.012");
            gates:
                ethg[16];
        }


        host9: EtherHost {
            @display("p=2839.77,162.63");
        }
        host10: EtherHost {
            @display("p=3133.7551,162.63");
        }
        host11: EtherHost {
            @display("p=3452.76,162.63");
        }
        host12: EtherHost {
            @display("p=3753,162.63");
        }
        host13: EtherHost {
            @display("p=4053.24,175.14");
        }
        host14: EtherHost {
            @display("p=4334.715,175.14");
        }
        host15: EtherHost {
            @display("p=4622.4453,175.14");
        }
        host16: EtherHost {
            @display("p=4922.685,175.14");
        }

        host17: EtherHost {
            @display("p=5373.045,168.88501");
        }
        host18: EtherHost {
            @display("p=5667.0303,168.88501");
        }
        host19: EtherHost {
            @display("p=5986.035,168.88501");
        }
        host20: EtherHost {
            @display("p=6286.275,168.88501");
        }
        host21: EtherHost {
            @display("p=6586.515,181.395");
        }
        host22: EtherHost {
            @display("p=6867.99,181.395");
        }
        host23: EtherHost {
            @display("p=7155.72,181.395");
        }
        host24: EtherHost {
            @display("p=7455.96,181.395");
        }

        host25: EtherHost {
            @display("p=7956.3604,168.88501");
        }
        host26: EtherHost {
            @display("p=8250.345,168.88501");
        }
        host27: EtherHost {
            @display("p=8569.351,168.88501");
        }
        host28: EtherHost {
            @display("p=8869.59,168.88501");
        }
        host29: EtherHost {
            @display("p=9169.83,181.395");
        }
        host30: EtherHost {
            @display("p=9445.05,181.395");
        }
        host31: EtherHost {
            @display("p=9739.035,181.395");
        }
        host32: EtherHost {
            @display("p=10039.275,181.395");
        }

        host33: EtherHost {
            @display("p=10676.659,158.56424");
        }
        host34: EtherHost {
            @display("p=10993.787,158.56424");
        }
        host35: EtherHost {
            @display("p=11310.916,158.56424");
        }
        host36: EtherHost {
            @display("p=11606.902,158.56424");
        }
        host37: EtherHost {
            @display("p=11913.46,169.1352");
        }
        host38: EtherHost {
            @display("p=12188.305,169.1352");
        }
        host39: EtherHost {
            @display("p=12473.721,169.1352");
        }
        host40: EtherHost {
            @display("p=12780.278,169.1352");
        }

        host41: EtherHost {
            @display("p=13277.112,158.56424");
        }
        host42: EtherHost {
            @display("p=13573.099,158.56424");
        }
        host43: EtherHost {
            @display("p=13890.228,158.56424");
        }
        host44: EtherHost {
            @display("p=14196.785,158.56424");
        }
        host45: EtherHost {
            @display("p=14492.771,169.1352");
        }
        host46: EtherHost {
            @display("p=14778.1875,169.1352");
        }
        host47: EtherHost {
            @display("p=15063.603,169.1352");
        }
        host48: EtherHost {
            @display("p=15349.019,169.1352");
        }

        host49: EtherHost {
            @display("p=15803.569,158.56424");
        }
        host50: EtherHost {
            @display("p=16110.127,158.56424");
        }
        host51: EtherHost {
            @display("p=16427.256,158.56424");
        }
        host52: EtherHost {
            @display("p=16723.242,158.56424");
        }
        host53: EtherHost {
            @display("p=17019.229,179.70615");
        }
        host54: EtherHost {
            @display("p=17304.645,179.70615");
        }
        host55: EtherHost {
            @display("p=17590.06,179.70615");
        }
        host56: EtherHost {
            @display("p=17896.617,179.70615");
        }

        host57: EtherHost {
            @display("p=18382.88,158.56424");
        }
        host58: EtherHost {
            @display("p=18689.44,158.56424");
        }
        host59: EtherHost {
            @display("p=18995.996,158.56424");
        }
        host60: EtherHost {
            @display("p=19313.125,158.56424");
        }
        host61: EtherHost {
            @display("p=19609.111,179.70615");
        }
        host62: EtherHost {
            @display("p=19873.385,179.70615");
        }
        host63: EtherHost {
            @display("p=20179.943,179.70615");
        }
        host64: EtherHost {
            @display("p=20475.93,179.70615");
        }

        host65: EtherHost {
            @display("p=433.40894,7431.3774");
        }
        host66: EtherHost {
            @display("p=729.3955,7431.3774");
        }
        host67: EtherHost {
            @display("p=1035.953,7431.3774");
        }
        host68: EtherHost {
            @display("p=1331.9396,7431.3774");
        }
        host69: EtherHost {
            @display("p=1649.0681,7463.0903");
        }
        host70: EtherHost {
            @display("p=1934.4838,7463.0903");
        }
        host71: EtherHost {
            @display("p=2219.8994,7463.0903");
        }
        host72: EtherHost {
            @display("p=2505.315,7463.0903");
        }

        host73: EtherHost {
            @display("p=3012.7207,7431.3774");
        }
        host74: EtherHost {
            @display("p=3308.7073,7431.3774");
        }
        host75: EtherHost {
            @display("p=3625.8357,7431.3774");
        }
        host76: EtherHost {
            @display("p=3932.3933,7431.3774");
        }
        host77: EtherHost {
            @display("p=4217.8086,7463.0903");
        }
        host78: EtherHost {
            @display("p=4492.6533,7463.0903");
        }
        host79: EtherHost {
            @display("p=4799.211,7463.0903");
        }
        host80: EtherHost {
            @display("p=5105.7686,7463.0903");
        }

        host81: EtherHost {
            @display("p=5549.7485,7452.5195");
        }
        host82: EtherHost {
            @display("p=5845.735,7452.5195");
        }
        host83: EtherHost {
            @display("p=6162.864,7452.5195");
        }
        host84: EtherHost {
            @display("p=6458.85,7452.5195");
        }
        host85: EtherHost {
            @display("p=6765.4077,7463.0903");
        }
        host86: EtherHost {
            @display("p=7050.823,7463.0903");
        }
        host87: EtherHost {
            @display("p=7336.239,7463.0903");
        }
        host88: EtherHost {
            @display("p=7632.2256,7463.0903");
        }

        host89: EtherHost {
            @display("p=8107.9185,7452.5195");
        }
        host90: EtherHost {
            @display("p=8403.905,7452.5195");
        }
        host91: EtherHost {
            @display("p=8710.462,7452.5195");
        }
        host92: EtherHost {
            @display("p=9006.449,7452.5195");
        }
        host93: EtherHost {
            @display("p=9323.577,7484.2324");
        }
        host94: EtherHost {
            @display("p=9608.993,7484.2324");
        }
        host95: EtherHost {
            @display("p=9894.409,7484.2324");
        }
        host96: EtherHost {
            @display("p=10190.3955,7484.2324");
        }

        host97: EtherHost {
            @display("p=10687.2295,7452.5195");
        }
        host98: EtherHost {
            @display("p=10983.217,7452.5195");
        }
        host99: EtherHost {
            @display("p=11300.345,7452.5195");
        }
        host100: EtherHost {
            @display("p=11606.902,7452.5195");
        }
        host101: EtherHost {
            @display("p=11892.318,7484.2324");
        }
        host102: EtherHost {
            @display("p=12167.163,7484.2324");
        }
        host103: EtherHost {
            @display("p=12484.291,7484.2324");
        }
        host104: EtherHost {
            @display("p=12780.278,7484.2324");
        }

        host105: EtherHost {
            @display("p=13403.964,7431.3774");
        }
        host106: EtherHost {
            @display("p=13699.95,7431.3774");
        }
        host107: EtherHost {
            @display("p=14017.079,7431.3774");
        }
        host108: EtherHost {
            @display("p=14323.637,7431.3774");
        }
        host109: EtherHost {
            @display("p=14619.623,7441.948");
        }
        host110: EtherHost {
            @display("p=14915.609,7441.948");
        }
        host111: EtherHost {
            @display("p=15201.025,7441.948");
        }
        host112: EtherHost {
            @display("p=15486.441,7441.948");
        }

        host113: EtherHost {
            @display("p=15919.85,7494.803");
        }
        host114: EtherHost {
            @display("p=16226.407,7494.803");
        }
        host115: EtherHost {
            @display("p=16532.965,7494.803");
        }
        host116: EtherHost {
            @display("p=16839.523,7494.803");
        }
        host117: EtherHost {
            @display("p=17135.51,7515.9453");
        }
        host118: EtherHost {
            @display("p=17410.354,7515.9453");
        }
        host119: EtherHost {
            @display("p=17706.34,7515.9453");
        }
        host120: EtherHost {
            @display("p=18012.898,7515.9453");
        }

        host121: EtherHost {
            @display("p=18499.162,7494.803");
        }
        host122: EtherHost {
            @display("p=18805.719,7494.803");
        }
        host123: EtherHost {
            @display("p=19112.277,7494.803");
        }
        host124: EtherHost {
            @display("p=19418.834,7494.803");
        }
        host125: EtherHost {
            @display("p=19725.393,7526.516");
        }
        host126: EtherHost {
            @display("p=19989.666,7526.516");
        }
        host127: EtherHost {
            @display("p=20296.223,7526.516");
        }
        host128: EtherHost {
            @display("p=20592.209,7526.516");
        }

        switch17: EtherSwitch {
            @display("p=1236.8011,4164.954");
            gates:
                ethg[16];
        }
        switch18: EtherSwitch {
            @display("p=3900.6804,4164.954");
            gates:
                ethg[16];
        }
        switch19: EtherSwitch {
            @display("p=6331.9985,4164.954");
            gates:
                ethg[16];
        }
        switch20: EtherSwitch {
            @display("p=9143.871,4133.241");
            gates:
                ethg[16];
        }
        switch21: EtherSwitch {
            @display("p=11871.176,4143.812");
            gates:
                ethg[16];
        }
        switch22: EtherSwitch {
            @display("p=14323.637,4143.812");
            gates:
                ethg[16];
        }
        switch23: EtherSwitch {
            @display("p=16913.52,4143.812");
            gates:
                ethg[16];
        }
        switch24: EtherSwitch {
            @display("p=19376.55,4175.525");
            gates:
                ethg[16];
        }
    connections:
        switch1.ethg[0] <--> cable <--> host1.ethg;
        switch1.ethg[1] <--> cable <--> host2.ethg;
        switch1.ethg[2] <--> cable <--> host3.ethg;
        switch1.ethg[3] <--> cable <--> host4.ethg;
        switch1.ethg[4] <--> cable <--> host5.ethg;
        switch1.ethg[5] <--> cable <--> host6.ethg;
        switch1.ethg[6] <--> cable <--> host7.ethg;
        switch1.ethg[7] <--> cable <--> host8.ethg;

        switch2.ethg[0] <--> cable <--> host9.ethg;
        switch2.ethg[1] <--> cable <--> host10.ethg;
        switch2.ethg[2] <--> cable <--> host11.ethg;
        switch2.ethg[3] <--> cable <--> host12.ethg;
        switch2.ethg[4] <--> cable <--> host13.ethg;
        switch2.ethg[5] <--> cable <--> host14.ethg;
        switch2.ethg[6] <--> cable <--> host15.ethg;
        switch2.ethg[7] <--> cable <--> host16.ethg;

        switch3.ethg[0] <--> cable <--> host17.ethg;
        switch3.ethg[1] <--> cable <--> host18.ethg;
        switch3.ethg[2] <--> cable <--> host19.ethg;
        switch3.ethg[3] <--> cable <--> host20.ethg;
        switch3.ethg[4] <--> cable <--> host21.ethg;
        switch3.ethg[5] <--> cable <--> host22.ethg;
        switch3.ethg[6] <--> cable <--> host23.ethg;
        switch3.ethg[7] <--> cable <--> host24.ethg;

        switch4.ethg[0] <--> cable <--> host25.ethg;
        switch4.ethg[1] <--> cable <--> host26.ethg;
        switch4.ethg[2] <--> cable <--> host27.ethg;
        switch4.ethg[3] <--> cable <--> host28.ethg;
        switch4.ethg[4] <--> cable <--> host29.ethg;
        switch4.ethg[5] <--> cable <--> host30.ethg;
        switch4.ethg[6] <--> cable <--> host31.ethg;
        switch4.ethg[7] <--> cable <--> host32.ethg;

        switch5.ethg[0] <--> cable <--> host33.ethg;
        switch5.ethg[1] <--> cable <--> host34.ethg;
        switch5.ethg[2] <--> cable <--> host35.ethg;
        switch5.ethg[3] <--> cable <--> host36.ethg;
        switch5.ethg[4] <--> cable <--> host37.ethg;
        switch5.ethg[5] <--> cable <--> host38.ethg;
        switch5.ethg[6] <--> cable <--> host39.ethg;
        switch5.ethg[7] <--> cable <--> host40.ethg;

        switch6.ethg[0] <--> cable <--> host41.ethg;
        switch6.ethg[1] <--> cable <--> host42.ethg;
        switch6.ethg[2] <--> cable <--> host43.ethg;
        switch6.ethg[3] <--> cable <--> host44.ethg;
        switch6.ethg[4] <--> cable <--> host45.ethg;
        switch6.ethg[5] <--> cable <--> host46.ethg;
        switch6.ethg[6] <--> cable <--> host47.ethg;
        switch6.ethg[7] <--> cable <--> host48.ethg;

        switch7.ethg[0] <--> cable <--> host49.ethg;
        switch7.ethg[1] <--> cable <--> host50.ethg;
        switch7.ethg[2] <--> cable <--> host51.ethg;
        switch7.ethg[3] <--> cable <--> host52.ethg;
        switch7.ethg[4] <--> cable <--> host53.ethg;
        switch7.ethg[5] <--> cable <--> host54.ethg;
        switch7.ethg[6] <--> cable <--> host55.ethg;
        switch7.ethg[7] <--> cable <--> host56.ethg;

        switch8.ethg[0] <--> cable <--> host57.ethg;
        switch8.ethg[1] <--> cable <--> host58.ethg;
        switch8.ethg[2] <--> cable <--> host59.ethg;
        switch8.ethg[3] <--> cable <--> host60.ethg;
        switch8.ethg[4] <--> cable <--> host61.ethg;
        switch8.ethg[5] <--> cable <--> host62.ethg;
        switch8.ethg[6] <--> cable <--> host63.ethg;
        switch8.ethg[7] <--> cable <--> host64.ethg;

        switch9.ethg[0] <--> cable <--> host65.ethg;
        switch9.ethg[1] <--> cable <--> host66.ethg;
        switch9.ethg[2] <--> cable <--> host67.ethg;
        switch9.ethg[3] <--> cable <--> host68.ethg;
        switch9.ethg[4] <--> cable <--> host69.ethg;
        switch9.ethg[5] <--> cable <--> host70.ethg;
        switch9.ethg[6] <--> cable <--> host71.ethg;
        switch9.ethg[7] <--> cable <--> host72.ethg;

        switch10.ethg[0] <--> cable <--> host73.ethg;
        switch10.ethg[1] <--> cable <--> host74.ethg;
        switch10.ethg[2] <--> cable <--> host75.ethg;
        switch10.ethg[3] <--> cable <--> host76.ethg;
        switch10.ethg[4] <--> cable <--> host77.ethg;
        switch10.ethg[5] <--> cable <--> host78.ethg;
        switch10.ethg[6] <--> cable <--> host79.ethg;
        switch10.ethg[7] <--> cable <--> host80.ethg;

        switch11.ethg[0] <--> cable <--> host81.ethg;
        switch11.ethg[1] <--> cable <--> host82.ethg;
        switch11.ethg[2] <--> cable <--> host83.ethg;
        switch11.ethg[3] <--> cable <--> host84.ethg;
        switch11.ethg[4] <--> cable <--> host87.ethg;
        switch11.ethg[5] <--> cable <--> host86.ethg;
        switch11.ethg[6] <--> cable <--> host87.ethg;
        switch11.ethg[7] <--> cable <--> host88.ethg;

        switch12.ethg[0] <--> cable <--> host89.ethg;
        switch12.ethg[1] <--> cable <--> host90.ethg;
        switch12.ethg[2] <--> cable <--> host91.ethg;
        switch12.ethg[3] <--> cable <--> host92.ethg;
        switch12.ethg[4] <--> cable <--> host93.ethg;
        switch12.ethg[5] <--> cable <--> host94.ethg;
        switch12.ethg[6] <--> cable <--> host95.ethg;
        switch12.ethg[7] <--> cable <--> host96.ethg;

        switch13.ethg[0] <--> cable <--> host97.ethg;
        switch13.ethg[1] <--> cable <--> host98.ethg;
        switch13.ethg[2] <--> cable <--> host99.ethg;
        switch13.ethg[3] <--> cable <--> host100.ethg;
        switch13.ethg[4] <--> cable <--> host101.ethg;
        switch13.ethg[5] <--> cable <--> host102.ethg;
        switch13.ethg[6] <--> cable <--> host103.ethg;
        switch13.ethg[7] <--> cable <--> host104.ethg;

        switch14.ethg[0] <--> cable <--> host105.ethg;
        switch14.ethg[1] <--> cable <--> host106.ethg;
        switch14.ethg[2] <--> cable <--> host107.ethg;
        switch14.ethg[3] <--> cable <--> host108.ethg;
        switch14.ethg[4] <--> cable <--> host109.ethg;
        switch14.ethg[5] <--> cable <--> host110.ethg;
        switch14.ethg[6] <--> cable <--> host111.ethg;
        switch14.ethg[7] <--> cable <--> host112.ethg;

        switch15.ethg[0] <--> cable <--> host113.ethg;
        switch15.ethg[1] <--> cable <--> host114.ethg;
        switch15.ethg[2] <--> cable <--> host115.ethg;
        switch15.ethg[3] <--> cable <--> host116.ethg;
        switch15.ethg[4] <--> cable <--> host117.ethg;
        switch15.ethg[5] <--> cable <--> host118.ethg;
        switch15.ethg[6] <--> cable <--> host119.ethg;
        switch15.ethg[7] <--> cable <--> host120.ethg;

        switch16.ethg[0] <--> cable <--> host121.ethg;
        switch16.ethg[1] <--> cable <--> host122.ethg;
        switch16.ethg[2] <--> cable <--> host123.ethg;
        switch16.ethg[3] <--> cable <--> host124.ethg;
        switch16.ethg[4] <--> cable <--> host125.ethg;
        switch16.ethg[5] <--> cable <--> host126.ethg;
        switch16.ethg[6] <--> cable <--> host127.ethg;
        switch16.ethg[7] <--> cable <--> host128.ethg;



        switch1.ethg[8] <--> cable <--> switch17.ethg[0];
        switch2.ethg[8] <--> cable <--> switch17.ethg[1];
        switch3.ethg[8] <--> cable <--> switch17.ethg[2];
        switch4.ethg[8] <--> cable <--> switch17.ethg[3];
        switch5.ethg[8] <--> cable <--> switch17.ethg[4];
        switch6.ethg[8] <--> cable <--> switch17.ethg[5];
        switch7.ethg[8] <--> cable <--> switch17.ethg[6];
        switch8.ethg[8] <--> cable <--> switch17.ethg[7];
        switch9.ethg[8] <--> cable <--> switch17.ethg[8];
        switch10.ethg[8] <--> cable <--> switch17.ethg[9];
        switch11.ethg[8] <--> cable <--> switch17.ethg[10];
        switch12.ethg[8] <--> cable <--> switch17.ethg[11];
        switch13.ethg[8] <--> cable <--> switch17.ethg[12];
        switch14.ethg[8] <--> cable <--> switch17.ethg[13];
        switch15.ethg[8] <--> cable <--> switch17.ethg[14];
        switch16.ethg[8] <--> cable <--> switch17.ethg[15];
        
        switch1.ethg[9] <--> cable <--> switch18.ethg[0];
        switch2.ethg[9] <--> cable <--> switch18.ethg[1];
        switch3.ethg[9] <--> cable <--> switch18.ethg[2];
        switch4.ethg[9] <--> cable <--> switch18.ethg[3];
        switch5.ethg[9] <--> cable <--> switch18.ethg[4];
        switch6.ethg[9] <--> cable <--> switch18.ethg[5];
        switch7.ethg[9] <--> cable <--> switch18.ethg[6];
        switch8.ethg[9] <--> cable <--> switch18.ethg[7];
        switch9.ethg[9] <--> cable <--> switch18.ethg[8];
        switch10.ethg[9] <--> cable <--> switch18.ethg[9];
        switch11.ethg[9] <--> cable <--> switch18.ethg[10];
        switch12.ethg[9] <--> cable <--> switch18.ethg[11];
        switch13.ethg[9] <--> cable <--> switch18.ethg[12];
        switch14.ethg[9] <--> cable <--> switch18.ethg[13];
        switch15.ethg[9] <--> cable <--> switch18.ethg[14];
        switch16.ethg[9] <--> cable <--> switch18.ethg[15];
        
        switch1.ethg[10] <--> cable <--> switch19.ethg[0];
        switch2.ethg[10] <--> cable <--> switch19.ethg[1];
        switch3.ethg[10] <--> cable <--> switch19.ethg[2];
        switch4.ethg[10] <--> cable <--> switch19.ethg[3];
        switch5.ethg[10] <--> cable <--> switch19.ethg[4];
        switch6.ethg[10] <--> cable <--> switch19.ethg[5];
        switch7.ethg[10] <--> cable <--> switch19.ethg[6];
        switch8.ethg[10] <--> cable <--> switch19.ethg[7];
        switch9.ethg[10] <--> cable <--> switch19.ethg[8];
        switch10.ethg[10] <--> cable <--> switch19.ethg[9];
        switch11.ethg[10] <--> cable <--> switch19.ethg[10];
        switch12.ethg[10] <--> cable <--> switch19.ethg[11];
        switch13.ethg[10] <--> cable <--> switch19.ethg[12];
        switch14.ethg[10] <--> cable <--> switch19.ethg[13];
        switch15.ethg[10] <--> cable <--> switch19.ethg[14];
        switch16.ethg[10] <--> cable <--> switch19.ethg[15];
        
        switch1.ethg[11] <--> cable <--> switch20.ethg[0];
        switch2.ethg[11] <--> cable <--> switch20.ethg[1];
        switch3.ethg[11] <--> cable <--> switch20.ethg[2];
        switch4.ethg[11] <--> cable <--> switch20.ethg[3];
        switch5.ethg[11] <--> cable <--> switch20.ethg[4];
        switch6.ethg[11] <--> cable <--> switch20.ethg[5];
        switch7.ethg[11] <--> cable <--> switch20.ethg[6];
        switch8.ethg[11] <--> cable <--> switch20.ethg[7];
        switch9.ethg[11] <--> cable <--> switch20.ethg[8];
        switch10.ethg[11] <--> cable <--> switch20.ethg[9];
        switch11.ethg[11] <--> cable <--> switch20.ethg[10];
        switch12.ethg[11] <--> cable <--> switch20.ethg[11];
        switch13.ethg[11] <--> cable <--> switch20.ethg[12];
        switch14.ethg[11] <--> cable <--> switch20.ethg[13];
        switch15.ethg[11] <--> cable <--> switch20.ethg[14];
        switch16.ethg[11] <--> cable <--> switch20.ethg[15];
        
        switch1.ethg[12] <--> cable <--> switch21.ethg[0];
        switch2.ethg[12] <--> cable <--> switch21.ethg[1];
        switch3.ethg[12] <--> cable <--> switch21.ethg[2];
        switch4.ethg[12] <--> cable <--> switch21.ethg[3];
        switch5.ethg[12] <--> cable <--> switch21.ethg[4];
        switch6.ethg[12] <--> cable <--> switch21.ethg[5];
        switch7.ethg[12] <--> cable <--> switch21.ethg[6];
        switch8.ethg[12] <--> cable <--> switch21.ethg[7];
        switch9.ethg[12] <--> cable <--> switch21.ethg[8];
        switch10.ethg[12] <--> cable <--> switch21.ethg[9];
        switch11.ethg[12] <--> cable <--> switch21.ethg[10];
        switch12.ethg[12] <--> cable <--> switch21.ethg[11];
        switch13.ethg[12] <--> cable <--> switch21.ethg[12];
        switch14.ethg[12] <--> cable <--> switch21.ethg[13];
        switch15.ethg[12] <--> cable <--> switch21.ethg[14];
        switch16.ethg[12] <--> cable <--> switch21.ethg[15];
        
        switch1.ethg[13] <--> cable <--> switch22.ethg[0];
        switch2.ethg[13] <--> cable <--> switch22.ethg[1];
        switch3.ethg[13] <--> cable <--> switch22.ethg[2];
        switch4.ethg[13] <--> cable <--> switch22.ethg[3];
        switch5.ethg[13] <--> cable <--> switch22.ethg[4];
        switch6.ethg[13] <--> cable <--> switch22.ethg[5];
        switch7.ethg[13] <--> cable <--> switch22.ethg[6];
        switch8.ethg[13] <--> cable <--> switch22.ethg[7];
        switch9.ethg[13] <--> cable <--> switch22.ethg[8];
        switch10.ethg[13] <--> cable <--> switch22.ethg[9];
        switch11.ethg[13] <--> cable <--> switch22.ethg[10];
        switch12.ethg[13] <--> cable <--> switch22.ethg[11];
        switch13.ethg[13] <--> cable <--> switch22.ethg[12];
        switch14.ethg[13] <--> cable <--> switch22.ethg[13];
        switch15.ethg[13] <--> cable <--> switch22.ethg[14];
        switch16.ethg[13] <--> cable <--> switch22.ethg[15];
        
        switch1.ethg[14] <--> cable <--> switch23.ethg[0];
        switch2.ethg[14] <--> cable <--> switch23.ethg[1];
        switch3.ethg[14] <--> cable <--> switch23.ethg[2];
        switch4.ethg[14] <--> cable <--> switch23.ethg[3];
        switch5.ethg[14] <--> cable <--> switch23.ethg[4];
        switch6.ethg[14] <--> cable <--> switch23.ethg[5];
        switch7.ethg[14] <--> cable <--> switch23.ethg[6];
        switch8.ethg[14] <--> cable <--> switch23.ethg[7];
        switch9.ethg[14] <--> cable <--> switch23.ethg[8];
        switch10.ethg[14] <--> cable <--> switch23.ethg[9];
        switch11.ethg[14] <--> cable <--> switch23.ethg[10];
        switch12.ethg[14] <--> cable <--> switch23.ethg[11];
        switch13.ethg[14] <--> cable <--> switch23.ethg[12];
        switch14.ethg[14] <--> cable <--> switch23.ethg[13];
        switch15.ethg[14] <--> cable <--> switch23.ethg[14];
        switch16.ethg[14] <--> cable <--> switch23.ethg[15];
        
        switch1.ethg[15] <--> cable <--> switch24.ethg[0];
        switch2.ethg[15] <--> cable <--> switch24.ethg[1];
        switch3.ethg[15] <--> cable <--> switch24.ethg[2];
        switch4.ethg[15] <--> cable <--> switch24.ethg[3];
        switch5.ethg[15] <--> cable <--> switch24.ethg[4];
        switch6.ethg[15] <--> cable <--> switch24.ethg[5];
        switch7.ethg[15] <--> cable <--> switch24.ethg[6];
        switch8.ethg[15] <--> cable <--> switch24.ethg[7];
        switch9.ethg[15] <--> cable <--> switch24.ethg[8];
        switch10.ethg[15] <--> cable <--> switch24.ethg[9];
        switch11.ethg[15] <--> cable <--> switch24.ethg[10];
        switch12.ethg[15] <--> cable <--> switch24.ethg[11];
        switch13.ethg[15] <--> cable <--> switch24.ethg[12];
        switch14.ethg[15] <--> cable <--> switch24.ethg[13];
        switch15.ethg[15] <--> cable <--> switch24.ethg[14];
        switch16.ethg[15] <--> cable <--> switch24.ethg[15];


}
