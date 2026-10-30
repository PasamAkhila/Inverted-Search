#include "inverted_Search.h"
char *file_name;

//creating databse
void create_database(Flist *f_head, Wlist *head[])
{
    while(f_head)
    {
        //read file one after the another until reach to null
        read_datafile(f_head, head, f_head->file_name);
        
        // move the file head to the next node 
        f_head = f_head->link;
    }
}

//function is to read the content of the file and create database 
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    // open the file in read mode 
    FILE *fptr = fopen(filename, "r");
    file_name = filename;
    
    //validation for file opening
    /*if(fptr == NULL)
        return FAILURE;*/

    // read words one by one 
    char word[WORD_SIZE];
    while(fscanf(fptr, "%s", word) != EOF)
    {
        //finding index of the word
        for ( int i = 0 ; word[i] != '\0' ; i++ )
        {
            word[i] = tolower(word[i]);
        }
        int index = tolower(word[0]) % 97;
        //check for the true index range
        if(!(index >= 0 &&  index <= 25))
        {
            index = 26;
        }
        // if already words are there with the same index
        if(head[index] != NULL)
        {
            Wlist *temp = head[index];
            int found = 0;
            while(temp)
            {
                // if the matching word is there
                if(strcmp(temp->word, word) == 0)
                {
                    update_word_count(&temp, filename);
                    found = 1;
                    break;
                }
                temp = temp->link;
            }
            if(found == 0 )
                insert_at_last(&head[index], word);
        }
        // if no words are there in this index
        else
            insert_at_last(&head[index], word);
    }
}
int update_word_count(Wlist **head, char *filename)
{

    Ltable *temp = (*head) -> Tlink;

    // if the word is present in the same file itself just increase the word count
    while ( temp != NULL )
    {
        if(strcmp(temp -> file_name , filename) == 0 )
        {
            temp->word_count += 1;
            return SUCCESS;
        }
        // traverse until last
        temp = temp->table_link;
    }
    /* else create a new node for the file 
        and increase file count in the head */
    
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL )
        return FAILURE;

    // for new tlink
    new -> word_count = 1;
    strcpy(new->file_name , filename);
    new -> table_link = NULL;

    // add the file in the last 
    temp = (*head) -> Tlink;
    while(temp->table_link != NULL )
    {
        temp = temp->table_link;
    }
    temp->table_link = new;

    (*head)->file_count += 1;
    return SUCCESS;
}
