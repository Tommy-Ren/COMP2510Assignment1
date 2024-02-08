#include <stdio.h>

int anagramTesting(char *str1, char *str2)
{
    int len1 = sizeof(str1) / sizeof(str1[1]);
    int len2 = sizeof(str2) / sizeof(str2[1]);

    if (len1 == len2)
    {
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                if (str1[i] == str2[j])
                {
                    str2[j] = "";
                }
                break;
            }
        }
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    // Check argument
    if (argc != 3)
    {
        // Quit
        return 1;
    }

    // Initilize variables
    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    char line1[] = {}, line2[] = {};

    // Read the input array from the specified file
    FILE *file = fopen(inputFileName, "r");
    if (file == NULL)
    {
        // Quit
        return 1;
    }

    // Read the first line for angle of rotation and second line for array dimensions
    fscanf(file, "%d", &line1);
    fscanf(file, "%d", &line2);

    fclose(file);

    int result = anagramTesting(&line1, &line2);
    if (result == 0)
    {
        fprintf(&outputFileName, "0! not anagram");
    }
    else
    {
        fprintf(&outputFileName, "1! anagram");
    }
}