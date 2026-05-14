all:
	mkdir -p build/
	gcc -o build/main src/main.c src/kadane.c

clean:
	rm -rf build/
