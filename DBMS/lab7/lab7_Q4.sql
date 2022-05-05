DECLARE
	n number(5);

BEGIN
	n := &n;
	IF(n >= 18) THEN
		DBMS_OUTPUT.PUT_LINE('eligible');
	ELSE
		DBMS_OUTPUT.PUT_LINE('not eligible');
	END IF;
END;
/