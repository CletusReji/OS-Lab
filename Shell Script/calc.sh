echo enter two numbers
read a b
echo enter the operation: 1. add 2. subtract 3. multiply 4. divide
read c
case $c in
1) r=$(expr $a + $b) ;;
2) r=$(expr $a - $b) ;;
3) r=$(expr $a \* $b) ;;
4) r=$(echo "scale=2; $a / $b" | bc) ;;
esac
echo result=$r
