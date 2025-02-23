echo enter two numbers
read a b
if [ $a -lt $b ]; then
    echo $b is larger
elif [ $a -eq $b ]; then
    echo both are equal
else
    echo $a is larger
fi
