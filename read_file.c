#include <stdio.h>

extern int sum(int* array, int size);

int main(){
    // Prompt user for file name
    char filename[30];
    printf("Which file would you like to sum? ");
    scanf("%s", filename);

    // Attempt to open the file
    FILE * file;
    file = fopen(filename, "r");
    
    // Check if the file exists
    if(file != NULL){
        // Find the size of the file (in the first line)
        int size;
        if(fscanf(file, "%d", &size)){
            // Create an array and store all the numbers
            int arr[size];
            int iterator = 0;
            int num;
            while(fscanf(file, "%d", &num)!=EOF){
                arr[iterator] = num;
                iterator += 1;
            }
            
            // Pass the array of numbers and its size to assembly
            int asmVal = sum(arr, size);
            printf("Sum from Assembly: %d\n", asmVal);
        }
        fclose(file);
    }
    else{
        // In case file name is mistyped/wrong
        printf("Invalid file name.\n");
    }
    return 0;
}