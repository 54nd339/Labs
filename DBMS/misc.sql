set serveroutput on FORMAT WRAPPED;
declare
    n number;
    i number;
    j number;
begin
    n:=&n;
    for i in 1..n loop
        for j in 1..n-i loop
            dbms_output.put('  ');
        end loop;
        for j in 1..i loop
            dbms_output.put('* ');
        end loop;
        dbms_output.new_line;
    end loop;

    for i in 1..n-1 loop
        for j in 1..i loop
            dbms_output.put('  ');
        end loop;
        for j in 1..n-i loop
            dbms_output.put('* ');
        end loop;
        dbms_output.new_line;
    end loop;
end;
/