read -p "Enter No. of elements : " n
echo "Enter Array elements : "
for ((i=0; i<n; i++))
do
    read a[$i]
done
max=${a[0]}; min=${a[0]}
for i in "${a[@]}"
do
    if [[ "$i" -gt "$max" ]]
    then
        max="$i"
    fi
    if [[ "$i" -lt "$min" ]]
    then
        min="$i"
    fi
done
echo "Max is: $max"
echo "Min is: $min"