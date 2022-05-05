DECLARE
	CURSOR CSR IS SELECT emp_id,salary FROM EMP_CURSOR
		WHERE dept_no='D05';
BEGIN
	FOR i IN CSR
	LOOP
		UPDATE EMP_CURSOR SET salary=i.salary*1.1
		WHERE emp_id=i.emp_id;
		INSERT INTO Emp_raise VALUES(i.emp_id, SYSDATE, i.salary*0.1);
	END LOOP;
	COMMIT;
END;
/