DECLARE
	n number(5);

BEGIN
	n:=&n;
	IF(MOD(n, 2) = 0) THEN
		DBMS_OUTPUT.PUT_LINE('even');
	ELSE
		DBMS_OUTPUT.PUT_LINE('odd');
	END IF;
END;
/