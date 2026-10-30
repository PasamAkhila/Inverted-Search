#include "inverted_Search.h"
extern char *file_name;

int insert_at_last(Wlist **head, data_t *data)
{
    // create the new node
    Wlist *new = malloc(sizeof(Wlist));
    if (new == NULL)
        return FAILURE;

    // update the fields of Wlist
    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;
    
    // updaate the link table
    update_link_table(&new);
    
    // if the list is empty
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    
    //if list is non empty
    // add in the last to the list
    Wlist *temp = *head;
    while(temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}
int update_link_table(Wlist *head[])
{
    //create new node
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
        return FAILURE;
    
    //update the fields
    new->word_count = 1;
    strcpy(new->file_name,file_name);
    new->table_link = NULL;
    
    //(*head)->Tlink = new;
    Ltable *temp = (*head) -> Tlink;
    if(temp == NULL)
    {
        (*head)->Tlink = new;
    }
    else
    {
        while(temp ->table_link != NULL)
        {
            temp = temp->table_link;
        }
        temp -> table_link = new;
    }
    
    return SUCCESS;
}