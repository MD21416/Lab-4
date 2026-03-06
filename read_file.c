#include <stdio.h>

extern int sum(int* array, int size);

int main(){
    char filename[30];
    printf("Which file would you like to sum? ");
    scanf("%s", filename);
    FILE * file;
    file = fopen(filename, "r");
    
    if(file != NULL){
        int size;
        if(fscanf(file, "%d", &size)){
            
            int arr[size];
            int iterator = 0;
            int num;
            while(fscanf(file, "%d", &num)!=EOF){
                arr[iterator] = num;
                iterator += 1;
            }

            int cVal = 0;
            for(int i = 0; i < size; i++){
                cVal += arr[i];
            }
            printf("Sum from C: %d\n", cVal);
            int asmVal = sum(arr, size);
            printf("Sum from Assembly: %d\n", asmVal);
        }
        fclose(file);
    }
    else{
        printf("Invalid file name.\n");
    }
    return 0;
}