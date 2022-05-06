set serveroutput on;
DECLARE
	n INTEGER;
	sq INTEGER;
	cb INTEGER;

BEGIN
	n := &n;
	sq := n * n;
	cb := sq * n;
	DBMS_OUTPUT.PUT_LINE('Square of '||n||' is '||sq);
	DBMS_OUTPUT.PUT_LINE('Cube of '||n||' is '||cb);
END;
/