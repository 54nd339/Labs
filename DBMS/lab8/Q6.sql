DECLARE
	vname EMPLOYEE.ename%TYPE;
	vdesg EMPLOYEE.job%TYPE;
	did NUMBER(2);
	CURSOR empcr(dno EMPLOYEE.deptno%TYPE) IS SELECT
	ename, job FROM EMPLOYEE WHERE dno=deptno;
BEGIN
	did:=&did;
	OPEN empcr(did);
	DBMS_OUTPUT.PUT_LINE('Employee in dept '||did||' : ');
	LOOP
		FETCH empcr INTO vname, vdesg;
		EXIT WHEN empcr%NOTFOUND;
		DBMS_OUTPUT.PUT_LINE(vname||' '||vdesg);
	END LOOP;
	CLOSE empcr;
END;
/