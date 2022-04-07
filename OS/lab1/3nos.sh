read -p "Enter 3 nos. : " a b c
if [ $a -ge $b -a $a -ge $c ]
then
	echo "$a is the largest number."
elif [ $b -ge $c ]
then
	echo "$b is the largest number."
else
	echo "$c is the largest number."
fi