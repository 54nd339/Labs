read -p "Enter the limits : " a b
for (( x=a; x<=b; x++))
    do
    f=0
    for (( i=2; i<=$(($x/2)); i++))
    do
        if [ $(( $x % $i )) -eq 0 ]
        then
            f=1
            break
        fi
    done

    if [ $f -ne 1 ]
    then
        echo "$x"
    fi
done