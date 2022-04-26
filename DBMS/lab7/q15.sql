set serveroutput on;
DECLARE
    n NUMBER;
    m NUMBER;
    temp NUMBER:=0;
    rem NUMBER;

BEGIN
    n:=&n;
    m:=n;
    WHILE n>0 LOOP
        rem:=MOD(n,10);
        temp:=(temp*10)+rem;
        n:=TRUNC(n/10);
    END LOOP; 
    IF (m = temp)
    THEN
        DBMS_OUTPUT.PUT_LINE('IT IS PALLINDROME');
    ELSE
        DBMS_OUTPUT.PUT_LINE('NOT A PALLINDROME');
    END IF;
END;
/