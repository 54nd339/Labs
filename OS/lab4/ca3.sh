read -p "Enter No. of elements : " n
echo "Enter Array elements : "
for ((i=0; i<n; i++))
do
    read a[$i]
done
sum=0
for ((i=0; i<n; i++))
do
    sum=$(($sum+${a[$i]}))
done
echo "Sum : $sum"