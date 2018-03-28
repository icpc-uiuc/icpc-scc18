title=$1
g++ -O2 -std=gnu++11 ${title}2.cpp -o ${title}2
for i in {1..41}; do
	python3 ./${title}.py <tests/$i.in >tests/$i.ans
	./${title}2 <tests/$i.in >tests/$i.ans2
	diff tests/$i.ans tests/$i.ans2
	rm tests/$i.ans2
done
rm ${title}2
