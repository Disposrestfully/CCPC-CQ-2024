g++ -o gen gen.cpp -O2 -std=c++17 -static
g++ -o brute1 brute1.cpp -O2 -std=c++17 -static
g++ -o brute2 brute2.cpp -O2 -std=c++17 -static
g++ -o brute3 brute3.cpp -O2 -std=c++17 -static
g++ -o gyh ../gyh/std.cpp -O2 -std=c++17 -static

for i in {1..20}; do
	./gen > input
	./brute3 < input > answer
	./gyh < input > output
	diff output answer -w -B
	if [ $? -eq 0 ]; then
		echo "Accepted #{$i}."
	else
		echo "Wrong answer!"
	fi
done

rm input output answer gen brute1 brute2 brute3 gyh
