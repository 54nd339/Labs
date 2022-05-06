set serveroutput on;
DECLARE
	n1 NUMBER;
	n2 NUMBER;
	n3 NUMBER;
	n4 NUMBER;
	n5 NUMBER;
	S NUMBER;
	A NUMBER;

BEGIN
	n1 := &n1;
	n2 := &n2;
	n3 := &n3;
	n4 := &n4;
	n5 := &n5;
	S := n1 + n2 + n3 + n4 + n5; 
	A := S / 5;
	DBMS_OUTPUT.PUT_LINE('SUM : '||S);
	DBMS_OUTPUT.PUT_LINE('AVG : '||A);
END; 
/