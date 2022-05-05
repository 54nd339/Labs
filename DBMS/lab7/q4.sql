set serveroutput on;
DECLARE
    n number(2);

BEGIN
    n:=&n;
    IF(n>=18) THEN
        DBMS_OUTPUT.PUT_LINE('ELIGIBLE TO VOTE');
    ELSE
        DBMS_OUTPUT.PUT_LINE('NOT ELIGIBLE TO VOTE');
    END IF;
END;
/