read -p "Enter no. : " x
for ((f=1; f<=x; f++))
do
    for (( i=1; i<=f; i++))
    do
        echo -n "$i"
    done
    echo
done
