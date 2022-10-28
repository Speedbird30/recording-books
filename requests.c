/*
Name: Sumit Subhash Jadhav
U89612131.
This program uses a dynamically allocated linked list to store the book requests.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TITLE_LEN 100
#define NAME_LEN 30
#define ROOM_LEN 20
struct book{
	char title[TITLE_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char classroom[ROOM_LEN+1];
	double price;
	struct book *next;
};


struct book *add_to_end(struct book *list);
void search(struct book *list);
void print_list(struct book *list);
void clear_list(struct book *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct book *book_list = NULL;
  printf("Operation Code: a for adding to the list, s for searching a book"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': book_list = add_to_end(book_list);
                break;
      case 's': search(book_list);
                break;
      case 'p': print_list(book_list);
                break;
      case 'q': clear_list(book_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct book *add_to_end(struct book *list)
/*
Ask the user to enter a book’s title, author’s first name, author’s last name, and classroom and
checks whether the book has already existed by title, author’s name, and classroom.
*/
{

    struct book *new_list;
    new_list = malloc(sizeof(struct book));
    struct book *temp = NULL;
    list = malloc(sizeof(struct book));
    if(new_list == NULL)   //as long as there is still memory to allocate
    {
        printf("Memory allocation failed");
        return list;
    }
    printf("Title: ");
    read_line(new_list->title, TITLE_LEN);
    printf("First name of the author: ");
    read_line(new_list->first, NAME_LEN);
    printf("Last name of the author: ");
    read_line(new_list->last, NAME_LEN);
    printf("Enter classroom: ");
    read_line(new_list->classroom, ROOM_LEN);

    for (temp=list; temp!=NULL; temp=temp->next)
    {
        if(strcmp(temp->title,new_list->title)==0 && strcmp(temp->first,new_list->first)==0 && strcmp(temp->last,new_list->last)==0 && strcmp(temp->classroom,new_list->classroom)==0)
        {
            printf("Book already exists.");
            free(new_list);
            break;
        }
        else
        {
            printf("Enter price: ");
            scanf("%lf",&new_list->price);
            new_list->next = NULL;
            return new_list;
        }
    }
    return new_list;
}

void search(struct book *list)   //finds all the books with title
{

    struct book *a; //a is used to store temporary value
    a = malloc(sizeof(struct book));

    printf("Title : ");
    read_line(a->title, TITLE_LEN);

    while (list != NULL)
        {
        if (strcmp(a->title,list->title)==0)
        {
            printf("Title : %s \n", list->title);
            printf("Another Name: %s \n", list->first);
            printf("Classroom : %s \n",list->classroom);
            printf("Price of the book : %lf \n", list->price);
            break;
        }
        else
        {
            printf("Book not found");
            break;
        }

    }

}
void print_list(struct book *list) // print the title, author, price, and classroom of all books in the list
{
    while (list != NULL)
    {
        printf("Title: %s\n", list->title);
        printf("Author: %s %s\n", list->first, list->last);
        printf("Classroom: %s", list->classroom);
        printf("Price: $%.2f", list->price);
        list = list -> next;
    }
}
void clear_list(struct book *list)   //memory allocated for the linked list is released
{
  struct book *p;
  while(list != NULL)
  {
	 p = list;
     list = list->next;
     if( p!= NULL)
           free(p);
  }
}
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()));
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
   }
   str[i] = '\0';
   return i;
}
