read -p "Enter no. of elements in a line : " x
for ((f=1; f<=100;))
do
    for (( i=1; i<=x && f<=100; i++))
    do
        echo -n "$f "
        f=$(($f+1))
    done
    echo
done