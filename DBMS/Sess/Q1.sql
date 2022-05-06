set serveroutput on;
DECLARE
    n NUMBER;

BEGIN
    n:=&n;
    IF MOD(n, 400)=0
    AND
    MOD(n, 100)!=0
    OR
    MOD(n, 4)=0 THEN
        dbms_output.Put_line(n||' is a leap year ');
    ELSE
        dbms_output.Put_line(n||' is not a leap year.');
    END IF;
END;
/