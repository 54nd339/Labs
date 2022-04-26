set serveroutput on;
DECLARE 
   case1 string(20) := 'Sandeep' ;
   
BEGIN  
   dbms_output.put_line('ORIGINAL TEST : '|| case1);
   dbms_output.put_line(UPPER(case1)); 
   dbms_output.put_line(LOWER(case1));
END;
/