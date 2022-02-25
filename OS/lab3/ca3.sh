read -p "Enter a no. : " x
sum=0
for (( i=1; i<=x ; i++))
do
    sum=$(($sum+$i))
done
echo "$sum"