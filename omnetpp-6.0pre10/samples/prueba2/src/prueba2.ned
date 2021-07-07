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

package src;

import inet.linklayer.configurator.L2NetworkConfigurator;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.EthernetSwitch;
import inet.node.ethernet.EthernetHost;
import ned.DatarateChannel;
// TODO documentation



network Red
{
    @display("bgb=240000,100000;i=block/network2");
    types:

        channel cable extends DatarateChannel
        {
            datarate = 10Mbps;
            delay = 0.1us;
        }



    submodules:
        host1: EthernetHost {
            @display("p=2474.568,2399.581");
        }
        host2: EthernetHost {
            @display("p=5848.979,2399.581");
        }
        host3: EthernetHost {
            @display("p=9298.377,2399.581");
        }
        host4: EthernetHost {
            @display("p=12672.788,2399.581");
        }
        host5: EthernetHost {
            @display("p=16047.198,2399.581");
        }
        host6: EthernetHost {
            @display("p=19421.61,2399.581");
        }
        host7: EthernetHost {
            @display("p=22871.008,2399.581");
        }
        host8: EthernetHost {
            @display("p=26245.418,2399.581");
        }
        host9: EthernetHost {
            @display("p=31419.516,2399.581");
        }
        host10: EthernetHost {
            @display("p=34793.926,2399.581");
        }
        host11: EthernetHost {
            @display("p=38243.324,2399.581");
        }
        host12: EthernetHost {
            @display("p=41617.734,2399.581");
        }
        host13: EthernetHost {
            @display("p=44992.145,2399.581");
        }
        host14: EthernetHost {
            @display("p=48366.555,2399.581");
        }
        host15: EthernetHost {
            @display("p=51815.953,2399.581");
        }
        host16: EthernetHost {
            @display("p=55190.363,2399.581");
        }
        host17: EthernetHost {
            @display("p=60214.49,2399.581");
        }
        host18: EthernetHost {
            @display("p=63588.9,2399.581");
        }
        host19: EthernetHost {
            @display("p=67038.3,2399.581");
        }
        host20: EthernetHost {
            @display("p=70412.71,2399.581");
        }
        host21: EthernetHost {
            @display("p=73787.12,2399.581");
        }
        host22: EthernetHost {
            @display("p=77161.53,2399.581");
        }
        host23: EthernetHost {
            @display("p=80610.93,2399.581");
        }
        host24: EthernetHost {
            @display("p=83985.336,2399.581");
        }
        host25: EthernetHost {
            @display("p=89159.44,2399.581");
        }
        host26: EthernetHost {
            @display("p=92533.84,2399.581");
        }
        host27: EthernetHost {
            @display("p=95983.24,2399.581");
        }
        host28: EthernetHost {
            @display("p=99357.66,2399.581");
        }
        host29: EthernetHost {
            @display("p=102732.06,2399.581");
        }
        host30: EthernetHost {
            @display("p=106106.48,2399.581");
        }
        host31: EthernetHost {
            @display("p=109555.875,2399.581");
        }
        host32: EthernetHost {
            @display("p=112930.28,2399.581");
        }
        host33: EthernetHost {
            @display("p=118629.29,2399.581");
        }
        host34: EthernetHost {
            @display("p=122003.7,2399.581");
        }
        host35: EthernetHost {
            @display("p=125453.1,2399.581");
        }
        host36: EthernetHost {
            @display("p=128827.51,2399.581");
        }
        host37: EthernetHost {
            @display("p=132201.92,2399.581");
        }
        host38: EthernetHost {
            @display("p=135576.33,2399.581");
        }
        host39: EthernetHost {
            @display("p=139025.73,2399.581");
        }
        host40: EthernetHost {
            @display("p=142400.14,2399.581");
        }
        host41: EthernetHost {
            @display("p=147574.23,2399.581");
        }
        host42: EthernetHost {
            @display("p=150948.64,2399.581");
        }
        host43: EthernetHost {
            @display("p=154398.05,2399.581");
        }
        host44: EthernetHost {
            @display("p=157772.45,2399.581");
        }
        host45: EthernetHost {
            @display("p=161146.88,2399.581");
        }
        host46: EthernetHost {
            @display("p=164521.28,2399.581");
        }
        host47: EthernetHost {
            @display("p=167970.67,2399.581");
        }
        host48: EthernetHost {
            @display("p=171345.1,2399.581");
        }
        host49: EthernetHost {
            @display("p=178393.86,2399.581");
        }
        host50: EthernetHost {
            @display("p=181693.28,2399.581");
        }
        host51: EthernetHost {
            @display("p=185217.67,2399.581");
        }
        host52: EthernetHost {
            @display("p=188592.08,2399.581");
        }
        host53: EthernetHost {
            @display("p=191891.5,2399.581");
        }
        host54: EthernetHost {
            @display("p=195340.89,2399.581");
        }
        host55: EthernetHost {
            @display("p=198790.3,2399.581");
        }
        host56: EthernetHost {
            @display("p=202164.7,2399.581");
        }
        host57: EthernetHost {
            @display("p=207338.8,2399.581");
        }
        host58: EthernetHost {
            @display("p=210638.23,2399.581");
        }
        host59: EthernetHost {
            @display("p=214162.61,2399.581");
        }
        host60: EthernetHost {
            @display("p=217537.02,2399.581");
        }
        host61: EthernetHost {
            @display("p=220911.44,2399.581");
        }
        host62: EthernetHost {
            @display("p=224285.84,2399.581");
        }
        host63: EthernetHost {
            @display("p=227735.25,2399.581");
        }
        host64: EthernetHost {
            @display("p=231109.66,2399.581");
        }
        host65: EthernetHost {
            @display("p=2474.568,46716.844");
        }
        host66: EthernetHost {
            @display("p=5699.005,46716.844");
        }
        host67: EthernetHost {
            @display("p=9298.377,46716.844");
        }
        host68: EthernetHost {
            @display("p=12672.788,46716.844");
        }
        host69: EthernetHost {
            @display("p=15972.212,46716.844");
        }
        host70: EthernetHost {
            @display("p=19421.61,46716.844");
        }
        host71: EthernetHost {
            @display("p=22871.008,46716.844");
        }
        host72: EthernetHost {
            @display("p=26245.418,46716.844");
        }
        host73: EthernetHost {
            @display("p=31419.516,46716.844");
        }
        host74: EthernetHost {
            @display("p=34643.953,46716.844");
        }
        host75: EthernetHost {
            @display("p=38243.324,46716.844");
        }
        host76: EthernetHost {
            @display("p=41617.734,46716.844");
        }
        host77: EthernetHost {
            @display("p=44992.145,46716.844");
        }
        host78: EthernetHost {
            @display("p=48366.555,46716.844");
        }
        host79: EthernetHost {
            @display("p=51815.953,46716.844");
        }
        host80: EthernetHost {
            @display("p=55190.363,46716.844");
        }
        host81: EthernetHost {
            @display("p=60214.49,46716.844");
        }
        host82: EthernetHost {
            @display("p=63438.926,46716.844");
        }
        host83: EthernetHost {
            @display("p=67038.3,46716.844");
        }
        host84: EthernetHost {
            @display("p=70412.71,46716.844");
        }
        host85: EthernetHost {
            @display("p=73712.13,46716.844");
        }
        host86: EthernetHost {
            @display("p=77161.53,46716.844");
        }
        host87: EthernetHost {
            @display("p=80610.93,46716.844");
        }
        host88: EthernetHost {
            @display("p=83985.336,46716.844");
        }
        host89: EthernetHost {
            @display("p=89159.44,46716.844");
        }
        host90: EthernetHost {
            @display("p=92383.875,46716.844");
        }
        host91: EthernetHost {
            @display("p=95983.24,46716.844");
        }
        host92: EthernetHost {
            @display("p=99357.66,46716.844");
        }
        host93: EthernetHost {
            @display("p=102732.06,46716.844");
        }
        host94: EthernetHost {
            @display("p=106106.48,46716.844");
        }
        host95: EthernetHost {
            @display("p=109555.875,46716.844");
        }
        host96: EthernetHost {
            @display("p=112930.28,46716.844");
        }
        host97: EthernetHost {
            @display("p=118629.29,46716.844");
        }
        host98: EthernetHost {
            @display("p=121853.73,46716.844");
        }
        host99: EthernetHost {
            @display("p=125453.1,46716.844");
        }
        host100: EthernetHost {
            @display("p=128827.51,46716.844");
        }
        host101: EthernetHost {
            @display("p=132126.94,46716.844");
        }
        host102: EthernetHost {
            @display("p=135576.33,46716.844");
        }
        host103: EthernetHost {
            @display("p=139025.73,46716.844");
        }
        host104: EthernetHost {
            @display("p=142400.14,46716.844");
        }
        host105: EthernetHost {
            @display("p=147574.23,46716.844");
        }
        host106: EthernetHost {
            @display("p=150798.67,46716.844");
        }
        host107: EthernetHost {
            @display("p=154398.05,46716.844");
        }
        host108: EthernetHost {
            @display("p=157772.45,46716.844");
        }
        host109: EthernetHost {
            @display("p=161146.88,46716.844");
        }
        host110: EthernetHost {
            @display("p=164521.28,46716.844");
        }
        host111: EthernetHost {
            @display("p=167970.67,46716.844");
        }
        host112: EthernetHost {
            @display("p=171345.1,46716.844");
        }
        host113: EthernetHost {
            @display("p=177943.94,46716.844");
        }
        host114: EthernetHost {
            @display("p=181168.38,46716.844");
        }
        host115: EthernetHost {
            @display("p=184767.75,46716.844");
        }
        host116: EthernetHost {
            @display("p=188142.16,46716.844");
        }
        host117: EthernetHost {
            @display("p=191441.58,46716.844");
        }
        host118: EthernetHost {
            @display("p=194890.97,46716.844");
        }
        host119: EthernetHost {
            @display("p=198340.38,46716.844");
        }
        host120: EthernetHost {
            @display("p=201714.78,46716.844");
        }
        host121: EthernetHost {
            @display("p=206888.88,46716.844");
        }
        host122: EthernetHost {
            @display("p=210113.31,46716.844");
        }
        host123: EthernetHost {
            @display("p=213712.69,46716.844");
        }
        host124: EthernetHost {
            @display("p=217087.1,46716.844");
        }
        host125: EthernetHost {
            @display("p=220461.52,46716.844");
        }
        host126: EthernetHost {
            @display("p=223835.92,46716.844");
        }
        host127: EthernetHost {
            @display("p=227285.33,46716.844");
        }
        host128: EthernetHost {
            @display("p=230659.73,46716.844");
        }
        switch1: EthernetSwitch {
            @display("p=13122.709,11173.05");
            gates:
                ethg[16];
        }
        switch2: EthernetSwitch {
            @display("p=41167.812,11173.05");
            gates:
                ethg[16];
        }
        switch3: EthernetSwitch {
            @display("p=69962.79,11173.05");
            gates:
                ethg[16];
        }
        switch4: EthernetSwitch {
            @display("p=100857.39,11697.958");
            gates:
                ethg[16];
        }
        switch5: EthernetSwitch {
            @display("p=128827.51,11173.05");
            gates:
                ethg[16];
        }
        switch6: EthernetSwitch {
            @display("p=158222.38,11173.05");
            gates:
                ethg[16];
        }
        switch7: EthernetSwitch {
            @display("p=188592.08,11173.05");
            gates:
                ethg[16];
        }
        switch8: EthernetSwitch {
            @display("p=220461.52,11697.958");
            gates:
                ethg[16];
        }
        switch9: EthernetSwitch {
            @display("p=13122.709,38543.27");
            gates:
                ethg[16];
        }
        switch10: EthernetSwitch {
            @display("p=41167.812,38543.27");
            gates:
                ethg[16];
        }
        switch11: EthernetSwitch {
            @display("p=70412.71,38543.27");
            gates:
                ethg[16];
        }
        switch12: EthernetSwitch {
            @display("p=100857.39,38543.27");
            gates:
                ethg[16];
        }
        switch13: EthernetSwitch {
            @display("p=128827.51,38543.27");
            gates:
                ethg[16];
        }
        switch14: EthernetSwitch {
            @display("p=157772.45,38543.27");
            gates:
                ethg[16];
        }
        switch15: EthernetSwitch {
            @display("p=189042,38018.363");
            gates:
                ethg[16];
        }
        switch16: EthernetSwitch {
            @display("p=220911.44,38543.27");
            gates:
                ethg[16];
        }
        switch17: EthernetSwitch {
            @display("p=13122.709,23770.85");
            gates:
                ethg[16];
        }
        switch18: EthernetSwitch {
            @display("p=41167.812,23770.85");
            gates:
                ethg[16];
        }
        switch19: EthernetSwitch {
            @display("p=69962.79,23770.85");
            gates:
                ethg[16];
        }
        switch20: EthernetSwitch {
            @display("p=98007.89,23770.85");
            gates:
                ethg[16];
        }
        switch21: EthernetSwitch {
            @display("p=128827.51,23770.85");
            gates:
                ethg[16];
        }
        switch22: EthernetSwitch {
            @display("p=158222.38,23770.85");
            gates:
                ethg[16];
        }
        switch23: EthernetSwitch {
            @display("p=189042,23245.941");
            gates:
                ethg[16];
        }
        switch24: EthernetSwitch {
            @display("p=220911.44,23770.85");
            gates:
                ethg[16];
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=30600.51,80701.34");
        }
        l2NetworkConfigurator: L2NetworkConfigurator {
            @display("p=73501.23,80701.34");
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
        switch11.ethg[4] <--> cable <--> host85.ethg;
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
