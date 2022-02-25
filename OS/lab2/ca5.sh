read -p "Enter a Number : " num
case ${#num} in
3)  echo "The number has 3 digits."
    case $(( $num % 10)) in
        $(( $num / 100)) ) echo "The Number is Palindrome." ;;
        *) echo "The Number is not Palindrome." ;;
    esac ;;
*) echo "Input requires a 3 digit number."
esac
