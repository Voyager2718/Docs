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
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="s0" />
        <signal name="s1" />
        <signal name="s2" />
        <signal name="s3" />
        <signal name="s4" />
        <signal name="s5" />
        <signal name="s6" />
        <port polarity="Input" name="a" />
        <port polarity="Input" name="b" />
        <port polarity="Output" name="s0" />
        <port polarity="Output" name="s1" />
        <port polarity="Output" name="s2" />
        <port polarity="Output" name="s3" />
        <port polarity="Output" name="s4" />
        <port polarity="Output" name="s5" />
        <port polarity="Output" name="s6" />
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
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
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <blockdef name="xnor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
            <circle r="8" cx="220" cy="-96" />
            <line x2="256" y1="-96" y2="-96" x1="228" />
            <line x2="60" y1="-28" y2="-28" x1="60" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="s0" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_3">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="s2" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_4">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="s3" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_5">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="s4" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_6">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="s6" name="O" />
        </block>
        <block symbolname="xnor2" name="XLXI_7">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="s5" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_8">
            <blockpin signalname="a" name="I" />
            <blockpin signalname="s1" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="a">
            <wire x2="976" y1="720" y2="1136" x1="976" />
            <wire x2="1456" y1="1136" y2="1136" x1="976" />
            <wire x2="976" y1="1136" y2="1312" x1="976" />
            <wire x2="976" y1="1312" y2="1440" x1="976" />
            <wire x2="1456" y1="1440" y2="1440" x1="976" />
            <wire x2="976" y1="1440" y2="1648" x1="976" />
            <wire x2="1472" y1="1648" y2="1648" x1="976" />
            <wire x2="976" y1="1648" y2="1840" x1="976" />
            <wire x2="1472" y1="1840" y2="1840" x1="976" />
            <wire x2="976" y1="1840" y2="2048" x1="976" />
            <wire x2="1472" y1="2048" y2="2048" x1="976" />
            <wire x2="976" y1="2048" y2="2256" x1="976" />
            <wire x2="976" y1="2256" y2="2416" x1="976" />
            <wire x2="1472" y1="2256" y2="2256" x1="976" />
            <wire x2="1456" y1="1312" y2="1312" x1="976" />
        </branch>
        <iomarker fontsize="28" x="976" y="720" name="a" orien="R270" />
        <iomarker fontsize="28" x="1200" y="720" name="b" orien="R270" />
        <instance x="1456" y="1568" name="XLXI_3" orien="R0" />
        <instance x="1472" y="1776" name="XLXI_4" orien="R0" />
        <instance x="1472" y="1968" name="XLXI_5" orien="R0" />
        <instance x="1472" y="2176" name="XLXI_7" orien="R0" />
        <instance x="1456" y="1264" name="XLXI_1" orien="R0" />
        <branch name="b">
            <wire x2="1200" y1="720" y2="1200" x1="1200" />
            <wire x2="1200" y1="1200" y2="1504" x1="1200" />
            <wire x2="1200" y1="1504" y2="1712" x1="1200" />
            <wire x2="1200" y1="1712" y2="1904" x1="1200" />
            <wire x2="1200" y1="1904" y2="2112" x1="1200" />
            <wire x2="1200" y1="2112" y2="2320" x1="1200" />
            <wire x2="1200" y1="2320" y2="2416" x1="1200" />
            <wire x2="1472" y1="2320" y2="2320" x1="1200" />
            <wire x2="1472" y1="2112" y2="2112" x1="1200" />
            <wire x2="1472" y1="1904" y2="1904" x1="1200" />
            <wire x2="1472" y1="1712" y2="1712" x1="1200" />
            <wire x2="1456" y1="1504" y2="1504" x1="1200" />
            <wire x2="1456" y1="1200" y2="1200" x1="1200" />
        </branch>
        <instance x="1472" y="2384" name="XLXI_6" orien="R0" />
        <instance x="1456" y="1344" name="XLXI_8" orien="R0" />
        <branch name="s0">
            <wire x2="1840" y1="1168" y2="1168" x1="1712" />
        </branch>
        <branch name="s1">
            <wire x2="1840" y1="1312" y2="1312" x1="1680" />
        </branch>
        <branch name="s2">
            <wire x2="1840" y1="1472" y2="1472" x1="1712" />
        </branch>
        <branch name="s3">
            <wire x2="1840" y1="1680" y2="1680" x1="1728" />
        </branch>
        <branch name="s4">
            <wire x2="1840" y1="1872" y2="1872" x1="1728" />
        </branch>
        <branch name="s5">
            <wire x2="1840" y1="2080" y2="2080" x1="1728" />
        </branch>
        <branch name="s6">
            <wire x2="1840" y1="2288" y2="2288" x1="1728" />
        </branch>
        <iomarker fontsize="28" x="1840" y="1168" name="s0" orien="R0" />
        <iomarker fontsize="28" x="1840" y="1312" name="s1" orien="R0" />
        <iomarker fontsize="28" x="1840" y="1472" name="s2" orien="R0" />
        <iomarker fontsize="28" x="1840" y="1680" name="s3" orien="R0" />
        <iomarker fontsize="28" x="1840" y="1872" name="s4" orien="R0" />
        <iomarker fontsize="28" x="1840" y="2080" name="s5" orien="R0" />
        <iomarker fontsize="28" x="1840" y="2288" name="s6" orien="R0" />
    </sheet>
</drawing>