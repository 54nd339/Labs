read -p "Enter No. of elements : " n
echo "Enter Array elements : "
for ((i=0; i<n; i++))
do
    read arr[$i]
done
echo "Original array is: ${arr[*]}";
j=0
for (( i = 0; i < $n; i++ ))
do
    if [[ $((${arr[$i]}%2)) -ne 0 ]]
    then
        if [[ $i -ne $j ]]
        then
            temp=${arr[$i]};
            arr[$i]=${arr[$j]};
            arr[$j]=$temp;
        fi
        j=$j+1
    fi
done
echo "Final array is: ${arr[*]}";