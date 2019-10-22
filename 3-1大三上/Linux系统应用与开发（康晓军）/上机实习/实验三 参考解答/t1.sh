echo 'Use one of the following options:'
echo '  P: To display current directory'
echo '  S: To display the name of running file'
echo '  D: To display today’s date and present time'
echo '  L: To see the listing of files in your present working directory'
echo '  W: To see who is logged in'
echo '  Q: To quit this program'
read -n 1 -p 'Enter your option and hit: '  option
echo
echo "Your option is $option"

case ${option^^} in
        P)
                pwd
                ;;
        S)
                echo $(basename $0)
                ;;
        D)
                date
                ;;
        L)
                ls -al
                ;;
        W)
                whoami
                ;;
        Q)
                exit
                ;;
        *)
                echo 'Please enter as required!'
                ;;
esac