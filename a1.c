#include <stdio.h>
#include <stdlib.h>

// Function to get length of the string
int strlength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to remove non-char out of the string
char removenonchar(char *str) {
    int length = strlength(str);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') 
         || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return *str;
}
// Function to test anagram of 2 strings
int anagramTesting(char *str1, char *str2) {
    *str1 = removenonchar(str1);
    *str2 = removenonchar(str2);
    int len1 = strlength(str1);
    int len2 = strlength(str2);
    int countsamechar = 0;
    
    if (len1 == len2) {
        for (int i = 0; i < len1; i++) {   
            for (int j = 0; j < len2; j++) {  
                if (str1[i] == str2[j]) {
                    countsamechar++;
                    str1[i] = *"\0";
                    str2[j] = *"\0";
                    break;
                }
            }
        }

        if (countsamechar == len1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    // Check argument
    if (argc != 3) {
        // Quit
        return 1;
    }

    // Initilize variables
    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    char line1[1000];
    char line2[1000];

    // Read the input file
    FILE *inputfile = fopen(inputFileName, "r");
    if (inputfile == NULL) {
        // Quit
        return 1;
    }

    // Read the first line and second line for 2 strings
    fgets(line1, 1000, inputfile);
    fgets(line2, 1000, inputfile);

    fclose(inputfile);

    // Call the anagramTesting function
    int result = anagramTesting(line1, line2);
    
    // Write the output file
    FILE *outputfile = fopen(outputFileName, "w");
    if (outputfile == NULL) {
        // Quit
        return 1;
    }

    if (result == 1) {
        fprintf(outputfile, "1! anagram");
    } else {
        fprintf(outputfile, "0! not anagram");
    }

    fclose(outputfile);

    return 0;
}