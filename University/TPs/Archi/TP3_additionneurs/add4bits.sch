<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan3e" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="s(3:0)" />
        <signal name="b(3:0)" />
        <signal name="a(3:0)" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="cout" />
        <signal name="a(3)" />
        <signal name="a(2)" />
        <signal name="a(1)" />
        <signal name="a(0)" />
        <signal name="b(3)" />
        <signal name="b(2)" />
        <signal name="b(1)" />
        <signal name="b(0)" />
        <signal name="s(3)" />
        <signal name="s(2)" />
        <signal name="s(1)" />
        <signal name="s(0)" />
        <port polarity="Output" name="s(3:0)" />
        <port polarity="Input" name="b(3:0)" />
        <port polarity="Input" name="a(3:0)" />
        <port polarity="Output" name="cout" />
        <blockdef name="half_add">
            <timestamp>2015-9-30T6:23:15</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="add1bit">
            <timestamp>2015-9-30T6:49:30</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="half_add" name="XLXI_1">
            <blockpin signalname="a(0)" name="a" />
            <blockpin signalname="b(0)" name="b" />
            <blockpin signalname="s(0)" name="s" />
            <blockpin signalname="XLXN_8" name="c" />
        </block>
        <block symbolname="add1bit" name="XLXI_5">
            <blockpin signalname="a(1)" name="a" />
            <blockpin signalname="XLXN_8" name="cin" />
            <blockpin signalname="b(1)" name="b" />
            <blockpin signalname="XLXN_9" name="cout" />
            <blockpin signalname="s(1)" name="s" />
        </block>
        <block symbolname="add1bit" name="XLXI_6">
            <blockpin signalname="a(2)" name="a" />
            <blockpin signalname="XLXN_9" name="cin" />
            <blockpin signalname="b(2)" name="b" />
            <blockpin signalname="XLXN_11" name="cout" />
            <blockpin signalname="s(2)" name="s" />
        </block>
        <block symbolname="add1bit" name="XLXI_7">
            <blockpin signalname="a(3)" name="a" />
            <blockpin signalname="XLXN_11" name="cin" />
            <blockpin signalname="b(3)" name="b" />
            <blockpin signalname="cout" name="cout" />
            <blockpin signalname="s(3)" name="s" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1440" y="1104" name="XLXI_1" orien="R0">
        </instance>
        <branch name="s(3:0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="2080" y="928" type="branch" />
            <wire x2="2080" y1="896" y2="912" x1="2080" />
            <wire x2="2080" y1="912" y2="928" x1="2080" />
            <wire x2="2080" y1="928" y2="1008" x1="2080" />
            <wire x2="2080" y1="1008" y2="1264" x1="2080" />
            <wire x2="2080" y1="1264" y2="1600" x1="2080" />
            <wire x2="2080" y1="1600" y2="1936" x1="2080" />
            <wire x2="2080" y1="1936" y2="2240" x1="2080" />
        </branch>
        <branch name="b(3:0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1248" y="944" type="branch" />
            <wire x2="1248" y1="896" y2="944" x1="1248" />
            <wire x2="1248" y1="944" y2="1072" x1="1248" />
            <wire x2="1248" y1="1072" y2="1264" x1="1248" />
            <wire x2="1248" y1="1264" y2="1600" x1="1248" />
            <wire x2="1248" y1="1600" y2="1936" x1="1248" />
            <wire x2="1248" y1="1936" y2="2256" x1="1248" />
        </branch>
        <branch name="a(3:0)">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1120" y="944" type="branch" />
            <wire x2="1120" y1="896" y2="944" x1="1120" />
            <wire x2="1120" y1="944" y2="1008" x1="1120" />
            <wire x2="1120" y1="1008" y2="1392" x1="1120" />
            <wire x2="1120" y1="1392" y2="1728" x1="1120" />
            <wire x2="1120" y1="1728" y2="2064" x1="1120" />
            <wire x2="1120" y1="2064" y2="2256" x1="1120" />
        </branch>
        <iomarker fontsize="28" x="2080" y="896" name="s(3:0)" orien="R270" />
        <iomarker fontsize="28" x="1248" y="896" name="b(3:0)" orien="R270" />
        <iomarker fontsize="28" x="1120" y="896" name="a(3:0)" orien="R270" />
        <instance x="1440" y="1232" name="XLXI_5" orien="M180">
        </instance>
        <instance x="1440" y="1568" name="XLXI_6" orien="M180">
        </instance>
        <instance x="1440" y="1904" name="XLXI_7" orien="M180">
        </instance>
        <branch name="XLXN_8">
            <wire x2="1360" y1="1168" y2="1328" x1="1360" />
            <wire x2="1440" y1="1328" y2="1328" x1="1360" />
            <wire x2="1840" y1="1168" y2="1168" x1="1360" />
            <wire x2="1840" y1="1072" y2="1072" x1="1824" />
            <wire x2="1840" y1="1072" y2="1168" x1="1840" />
        </branch>
        <branch name="XLXN_9">
            <wire x2="1360" y1="1504" y2="1664" x1="1360" />
            <wire x2="1440" y1="1664" y2="1664" x1="1360" />
            <wire x2="1904" y1="1504" y2="1504" x1="1360" />
            <wire x2="1904" y1="1392" y2="1392" x1="1824" />
            <wire x2="1904" y1="1392" y2="1504" x1="1904" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="1376" y1="1840" y2="2000" x1="1376" />
            <wire x2="1440" y1="2000" y2="2000" x1="1376" />
            <wire x2="1856" y1="1840" y2="1840" x1="1376" />
            <wire x2="1840" y1="1728" y2="1728" x1="1824" />
            <wire x2="1856" y1="1728" y2="1728" x1="1840" />
            <wire x2="1856" y1="1728" y2="1840" x1="1856" />
        </branch>
        <branch name="cout">
            <attrtext style="alignment:SOFT-TVCENTER" attrname="Name" x="1936" y="2160" type="branch" />
            <wire x2="1936" y1="2064" y2="2064" x1="1824" />
            <wire x2="1936" y1="2064" y2="2160" x1="1936" />
            <wire x2="1936" y1="2160" y2="2240" x1="1936" />
        </branch>
        <iomarker fontsize="28" x="1936" y="2240" name="cout" orien="R90" />
        <bustap x2="1216" y1="2064" y2="2064" x1="1120" />
        <branch name="a(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1328" y="2064" type="branch" />
            <wire x2="1328" y1="2064" y2="2064" x1="1216" />
            <wire x2="1440" y1="2064" y2="2064" x1="1328" />
        </branch>
        <bustap x2="1216" y1="1728" y2="1728" x1="1120" />
        <branch name="a(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1328" y="1728" type="branch" />
            <wire x2="1328" y1="1728" y2="1728" x1="1216" />
            <wire x2="1440" y1="1728" y2="1728" x1="1328" />
        </branch>
        <bustap x2="1216" y1="1392" y2="1392" x1="1120" />
        <branch name="a(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1328" y="1392" type="branch" />
            <wire x2="1328" y1="1392" y2="1392" x1="1216" />
            <wire x2="1440" y1="1392" y2="1392" x1="1328" />
        </branch>
        <bustap x2="1216" y1="1008" y2="1008" x1="1120" />
        <branch name="a(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1328" y="1008" type="branch" />
            <wire x2="1328" y1="1008" y2="1008" x1="1216" />
            <wire x2="1440" y1="1008" y2="1008" x1="1328" />
        </branch>
        <bustap x2="1344" y1="1936" y2="1936" x1="1248" />
        <branch name="b(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1392" y="1936" type="branch" />
            <wire x2="1392" y1="1936" y2="1936" x1="1344" />
            <wire x2="1440" y1="1936" y2="1936" x1="1392" />
        </branch>
        <bustap x2="1344" y1="1600" y2="1600" x1="1248" />
        <branch name="b(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1392" y="1600" type="branch" />
            <wire x2="1392" y1="1600" y2="1600" x1="1344" />
            <wire x2="1440" y1="1600" y2="1600" x1="1392" />
        </branch>
        <bustap x2="1344" y1="1264" y2="1264" x1="1248" />
        <branch name="b(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1392" y="1264" type="branch" />
            <wire x2="1392" y1="1264" y2="1264" x1="1344" />
            <wire x2="1440" y1="1264" y2="1264" x1="1392" />
        </branch>
        <bustap x2="1344" y1="1072" y2="1072" x1="1248" />
        <branch name="b(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1392" y="1072" type="branch" />
            <wire x2="1392" y1="1072" y2="1072" x1="1344" />
            <wire x2="1440" y1="1072" y2="1072" x1="1392" />
        </branch>
        <bustap x2="1984" y1="1936" y2="1936" x1="2080" />
        <branch name="s(3)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1904" y="1936" type="branch" />
            <wire x2="1904" y1="1936" y2="1936" x1="1824" />
            <wire x2="1984" y1="1936" y2="1936" x1="1904" />
        </branch>
        <bustap x2="1984" y1="1600" y2="1600" x1="2080" />
        <branch name="s(2)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1904" y="1600" type="branch" />
            <wire x2="1904" y1="1600" y2="1600" x1="1824" />
            <wire x2="1984" y1="1600" y2="1600" x1="1904" />
        </branch>
        <bustap x2="1984" y1="1264" y2="1264" x1="2080" />
        <branch name="s(1)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1904" y="1264" type="branch" />
            <wire x2="1904" y1="1264" y2="1264" x1="1824" />
            <wire x2="1984" y1="1264" y2="1264" x1="1904" />
        </branch>
        <bustap x2="1984" y1="1008" y2="1008" x1="2080" />
        <branch name="s(0)">
            <attrtext style="alignment:SOFT-BCENTER" attrname="Name" x="1904" y="1008" type="branch" />
            <wire x2="1904" y1="1008" y2="1008" x1="1824" />
            <wire x2="1984" y1="1008" y2="1008" x1="1904" />
        </branch>
    </sheet>
</drawing>