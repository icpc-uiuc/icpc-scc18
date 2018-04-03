g++ -O2 -std=gnu++11 fence.cpp -o fence
for i in {0..27}; do
	./fence <test/$i.in >test/$i.ans
	time python3 fence.py <test/$i.in >test/$i.ans2
	diff test/$i.ans test/$i.ans2
	rm test/$i.ans2
done
