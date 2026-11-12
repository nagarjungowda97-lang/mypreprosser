mypreprocessor: main.o mypreprocessor_comment.o mypreprocessor_macros.o mypreprocessor_fileinc.o
	gcc main.o mypreprocessor_comment.o mypreprocessor_macros.o mypreprocessor_fileinc.o -o mypreprocessor
  
main.o:main.c
	gcc -c main.c
  
mypreprocessor_comment.o:mypreprocessor_comment.c
	gcc -c mypreprocessor_comment.c
 
mypreprocessor_macros.o:mypreprocessor_macros.c
	gcc -c mypreprocessor_macros.c
 
mypreprocessor_fileinc.o:mypreprocessor_fileinc.c
	gcc -c mypreprocessor_fileinc.c
clear:
	@echo "Cleaning up..."
	rm -v *.o
