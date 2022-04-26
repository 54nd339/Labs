set serveroutput on;
DECLARE
    a NUMBER;
    b NUMBER;
    s NUMBER:=0;
BEGIN
    a:=&a;
    b:=&b;
    WHILE (b!=0) LOOP
        s:=s+a;
        b:=b-1;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(s);
END;
/