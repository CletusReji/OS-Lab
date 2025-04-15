echo enter a number
read n
a=$n
res=0
while [ $a -gt 0 ]; do
    c=$(expr $a % 10)
    mul=$(expr $c \* $c \* $c)
    res=$(expr $res + $mul)
    a=$(expr $a / 10)
done
if [ $res -eq $n ]; then
    echo it is armstrong number
else
    echo it is not armstrong number
fi
