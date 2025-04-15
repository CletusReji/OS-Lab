echo enter the number
read a
num=$a
res=0
while [ $a -gt 0 ]; do
    res=$(expr $res \* 10)
    sums=$(expr $a % 10)
    res=$(expr $res + $sums)
    a=$(expr $a / 10)
done
if [ $num -eq $res ]; then
    echo number is a palindrome
else
    echo number is not a palindrome
fi
