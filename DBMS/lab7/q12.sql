set serveroutput on;
DECLARE
   NUM NUMBER;
   I NUMBER;
BEGIN
   NUM := &NUM;
   FOR I IN 1 ..NUM LOOP 
      IF(MOD(I,2)!=0) THEN
         DBMS_OUTPUT.PUT_LINE(I);
      END IF;
   END LOOP;
END;
/    