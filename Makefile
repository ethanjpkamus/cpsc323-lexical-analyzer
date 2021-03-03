test:
	clear
# 	clear && printf '\e[3J'
	clang++ -std=c++17 main.cpp -o main.o
	./main.o sample-input.txt

clean:
	rm *.o