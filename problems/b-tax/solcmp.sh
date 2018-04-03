g++ -O2 -std=gnu++11 tax.cpp -o tax
for i in {0..25}; do
	./tax <test/$i.in >test/$i.ans
	python3 tax.py <test/$i.in >test/$i.ans2
	diff test/$i.ans test/$i.ans2
	rm test/$i.ans2
done
