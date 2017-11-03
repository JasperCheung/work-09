all: dir.c
	gcc dir.c
	./a.out

clean: 
	rm *.test	
	rm -rf theD

