read -p "Please enter a character: " c
case $c in
    [0-9]*) echo "Number." ;;
    [a-z]*) echo "Lowercase Letter." ;;
    [A-Z]*) echo "Upercase Letter." ;;
    ?) echo "character." ;;
    "") echo "NULL." ;;
    *) echo "Anything Else." ;;
esac
