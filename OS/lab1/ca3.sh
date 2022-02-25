read -p "Enter 2 binary values : " x y
if [ $x -eq 1 ] && [ $y -eq 1 ]
then
	echo "BOTH ARE TRUE"
else
	echo "BOTH ARE NOT TRUE"
fi

if [ $x -eq 1 ] || [ $y -eq 1 ]
then
	echo "EITHER OF THEN ARE TRUE"
else
	echo "NONE ARE TRUE"
fi

if [ ! $x -eq 0 ]
then
	echo "$x IS TRUE"
else
	echo "$x IS FALSE"
fi
