--------------------------------------------------------------------------------
-- Copyright (c) 1995-2010 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 12.4
--  \   \         Application : sch2hdl
--  /   /         Filename : add4bits.vhf
-- /___/   /\     Timestamp : 09/30/2015 09:21:53
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan3e -flat -suppress -vhdl /home/l2/deplechin/Documents/Archi_tp/TP3_additionneurs/add4bits.vhf -w /home/l2/deplechin/Documents/Archi_tp/TP3_additionneurs/add4bits.sch
--Design Name: add4bits
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

entity half_add_MUSER_add4bits is
   port ( a : in    std_logic; 
          b : in    std_logic; 
          c : out   std_logic; 
          s : out   std_logic);
end half_add_MUSER_add4bits;

architecture BEHAVIORAL of half_add_MUSER_add4bits is
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

entity add1bit_MUSER_add4bits is
   port ( a    : in    std_logic; 
          b    : in    std_logic; 
          cin  : in    std_logic; 
          cout : out   std_logic; 
          s    : out   std_logic);
end add1bit_MUSER_add4bits;

architecture BEHAVIORAL of add1bit_MUSER_add4bits is
   attribute BOX_TYPE   : string ;
   signal XLXN_1 : std_logic;
   signal XLXN_5 : std_logic;
   signal XLXN_6 : std_logic;
   component half_add_MUSER_add4bits
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
   XLXI_1 : half_add_MUSER_add4bits
      port map (a=>a,
                b=>b,
                c=>XLXN_6,
                s=>XLXN_1);
   
   XLXI_2 : half_add_MUSER_add4bits
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

entity add4bits is
   port ( a    : in    std_logic_vector (3 downto 0); 
          b    : in    std_logic_vector (3 downto 0); 
          cout : out   std_logic; 
          s    : out   std_logic_vector (3 downto 0));
end add4bits;

architecture BEHAVIORAL of add4bits is
   signal XLXN_8  : std_logic;
   signal XLXN_9  : std_logic;
   signal XLXN_11 : std_logic;
   component half_add_MUSER_add4bits
      port ( a : in    std_logic; 
             b : in    std_logic; 
             s : out   std_logic; 
             c : out   std_logic);
   end component;
   
   component add1bit_MUSER_add4bits
      port ( a    : in    std_logic; 
             cin  : in    std_logic; 
             b    : in    std_logic; 
             cout : out   std_logic; 
             s    : out   std_logic);
   end component;
   
begin
   XLXI_1 : half_add_MUSER_add4bits
      port map (a=>a(0),
                b=>b(0),
                c=>XLXN_8,
                s=>s(0));
   
   XLXI_5 : add1bit_MUSER_add4bits
      port map (a=>a(1),
                b=>b(1),
                cin=>XLXN_8,
                cout=>XLXN_9,
                s=>s(1));
   
   XLXI_6 : add1bit_MUSER_add4bits
      port map (a=>a(2),
                b=>b(2),
                cin=>XLXN_9,
                cout=>XLXN_11,
                s=>s(2));
   
   XLXI_7 : add1bit_MUSER_add4bits
      port map (a=>a(3),
                b=>b(3),
                cin=>XLXN_11,
                cout=>cout,
                s=>s(3));
   
end BEHAVIORAL;


