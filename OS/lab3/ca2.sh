sum=0
for i in {2..20..2}
do
    #echo "$i"
    sum=$(($sum+$i))
done
echo "$sum"