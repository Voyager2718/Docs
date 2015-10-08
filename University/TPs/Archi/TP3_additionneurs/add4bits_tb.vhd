-- Vhdl test bench created from schematic /home/l2/deplechin/Documents/Archi_tp/TP3_additionneurs/add4bits.sch - Wed Sep 30 09:10:31 2015
--
-- Notes: 
-- 1) This testbench template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the unit under test.
-- Xilinx recommends that these types always be used for the top-level
-- I/O of a design in order to guarantee that the testbench will bind
-- correctly to the timing (post-route) simulation model.
-- 2) To use this template as your testbench, change the filename to any
-- name of your choice with the extension .vhd, and use the "Source->Add"
-- menu in Project Navigator to import the testbench. Then
-- edit the user defined section below, adding code to generate the 
-- stimulus for your design.
--
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
LIBRARY UNISIM;
USE UNISIM.Vcomponents.ALL;
ENTITY add4bits_add4bits_sch_tb IS
END add4bits_add4bits_sch_tb;
ARCHITECTURE behavioral OF add4bits_add4bits_sch_tb IS 

   COMPONENT add4bits
   PORT( 
	b : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
   a : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
   s : OUT STD_LOGIC_VECTOR (3 DOWNTO 0);
   cout : OUT STD_LOGIC
	);
   END COMPONENT;

SIGNAL b : STD_LOGIC_VECTOR (3 DOWNTO 0);
SIGNAL a : STD_LOGIC_VECTOR (3 DOWNTO 0);
SIGNAL s : STD_LOGIC_VECTOR (3 DOWNTO 0);
SIGNAL cout : STD_LOGIC;

BEGIN

   UUT: add4bits PORT MAP(
		b => b,
		a => a,
		s => s,
		cout => cout
   );

-- *** Test Bench - User Defined Section ***
   tb : PROCESS
   BEGIN
		a<= "0100";
		b<= "1101";
      WAIT for 200 ns;
		a<=x"5";
		b<=x"8";
		WAIT for 200 ns;
		a<=x"0";
		b<=x"0";
		WAIT for 200 ns;
		a<=x"1";
		b<="0110";
		WAIT for 200 ns;
		a<=x"B";
		b<=x"4";
   END PROCESS;
-- *** End Test Bench - User Defined Section ***

END;
