#include "inverted_Search.h"
void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int empty;
    int i = 1;
    /* finding file existence , file non empty and
        create list of files */
    
    while(argv[i] != NULL )
    {
        empty = isfileexist(argv[i]);
        // if file is not available 
        if( empty == FILE_NOTAVAILABLE)
        {
            printf("%s is not avaialable\n", argv[i]);
            printf("so we are not proceed with this file Give another file\n");
            i++;
            continue;
        }
        empty = isFileEmpty(argv[i]);
        
        // if the file is empty 
        if ( empty == FILE_EMPTY )
        {
            printf("%s is with no content in it \n", argv[i]);
            printf("so we are not proceed with this file Give another file\n");
            i++;
            continue;
        }
        // if the file is available and non empty 
        // add the file into list
        else 
        {
            int val = to_create_list_of_files(f_head, argv[i]);
            if(val == SUCCESS)
            {
                printf("Successfully added %s file into Linked List\n", argv[i]);
            }
            else if(val == REPEATATION)
            {
                printf("%s file is already exist in the list \n",argv[i]);
            }
            else
            {
                printf("Something went wrong!!!!\nPlease try again");
            }
        }
        i++;
    }
}

//function to check the file existence

int isfileexist(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }
    fclose(fptr);
    return SUCCESS;
}
//function to check the file empty 

int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    //move the pointer to last and identify the count
    if(fptr == NULL)
        return FILE_NOTAVAILABLE;
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr)== 0 )
    {
        fclose(fptr);
        return FILE_EMPTY;
    }
    fclose(fptr);
    return SUCCESS;
}
// function to add the files using insert at last 
int to_create_list_of_files(Flist **f_head, char *name)
{
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
        return FAILURE;
    
    strcpy(new -> file_name , name );
    new->link = NULL;
    // if the list is empty add to the head 
    if(*f_head == NULL )
    {
        *f_head = new;
        return SUCCESS;
    }

    Flist *temp1 = *f_head;
    
    // if the file is already exist , not adding into the list 
 
    while ( temp1 != NULL)
    {
        // if the file is already exist , not adding into the list 
        if(strcmp(temp1 -> file_name ,name) == 0 ){
            free(new);
           return REPEATATION;
        }
        temp1 = temp1->link;
    }
    // traverse until last and add file

    Flist *temp = *f_head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    
    temp->link = new;
    return SUCCESS;
}
