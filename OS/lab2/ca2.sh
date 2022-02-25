echo "Enter 1 for Addition."
echo "Enter 2 for Subtraction."
echo "Enter 3 for Multiplication."
echo "Enter 4 for Division."
read -p "Enter your Option : " c
case $c in
    1 | 2 | 3 | 4)
    read -p "Enter 2 numbers : " a b
    case $c in
        1) echo "$a + $b =" $(($a+$b)) ;;
        2) echo "$a - $b =" $(($a-$b)) ;;
        3) echo "$a * $b =" $(($a*$b)) ;;
        4) echo "$a / $b =" $(($a/$b))
        echo "$a % $b =" $(($a%$b)) ;;
    esac ;;
    *) echo "Invalid Option." ;;
esac
