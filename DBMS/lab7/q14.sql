set serveroutput on;
DECLARE 
    n NUMBER; 
    temp NUMBER; 
    r NUMBER; 

BEGIN 
    n := &n; 
    temp := 0; 
    WHILE (n>0) LOOP 
        r := MOD(n, 10); 
        temp := temp + r; 
        n := TRUNC(n / 10); 
    END LOOP; 
    DBMS_OUTPUT.PUT_LINE('sum of digits = '|| temp); 
END; 
/