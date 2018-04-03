title=$1
g++ -O2 -std=gnu++11 $title.cpp -o ${title}
g++ -O2 -std=gnu++11 ${title}2.cpp -o ${title}2
g++ -O2 -std=gnu++11 checker.cpp -o checker
for i in {0..49}; do
	./${title} <test/$i.in >test/$i.ans
	./${title}2 <test/$i.in >test/$i.ans2

    ./checker test/$i.in test/sol1.$i. < test/$i.ans
    ./checker test/$i.in test/sol2.$i. < test/$i.ans2

    diff test/sol1.$i.judgemessage.txt expected.txt
    diff test/sol2.$i.judgemessage.txt expected.txt

#	rm test/$i.ans
	rm test/$i.ans2
	rm test/sol1.$i.judgemessage.txt
	rm test/sol2.$i.judgemessage.txt
done
rm ${title}
rm ${title}2
rm checker
