read -p "Enter No. of elements : " n
echo "Enter Array elements : "
sum=0;
for ((i=0; i<n; i++))
do
    read arr[$i]
    sum=$(($sum+${arr[$i]}))
done
echo "Original array is: ${arr[*]}";

flag=1;
for (( i = 0; i < $n-1; i++ ))
do
    flag=0;
    for ((j = 0; j < $n-1-$i; j++ ))
    do
        if [[ ${arr[$j]} -gt ${arr[$j+1]} ]]
        then
            temp=${arr[$j]};
            arr[$j]=${arr[$j+1]};
            arr[$j+1]=$temp;
            flag=1;
        fi
    done

    if [[ $flag -eq 0 ]]; then
        break;
    fi
done

mean=$(($sum/$n))
echo "Mean : $mean"
if [[ $(($n%2)) -ne 0 ]];
then
    median=${arr[$n/2]};
else
    sum=$(( ${arr[$(($n-1))/2]} + ${arr[$(($n-1))/2+1]} ))
    median=$(echo "scale=2; $sum/2" | bc)
fi
echo "Median : $median"
sum=0
for ((i=0; i<n; i++))
do
    temp=$(echo "$((${arr[$i]}-$mean))^2" | bc)
    sum=$(($sum+$temp))
done
sum=$(echo "scale=2; $sum/$n" | bc)
sd=$(echo "sqrt($sum)" | bc)
echo "Standard Deviation : $sd"