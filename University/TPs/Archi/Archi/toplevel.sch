<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="data(7:0)" />
        <signal name="sevenseg(6:0)" />
        <signal name="anodes(3:0)" />
        <signal name="XLXN_4(6:0)" />
        <signal name="data(3:0)" />
        <signal name="switches(7:0)" />
        <signal name="XLXN_10" />
        <signal name="led(7:0)" />
        <port polarity="Output" name="sevenseg(6:0)" />
        <port polarity="Output" name="anodes(3:0)" />
        <port polarity="Input" name="switches(7:0)" />
        <port polarity="Output" name="led(7:0)" />
        <blockdef name="ibuf8">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="96" x="128" y="-44" height="24" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
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
        <blockdef name="x7seg">
            <timestamp>2015-9-23T6:56:46</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="x7seg" name="XLXI_4">
            <blockpin signalname="data(3:0)" name="sw(3:0)" />
            <blockpin signalname="sevenseg(6:0)" name="sevenseg(6:0)" />
            <blockpin signalname="anodes(3:0)" name="anodes(3:0)" />
        </block>
        <block symbolname="ibuf8" name="XLXI_1">
            <blockpin signalname="switches(7:0)" name="I(7:0)" />
            <blockpin signalname="data(7:0)" name="O(7:0)" />
        </block>
        <block symbolname="obuf8" name="XLXI_3">
            <blockpin signalname="data(7:0)" name="I(7:0)" />
            <blockpin signalname="led(7:0)" name="O(7:0)" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="data(7:0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1056" y="1200" type="branch" />
            <wire x2="1056" y1="1200" y2="1200" x1="784" />
            <wire x2="1072" y1="1200" y2="1200" x1="1056" />
            <wire x2="1216" y1="1200" y2="1200" x1="1072" />
        </branch>
        <branch name="sevenseg(6:0)">
            <wire x2="2192" y1="1504" y2="1504" x1="1648" />
            <wire x2="2208" y1="1504" y2="1504" x1="2192" />
        </branch>
        <branch name="anodes(3:0)">
            <wire x2="2192" y1="1568" y2="1568" x1="1648" />
            <wire x2="2208" y1="1568" y2="1568" x1="2192" />
        </branch>
        <instance x="1264" y="1600" name="XLXI_4" orien="R0">
        </instance>
        <iomarker fontsize="28" x="2208" y="1504" name="sevenseg(6:0)" orien="R0" />
        <iomarker fontsize="28" x="2208" y="1568" name="anodes(3:0)" orien="R0" />
        <branch name="data(3:0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1072" y="1392" type="branch" />
            <wire x2="1072" y1="1296" y2="1312" x1="1072" />
            <wire x2="1072" y1="1312" y2="1392" x1="1072" />
            <wire x2="1072" y1="1392" y2="1504" x1="1072" />
            <wire x2="1264" y1="1504" y2="1504" x1="1072" />
        </branch>
        <instance x="560" y="1232" name="XLXI_1" orien="R0" />
        <branch name="switches(7:0)">
            <wire x2="544" y1="1200" y2="1200" x1="496" />
            <wire x2="560" y1="1200" y2="1200" x1="544" />
        </branch>
        <bustap x2="1072" y1="1200" y2="1296" x1="1072" />
        <branch name="led(7:0)">
            <wire x2="1456" y1="1200" y2="1200" x1="1440" />
            <wire x2="1504" y1="1200" y2="1200" x1="1456" />
        </branch>
        <instance x="1216" y="1232" name="XLXI_3" orien="R0" />
        <iomarker fontsize="28" x="1504" y="1200" name="led(7:0)" orien="R0" />
        <iomarker fontsize="28" x="496" y="1200" name="switches(7:0)" orien="R180" />
    </sheet>
</drawing>