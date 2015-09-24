<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="a" />
        <signal name="b" />
        <signal name="c" />
        <signal name="s" />
        <signal name="t" />
        <port polarity="Input" name="a" />
        <port polarity="Input" name="b" />
        <port polarity="Input" name="c" />
        <port polarity="Output" name="s" />
        <port polarity="Output" name="t" />
        <blockdef name="circuit1">
            <timestamp>2015-9-23T7:44:2</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <blockdef name="circuit2">
            <timestamp>2015-9-23T7:45:13</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
        </blockdef>
        <block symbolname="circuit1" name="XLXI_1">
            <blockpin signalname="a" name="a" />
            <blockpin signalname="b" name="b" />
            <blockpin signalname="c" name="c" />
            <blockpin signalname="s" name="s" />
        </block>
        <block symbolname="circuit2" name="XLXI_2">
            <blockpin signalname="a" name="a" />
            <blockpin signalname="b" name="b" />
            <blockpin signalname="c" name="c" />
            <blockpin signalname="t" name="s" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="a">
            <wire x2="448" y1="784" y2="1024" x1="448" />
            <wire x2="992" y1="1024" y2="1024" x1="448" />
            <wire x2="448" y1="1024" y2="1600" x1="448" />
            <wire x2="448" y1="1600" y2="2064" x1="448" />
            <wire x2="448" y1="2064" y2="2080" x1="448" />
            <wire x2="992" y1="1600" y2="1600" x1="448" />
        </branch>
        <branch name="b">
            <wire x2="656" y1="784" y2="1088" x1="656" />
            <wire x2="992" y1="1088" y2="1088" x1="656" />
            <wire x2="656" y1="1088" y2="1664" x1="656" />
            <wire x2="992" y1="1664" y2="1664" x1="656" />
            <wire x2="656" y1="1664" y2="1728" x1="656" />
            <wire x2="656" y1="1728" y2="2096" x1="656" />
        </branch>
        <branch name="c">
            <wire x2="864" y1="784" y2="1152" x1="864" />
            <wire x2="992" y1="1152" y2="1152" x1="864" />
            <wire x2="864" y1="1152" y2="1728" x1="864" />
            <wire x2="864" y1="1728" y2="2080" x1="864" />
            <wire x2="992" y1="1728" y2="1728" x1="864" />
        </branch>
        <instance x="992" y="1184" name="XLXI_1" orien="R0">
        </instance>
        <instance x="992" y="1760" name="XLXI_2" orien="R0">
        </instance>
        <iomarker fontsize="28" x="448" y="784" name="a" orien="R270" />
        <iomarker fontsize="28" x="656" y="784" name="b" orien="R270" />
        <iomarker fontsize="28" x="864" y="784" name="c" orien="R270" />
        <branch name="s">
            <wire x2="1760" y1="1024" y2="1024" x1="1376" />
        </branch>
        <branch name="t">
            <wire x2="1760" y1="1600" y2="1600" x1="1376" />
        </branch>
        <iomarker fontsize="28" x="1760" y="1024" name="s" orien="R0" />
        <iomarker fontsize="28" x="1760" y="1600" name="t" orien="R0" />
    </sheet>
</drawing>