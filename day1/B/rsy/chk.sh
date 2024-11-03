g++ -o gen gen.cpp -O2 -std=c++17 -static
g++ -o brute brute.cpp -O2 -std=c++17 -static
g++ -o test test.cpp -O2 -std=c++17 -static
g++ -o std ../psj/std.cpp -O2 -std=c++17 -static

for i in {1..100}; do
	./gen > input
	./brute < input > answer
	./test < input > output
	# ./std < input > std_output
	diff output answer -w -B
	if [ $? -eq 0 ]; then
		echo "Accepted #$i."
	else
		echo "Test code: Wrong answer!"
	fi
	# diff std_output answer -w -B
	# if [ $? -eq 0 ]; then
	# 	echo "Accepted #$i."
	# else
	# 	echo "Std: Wrong answer!"
	# fi
done

rm gen brute test std input output answer std_output
