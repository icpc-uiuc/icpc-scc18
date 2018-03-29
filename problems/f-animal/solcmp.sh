g++ -O2 -std=gnu++11 animal.cpp -o animal
for i in {0..39}; do
	echo "test $i"
	./animal <tests/$i.in >tests/$i.ans
	pypy animal.py <tests/$i.in >tests/$i.ans2
	diff tests/$i.ans tests/$i.ans2
	rm tests/$i.ans2
done
