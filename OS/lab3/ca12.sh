read -p "Enter no. : " x
for ((f=x; f>=1; f--))
do
    for (( i=1; i<=f; i++))
    do
        echo -n "$i"
    done
    echo
done
