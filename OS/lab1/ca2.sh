read -p "Enter 2 nos. : " x y
if [ $x -gt $y ]
then
	echo "$x is greater than $y"
elif [ $x -eq $y ]
then
	echo "$x is equal to $y"
else
	echo "$x is lesser than $y"
fi
if [ 3 -ne 4 ]
then
	echo "3 not equals 4"
fi
if [ 4 -ge 3 ]
then
	echo "3 greater than equals 4"
fi
if [ 3 -le 4 ]
then
	echo "3 lesser than equals 4"
fi
