cd abcd

for i in {1..5} ; do
	fname="Test$i"
	cd $fname
	
	cd f1
	cat TEST.txt >> ../../merged.txt
	
	cd ..
	cd f2
	cat TEXT.txt >> ../../merged.txt
	
	cd ../..
	
done
