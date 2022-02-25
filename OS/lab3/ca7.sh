read -p "Enter a number : " x
ans=0
for (( i=1; i<=$(($x/2)); i++))
do
    if [[ $(( $x % $i)) -eq 0  ]]
    then
        ans=$(($ans+$i))
    fi
done

if [ $x -eq $ans ]
then
    echo "$x is perfect"
else
    echo "$x is NOT perfect"
fi
