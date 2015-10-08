--------------------------------------------------------------------------------
-- Copyright (c) 1995-2010 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 12.4
--  \   \         Application : sch2hdl
--  /   /         Filename : toplevel.vhf
-- /___/   /\     Timestamp : 09/30/2015 09:57:17
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3e -flat -suppress -vhdl /home/l2/deplechin/Documents/Archi_tp/TP3_additionneurs/toplevel.vhf -w /home/l2/deplechin/Documents/Archi_tp/TP3_additionneurs/toplevel.sch
--Design Name: toplevel
--Device: spartan3e
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--

library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity OBUF8_MXILINX_toplevel is
   port ( I : in    std_logic_vector (7 downto 0); 
          O : out   std_logic_vector (7 downto 0));
end OBUF8_MXILINX_toplevel;

architecture BEHAVIORAL of OBUF8_MXILINX_toplevel is
   attribute IOSTANDARD : string ;
   attribute SLEW       : string ;
   attribute DRIVE      : string ;
   attribute BOX_TYPE   : string ;
   component OBUF
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute IOSTANDARD of OBUF : component is "DEFAULT";
   attribute SLEW of OBUF : component is "SLOW";
   attribute DRIVE of OBUF : component is "12";
   attribute BOX_TYPE of OBUF : component is "BLACK_BOX";
   
begin
   I_36_30 : OBUF
      port map (I=>I(0),
                O=>O(0));
   
   I_36_31 : OBUF
      port map (I=>I(1),
                O=>O(1));
   
   I_36_32 : OBUF
      port map (I=>I(2),
                O=>O(2));
   
   I_36_33 : OBUF
      port map (I=>I(3),
                O=>O(3));
   
   I_36_34 : OBUF
      port map (I=>I(7),
                O=>O(7));
   
   I_36_35 : OBUF
      port map (I=>I(6),
                O=>O(6));
   
   I_36_36 : OBUF
      port map (I=>I(5),
                O=>O(5));
   
   I_36_37 : OBUF
      port map (I=>I(4),
                O=>O(4));
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity half_add_MUSER_toplevel is
   port ( a : in    std_logic; 
          b : in    std_logic; 
          c : out   std_logic; 
          s : out   std_logic);
end half_add_MUSER_toplevel;

architecture BEHAVIORAL of half_add_MUSER_toplevel is
   attribute BOX_TYPE   : string ;
   component AND2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of AND2 : component is "BLACK_BOX";
   
   component XOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XOR2 : component is "BLACK_BOX";
   
begin
   XLXI_1 : AND2
      port map (I0=>b,
                I1=>a,
                O=>c);
   
   XLXI_2 : XOR2
      port map (I0=>b,
                I1=>a,
                O=>s);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity add1bit_MUSER_toplevel is
   port ( a    : in    std_logic; 
          b    : in    std_logic; 
          cin  : in    std_logic; 
          cout : out   std_logic; 
          s    : out   std_logic);
end add1bit_MUSER_toplevel;

architecture BEHAVIORAL of add1bit_MUSER_toplevel is
   attribute BOX_TYPE   : string ;
   signal XLXN_1 : std_logic;
   signal XLXN_5 : std_logic;
   signal XLXN_6 : std_logic;
   component half_add_MUSER_toplevel
      port ( a : in    std_logic; 
             b : in    std_logic; 
             s : out   std_logic; 
             c : out   std_logic);
   end component;
   
   component OR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of OR2 : component is "BLACK_BOX";
   
begin
   XLXI_1 : half_add_MUSER_toplevel
      port map (a=>a,
                b=>b,
                c=>XLXN_6,
                s=>XLXN_1);
   
   XLXI_2 : half_add_MUSER_toplevel
      port map (a=>XLXN_1,
                b=>cin,
                c=>XLXN_5,
                s=>s);
   
   XLXI_3 : OR2
      port map (I0=>XLXN_6,
                I1=>XLXN_5,
                O=>cout);
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity add4bits_MUSER_toplevel is
   port ( a    : in    std_logic_vector (3 downto 0); 
          b    : in    std_logic_vector (3 downto 0); 
          cout : out   std_logic; 
          s    : out   std_logic_vector (3 downto 0));
end add4bits_MUSER_toplevel;

architecture BEHAVIORAL of add4bits_MUSER_toplevel is
   signal XLXN_8  : std_logic;
   signal XLXN_9  : std_logic;
   signal XLXN_11 : std_logic;
   component half_add_MUSER_toplevel
      port ( a : in    std_logic; 
             b : in    std_logic; 
             s : out   std_logic; 
             c : out   std_logic);
   end component;
   
   component add1bit_MUSER_toplevel
      port ( a    : in    std_logic; 
             cin  : in    std_logic; 
             b    : in    std_logic; 
             cout : out   std_logic; 
             s    : out   std_logic);
   end component;
   
begin
   XLXI_1 : half_add_MUSER_toplevel
      port map (a=>a(0),
                b=>b(0),
                c=>XLXN_8,
                s=>s(0));
   
   XLXI_5 : add1bit_MUSER_toplevel
      port map (a=>a(1),
                b=>b(1),
                cin=>XLXN_8,
                cout=>XLXN_9,
                s=>s(1));
   
   XLXI_6 : add1bit_MUSER_toplevel
      port map (a=>a(2),
                b=>b(2),
                cin=>XLXN_9,
                cout=>XLXN_11,
                s=>s(2));
   
   XLXI_7 : add1bit_MUSER_toplevel
      port map (a=>a(3),
                b=>b(3),
                cin=>XLXN_11,
                cout=>cout,
                s=>s(3));
   
end BEHAVIORAL;



library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity toplevel is
   port ( switches : in    std_logic_vector (7 downto 0); 
          anodes   : out   std_logic_vector (3 downto 0); 
          led      : out   std_logic_vector (7 downto 0); 
          sevenseg : out   std_logic_vector (6 downto 0));
end toplevel;

architecture BEHAVIORAL of toplevel is
   attribute HU_SET     : string ;
   signal myled    : std_logic_vector (7 downto 0);
   component add4bits_MUSER_toplevel
      port ( b    : in    std_logic_vector (3 downto 0); 
             a    : in    std_logic_vector (3 downto 0); 
             s    : out   std_logic_vector (3 downto 0); 
             cout : out   std_logic);
   end component;
   
   component x7seg
      port ( sw       : in    std_logic_vector (3 downto 0); 
             sevenseg : out   std_logic_vector (6 downto 0); 
             anodes   : out   std_logic_vector (3 downto 0));
   end component;
   
   component OBUF8_MXILINX_toplevel
      port ( I : in    std_logic_vector (7 downto 0); 
             O : out   std_logic_vector (7 downto 0));
   end component;
   
   attribute HU_SET of XLXI_9 : label is "XLXI_9_0";
begin
   myled(7 downto 5) <= b"000";
   XLXI_7 : add4bits_MUSER_toplevel
      port map (a(3 downto 0)=>switches(3 downto 0),
                b(3 downto 0)=>switches(7 downto 4),
                cout=>myled(4),
                s(3 downto 0)=>myled(3 downto 0));
   
   XLXI_8 : x7seg
      port map (sw(3 downto 0)=>myled(3 downto 0),
                anodes(3 downto 0)=>anodes(3 downto 0),
                sevenseg(6 downto 0)=>sevenseg(6 downto 0));
   
   XLXI_9 : OBUF8_MXILINX_toplevel
      port map (I(7 downto 0)=>myled(7 downto 0),
                O(7 downto 0)=>led(7 downto 0));
   
end BEHAVIORAL;


