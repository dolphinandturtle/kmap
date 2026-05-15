all:
	mkdir -p build/
	gcc -o build/demo demo.c src/kadane.c src/marray.c

clean:
	rm -rf build/
