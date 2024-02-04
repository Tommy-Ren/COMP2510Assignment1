#include <stdio.h>

int anagramTesting(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == len2) {
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (str1[i] == str2[j]) {
                    str2[j] = "";
                }
                break;
            }
        }
    } else {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    // Check argument
    if (argc != 2)
    {
        printf("Usage: %s <input_file> <input_angle_degrees>\n", argv[0]);
        return 1;
    }

    // Initilize variables
    char *inputFileName = argv[1];
    int rotationAngle = 0;
    int dimensions = 0;
    int arr[10][10] = {0};
    int rows = 0, cols = 0;
    char inputChar;

    // Read the input array from the specified file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    // Read the first line for angle of rotation and second line for array dimensions
    fscanf(file, "%d", &rotationAngle);
    fscanf(file, "%d", &dimensions);
    // Read the input array character by character
    int counter = 0; // To skip first two lines in the file
    while (rows < 10 && (inputChar = fgetc(file)) != 'E')
    {
        if (inputChar == '\n')
        {
            counter++;
        }
        if (inputChar == '\n' && counter >= 2)
        {
            rows++;
            cols = 0;
        }
        else if (cols < 10 && inputChar >= '0' && inputChar <= '9')
        {
            arr[rows][cols++] = inputChar - '0';
        }
    }

    fclose(file);
    printf("A%s\n", a_num);
    // Actual dimensions of the input array
    rows = cols = dimensions;

    printf("Input array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 0)
                printf(" ");
            else
                printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nRotated array (%d degrees):\n", rotationAngle);
    rotateArray(arr, rotationAngle, rows, cols);
}