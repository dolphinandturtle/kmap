demo:
	mkdir -p build/
	gcc -o build/demo demo.c src/* lib/kadane/src/*

clean:
	rm -rf build/
