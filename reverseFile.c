#include <stdio.h>
#include <string.h>

char *reverseFile(char *string)
{
    char *reversedString;//creating a character pointer to store the reversed string
    int i;
    for (i = 0; i < strlen(string); i++)//loop iterates strlen(string) times which is the length of the string
    {
        reversedString[i] = string[strlen(string) - i - 1];//last char of the string from file is copied to reversed string
    }
    reversedString[strlen(string) + 1] = '\0';//'\0' is to end the reversed string
    return reversedString;//it returns the reversed string
}
int main()
{
    FILE *fptr = NULL;
    fptr = fopen("file.txt", "r");//we open the file.txt in reading mode because we only need the content and don't have to change it
    char str[100];
    fgets(str, 100, fptr);//reads 100 characters from the file.txt
    printf("The content of the file is %s\n", str);
    char *string = reverseFile(str);
    printf("\nThe contents of the file in reversed order %s\n", string);
    FILE *ptr = NULL;
    ptr = fopen("copyFile.txt", "w");//we open the copyFile.txt in write mode because we only have to print the content and not read it
    fprintf(ptr, "%s", str);//this prints the content in copyFile.txt
    return 0;
}
