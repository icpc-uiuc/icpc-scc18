g++ -O2 -std=gnu++11 tax.cpp -o tax
for i in {0..25}; do
	./tax <tests/$i.in >tests/$i.ans
	python3 tax.py <tests/$i.in >tests/$i.ans2
	diff tests/$i.ans tests/$i.ans2
	rm tests/$i.ans2
done
