read -p "Enter No. of elements : " n
echo "Enter Array elements : "
for ((i=0; i<n; i++))
do
    read arr[$i]
done
echo "Original array is: ${arr[*]}";

first=0; second=-1;
for (( i = 1; i < $n; i++ ))
do
    if [[ ${arr[$i]} -gt ${arr[$first]} ]];
    then
        second=$first;
        first=$i;
    elif [[ ${arr[$i]} -lt ${arr[$first]} ]];
    then
        if [[ $second -eq -1 || ${arr[$second]} -lt ${arr[$i]} ]]
        then
            second=$i;
        fi
    fi
done

if [[ $second -eq -1 ]];
then
    echo "Second Largest didn't exist";
else
    echo "Second largest : " ${arr[$second]}
fi