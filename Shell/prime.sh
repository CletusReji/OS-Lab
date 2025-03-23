echo enter the number
read a
c=0
i=1
while [ $i -lt $(expr $a + 1) ]; do
    r=$(expr $a % $i)
    if [ $r -eq 0 ]; then
        c=$(expr $c + 1)
    fi
    i=$(expr $i + 1)
done
if [ $a == 1 ]; then
    echo 1 is neither prime nor composite
elif [ $c -gt 2 ]; then
    echo $a is not a prime number
else
    echo $a is a prime number
fi
