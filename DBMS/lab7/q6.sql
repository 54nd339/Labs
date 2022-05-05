set serveroutput on;
DECLARE 
    x NUMBER; 
    y NUMBER; 
    z NUMBER; 
    p NUMBER;

BEGIN 
    x:=&x;
    y:=&y;
    z:=&z;
    p:=&p;
    IF(x<y) and (x<z) THEN
        IF(x<p) THEN
            DBMS_OUTPUT.PUT_LINE(x||' IS SMALLEST');
        ELSE
            DBMS_OUTPUT.PUT_LINE(p||' IS SMALLEST');
        END IF;
    ELSIF(y<x) and (y<z) THEN
        IF(y<p) THEN
            DBMS_OUTPUT.PUT_LINE(y||' IS SMALLEST');
        ELSE
            DBMS_OUTPUT.PUT_LINE(p||' IS SMALLEST');
        END IF;
    ELSE
        IF (z<p) THEN
            DBMS_OUTPUT.PUT_LINE(z||' IS SMALLEST');
        ELSE
            DBMS_OUTPUT.PUT_LINE(p||' IS SMALLEST');
        END IF;
    END IF;
END;
/