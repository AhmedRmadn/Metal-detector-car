LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY DSD IS
PORT(
    bluetooth : IN std_logic_Vector(1 DOWNTo 0);
    prox : IN std_logic;
    ultra : IN std_logic;
    motors : OUT std_logic_Vector(3 DOWNTo 0);
    buzzer: OUT std_logic);
END DSD;
ARCHITECTURE arch OF DSD IS
BEGIN
PROCESS(bluetooth,prox,ultra)
BEGIN
IF bluetooth = "00" THEN motors <= "0000" ;
ELSIF prox = '0' AND bluetooth = "01" THEN motors <= "0110" ;
ELSIF prox = '0' AND bluetooth = "10" THEN motors <= "1001" ;
ELSIF prox = '0' AND ultra = '0' AND bluetooth = "11" THEN motors <= "0101" ;
ELSIF prox = '0' AND ultra = '1' AND bluetooth = "11" THEN motors <= "0000" ;
ELSIF prox = '1' OR ultra = '1' THEN motors <= "0000" ;
END IF;
buzzer <= prox ;
END PROCESS;
END arch;