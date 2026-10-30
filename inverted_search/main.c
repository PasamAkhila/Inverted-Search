#include "inverted_Search.h"

int main(int argc , char *argv[])
{
    int option;
    char choice;
    int db_created = 0;
    Wlist *head[27] = {NULL};
    // to clear the screen 
    system("clear");
    
    //Validation for Command line arguments 
    // enter CLA with atleast one input file
    if(argc < 2)
    {
        printf("Enter the valid arguments with atleast one input file\n");
        printf("Ex: ./a.out file1.txt file2.txt\n");
        return 0;
    }
    
    //Create the File linked list
    
    Flist *f_head = NULL;
    
    /*Validation of files for its
        avaialability, duplicate, and 
        empty file or not 
    */
    file_validation_n_file_list(&f_head, argv);
    
    // if no files are added 
    if(f_head == NULL)
    {
        printf("No files are added to the list\n");
        printf("Hence the process got terminated\n");
        return -1;
    }
    
    //menu for inverted search
    printf("*****************************************************************\n");
    printf("                    INVERTED SEARCH MENU                         \n");
    printf("*****************************************************************\n");
    
    while(1){
    
        printf("1.Create database\n2.Display database\n3.Update database\n4.Search word\n5.Save database\n");
        printf("\nEnter option:\n");
        if(scanf("%d",&option) != 1)
        {
            printf("Invalid input - Program Terminating\n");
            exit(0);
        }
        int c; // to clear buffer
        while((c = getchar()) != '\n' && c != EOF);
        
        // switch to match the option to function
        switch(option)
        {
            case 1:
            if(db_created == 0)
            {
                create_database(f_head, head);
                db_created = 1;
                printf("Database created\n");
            }
            else    
                printf("Database already created!!!\n");
                break;
            case 2:
                display_database(head);
                break;
            case 3:
                update_database(head,&f_head);
                break;
            case 4:
                char word[WORD_SIZE];
                printf("Enter the word to search: ");
                scanf("%s", word);
                int index = tolower(word[0]) % 97;
                search(head[index], word);
                break;
            case 5:
                save_database(head);
                break;
            default:
                printf("Invalid Choice\n");
        }

        printf("\nDo you want to continuee? (y/n):");
        scanf(" %c",&choice);

        if(!(choice == 'y' || choice == 'Y' ))
        {
            printf("Termination\n");
            break;
        }
    }
    return 0;
}