#include "inverted_Search.h"

int search(Wlist *head, char *word)
{
    // check whether the list is empty or not
    if(head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    for ( int k = 0 ; word[k] != '\0' ; k++ )
        word[k] = tolower(word[k]);
    
    //if file is not empty
    while(head)
    {
        //compare each node word with the given word to find match
        // if the matching word is there  
        if(!(strcmp(head->word, word)))
        {
            printf("\nHurray!!!!\n");
            printf("Word %s is present in %d files\n", word, head->file_count);
            Ltable *Thead = head->Tlink;
            while(Thead)
            {
                printf("In file %s\t%d times\n", Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
            }
            return 1;
        }
        head = head->link;
    }
    //if the word is not found in the list 
    printf("Searched word is not found in the database \n");
    return 0;
}