echo "first num is " $1
echo "second num is " $2
echo "third  num is " $3

num1=$1
num2=$2
num3=$3

if [[ $num1 < $num2 && $num1 < $num3 ]];
then 
echo" num1 is the smallest "
fi

if [[ $num2 < $num1 && $num2 < $num3 ]];
then 
echo" num2 is the smallest "
fi

if [[ $num3 < $num1 && $num3 < $num2 ]];
then 
echo" num3 is the smallest "

fi
