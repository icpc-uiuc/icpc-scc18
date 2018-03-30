g++ -O2 -std=gnu++11 fence.cpp -o fence
for i in {0..27}; do
	./fence <tests/$i.in >tests/$i.ans
	time python3 fence.py <tests/$i.in >tests/$i.ans2
	diff tests/$i.ans tests/$i.ans2
	rm tests/$i.ans2
done
