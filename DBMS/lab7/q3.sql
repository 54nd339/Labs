set serveroutput on;
DECLARE
    a int;
    cube int;
    sqr int;
BEGIN
    a:=&a;
    sqr:= a*a;
    cube:= sqr*a;
    dbms_output.put_line('The square of the number is ' || sqr);
    dbms_output.put_line('The Cube of the number is '||cube);
END;
/