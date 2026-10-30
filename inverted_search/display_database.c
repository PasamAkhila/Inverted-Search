#include "inverted_Search.h"
void display_database(Wlist *head[])
{
    //Display the content of all the head
    printf("***************************************************************\n");
    printf("Index\tWord\t   File Count\tFilename\t   Word Count\n");
    printf("***************************************************************\n");
    for(int i = 0; i < 27;i++)
    {
        //print words one after the other in alphabetic order 
        if(head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}
int print_word_count(Wlist *head)
{
    //traverse through the Wlist
    while(head != NULL)
    {
        // printing index , word and file count 
        
        printf("|[%-2d]|\t|%-7s|\t|%-3d|\t", tolower(head->word[0]) - 97, head->word, head->file_count);
        
        //traverse through the Tlink table
        Ltable *Thead = head->Tlink;
        int first = 1;
        
        // printing filename and word count 
        while(Thead)
        {
            // if it is first file 
            if(first){
                printf("|%-15s|\t|%-3d|\n", Thead->file_name, Thead->word_count);
                first = 0;
            }
            // for other than first file 
            else
            {
                printf("%-32s|%-15s|\t|%-3d|\n","",Thead->file_name , Thead->word_count);
            }
            // traverse through the last 
            Thead = Thead->table_link;
        }
        printf("-------------------------------------------------------------\n");
        head = head->link;
    }
    return SUCCESS;
}