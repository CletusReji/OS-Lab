echo enter three numbers
read a b c
if [ $a -gt $b ]; then
    if [ $a -gt $c ]; then
        echo $a is larger
    else
        echo $c is larger
    fi
else
    if [ $b -gt $c ]; then
        echo $b is larger
    else
        echo $c is larger
    fi
fi
