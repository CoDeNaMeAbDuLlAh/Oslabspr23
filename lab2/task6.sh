echo "Enter how many terms you want to generqate  :"

read n 
x1=0
x2=1
echo "fib series: "
  
    for (( i=0; i<n; i++ ))
    do
    echo -n "$x1 "
    fn=$((x1 + x2))
    x1=$x2
    x2=$fn
    done
