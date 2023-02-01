echo "Abdullah shaikh 21k-4783 "
for i in {1..5} ; do 
newfolder="Test$i"
mkdir $newfolder
cd $newfolder
mkdir f1
cd f1
touch TEST.txt
date > TEST.txt
cd .. 
mkdir f2
cd f2
touch TEXT.txt
date >TEXT.txt
cd ..
cd ..
done 
