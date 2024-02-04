#include <stdio.h>

void anagram (char *str1, char *str2) {
    for (int i = 0; i < 6; i++) {
	    for (int j = 0; j < 6; j++) {
	        if (str1[i] == str2[j]) {
		        printf("Anagram\n");
    	    	}
	    }
    }
}

int main(){
    char str1[6]  = "listen";
    char str2[6]  = "silent";
    anagram(str1, str2);
    return 0;
}