sum=0
for i in {1..20}
do
    sum=$(($sum+$i))
done
echo "$sum"