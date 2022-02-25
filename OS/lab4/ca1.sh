read -p "Enter No. of elements : " n
echo "Enter Array elements : "
for ((i=0; i<n; i++))
do
    read a[$i]
done
echo -n "Elements in forward direction : "
for ((i=0; i<n; i++))
do
    echo -n "${a[$i]} "
done
echo
echo -n "Elements in reverse direction : "
for ((i=n-1; i>=0; i--))
do
    echo -n "${a[$i]} "
done