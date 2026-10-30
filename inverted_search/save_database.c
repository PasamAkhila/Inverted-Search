#include "inverted_Search.h"

int save_database(Wlist *head[])
{
    char file_name[FNAME_SIZE];
    //Example .txt or CSV
    printf("Enter the filename: ");
    scanf("%s", file_name);

    // open the file in write mode 
    FILE *fptr = fopen(file_name, "w");
    // check for file open or not 
    if(fptr == NULL)
    {
        printf("File not opened\n");
        return FAILURE ;
    }
    fprintf(fptr , "==============================================\n");
    fprintf(fptr , "INDEX\tWORD\tFILE_COUNT\tFILENAME\tWORD_COUNT\n");
    fprintf(fptr ,"===============================================\n");
    for (int i = 0; i < 27; i++)
    {
        // check if the list is empty or not
        if(head[i] != NULL)
        {
            write_databasefile(head[i], fptr);
        }
    }
    printf("Database saved to %s\n" , file_name);
    fclose(fptr);
}
// function to write the content into the file
void write_databasefile(Wlist *head, FILE *fptr)
{
    while(head)
    {
        fprintf(fptr , "[%-2d] %-12s\t%-3d ", tolower(head->word[0]) - 'a' , head->word , head->file_count);
        Ltable *temp = head->Tlink;
        while ( temp)
        {
            fprintf(fptr , "\t%s\t%d",temp->file_name , temp->word_count);
            temp = temp->table_link;
        }
        fprintf(fptr, "\n");
        head = head->link;
    }
}