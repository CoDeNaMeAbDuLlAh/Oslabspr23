cd abcd
for i in {1..5} ; 
        do
	fname="Test$i" 
	cd $fname
	cd f1
	rm *.txt
	cd ..
	cd f2
	rm *.txt
	cd ../..
        done
