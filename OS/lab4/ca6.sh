read -p "Enter No. of elements : " n
echo "Enter Array elements : "
for ((i=0; i<n; i++))
do
    read arr[$i]
done
echo "Original array is: ${arr[*]}";

for (( i = 0; $(($i+1)) < $n; i=$(($i+2)) ))
do
    temp=${arr[$i]};
    arr[$i]=${arr[$i+1]};
    arr[$i+1]=$temp;
done
echo "Final array is: ${arr[*]}";