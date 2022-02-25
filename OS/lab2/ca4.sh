read -p "Enter 3 sides : " a b c
if [ $(( $a + $b )) -gt $c -a $(( $b + $c )) -gt $a -a $(( $c + $a )) -gt $b ]
then
	echo "It is a valid triangle"
	s=$((($a+$b+$c)/2))
	n=$(($s*($s-$a)*($s-$b)*($s-$c)))
	a=$(echo "sqrt($n)" | bc)
	echo "Area :" $a
else
	echo "It is not a valid triangle"
fi
