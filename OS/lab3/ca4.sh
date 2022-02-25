read -p "Enter a no. : " x
f=0
for (( i=2; i<=$(($x/2)); i++))
do
    if [ $(( $x % $i )) -eq 0 ]
    then
        f=1
        break
    fi
done

if [ $f -eq 1 ]
then
    echo "Not Prime"
else
    echo "Prime"
fi