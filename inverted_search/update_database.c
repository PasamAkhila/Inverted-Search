#include "inverted_Search.h"

int update_database(Wlist *head[], Flist **f_head)
{
    // taking input to enter the new file from the user 
    char file_name[FNAME_SIZE];
    printf("Enter the file to be added to the file linked list: ");
    scanf("%s", file_name);

    // do the file validation and create database
    file_validation(f_head,file_name);
    //Flist *temp = *f_head;
    while(*f_head )
    {
        if(strcmp((*f_head)->file_name, file_name) == 0)
        {
            create_database(*f_head, head);
            return SUCCESS;
        }
        *f_head = (*f_head)-> link;
    }
    return FAILURE;
}

/* checking for the availability and contents of the file
    and add to the list */
void file_validation (Flist **f_head, char *filename){
        int empty;
        empty = isfileexist(filename);
        if( empty == FILE_NOTAVAILABLE)
        {
            printf("%s is not avaialable\n",filename );
            printf("so we are not proceed Give another file\n");
            return ;
        }
        empty = isFileEmpty(filename);
        if ( empty == FILE_EMPTY )
        {
            printf("%s is Empty\n", filename);
            printf("so we are not proceed with this file Give another file\n");
            return;
        }
        else 
        {
            int val = to_create_list_of_files(f_head,filename );
            if(val == SUCCESS)
            {
                printf("Successfully added %s file into Linked List\n",filename );
            }
            else if(val == REPEATATION)
            {
                printf("%s file is already exist\n",filename);
            }
            else
            {
                printf("Something went wrong!!!!\nPlease try again");
            }

        }
}