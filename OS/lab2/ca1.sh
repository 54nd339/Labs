read -p "Enter your marks : " marks
case $(( $marks /10)) in
    9 | 10) echo "O grade." ;;
    8) echo "E grade." ;;
    7) echo "A grade." ;;
    6) echo "B grade." ;;
    5) echo "C grade." ;;
    4) echo "D grade." ;;
    3 | 2 | 1) echo "F grade." ;;
    *) echo "Invalid Marks." ;;
esac
