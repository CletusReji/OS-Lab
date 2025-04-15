echo enter the year
read a
if [ $(expr $a % 4) -eq 0 ]; then
    if [ $(expr $a % 100) -eq 0 ]; then
        if [ $(expr $a % 400) -eq 0 ]; then
            echo $a is a leap year
        else
            echo $a is not a leap year
        fi
    else
        echo $a is a leap year
    fi
else
    echo $a is not a leap year
fi
