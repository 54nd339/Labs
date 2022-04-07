read -p "Enter a year : " y
if [ $(( $y % 4)) -eq 0 -a $(( $y % 100)) -ne 0 -o $(( $y % 400)) -eq 0 ]
then
	echo "$y is a leap year"
else
	echo "$y is not a leap year"
fi