set serveroutput on;
DECLARE
   NUM NUMBER;
   SUMM NUMBER := 0;
   I NUMBER;

BEGIN
   NUM := &NUM;
   FOR I IN 1 ..NUM
   LOOP
      SUMM := SUMM + I;
   END LOOP;
   DBMS_OUTPUT.PUT_LINE ('Sum = ' || SUMM);
END;
/