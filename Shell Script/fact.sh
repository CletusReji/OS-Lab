echo enter the number
read a
res=0
while [ $a -gt 1 ]; do
    res=$(expr $res \* $a)
    a=$(expr $a - 1)
done
echo factorial is $res
