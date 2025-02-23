echo enter number of terms
read i
a=0
b=1
echo fibonacci series is
while [ $i -gt 0 ]; do
    echo $a
    c=$(expr $a + $b)
    a=$b
    b=$c
    i=$(expr $i - 1)
done
