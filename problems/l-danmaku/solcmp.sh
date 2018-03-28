title=$1
g++ -O2 -std=gnu++11 $title.cpp -o ${title}
g++ -O2 -std=gnu++11 ${title}2.cpp -o ${title}2
for i in {0..29}; do
	#./${title} <test/$i.in >test/$i.ans
	./${title}2 <test/$i.in >test/$i.ans2
	diff test/$i.ans test/$i.ans2
	rm test/$i.ans2
done
rm ${title}
rm ${title}2
