echo enter the number
read a
res=0
while [ $a -gt 0 ]; do
    c=$(expr $a % 10)
    res=$(expr $res + $c)
    a=$(expr $a / 10)
done
echo sum of digits=$res
