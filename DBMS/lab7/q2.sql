set serveroutput on;
DECLARE 
    a NUMBER; 
    b NUMBER; 
    c NUMBER; 
    d NUMBER;
    e NUMBER;    
    sum5 NUMBER; 
    avg5 NUMBER;   
BEGIN 
    a:=&a;
    b:=&b;
    c:=&c;
    d:=&d;
    e:=&e;
    sum5 := a + b + c + d + e; 
    avg5 := sum5 / 5; 
    dbms_output.Put_line('Sum = ' ||sum5); 
    dbms_output.Put_line('Average = ' ||avg5); 
END;
/