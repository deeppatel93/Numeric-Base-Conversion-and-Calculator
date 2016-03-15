/*
	calc
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "calc.h"


//Purpose: convert decimal to octal 
//Parameters: decimal value as int
//Output: octal value as int
long long int decToOct(long long int dec){
	long long int current = dec;
	long long int sum = 0;
	long long int base = 1;
	long long int rem = 0;
     
    while(current != 0) {
        rem = current % 8;
        current = current / 8;
        sum = sum  + (rem * base);
        base = base * 10;
    }
    return sum;
}

//Purpose: convert decimal to hex char array
//Parameters: decimal value as int
//Output: char array hex pointer
char* decToHex(long long int dec){
	long long int current = dec;
	long long int rem = 0;
    int i =1 ;
	int j;
	int start;
    char answer[999];
	char * end = answer;
	int isNeg = 0;
	char m = '-';
	char z = 'x';
	if(current < 0){
		isNeg = 1;
		current = current * -1;
		start = 3;
	}
	else{
		start = 2;
	}

    while(current != 0){
         rem = current % 16;

      if(rem  < 10){
	          rem  = rem + 48;
	  }
      else{
         rem = rem + 55;
	  }
      answer[i++]= rem;
      current = current / 16;
  }
	if(isNeg == 1){
		 printf("-");
		 printf("x");
	 }
	 else{
		 printf("x");
	 }
    for(j = i -1 ;j> 0;j--){
		  printf("%c",answer[j]);
	}
    
	printf("\n\n");
return end;
}

//Purpose: convert decimal to binary 
//Parameters: decimal value as int
//Output: binary value as int
long long int decToBin(long long int dec){
	long long int current = dec;
	long long int sum = 0;
	long long int base = 1;
	long long int rem = 0;
     
    while(current != 0) {
        rem = current % 2;
        current = current / 2;
        sum = sum  + (rem * base);
        base = base * 10;
    }
    return sum;
}

//Purpose: convert octal to decimal 
//Parameters: octal value as int
//Output: decimal value as int
long long int octToDec(long long int oct){
    long long int sum = 0;
    long long int neg = 0;
	long long int rem = 0;
    long long int base = 1;
	if(oct < 0){
		neg = 1;
		oct = -1 * oct;	
	}
	long long int current = oct;
	
	while(current > 0){
		rem = current % 10;
        sum = sum + rem * base;
        current = current / 10 ;
        base = base * 8;
	}
	if(neg == 1){
		return (sum * -1);
	}
	return sum;
}

//Purpose: convert hex array to decimal
//Parameters: hex char array
//Output: decimal value as int
long long int hexToDec(char* hex){
	int l  = strlen(hex) -2;
	int startIndex = 1;
	int isNeg = 0;
	long long int sum = 0;
	int i = 0;
	long long int digit = 0;
	if(hex[0] == '-'){
		startIndex = 2;
		isNeg = 1;
		l = strlen(hex) - 3;
	}
	
	 for(i=startIndex; hex[i]!='\0'; i++)  
    {  
       char c = hex[i];
        switch(c)  
        {  
            case '0':  
                digit = 0;  
                break;  
            case '1':  
                digit = 1;  
                break;  
            case '2':  
				digit = 2;  
                break;  
            case '3':  
                digit = 3;  
                break;  
            case '4':  
                digit = 4;  
                break;  
            case '5':  
                digit = 5;  
                break;  
            case '6':  
                digit = 6;  
                break;  
            case '7':  
                digit = 7;  
                break;  
            case '8':  
                digit = 8;  
                break;  
            case '9':  
                digit = 9;  
                break;  
            case 'a':  
            case 'A':  
                digit = 10;  
                break;  
            case 'b':  
            case 'B':  
                digit = 11;  
                break;  
            case 'c':  
            case 'C':  
                digit = 12;  
                break;  
            case 'd':  
            case 'D':  
                digit = 13;  
                break;  
            case 'e':  
            case 'E':  
                digit = 14;  
                break;  
            case 'f':  
            case 'F':  
                digit = 15;  
                break;  
        }  
		sum = sum + (digit * pow(16, l)); 
        l--;  
		
    }   
	if(isNeg == 1){
			sum = sum * -1;
	}
	return sum ;
		
}

//Purpose: converts binary char array to decimal
//Parameters: char array of bit string
//Output: decimal value a int
long long int binToDec(char * first){
	int l = strlen(first) - 1;
	long long int base = 0;
	long long int sum = 0;
	int endIndex = 0;
	if(first[0] == '-'){
		endIndex = 1;
		
	}
	while(l > endIndex){
		
		if(first[l] == '1'){
			sum = sum + pow(2,base);
			
		}
		base++;
		l--;
	}
	if(endIndex == 1){
		return (-1 * sum);
	}
	return sum;
}

//Purpose: add two ints
//Parameters: two ints
//Output: returns one int 
long long int add(long long int one,long long int two){
	return (one + two);
}

//Purpose: mulitply two ints
//Parameters: two ints
//Output: returns one int 
long long int multi(long long int one,long long int two){
	return (one * two);
}

//Purpose: subtract two ints
//Parameters: two ints
//Output: returns one int 
long long int sub(long long int one, long long int two){
	return (one - two);
}
//Purpose: converts an int to an char array
//Parameters: int of value, and output of the array
//Output: pointer to char array
char *intToChar (long long int current, char c){
	if (current == 0){
	 return "0";
	}
    long int digit =   current * 10;
	long int size = 0;
	int isNeg = 0;
	if(current < 0){
		isNeg = 1;
	}
	while (digit /= 10){
		size++;
	}
	if (isNeg == 1){
	size++;
	current = current * -1;;
	}
	size++;
	char *end = malloc(size+1);
	
	end[size] = '\0';
	while(size--)
	{
		end[size] = current % 10 + '0';
		current /= 10;
	}
	
	if (isNeg){
		end [0] = '-';
		end [1] = c;
	}
	else{
		end [0] = c;
	}
	return end;
}


//Purpose: converts char to int
//Parameters: char array 
//Output: an int
long long int charToInt(char* old){

	long long int i;
	long long int digit = 0;
	long long int temp = 0;
	long long int tenPower = 0;
	long long int newInt = 0;
	long long int tenTotal = 1;
	long long int s = 0;
	int neg = 0;
	if(old[0] == '-'){
		neg = 1;
	}

	for(i = strlen(old) - 1; i >  0; i--){
		if(isalpha(old[i])){
			break;
		}
		digit = old[i] - '0';
		if(tenPower == 0){
			temp = digit;
		}
		if(tenPower == 	1){
			temp = 10 * digit;
		}
		else{
			while(s < tenPower ){
				tenTotal = tenTotal * 10;
				s++;
				temp = tenTotal * digit;
			}
		}
		newInt = newInt + temp;
		tenPower++;
	}
	if(neg == 1){
		newInt = -1 * newInt;
	}
	return newInt;
}


//Purpose: check of valid binary
//Parameters: char array to be tested
//Output: 1 if valid, 0 if not valid
int binCheck(char * first){
	int i;
	int start;
	if(first[0] == '-'){
		start = 2;
	}
	else{
		start = 1;
	}
	if(start == 1 && strlen(first) == 1){
		return 0;
	}
	else if(start == 2 && strlen(first) == 2){
		return 0;
}
	for(i = start; i < strlen(first); i++){
		if(first[i] != '0' && first[i] != '1' ){
			return 0;
		}
	}
	return 1;
}

//Purpose: check of valid hex
//Parameters: char array to be tested
//Output: 1 if valid, 0 if not valid
int hexCheck(char * c){
	int i;
	int start;
	if(c[0] == '-'){
		start = 2;
	}
	else{
		start = 1;
	}
	if(start == 1 && strlen(c) == 1){
		return 0;
	}
	else if(start == 2 && strlen(c) == 2){
		return 0;
}
	for(i = start; i < strlen(c);i++){
				if((c[i] >= '0' && c[i] <= '9') || ((c[i] >= 'a') && (c[i] <= 'f')) || ((c[i] >= 'A') && (c[i] <= 'F'))){
					continue;
				}
				else{
					return 0;
				}
		}
	return 1;
}

//Purpose: check of valid octal
//Parameters: char array to be tested
//Output: 1 if valid, 0 if not valid
int octCheck(char* c){
	int i;
	int start;
	if(c[0] == '-'){
		start = 2;
	}
	else{
		start = 1;
	}
	if(start == 1 && strlen(c) == 1){
		return 0;
	}
	else if(start == 2 && strlen(c) == 2){
		return 0;
}
	
	for(i = start; i < strlen(c); i++){
		if((c[i] >= '0' && c[i] <= '7')){
			 continue;
		 }
		else{
			return 0;
		}
	}
	return 1;
}

//Purpose: check of valid decimal
//Parameters: char array to be tested
//Output: 1 if valid, 0 if not valid
int decCheck(char * first){
	int i;
	int start;
	if(first[0] == '-'){
		start = 2;
	}
	else{
		start = 1;
	}
	if(start == 1 && strlen(first) == 1){
		return 0;
	}
	else if(start == 2 && strlen(first) == 2){
		return 0;
}
	for(i = start; i < strlen(first); i++){
		if(!isdigit(first[i])){
			return 0;
		}
	}
	return 1;
}
int main(int argc, char **argv){
	//checks for error
	if(argc != 5){
		fprintf(stderr,"ERROR, Incorrect  number of arguements\n\n");
		return -1;
	}
	//gets input
	long long int answer;
	char *sign = argv[1];
	char *first = argv[2];
	char *second = argv[3];
	char *final = argv[4];
	long long int one;
	long long int two;
	//converts to int and then to decimal
	//checks if char array is valid
	if(first[0] == 'd' || first[1] == 'd'){
		if(decCheck(first) == 0){
			fprintf(stderr,"ERROR,  Incorrect number1\n\n");
			return -1;
		}
		else{
			one = charToInt(first);
		}
	}
	else if(first[0] == 'o' || first[1] == 'o'){
		if(octCheck(first) == 0){
			fprintf(stderr,"ERROR,  Incorrect number1\n\n");
			return -1;
		}
		else{
			one = charToInt(first);
			one = octToDec(one);
		}
		
		
	}
	else if(first[0] == 'x' || first[1] == 'x'){
		if(hexCheck(first) == 0){
			fprintf(stderr,"ERROR,  Incorrect number1\n\n");
			return -1;
		}
		else{
			one = hexToDec(first);
		}
		
	}
	else if(first[0] == 'b' || first[1] == 'b'){
		if(binCheck(first) == 0){
			fprintf(stderr,"ERROR,  Incorrect number1\n\n");
			return -1;
		}
		else{
			one = binToDec(first);
		}
		
	}
	else{
		fprintf(stderr,"ERROR,  Incorrect number1\n\n");
		return -1;
	}
		
		
	//converts to int and then to decimal
	//checks if char array is valid	
	if(second[0] == 'd' || second[1] == 'd'){
		if(decCheck(second) == 0){
			fprintf(stderr,"ERROR,  Incorrect number12\n\n");
			return -1;
		}
		else{
			two = charToInt(second);
		}
	}
	else if(second[0] == 'o' || second[1] == 'o'){
		if(octCheck(second) == 0){
			fprintf(stderr,"ERROR,  Incorrect number2\n\n");
			return -1;
		}
		else{
			two = charToInt(second);
			two = octToDec(two);
		}
	}
	else if(second[0] == 'x' || second[1] == 'x'){
		if(hexCheck(second) == 0){
			fprintf(stderr,"ERROR,  Incorrect number2\n\n");
			return -1;
		}
		else{
			two = hexToDec(second);
		}
	}
	else if(second[0] == 'b' || second[1] == 'b'){
		if(binCheck(second) == 0){
			fprintf(stderr,"ERROR,  Incorrect number2\n\n");
			return -1;
		}
		else{
			two = binToDec(second);
		}
	}
	else{
		fprintf(stderr, "ERROR Incorrect number2\n\n");
		return -1;
	}
	
	//performs operation on decimal values
	if(sign[0] == '+'){
		answer = add(one,two);
	}
	else if(sign[0] == '-'){
		answer = sub(one,two);
	}
	else if(sign[0] == '*'){
		answer = multi(one,two);
	}
	else{
		fprintf(stderr,"ERROR, Incorrect operation\n\n");
		return -1;
	}
	
	
	// converts to desired form
	//prints answer
	if(final[0] == 'd'){
		if(answer == 0){
			printf("d");
		}
		char c = final[0];
	    char* z = intToChar(answer,c);
	    printf("%s \n\n", z);
	}
	else if(final[0] == 'o'){
		if(answer == 0){
			printf("o");
		}
		answer = decToOct(answer);
		char c = final[0];
	    char* z = intToChar(answer,c);
	    printf("%s \n\n", z);
	}
	else if(final[0] == 'x'){
		 char* d = decToHex(answer);
	}
	else if(final[0] == 'b'){
		if(answer == 0){
			printf("b");
		}
		answer = decToBin(answer);
		char c = final[0];
	    char* z = intToChar(answer,c);
	    printf("%s \n\n", z);
	}
	else{
		fprintf(stderr, "ERROR, Incorrect output base\n\n");
		return -1;
	}
	
	return 0;
}