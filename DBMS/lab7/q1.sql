set serveroutput on;
DECLARE 
    x NUMBER; 
    y NUMBER; 
    z NUMBER; 

BEGIN 
    x:=&x;
    y:=&y;
    z:=&z;

    IF (x>y) and (x>z) THEN
        DBMS_OUTPUT.PUT_LINE(x||' IS LARGEST');
    ELSIF (y>x) and (y>z) THEN
        DBMS_OUTPUT.PUT_LINE(y||' IS LARGEST');
    ELSE
        DBMS_OUTPUT.PUT_LINE(z||' IS LARGEST');
    END IF;
END;
/