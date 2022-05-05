set serveroutput on;
DECLARE
    n NUMBER;            
    i NUMBER;           
    temp NUMBER;          
BEGIN
    n := &n;                
    i := 2;
    temp := 1;
    FOR i IN 2..n/2 LOOP
        IF MOD(n, i) = 0 THEN
            temp := 0;
            EXIT;
        END IF;
    END LOOP;
    
    IF temp = 1 THEN
        DBMS_OUTPUT.PUT_LINE('IT IS PRIME NUMBER');
    ELSE
        DBMS_OUTPUT.PUT_LINE('NOT A PRIME NUMBER');
    END IF;
END;  
/