<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="XLXN_4" />
        <signal name="a" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="b" />
        <signal name="c" />
        <signal name="s" />
        <port polarity="Input" name="a" />
        <port polarity="Input" name="b" />
        <port polarity="Input" name="c" />
        <port polarity="Output" name="s" />
        <blockdef name="nand2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="nand2" name="XLXI_1">
            <blockpin signalname="XLXN_4" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_2">
            <blockpin signalname="XLXN_3" name="I0" />
            <blockpin signalname="XLXN_2" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_3">
            <blockpin signalname="c" name="I0" />
            <blockpin signalname="b" name="I1" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="b" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_5">
            <blockpin signalname="c" name="I" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_6">
            <blockpin signalname="XLXN_7" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="s" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1456" y="624" name="XLXI_1" orien="R0" />
        <instance x="1136" y="848" name="XLXI_2" orien="R0" />
        <instance x="1472" y="1040" name="XLXI_3" orien="R0" />
        <instance x="848" y="816" name="XLXI_5" orien="R0" />
        <instance x="848" y="752" name="XLXI_4" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="1136" y1="720" y2="720" x1="1072" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="1136" y1="784" y2="784" x1="1072" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="1424" y1="752" y2="752" x1="1392" />
            <wire x2="1424" y1="560" y2="752" x1="1424" />
            <wire x2="1456" y1="560" y2="560" x1="1424" />
        </branch>
        <branch name="a">
            <wire x2="1456" y1="496" y2="496" x1="672" />
        </branch>
        <instance x="1904" y="800" name="XLXI_6" orien="R0" />
        <branch name="XLXN_6">
            <wire x2="1808" y1="528" y2="528" x1="1712" />
            <wire x2="1808" y1="528" y2="672" x1="1808" />
            <wire x2="1904" y1="672" y2="672" x1="1808" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1808" y1="944" y2="944" x1="1728" />
            <wire x2="1808" y1="736" y2="944" x1="1808" />
            <wire x2="1904" y1="736" y2="736" x1="1808" />
        </branch>
        <branch name="b">
            <wire x2="832" y1="720" y2="720" x1="672" />
            <wire x2="848" y1="720" y2="720" x1="832" />
            <wire x2="832" y1="720" y2="912" x1="832" />
            <wire x2="1472" y1="912" y2="912" x1="832" />
        </branch>
        <branch name="c">
            <wire x2="752" y1="784" y2="784" x1="672" />
            <wire x2="848" y1="784" y2="784" x1="752" />
            <wire x2="752" y1="784" y2="976" x1="752" />
            <wire x2="1472" y1="976" y2="976" x1="752" />
        </branch>
        <iomarker fontsize="28" x="672" y="496" name="a" orien="R180" />
        <iomarker fontsize="28" x="672" y="784" name="c" orien="R180" />
        <branch name="s">
            <wire x2="2192" y1="704" y2="704" x1="2160" />
        </branch>
        <iomarker fontsize="28" x="2192" y="704" name="s" orien="R0" />
        <iomarker fontsize="28" x="672" y="720" name="b" orien="R180" />
    </sheet>
</drawing>