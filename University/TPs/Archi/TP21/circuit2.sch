<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="a" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="b" />
        <signal name="c" />
        <signal name="s" />
        <port polarity="Input" name="a" />
        <port polarity="Input" name="b" />
        <port polarity="Input" name="c" />
        <port polarity="Output" name="s" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="nor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
        </blockdef>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="c" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_5">
            <blockpin signalname="b" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_7">
            <blockpin signalname="XLXN_2" name="I0" />
            <blockpin signalname="XLXN_1" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_10">
            <blockpin signalname="XLXN_3" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_11">
            <blockpin signalname="c" name="I0" />
            <blockpin signalname="b" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_12">
            <blockpin signalname="XLXN_6" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="s" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1216" y="1520" name="XLXI_4" orien="R0" />
        <instance x="1216" y="1456" name="XLXI_5" orien="R0" />
        <branch name="XLXN_1">
            <wire x2="1504" y1="1424" y2="1424" x1="1440" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1504" y1="1488" y2="1488" x1="1440" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="1792" y1="1456" y2="1456" x1="1760" />
            <wire x2="1792" y1="1264" y2="1456" x1="1792" />
            <wire x2="1824" y1="1264" y2="1264" x1="1792" />
        </branch>
        <branch name="a">
            <wire x2="1824" y1="1200" y2="1200" x1="1040" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="2176" y1="1232" y2="1232" x1="2080" />
            <wire x2="2176" y1="1232" y2="1376" x1="2176" />
            <wire x2="2272" y1="1376" y2="1376" x1="2176" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="2176" y1="1648" y2="1648" x1="2096" />
            <wire x2="2176" y1="1440" y2="1648" x1="2176" />
            <wire x2="2272" y1="1440" y2="1440" x1="2176" />
        </branch>
        <branch name="b">
            <wire x2="1200" y1="1424" y2="1424" x1="1040" />
            <wire x2="1216" y1="1424" y2="1424" x1="1200" />
            <wire x2="1200" y1="1424" y2="1616" x1="1200" />
            <wire x2="1840" y1="1616" y2="1616" x1="1200" />
        </branch>
        <branch name="c">
            <wire x2="1120" y1="1488" y2="1488" x1="1040" />
            <wire x2="1216" y1="1488" y2="1488" x1="1120" />
            <wire x2="1120" y1="1488" y2="1680" x1="1120" />
            <wire x2="1840" y1="1680" y2="1680" x1="1120" />
        </branch>
        <branch name="s">
            <wire x2="2560" y1="1408" y2="1408" x1="2528" />
        </branch>
        <iomarker fontsize="28" x="1040" y="1200" name="a" orien="R180" />
        <iomarker fontsize="28" x="1040" y="1488" name="c" orien="R180" />
        <iomarker fontsize="28" x="2560" y="1408" name="s" orien="R0" />
        <iomarker fontsize="28" x="1040" y="1424" name="b" orien="R180" />
        <instance x="1504" y="1552" name="XLXI_7" orien="R0" />
        <instance x="1824" y="1328" name="XLXI_10" orien="R0" />
        <instance x="1840" y="1744" name="XLXI_11" orien="R0" />
        <instance x="2272" y="1504" name="XLXI_12" orien="R0" />
    </sheet>
</drawing>