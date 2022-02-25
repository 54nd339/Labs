read -p "Enter 2 nos. : " m n
pow=1
for((i=1; i<=$n; i++)) do
    pow=$(($pow*$m))
done
echo "$m^$n : $pow"