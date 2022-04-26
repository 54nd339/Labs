set serveroutput on;
DECLARE
    n NUMBER;

BEGIN
    SELECT AVG(sal) INTO n FROM employee;
    DBMS_OUTPUT.PUT_LINE('Average= ' || n);
END;
/