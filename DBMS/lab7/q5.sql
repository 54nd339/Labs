set serveroutput on;
DECLARE
    n number;

BEGIN
    n:=&n;
    IF(MOD(n,100)=0) THEN
        DBMS_OUTPUT.PUT_LINE('multiple of 100');
    ELSE
        DBMS_OUTPUT.PUT_LINE('not a multiple of 100');
    END IF;
END;
/