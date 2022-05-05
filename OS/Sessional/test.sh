read -p "Enter no. : " x
sum=0
for ((i=1; i<=x; i++))
do
    sum=$(($sum + $i))
    echo -n "$sum "
done
