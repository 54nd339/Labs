set serveroutput on;
declare
    a NUMBER;
    b NUMBER;
    c NUMBER;
begin
    a:=&a;
    b:=&b;
    dbms_output.Put_line('BEFORE SWAP :');
    dbms_output.Put_line('a = ' ||a);
    dbms_output.Put_line('b = ' ||b);

    c:=a;
    a:=b;
    b:=c;
    dbms_output.Put_line('AFTER SWAP :');
    dbms_output.Put_line('a = ' ||a);
    dbms_output.Put_line('b = ' ||b);
end;
/