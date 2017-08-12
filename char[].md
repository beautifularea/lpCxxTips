# Difference between char * and char [].

* char *s = "Hello world"; </br>
 will place Hello world in the read-only parts of the memory and making s a pointer to that, making any writing operation on this memory illegal. 

* char s[] = "Hello world"; </br>
 puts the literal string in read-only memory and copies the string to newly allocated memory on the stack. Thus making
 s[0] = 'J';
 legal.
