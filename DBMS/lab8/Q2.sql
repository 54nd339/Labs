set serveroutput on;
DECLARE
	rowaff number(4);
BEGIN 
	UPDATE emp_cursor SET salary=salary*1.15 WHERE dept_no='D05';
	rowaff:= SQL%rowcount;
	IF rowaff>0 THEN 
		DBMS_OUTPUT.PUT_LINE(rowaff||' modified');
	ELSE
		DBMS_OUTPUT.PUT_LINE('no employee in D05');
	END IF;
END;
/