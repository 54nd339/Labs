set serveroutput on;
declare
    a NUMBER;
    b NUMBER;
    c NUMBER;
begin
    a:=&a;
    b:=&b;
    dbms_output.Put_line('BEFORE SWAP : a = ' ||a|| ', b = ' ||b);

    c:=a;
    a:=b;
    b:=c;
    dbms_output.Put_line('AFTER SWAP : a = ' ||a|| ', b = ' ||b);
end;
/