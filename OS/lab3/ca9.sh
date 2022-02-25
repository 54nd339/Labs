read -p "Enter a no. : " x
rev=""
word=""
while [ $x -gt 0 ]
do
    case $(( $x % 10 )) in
        1) word="one" ;;
        2) word="two" ;;
        3) word="three" ;;
        4) word="four" ;;
        5) word="five" ;;
        6) word="six" ;;
        7) word="seven" ;;
        8) word="eight" ;;
        9) word="nine" ;;
        0) word="zero" ;;
        *) echo "Invalid Char." ;;
    esac
    x=$(( $x / 10 ))
    rev=$( echo "${word} ${rev}" )
done
echo "$rev"
