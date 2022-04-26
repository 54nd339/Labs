DECLARE
	CURSOR CSR IS SELECT emp_name,dept_no,salary FROM EMP_CURSOR
		ORDER BY salary DESC;
	vname EMP_CURSOR.emp_name%TYPE;
	vdept EMP_CURSOR.dept_no%TYPE;
	vsal EMP_CURSOR.salary%TYPE;
BEGIN
	OPEN CSR;
	LOOP
		FETCH CSR INTO vname,vdept,vsal;
		EXIT WHEN CSR%ROWCOUNT=4 OR CSR%NOTFOUND;
		DBMS_OUTPUT.PUT_LINE(vname||' '||vdept||' '||vsal);
	END LOOP;
	CLOSE CSR;
END;
/