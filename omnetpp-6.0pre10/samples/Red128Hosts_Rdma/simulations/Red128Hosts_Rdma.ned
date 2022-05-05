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
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package red128hosts_rdma.simulations;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.Eth40G;
import inet.node.rdma.RdmaHost;
import inet.node.ethernet.EthernetSwitch;
import ned.DatarateChannel;
//
// TODO auto-generated type
//
network Red128Hosts_Rdma
{
    @display("bgb=2731.9736,1134.2999");
    types:
        channel cable extends DatarateChannel
        {
            double retardoRed @unit(us);
            datarate = 40Gbps;
            delay = retardoRed;
        }
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=2666.625,382.9;is=s");
        }
        H_0: RdmaHost {
            @display("p=15,21.307693");
        }
        H_1: RdmaHost {
            @display("p=50,21");
        }
        H_2: RdmaHost {
            @display("p=85,21");
        }
        H_3: RdmaHost {
            @display("p=120,21");
        }
        H_4: RdmaHost {
            @display("p=155,21");
        }
        H_5: RdmaHost {
            @display("p=190,21");
        }
        H_6: RdmaHost {
            @display("p=225,21");
        }
        H_7: RdmaHost {
            @display("p=260,21");
        }
        SW_1_1: EthernetSwitch {
            @display("p=118.30001,229.84001");
            gates:
                ethg[16];
        }
        H_8: RdmaHost {
            @display("p=350,21");
        }
        H_9: RdmaHost {
            @display("p=385,21");
        }
        H_10: RdmaHost {
            @display("p=420,21");
        }
        H_11: RdmaHost {
            @display("p=455,21");
        }
        H_12: RdmaHost {
            @display("p=490,21");
        }
        H_13: RdmaHost {
            @display("p=525,21");
        }
        H_14: RdmaHost {
            @display("p=560,21");
        }
        H_15: RdmaHost {
            @display("p=595,21");
        }
        SW_1_2: EthernetSwitch {
            @display("p=461.37003,229.84001");
            gates:
                ethg[16];
        }
        H_16: RdmaHost {
            @display("p=685,21");
        }
        H_17: RdmaHost {
            @display("p=720,21");
        }
        H_18: RdmaHost {
            @display("p=755,21");
        }
        H_19: RdmaHost {
            @display("p=790,21");
        }
        H_20: RdmaHost {
            @display("p=825,21");
        }
        H_21: RdmaHost {
            @display("p=860,21");
        }
        H_22: RdmaHost {
            @display("p=895,21");
        }
        H_23: RdmaHost {
            @display("p=930,21");
        }
        SW_1_3: EthernetSwitch {
            @display("p=789.23004,229.84001");
            gates:
                ethg[16];
        }
        H_24: RdmaHost {
            @display("p=1020,21");
        }
        H_25: RdmaHost {
            @display("p=1055,21");
        }
        H_26: RdmaHost {
            @display("p=1090,21");
        }
        H_27: RdmaHost {
            @display("p=1125,21");
        }
        H_28: RdmaHost {
            @display("p=1160,21");
        }
        H_29: RdmaHost {
            @display("p=1195,21");
        }
        H_30: RdmaHost {
            @display("p=1230,21");
        }
        H_31: RdmaHost {
            @display("p=1265,21");
        }
        SW_1_4: EthernetSwitch {
            @display("p=1123.8501,229.84001");
            gates:
                ethg[16];
        }
        H_32: RdmaHost {
            @display("p=1355,21");
        }
        H_33: RdmaHost {
            @display("p=1390,21");
        }
        H_34: RdmaHost {
            @display("p=1425,21");
        }
        H_35: RdmaHost {
            @display("p=1460,21");
        }
        H_36: RdmaHost {
            @display("p=1495,21");
        }
        H_37: RdmaHost {
            @display("p=1530,21");
        }
        H_38: RdmaHost {
            @display("p=1565,21");
        }
        H_39: RdmaHost {
            @display("p=1600,21");
        }
        SW_1_5: EthernetSwitch {
            @display("p=1478.7501,229.84001");
            gates:
                ethg[16];
        }
        H_40: RdmaHost {
            @display("p=1690,21");
        }
        H_41: RdmaHost {
            @display("p=1725,21");
        }
        H_42: RdmaHost {
            @display("p=1760,21");
        }
        H_43: RdmaHost {
            @display("p=1795,21");
        }
        H_44: RdmaHost {
            @display("p=1830,21");
        }
        H_45: RdmaHost {
            @display("p=1865,21");
        }
        H_46: RdmaHost {
            @display("p=1900,21");
        }
        H_47: RdmaHost {
            @display("p=1935,21");
        }
        SW_1_6: EthernetSwitch {
            @display("p=1813.3701,229.84001");
            gates:
                ethg[16];
        }
        H_48: RdmaHost {
            @display("p=2025,21");
        }
        H_49: RdmaHost {
            @display("p=2060,21");
        }
        H_50: RdmaHost {
            @display("p=2095,21");
        }
        H_51: RdmaHost {
            @display("p=2130,21");
        }
        H_52: RdmaHost {
            @display("p=2165,21");
        }
        H_53: RdmaHost {
            @display("p=2200,21");
        }
        H_54: RdmaHost {
            @display("p=2235,21");
        }
        H_55: RdmaHost {
            @display("p=2270,21");
        }
        SW_1_7: EthernetSwitch {
            @display("p=2139.54,229.84001");
            gates:
                ethg[16];
        }
        H_56: RdmaHost {
            @display("p=2360,21");
        }
        H_57: RdmaHost {
            @display("p=2395,21");
        }
        H_58: RdmaHost {
            @display("p=2430,21");
        }
        H_59: RdmaHost {
            @display("p=2465,21");
        }
        H_60: RdmaHost {
            @display("p=2500,21");
        }
        H_61: RdmaHost {
            @display("p=2535,21");
        }
        H_62: RdmaHost {
            @display("p=2570,21");
        }
        H_63: RdmaHost {
            @display("p=2605,21");
        }
        SW_1_8: EthernetSwitch {
            @display("p=2499.5103,229.84001");
            gates:
                ethg[16];
        }
        H_64: RdmaHost {
            @display("p=15,1000");
        }
        H_65: RdmaHost {
            @display("p=50,1000");
        }
        H_66: RdmaHost {
            @display("p=85,1000");
        }
        H_67: RdmaHost {
            @display("p=120,1000");
        }
        H_68: RdmaHost {
            @display("p=155,1000");
        }
        H_69: RdmaHost {
            @display("p=190,1000");
        }
        H_70: RdmaHost {
            @display("p=225,1000");
        }
        H_71: RdmaHost {
            @display("p=260,1000");
        }
        SW_2_1: EthernetSwitch {
            @display("p=119.95619,759.72253");
            gates:
                ethg[16];
        }
        H_72: RdmaHost {
            @display("p=350,1000");
        }
        H_73: RdmaHost {
            @display("p=385,1000");
        }
        H_74: RdmaHost {
            @display("p=420,1000");
        }
        H_75: RdmaHost {
            @display("p=455,1000");
        }
        H_76: RdmaHost {
            @display("p=490,1000");
        }
        H_77: RdmaHost {
            @display("p=525,1000");
        }
        H_78: RdmaHost {
            @display("p=560,1000");
        }
        H_79: RdmaHost {
            @display("p=595,1000");
        }
        SW_2_2: EthernetSwitch {
            @display("p=462.68817,759.72253");
            gates:
                ethg[16];
        }
        H_80: RdmaHost {
            @display("p=685,1000");
        }
        H_81: RdmaHost {
            @display("p=720,1000");
        }
        H_82: RdmaHost {
            @display("p=755,1000");
        }
        H_83: RdmaHost {
            @display("p=790,1000");
        }
        H_84: RdmaHost {
            @display("p=825,1000");
        }
        H_85: RdmaHost {
            @display("p=860,1000");
        }
        H_86: RdmaHost {
            @display("p=895,1000");
        }
        H_87: RdmaHost {
            @display("p=930,1000");
        }
        SW_2_3: EthernetSwitch {
            @display("p=788.28357,759.72253");
            gates:
                ethg[16];
        }
        H_88: RdmaHost {
            @display("p=1020,1000");
        }
        H_89: RdmaHost {
            @display("p=1055,1000");
        }
        H_90: RdmaHost {
            @display("p=1090,1000");
        }
        H_91: RdmaHost {
            @display("p=1125,1000");
        }
        H_92: RdmaHost {
            @display("p=1160,1000");
        }
        H_93: RdmaHost {
            @display("p=1195,1000");
        }
        H_94: RdmaHost {
            @display("p=1230,1000");
        }
        H_95: RdmaHost {
            @display("p=1265,1000");
        }
        SW_2_4: EthernetSwitch {
            @display("p=1122.4473,759.72253");
            gates:
                ethg[16];
        }
        H_96: RdmaHost {
            @display("p=1355,1000");
        }
        H_97: RdmaHost {
            @display("p=1390,1000");
        }
        H_98: RdmaHost {
            @display("p=1425,1000");
        }
        H_99: RdmaHost {
            @display("p=1460,1000");
        }
        H_100: RdmaHost {
            @display("p=1495,1000");
        }
        H_101: RdmaHost {
            @display("p=1530,1000");
        }
        H_102: RdmaHost {
            @display("p=1565,1000");
        }
        H_103: RdmaHost {
            @display("p=1600,1000");
        }
        SW_2_5: EthernetSwitch {
            @display("p=1476.6036,759.72253");
            gates:
                ethg[16];
        }
        H_104: RdmaHost {
            @display("p=1690,1000");
        }
        H_105: RdmaHost {
            @display("p=1725,1000");
        }
        H_106: RdmaHost {
            @display("p=1760,1000");
        }
        H_107: RdmaHost {
            @display("p=1795,1000");
        }
        H_108: RdmaHost {
            @display("p=1830,1000");
        }
        H_109: RdmaHost {
            @display("p=1865,1000");
        }
        H_110: RdmaHost {
            @display("p=1900,1000");
        }
        H_111: RdmaHost {
            @display("p=1935,1000");
        }
        SW_2_6: EthernetSwitch {
            @display("p=1810.7673,759.72253");
            gates:
                ethg[16];
        }
        H_112: RdmaHost {
            @display("p=2025,1000");
        }
        H_113: RdmaHost {
            @display("p=2060,1000");
        }
        H_114: RdmaHost {
            @display("p=2095,1000");
        }
        H_115: RdmaHost {
            @display("p=2130,1000");
        }
        H_116: RdmaHost {
            @display("p=2165,1000");
        }
        H_117: RdmaHost {
            @display("p=2200,1000");
        }
        H_118: RdmaHost {
            @display("p=2235,1000");
        }
        H_119: RdmaHost {
            @display("p=2270,1000");
        }
        SW_2_7: EthernetSwitch {
            @display("p=2139.2188,759.72253");
            gates:
                ethg[16];
        }
        H_120: RdmaHost {
            @display("p=2360,1000");
        }
        H_121: RdmaHost {
            @display("p=2395,1000");
        }
        H_122: RdmaHost {
            @display("p=2430,1000");
        }
        H_123: RdmaHost {
            @display("p=2465,1000");
        }
        H_124: RdmaHost {
            @display("p=2500,1000");
        }
        H_125: RdmaHost {
            @display("p=2535,1000");
        }
        H_126: RdmaHost {
            @display("p=2570,1000");
        }
        H_127: RdmaHost {
            @display("p=2605,1000");
        }
        SW_2_8: EthernetSwitch {
            @display("p=2499.0874,759.72253");
            gates:
                ethg[16];
        }
        SW_3_1: EthernetSwitch {
            @display("p=118.638,472.355");
            gates:
                ethg[16];
        }
        SW_3_2: EthernetSwitch {
            @display("p=461.37,485.53702");
            gates:
                ethg[16];
        }
        SW_3_3: EthernetSwitch {
            @display("p=788.28357,485.537");
            gates:
                ethg[16];
        }
        SW_3_4: EthernetSwitch {
            @display("p=1122.4473,494.1053");
            gates:
                ethg[16];
        }
        SW_3_5: EthernetSwitch {
            @display("p=1476.6036,494.1053");
            gates:
                ethg[16];
        }
        SW_3_6: EthernetSwitch {
            @display("p=1810.7673,494.1053");
            gates:
                ethg[16];
        }
        SW_3_7: EthernetSwitch {
            @display("p=2139.2188,494.1053");
            gates:
                ethg[16];
        }
        SW_3_8: EthernetSwitch {
            @display("p=2499.0874,494.1053");
            gates:
                ethg[16];
        }
    connections:
        H_0.ethg++ <--> Eth40G <--> SW_1_1.ethg[0];
        H_1.ethg++ <--> Eth40G <--> SW_1_1.ethg[1];
        H_2.ethg++ <--> Eth40G <--> SW_1_1.ethg[2];
        H_3.ethg++ <--> Eth40G <--> SW_1_1.ethg[3];
        H_4.ethg++ <--> Eth40G <--> SW_1_1.ethg[4];
        H_5.ethg++ <--> Eth40G <--> SW_1_1.ethg[5];
        H_6.ethg++ <--> Eth40G <--> SW_1_1.ethg[6];
        H_7.ethg++ <--> Eth40G <--> SW_1_1.ethg[7];
        H_8.ethg++ <--> Eth40G <--> SW_1_2.ethg[0];
        H_9.ethg++ <--> Eth40G <--> SW_1_2.ethg[1];
        H_10.ethg++ <--> Eth40G <--> SW_1_2.ethg[2];
        H_11.ethg++ <--> Eth40G <--> SW_1_2.ethg[3];
        H_12.ethg++ <--> Eth40G <--> SW_1_2.ethg[4];
        H_13.ethg++ <--> Eth40G <--> SW_1_2.ethg[5];
        H_14.ethg++ <--> Eth40G <--> SW_1_2.ethg[6];
        H_15.ethg++ <--> Eth40G <--> SW_1_2.ethg[7];
        H_16.ethg++ <--> Eth40G <--> SW_1_3.ethg[0];
        H_17.ethg++ <--> Eth40G <--> SW_1_3.ethg[1];
        H_18.ethg++ <--> Eth40G <--> SW_1_3.ethg[2];
        H_19.ethg++ <--> Eth40G <--> SW_1_3.ethg[3];
        H_20.ethg++ <--> Eth40G <--> SW_1_3.ethg[4];
        H_21.ethg++ <--> Eth40G <--> SW_1_3.ethg[5];
        H_22.ethg++ <--> Eth40G <--> SW_1_3.ethg[6];
        H_23.ethg++ <--> Eth40G <--> SW_1_3.ethg[7];
        H_24.ethg++ <--> Eth40G <--> SW_1_4.ethg[0];
        H_25.ethg++ <--> Eth40G <--> SW_1_4.ethg[1];
        H_26.ethg++ <--> Eth40G <--> SW_1_4.ethg[2];
        H_27.ethg++ <--> Eth40G <--> SW_1_4.ethg[3];
        H_28.ethg++ <--> Eth40G <--> SW_1_4.ethg[4];
        H_29.ethg++ <--> Eth40G <--> SW_1_4.ethg[5];
        H_30.ethg++ <--> Eth40G <--> SW_1_4.ethg[6];
        H_31.ethg++ <--> Eth40G <--> SW_1_4.ethg[7];
        H_32.ethg++ <--> Eth40G <--> SW_1_5.ethg[0];
        H_33.ethg++ <--> Eth40G <--> SW_1_5.ethg[1];
        H_34.ethg++ <--> Eth40G <--> SW_1_5.ethg[2];
        H_35.ethg++ <--> Eth40G <--> SW_1_5.ethg[3];
        H_36.ethg++ <--> Eth40G <--> SW_1_5.ethg[4];
        H_37.ethg++ <--> Eth40G <--> SW_1_5.ethg[5];
        H_38.ethg++ <--> Eth40G <--> SW_1_5.ethg[6];
        H_39.ethg++ <--> Eth40G <--> SW_1_5.ethg[7];
        H_40.ethg++ <--> Eth40G <--> SW_1_6.ethg[0];
        H_41.ethg++ <--> Eth40G <--> SW_1_6.ethg[1];
        H_42.ethg++ <--> Eth40G <--> SW_1_6.ethg[2];
        H_43.ethg++ <--> Eth40G <--> SW_1_6.ethg[3];
        H_44.ethg++ <--> Eth40G <--> SW_1_6.ethg[4];
        H_45.ethg++ <--> Eth40G <--> SW_1_6.ethg[5];
        H_46.ethg++ <--> Eth40G <--> SW_1_6.ethg[6];
        H_47.ethg++ <--> Eth40G <--> SW_1_6.ethg[7];
        H_48.ethg++ <--> Eth40G <--> SW_1_7.ethg[0];
        H_49.ethg++ <--> Eth40G <--> SW_1_7.ethg[1];
        H_50.ethg++ <--> Eth40G <--> SW_1_7.ethg[2];
        H_51.ethg++ <--> Eth40G <--> SW_1_7.ethg[3];
        H_52.ethg++ <--> Eth40G <--> SW_1_7.ethg[4];
        H_53.ethg++ <--> Eth40G <--> SW_1_7.ethg[5];
        H_54.ethg++ <--> Eth40G <--> SW_1_7.ethg[6];
        H_55.ethg++ <--> Eth40G <--> SW_1_7.ethg[7];
        H_56.ethg++ <--> Eth40G <--> SW_1_8.ethg[0];
        H_57.ethg++ <--> Eth40G <--> SW_1_8.ethg[1];
        H_58.ethg++ <--> Eth40G <--> SW_1_8.ethg[2];
        H_59.ethg++ <--> Eth40G <--> SW_1_8.ethg[3];
        H_60.ethg++ <--> Eth40G <--> SW_1_8.ethg[4];
        H_61.ethg++ <--> Eth40G <--> SW_1_8.ethg[5];
        H_62.ethg++ <--> Eth40G <--> SW_1_8.ethg[6];
        H_63.ethg++ <--> Eth40G <--> SW_1_8.ethg[7];
        H_64.ethg++ <--> Eth40G <--> SW_2_1.ethg[0];
        H_65.ethg++ <--> Eth40G <--> SW_2_1.ethg[1];
        H_66.ethg++ <--> Eth40G <--> SW_2_1.ethg[2];
        H_67.ethg++ <--> Eth40G <--> SW_2_1.ethg[3];
        H_68.ethg++ <--> Eth40G <--> SW_2_1.ethg[4];
        H_69.ethg++ <--> Eth40G <--> SW_2_1.ethg[5];
        H_70.ethg++ <--> Eth40G <--> SW_2_1.ethg[6];
        H_71.ethg++ <--> Eth40G <--> SW_2_1.ethg[7];
        H_72.ethg++ <--> Eth40G <--> SW_2_2.ethg[0];
        H_73.ethg++ <--> Eth40G <--> SW_2_2.ethg[1];
        H_74.ethg++ <--> Eth40G <--> SW_2_2.ethg[2];
        H_75.ethg++ <--> Eth40G <--> SW_2_2.ethg[3];
        H_76.ethg++ <--> Eth40G <--> SW_2_2.ethg[4];
        H_77.ethg++ <--> Eth40G <--> SW_2_2.ethg[5];
        H_78.ethg++ <--> Eth40G <--> SW_2_2.ethg[6];
        H_79.ethg++ <--> Eth40G <--> SW_2_2.ethg[7];
        H_80.ethg++ <--> Eth40G <--> SW_2_3.ethg[0];
        H_81.ethg++ <--> Eth40G <--> SW_2_3.ethg[1];
        H_82.ethg++ <--> Eth40G <--> SW_2_3.ethg[2];
        H_83.ethg++ <--> Eth40G <--> SW_2_3.ethg[3];
        H_84.ethg++ <--> Eth40G <--> SW_2_3.ethg[4];
        H_85.ethg++ <--> Eth40G <--> SW_2_3.ethg[5];
        H_86.ethg++ <--> Eth40G <--> SW_2_3.ethg[6];
        H_87.ethg++ <--> Eth40G <--> SW_2_3.ethg[7];
        H_88.ethg++ <--> Eth40G <--> SW_2_4.ethg[0];
        H_89.ethg++ <--> Eth40G <--> SW_2_4.ethg[1];
        H_90.ethg++ <--> Eth40G <--> SW_2_4.ethg[2];
        H_91.ethg++ <--> Eth40G <--> SW_2_4.ethg[3];
        H_92.ethg++ <--> Eth40G <--> SW_2_4.ethg[4];
        H_93.ethg++ <--> Eth40G <--> SW_2_4.ethg[5];
        H_94.ethg++ <--> Eth40G <--> SW_2_4.ethg[6];
        H_95.ethg++ <--> Eth40G <--> SW_2_4.ethg[7];
        H_96.ethg++ <--> Eth40G <--> SW_2_5.ethg[0];
        H_97.ethg++ <--> Eth40G <--> SW_2_5.ethg[1];
        H_98.ethg++ <--> Eth40G <--> SW_2_5.ethg[2];
        H_99.ethg++ <--> Eth40G <--> SW_2_5.ethg[3];
        H_100.ethg++ <--> Eth40G <--> SW_2_5.ethg[4];
        H_101.ethg++ <--> Eth40G <--> SW_2_5.ethg[5];
        H_102.ethg++ <--> Eth40G <--> SW_2_5.ethg[6];
        H_103.ethg++ <--> Eth40G <--> SW_2_5.ethg[7];
        H_104.ethg++ <--> Eth40G <--> SW_2_6.ethg[0];
        H_105.ethg++ <--> Eth40G <--> SW_2_6.ethg[1];
        H_106.ethg++ <--> Eth40G <--> SW_2_6.ethg[2];
        H_107.ethg++ <--> Eth40G <--> SW_2_6.ethg[3];
        H_108.ethg++ <--> Eth40G <--> SW_2_6.ethg[4];
        H_109.ethg++ <--> Eth40G <--> SW_2_6.ethg[5];
        H_110.ethg++ <--> Eth40G <--> SW_2_6.ethg[6];
        H_111.ethg++ <--> Eth40G <--> SW_2_6.ethg[7];
        H_112.ethg++ <--> Eth40G <--> SW_2_7.ethg[0];
        H_113.ethg++ <--> Eth40G <--> SW_2_7.ethg[1];
        H_114.ethg++ <--> Eth40G <--> SW_2_7.ethg[2];
        H_115.ethg++ <--> Eth40G <--> SW_2_7.ethg[3];
        H_116.ethg++ <--> Eth40G <--> SW_2_7.ethg[4];
        H_117.ethg++ <--> Eth40G <--> SW_2_7.ethg[5];
        H_118.ethg++ <--> Eth40G <--> SW_2_7.ethg[6];
        H_119.ethg++ <--> Eth40G <--> SW_2_7.ethg[7];
        H_120.ethg++ <--> Eth40G <--> SW_2_8.ethg[0];
        H_121.ethg++ <--> Eth40G <--> SW_2_8.ethg[1];
        H_122.ethg++ <--> Eth40G <--> SW_2_8.ethg[2];
        H_123.ethg++ <--> Eth40G <--> SW_2_8.ethg[3];
        H_124.ethg++ <--> Eth40G <--> SW_2_8.ethg[4];
        H_125.ethg++ <--> Eth40G <--> SW_2_8.ethg[5];
        H_126.ethg++ <--> Eth40G <--> SW_2_8.ethg[6];
        H_127.ethg++ <--> Eth40G <--> SW_2_8.ethg[7];
        SW_3_1.ethg[0] <--> Eth40G <--> SW_1_1.ethg[8];
        SW_3_1.ethg[1] <--> Eth40G <--> SW_1_2.ethg[8];
        SW_3_1.ethg[2] <--> Eth40G <--> SW_1_3.ethg[8];
        SW_3_1.ethg[3] <--> Eth40G <--> SW_1_4.ethg[8];
        SW_3_1.ethg[4] <--> Eth40G <--> SW_1_5.ethg[8];
        SW_3_1.ethg[5] <--> Eth40G <--> SW_1_6.ethg[8];
        SW_3_1.ethg[6] <--> Eth40G <--> SW_1_7.ethg[8];
        SW_3_1.ethg[7] <--> Eth40G <--> SW_1_8.ethg[8];
        SW_3_1.ethg[8] <--> Eth40G <--> SW_2_1.ethg[8];
        SW_3_1.ethg[9] <--> Eth40G <--> SW_2_2.ethg[8];
        SW_3_1.ethg[10] <--> Eth40G <--> SW_2_3.ethg[8];
        SW_3_1.ethg[11] <--> Eth40G <--> SW_2_4.ethg[8];
        SW_3_1.ethg[12] <--> Eth40G <--> SW_2_5.ethg[8];
        SW_3_1.ethg[13] <--> Eth40G <--> SW_2_6.ethg[8];
        SW_3_1.ethg[14] <--> Eth40G <--> SW_2_7.ethg[8];
        SW_3_1.ethg[15] <--> Eth40G <--> SW_2_8.ethg[8];
        SW_3_2.ethg[0] <--> Eth40G <--> SW_1_1.ethg[9];
        SW_3_2.ethg[1] <--> Eth40G <--> SW_1_2.ethg[9];
        SW_3_2.ethg[2] <--> Eth40G <--> SW_1_3.ethg[9];
        SW_3_2.ethg[3] <--> Eth40G <--> SW_1_4.ethg[9];
        SW_3_2.ethg[4] <--> Eth40G <--> SW_1_5.ethg[9];
        SW_3_2.ethg[5] <--> Eth40G <--> SW_1_6.ethg[9];
        SW_3_2.ethg[6] <--> Eth40G <--> SW_1_7.ethg[9];
        SW_3_2.ethg[7] <--> Eth40G <--> SW_1_8.ethg[9];
        SW_3_2.ethg[8] <--> Eth40G <--> SW_2_1.ethg[9];
        SW_3_2.ethg[9] <--> Eth40G <--> SW_2_2.ethg[9];
        SW_3_2.ethg[10] <--> Eth40G <--> SW_2_3.ethg[9];
        SW_3_2.ethg[11] <--> Eth40G <--> SW_2_4.ethg[9];
        SW_3_2.ethg[12] <--> Eth40G <--> SW_2_5.ethg[9];
        SW_3_2.ethg[13] <--> Eth40G <--> SW_2_6.ethg[9];
        SW_3_2.ethg[14] <--> Eth40G <--> SW_2_7.ethg[9];
        SW_3_2.ethg[15] <--> Eth40G <--> SW_2_8.ethg[9];
        SW_3_3.ethg[0] <--> Eth40G <--> SW_1_1.ethg[10];
        SW_3_3.ethg[1] <--> Eth40G <--> SW_1_2.ethg[10];
        SW_3_3.ethg[2] <--> Eth40G <--> SW_1_3.ethg[10];
        SW_3_3.ethg[3] <--> Eth40G <--> SW_1_4.ethg[10];
        SW_3_3.ethg[4] <--> Eth40G <--> SW_1_5.ethg[10];
        SW_3_3.ethg[5] <--> Eth40G <--> SW_1_6.ethg[10];
        SW_3_3.ethg[6] <--> Eth40G <--> SW_1_7.ethg[10];
        SW_3_3.ethg[7] <--> Eth40G <--> SW_1_8.ethg[10];
        SW_3_3.ethg[8] <--> Eth40G <--> SW_2_1.ethg[10];
        SW_3_3.ethg[9] <--> Eth40G <--> SW_2_2.ethg[10];
        SW_3_3.ethg[10] <--> Eth40G <--> SW_2_3.ethg[10];
        SW_3_3.ethg[11] <--> Eth40G <--> SW_2_4.ethg[10];
        SW_3_3.ethg[12] <--> Eth40G <--> SW_2_5.ethg[10];
        SW_3_3.ethg[13] <--> Eth40G <--> SW_2_6.ethg[10];
        SW_3_3.ethg[14] <--> Eth40G <--> SW_2_7.ethg[10];
        SW_3_3.ethg[15] <--> Eth40G <--> SW_2_8.ethg[10];
        SW_3_4.ethg[0] <--> Eth40G <--> SW_1_1.ethg[11];
        SW_3_4.ethg[1] <--> Eth40G <--> SW_1_2.ethg[11];
        SW_3_4.ethg[2] <--> Eth40G <--> SW_1_3.ethg[11];
        SW_3_4.ethg[3] <--> Eth40G <--> SW_1_4.ethg[11];
        SW_3_4.ethg[4] <--> Eth40G <--> SW_1_5.ethg[11];
        SW_3_4.ethg[5] <--> Eth40G <--> SW_1_6.ethg[11];
        SW_3_4.ethg[6] <--> Eth40G <--> SW_1_7.ethg[11];
        SW_3_4.ethg[7] <--> Eth40G <--> SW_1_8.ethg[11];
        SW_3_4.ethg[8] <--> Eth40G <--> SW_2_1.ethg[11];
        SW_3_4.ethg[9] <--> Eth40G <--> SW_2_2.ethg[11];
        SW_3_4.ethg[10] <--> Eth40G <--> SW_2_3.ethg[11];
        SW_3_4.ethg[11] <--> Eth40G <--> SW_2_4.ethg[11];
        SW_3_4.ethg[12] <--> Eth40G <--> SW_2_5.ethg[11];
        SW_3_4.ethg[13] <--> Eth40G <--> SW_2_6.ethg[11];
        SW_3_4.ethg[14] <--> Eth40G <--> SW_2_7.ethg[11];
        SW_3_4.ethg[15] <--> Eth40G <--> SW_2_8.ethg[11];
        SW_3_5.ethg[0] <--> Eth40G <--> SW_1_1.ethg[12];
        SW_3_5.ethg[1] <--> Eth40G <--> SW_1_2.ethg[12];
        SW_3_5.ethg[2] <--> Eth40G <--> SW_1_3.ethg[12];
        SW_3_5.ethg[3] <--> Eth40G <--> SW_1_4.ethg[12];
        SW_3_5.ethg[4] <--> Eth40G <--> SW_1_5.ethg[12];
        SW_3_5.ethg[5] <--> Eth40G <--> SW_1_6.ethg[12];
        SW_3_5.ethg[6] <--> Eth40G <--> SW_1_7.ethg[12];
        SW_3_5.ethg[7] <--> Eth40G <--> SW_1_8.ethg[12];
        SW_3_5.ethg[8] <--> Eth40G <--> SW_2_1.ethg[12];
        SW_3_5.ethg[9] <--> Eth40G <--> SW_2_2.ethg[12];
        SW_3_5.ethg[10] <--> Eth40G <--> SW_2_3.ethg[12];
        SW_3_5.ethg[11] <--> Eth40G <--> SW_2_4.ethg[12];
        SW_3_5.ethg[12] <--> Eth40G <--> SW_2_5.ethg[12];
        SW_3_5.ethg[13] <--> Eth40G <--> SW_2_6.ethg[12];
        SW_3_5.ethg[14] <--> Eth40G <--> SW_2_7.ethg[12];
        SW_3_5.ethg[15] <--> Eth40G <--> SW_2_8.ethg[12];
        SW_3_6.ethg[0] <--> Eth40G <--> SW_1_1.ethg[13];
        SW_3_6.ethg[1] <--> Eth40G <--> SW_1_2.ethg[13];
        SW_3_6.ethg[2] <--> Eth40G <--> SW_1_3.ethg[13];
        SW_3_6.ethg[3] <--> Eth40G <--> SW_1_4.ethg[13];
        SW_3_6.ethg[4] <--> Eth40G <--> SW_1_5.ethg[13];
        SW_3_6.ethg[5] <--> Eth40G <--> SW_1_6.ethg[13];
        SW_3_6.ethg[6] <--> Eth40G <--> SW_1_7.ethg[13];
        SW_3_6.ethg[7] <--> Eth40G <--> SW_1_8.ethg[13];
        SW_3_6.ethg[8] <--> Eth40G <--> SW_2_1.ethg[13];
        SW_3_6.ethg[9] <--> Eth40G <--> SW_2_2.ethg[13];
        SW_3_6.ethg[10] <--> Eth40G <--> SW_2_3.ethg[13];
        SW_3_6.ethg[11] <--> Eth40G <--> SW_2_4.ethg[13];
        SW_3_6.ethg[12] <--> Eth40G <--> SW_2_5.ethg[13];
        SW_3_6.ethg[13] <--> Eth40G <--> SW_2_6.ethg[13];
        SW_3_6.ethg[14] <--> Eth40G <--> SW_2_7.ethg[13];
        SW_3_6.ethg[15] <--> Eth40G <--> SW_2_8.ethg[13];
        SW_3_7.ethg[0] <--> Eth40G <--> SW_1_1.ethg[14];
        SW_3_7.ethg[1] <--> Eth40G <--> SW_1_2.ethg[14];
        SW_3_7.ethg[2] <--> Eth40G <--> SW_1_3.ethg[14];
        SW_3_7.ethg[3] <--> Eth40G <--> SW_1_4.ethg[14];
        SW_3_7.ethg[4] <--> Eth40G <--> SW_1_5.ethg[14];
        SW_3_7.ethg[5] <--> Eth40G <--> SW_1_6.ethg[14];
        SW_3_7.ethg[6] <--> Eth40G <--> SW_1_7.ethg[14];
        SW_3_7.ethg[7] <--> Eth40G <--> SW_1_8.ethg[14];
        SW_3_7.ethg[8] <--> Eth40G <--> SW_2_1.ethg[14];
        SW_3_7.ethg[9] <--> Eth40G <--> SW_2_2.ethg[14];
        SW_3_7.ethg[10] <--> Eth40G <--> SW_2_3.ethg[14];
        SW_3_7.ethg[11] <--> Eth40G <--> SW_2_4.ethg[14];
        SW_3_7.ethg[12] <--> Eth40G <--> SW_2_5.ethg[14];
        SW_3_7.ethg[13] <--> Eth40G <--> SW_2_6.ethg[14];
        SW_3_7.ethg[14] <--> Eth40G <--> SW_2_7.ethg[14];
        SW_3_7.ethg[15] <--> Eth40G <--> SW_2_8.ethg[14];
        SW_3_8.ethg[0] <--> Eth40G <--> SW_1_1.ethg[15];
        SW_3_8.ethg[1] <--> Eth40G <--> SW_1_2.ethg[15];
        SW_3_8.ethg[2] <--> Eth40G <--> SW_1_3.ethg[15];
        SW_3_8.ethg[3] <--> Eth40G <--> SW_1_4.ethg[15];
        SW_3_8.ethg[4] <--> Eth40G <--> SW_1_5.ethg[15];
        SW_3_8.ethg[5] <--> Eth40G <--> SW_1_6.ethg[15];
        SW_3_8.ethg[6] <--> Eth40G <--> SW_1_7.ethg[15];
        SW_3_8.ethg[7] <--> Eth40G <--> SW_1_8.ethg[15];
        SW_3_8.ethg[8] <--> Eth40G <--> SW_2_1.ethg[15];
        SW_3_8.ethg[9] <--> Eth40G <--> SW_2_2.ethg[15];
        SW_3_8.ethg[10] <--> Eth40G <--> SW_2_3.ethg[15];
        SW_3_8.ethg[11] <--> Eth40G <--> SW_2_4.ethg[15];
        SW_3_8.ethg[12] <--> Eth40G <--> SW_2_5.ethg[15];
        SW_3_8.ethg[13] <--> Eth40G <--> SW_2_6.ethg[15];
        SW_3_8.ethg[14] <--> Eth40G <--> SW_2_7.ethg[15];
        SW_3_8.ethg[15] <--> Eth40G <--> SW_2_8.ethg[15];
}
