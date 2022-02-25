read -p "Enter a Number : " num
case ${#num} in
    1) echo "Single Digit." ;;
    2) echo "Double Digit." ;;
    3) echo "Triple Digit." ;;
    *) echo "More than 3 digits." ;;
esac
