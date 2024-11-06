g++ -o val val.cpp -static -O2 -std=c++17
for i in {1..1}; do
	./val < ../down/$i.in
	if [ $? -eq 0 ]; then
		echo "Sample #$i is valid."
	else
		echo "Sample #$i is invalid."
	fi
done
for i in {1..1}; do
	./val < $i.in
	if [ $? -eq 0 ]; then
		echo "Testcase #$i is valid."
	else
		echo "Testcase #$i is invalid."
	fi
done
rm val
