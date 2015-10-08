<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="cout" />
        <signal name="a" />
        <signal name="cin" />
        <signal name="s" />
        <signal name="b" />
        <port polarity="Output" name="cout" />
        <port polarity="Input" name="a" />
        <port polarity="Input" name="cin" />
        <port polarity="Output" name="s" />
        <port polarity="Input" name="b" />
        <blockdef name="half_add">
            <timestamp>2015-9-30T6:23:15</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <block symbolname="half_add" name="XLXI_1">
            <blockpin signalname="a" name="a" />
            <blockpin signalname="b" name="b" />
            <blockpin signalname="XLXN_1" name="s" />
            <blockpin signalname="XLXN_6" name="c" />
        </block>
        <block symbolname="half_add" name="XLXI_2">
            <blockpin signalname="XLXN_1" name="a" />
            <blockpin signalname="cin" name="b" />
            <blockpin signalname="s" name="s" />
            <blockpin signalname="XLXN_5" name="c" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="XLXN_6" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="cout" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1104" y="1216" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1728" y="1424" name="XLXI_2" orien="R0">
        </instance>
        <branch name="XLXN_1">
            <wire x2="1632" y1="1120" y2="1120" x1="1488" />
            <wire x2="1632" y1="1120" y2="1328" x1="1632" />
            <wire x2="1728" y1="1328" y2="1328" x1="1632" />
        </branch>
        <instance x="2368" y="1648" name="XLXI_3" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="2240" y1="1392" y2="1392" x1="2112" />
            <wire x2="2240" y1="1392" y2="1520" x1="2240" />
            <wire x2="2368" y1="1520" y2="1520" x1="2240" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1568" y1="1184" y2="1184" x1="1488" />
            <wire x2="1568" y1="1184" y2="1584" x1="1568" />
            <wire x2="2368" y1="1584" y2="1584" x1="1568" />
        </branch>
        <branch name="cout">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="2672" y="1552" type="branch" />
            <wire x2="2672" y1="1552" y2="1552" x1="2624" />
            <wire x2="2736" y1="1552" y2="1552" x1="2672" />
        </branch>
        <branch name="a">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1072" y="1120" type="branch" />
            <wire x2="1072" y1="1120" y2="1120" x1="928" />
            <wire x2="1104" y1="1120" y2="1120" x1="1072" />
        </branch>
        <branch name="b">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1072" y="1184" type="branch" />
            <wire x2="1072" y1="1184" y2="1184" x1="928" />
            <wire x2="1104" y1="1184" y2="1184" x1="1072" />
        </branch>
        <branch name="cin">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1168" y="1392" type="branch" />
            <wire x2="1168" y1="1392" y2="1392" x1="928" />
            <wire x2="1728" y1="1392" y2="1392" x1="1168" />
        </branch>
        <branch name="s">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="2656" y="1328" type="branch" />
            <wire x2="2144" y1="1328" y2="1328" x1="2112" />
            <wire x2="2656" y1="1328" y2="1328" x1="2144" />
            <wire x2="2736" y1="1328" y2="1328" x1="2656" />
        </branch>
        <iomarker fontsize="28" x="2736" y="1552" name="cout" orien="R0" />
        <iomarker fontsize="28" x="928" y="1120" name="a" orien="R180" />
        <iomarker fontsize="28" x="928" y="1184" name="b" orien="R180" />
        <iomarker fontsize="28" x="928" y="1392" name="cin" orien="R180" />
        <iomarker fontsize="28" x="2736" y="1328" name="s" orien="R0" />
    </sheet>
</drawing>