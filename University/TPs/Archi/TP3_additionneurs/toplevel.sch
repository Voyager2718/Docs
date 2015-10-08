<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="switches(7:0)" />
        <signal name="myled(7:0)">
        </signal>
        <signal name="myled(7:5)" />
        <signal name="myled(3:0)" />
        <signal name="myled(4)" />
        <signal name="switches(7:4)" />
        <signal name="switches(3:0)" />
        <signal name="led(7:0)" />
        <signal name="XLXN_25(3:0)" />
        <signal name="sevenseg(6:0)" />
        <signal name="anodes(3:0)" />
        <signal name="XLXN_28(3:0)" />
        <port polarity="Input" name="switches(7:0)" />
        <port polarity="Output" name="led(7:0)" />
        <port polarity="Output" name="sevenseg(6:0)" />
        <port polarity="Output" name="anodes(3:0)" />
        <blockdef name="constant">
            <timestamp>2006-1-1T10:10:10</timestamp>
            <rect width="112" x="0" y="0" height="64" />
            <line x2="112" y1="32" y2="32" x1="144" />
        </blockdef>
        <blockdef name="add4bits">
            <timestamp>2015-9-30T7:24:31</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="x7seg">
            <timestamp>2015-9-16T7:31:48</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="obuf8">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <rect width="64" x="0" y="-44" height="24" />
            <rect width="96" x="128" y="-44" height="24" />
        </blockdef>
        <block symbolname="constant" name="XLXI_4">
            <attr value="000" name="CValue">
                <trait delete="all:1 sym:0" />
                <trait editname="all:1 sch:0" />
                <trait valuetype="BitVector 3 Binary" />
            </attr>
            <blockpin signalname="myled(7:5)" name="O" />
        </block>
        <block symbolname="add4bits" name="XLXI_7">
            <blockpin signalname="switches(7:4)" name="b(3:0)" />
            <blockpin signalname="switches(3:0)" name="a(3:0)" />
            <blockpin signalname="myled(3:0)" name="s(3:0)" />
            <blockpin signalname="myled(4)" name="cout" />
        </block>
        <block symbolname="x7seg" name="XLXI_8">
            <blockpin signalname="myled(3:0)" name="sw(3:0)" />
            <blockpin signalname="sevenseg(6:0)" name="sevenseg(6:0)" />
            <blockpin signalname="anodes(3:0)" name="anodes(3:0)" />
        </block>
        <block symbolname="obuf8" name="XLXI_9">
            <blockpin signalname="myled(7:0)" name="I(7:0)" />
            <blockpin signalname="led(7:0)" name="O(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="switches(7:0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1168" y="1632" type="branch" />
            <wire x2="1168" y1="608" y2="1296" x1="1168" />
            <wire x2="1168" y1="1296" y2="1360" x1="1168" />
            <wire x2="1168" y1="1360" y2="1632" x1="1168" />
            <wire x2="1168" y1="1632" y2="1808" x1="1168" />
        </branch>
        <branch name="myled(7:0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="2144" y="1456" type="branch" />
            <wire x2="2144" y1="1152" y2="1296" x1="2144" />
            <wire x2="2144" y1="1296" y2="1360" x1="2144" />
            <wire x2="2144" y1="1360" y2="1456" x1="2144" />
            <wire x2="2144" y1="1456" y2="1712" x1="2144" />
            <wire x2="2144" y1="1712" y2="1792" x1="2144" />
        </branch>
        <instance x="1776" y="1680" name="XLXI_4" orien="R0">
        </instance>
        <bustap x2="2048" y1="1712" y2="1712" x1="2144" />
        <branch name="myled(7:5)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1984" y="1712" type="branch" />
            <wire x2="1984" y1="1712" y2="1712" x1="1920" />
            <wire x2="2048" y1="1712" y2="1712" x1="1984" />
        </branch>
        <bustap x2="2048" y1="1296" y2="1296" x1="2144" />
        <bustap x2="2048" y1="1360" y2="1360" x1="2144" />
        <branch name="myled(4)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="2032" y="1360" type="branch" />
            <wire x2="2032" y1="1360" y2="1360" x1="1760" />
            <wire x2="2048" y1="1360" y2="1360" x1="2032" />
        </branch>
        <bustap x2="1264" y1="1296" y2="1296" x1="1168" />
        <branch name="switches(7:4)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1280" y="1296" type="branch" />
            <wire x2="1280" y1="1296" y2="1296" x1="1264" />
            <wire x2="1376" y1="1296" y2="1296" x1="1280" />
        </branch>
        <bustap x2="1264" y1="1360" y2="1360" x1="1168" />
        <branch name="switches(3:0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1280" y="1360" type="branch" />
            <wire x2="1280" y1="1360" y2="1360" x1="1264" />
            <wire x2="1376" y1="1360" y2="1360" x1="1280" />
        </branch>
        <instance x="2176" y="1152" name="XLXI_9" orien="R270" />
        <branch name="led(7:0)">
            <wire x2="2144" y1="608" y2="928" x1="2144" />
        </branch>
        <iomarker fontsize="28" x="1168" y="608" name="switches(7:0)" orien="R270" />
        <iomarker fontsize="28" x="2144" y="608" name="led(7:0)" orien="R270" />
        <instance x="1376" y="1392" name="XLXI_7" orien="R0">
        </instance>
        <branch name="myled(3:0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="2032" y="1296" type="branch" />
            <wire x2="1376" y1="752" y2="752" x1="1296" />
            <wire x2="1296" y1="752" y2="928" x1="1296" />
            <wire x2="1904" y1="928" y2="928" x1="1296" />
            <wire x2="1904" y1="928" y2="1296" x1="1904" />
            <wire x2="2032" y1="1296" y2="1296" x1="1904" />
            <wire x2="2048" y1="1296" y2="1296" x1="2032" />
            <wire x2="1904" y1="1296" y2="1296" x1="1760" />
        </branch>
        <instance x="1376" y="848" name="XLXI_8" orien="R0">
        </instance>
        <branch name="sevenseg(6:0)">
            <wire x2="1888" y1="752" y2="752" x1="1760" />
        </branch>
        <branch name="anodes(3:0)">
            <wire x2="1888" y1="816" y2="816" x1="1760" />
        </branch>
        <iomarker fontsize="28" x="1888" y="752" name="sevenseg(6:0)" orien="R0" />
        <iomarker fontsize="28" x="1888" y="816" name="anodes(3:0)" orien="R0" />
    </sheet>
</drawing>