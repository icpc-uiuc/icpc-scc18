g++ -O2 -std=gnu++11 animal.cpp -o animal
for i in {0..39}; do
	echo "test $i"
	./animal <test/$i.in >test/$i.ans
	pypy animal.py <test/$i.in >test/$i.ans2
	diff test/$i.ans test/$i.ans2
	rm test/$i.ans2
done
