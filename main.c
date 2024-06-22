#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct books
{
int id;
char bookName[50];
char authorName[50];
char date[12];
}b;

struct student
{
int id;
char sName[50];
char sClass[50];
int sRoll;
char bookName[50];
char date[12];
}s;


FILE *fp;

int main()
{
      int ch,t_id,t_pass;

        printf("\t\t\t==================================================================\n\n");
        printf("\t\t\t\t\t************User Login************\n\n");
        printf("\t\t\t==================================================================\n\n");

        printf("\t\t\t\t\tEnter Your College ID....");
        scanf("%d",&t_id);
        printf("\t\t\t\t\tEnter Your Personal Passcode....");
        scanf("%d",&t_pass);

    if(123==t_id && 12345==t_pass)
      {

        while(1)
        {
        system("cls");
        printf("\t\t\t============================================================\n\n");
        printf("\t\t\t\t\t Library Book Management System\n\n");
        printf("\t\t\t============================================================\n\n");
        printf("\t====================================================================================================\n");
        printf("\t  1.Add Book");
        printf("\t2.Book List");
        printf("\t3.Remove Book");
        printf("\t4.Issue Book List");
        printf("\t5.Search Book");
        printf("\t0.Exit\n");
        printf("\t====================================================================================================\n\n");
        printf("\t\t\t\t\t\tEnter Your Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 0:
            exit(0);

            case 1:
            addbook();
            break;

            case 2:
            booklist();
            break;

            case 3:
            del();
            break;

            case 4:
            issuelist();
            break;

            case 5:
            search();
            break;

            default:
            printf("Invalid Choice....\n\n");

        }     //Switch Bracket
        }    //While Bracket

     }       //if Bracket

       else if(321==t_id && 54321==t_pass)
         {
            while(1)
            {
        system("cls");
        printf("\t\t\t============================================================\n\n");
        printf("\t\t\t\t\t Students Portal\n\n");
        printf("\t\t\t============================================================\n\n");
        printf("\t====================================================================================================\n");
        printf("\t1.Book List");
        printf("\t2.Search Book");
        printf("\t3.Issue Book");
        printf("\t4.Book Report");
        printf("\t0.Exit\n");
        printf("\t====================================================================================================\n\n");
        printf("\t\t\t\t\t\tEnter Your Choice: ");
        scanf("%d",&ch);

             switch(ch)
             {
             case 0:
             exit(0);

             case 1:
             booklist();
             break;

             case 2:
             search();
             break;

             case 3:
             issuebook();
             break;

             case 4:
             issueelist();
             break;

             default:
             printf("\t\t*******************Invalid Choice*******************\n\n");
             }
           }
       }

    return 0;
}

void addbook()
{
    int b_id;
    char myDate[12];
    time_t t=time(NULL);
    system("cls");
    struct tm tm= *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    strcpy(b.date, myDate);

    fp=fopen("books.txt","a+");
    printf("\t\t\t==================================================================\n\n");
    printf("\t\t\t\t\t************Add Menu************\n\n");
    printf("\t\t\t==================================================================\n\n");

    printf("\t\t\t\t\t-------------------------------------\n");
    printf("\t\t\t\t\t\tEnter book id: ");
    scanf("%d",&b.id);
    while(fread(&b_id,sizeof(b_id),1,fp)==1)
        {
         if(b.id==b_id)
         {
             printf("\t\t\t\t\t-------------------------------------\n");
             printf("\t\t\t\t\tBook is already added in library\n");
             printf("\t\t\t\t\t-------------------------------------\n");
             goto up;
         }
        }

    printf("\t\t\t\t\t-------------------------------------\n");
    printf("\t\t\t\t\t\tEnter book name: ");
    fflush(stdin);
    gets(b.bookName);

    printf("\t\t\t\t\t-------------------------------------\n");
    printf("\t\t\t\t\t\tEnter author name: ");
    fflush(stdin);
    gets(b.authorName);

    printf("\t\t\t\t\t-------------------------------------\n");
    printf("\t\t\t\t\t*********Book Added Successfully*********");
    fwrite(&b,sizeof(b),1,fp);
    up:
    fclose(fp);
    getch();
}


void booklist()
{
  system("cls");
    printf("\t\t\t==============================================================================\n\n");
    printf("\t\t\t\t\t\t************Book List************\n\n");
    printf("\t\t\t==============================================================================\n\n");
    printf("\t\t\t%-10s %-30s %-20s %s\n\n","Book id", "Book Name", "Author", "Date");

    fp=fopen("books.txt","rb");
    while(fread(&b,sizeof(b),1,fp) == 1)
    {
    printf("\t\t\t%-10d %-30s %-20s %s\n\n",b.id, b.bookName, b.authorName, b.date);
    }
  getch();
  fclose(fp);

}

void del()
{
  int id,f=0;

    booklist();
      system("cls");
  printf("\t\t\t==============================================================================\n\n");
  printf("\t\t\t\t\t\t************Remove Book************\n\n");
  printf("\t\t\t==============================================================================\n\n");
  printf("\t\t\t------------------------------------------------------------------------------\n\n");
  printf("\t\t\t\t\tEnter Book id to remove: ");
  scanf("%d",&id);

FILE *ft;

   fp=fopen("books.txt","rb");
   ft=fopen("temp.txt","wb");

     while(fread(&b,sizeof(b),1,fp)==1)
        {
          if(id == b.id)
           {
            f=1;
           }
          else
           {
            fwrite(&b,sizeof(b),1,ft);
           }
       }

    if(f==1)
    {
    printf("\t\t\t------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\tDelete Successfully.");
    }
    else
    {
    printf("\t\t\t------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tRecord Not Found !");
    }

   fclose(fp);
   fclose(ft);

remove("books.txt");
rename("temp.txt","books.txt");
getch();
}

void issuebook()
{
char myDate[12];
time_t t=time(NULL);
struct tm tm=*localtime(&t);
sprintf(myDate, "%02d/%02d/%d",tm.tm_mday, tm.tm_mon+1,tm.tm_year + 1900);
strcpy(s.date,myDate);

int f=0;
system("cls");
printf("\t\t\t==============================================================================\n\n");
printf("\t\t\t\t\t\t************Issue Book************\n\n");
printf("\t\t\t==============================================================================\n\n");

printf("\t\t\t------------------------------------------------------------------------------\n");
printf("\t\t\t\t\tEnter Book id to issue: ");
scanf("%d", &s.id);
fp=fopen("books.txt","ab+");

while(fread(&b, sizeof(b),1,fp) ==1 )
{
    if(b.id == s.id)
        {
          strcpy(s.bookName,b.bookName);
          f=1;
          break;
        }
}

if(f==0)
    {
    printf("No book found with this id\n");
    printf("Please try again...\n\n");
    return;
    }

fp=fopen("issue.txt","ab+");
printf("\t\t\t------------------------------------------------------------------------------\n");
printf("\t\t\t\t\tEnter Student Name: ");
fflush(stdin);
gets(s.sName);

printf("\t\t\t------------------------------------------------------------------------------\n");
printf("\t\t\t\t\tEnter Student Class: ");
fflush(stdin);
gets(s.sClass);

printf("\t\t\t------------------------------------------------------------------------------\n");
printf("\t\t\t\t\tEnter Student Roll: ");
scanf("%d",&s.sRoll);

printf("\t\t\t------------------------------------------------------------------------------\n");
printf("\t\t\t\t\tBook Issued Successsfully\n\n");

fwrite(&s, sizeof(s),1,fp);
fclose(fp);
getch();
}

void issuelist(){
system("cls");
printf("\t\t\t===================================================================================\n\n");
printf("\t\t\t\t\t\t************Book Issue List************\n\n");
printf("\t===============================================================================================================\n\n");

printf("\t%-10s %-30s %-20s %-10s %-25s %s\n\n", "Id","Name","Class","Roll","Book Name", "Date");
fp=fopen("issue.txt","rb+");
while(fread(&s, sizeof(s),1,fp) == 1)
{
    printf("\t%-10d %-30s %-20s %-10d %-25s %s\n",s.id, s.sName, s.sClass, s.sRoll, s.bookName, s.date);
}
fclose(fp);
getch();
}

void search()
{
  char se_book[20];
  system("cls");
printf("\t\t\t==============================================================================\n\n");
printf("\t\t\t\t\t\t************Search Book************\n\n");
printf("\t\t\t==============================================================================\n\n");
  printf("\t\t\t\t\tBook Name...");
  scanf("%s",&se_book);
printf("\t===============================================================================================================\n\n");
  printf("\t\t\t%-10s %-30s %-20s %s\n\n","Book id", "Book Name", "Author", "Date");

  fp=fopen("books.txt","rb");
  while(fread(&b,sizeof(b),1,fp) == 1)
    {
     if(strcmp(b.bookName,se_book)==0)
      {
       printf("\t\t\t%-10d %-30s %-20s %s\n\n",b.id, b.bookName, b.authorName, b.date);
      }
    }

   getch();
   fclose(fp);
}


void issueelist(){

int se_roll;
char se_name[50];

system("cls");
printf("\t\t\t==============================================================================\n\n");
printf("\t\t\t\t\t\t************Your Issue Book Report************\n\n");
printf("\t\t\t==============================================================================\n\n");

printf("\t\t\t------------------------------------------------------------------------------\n");
printf("\t\t\t\t\tEnter Student Name: ");
scanf("%s",&se_name);
printf("\t\t\t------------------------------------------------------------------------------\n");
printf("\t\t\t\t\tEnter Roll Number: ");
scanf("%d",&se_roll);

printf("\t================================================================================================================\n\n");
printf("\t%-10s %-30s %-20s %-10s %-30s %s\n\n", "Id","Name","Class","Roll","Book Name", "Date");
fp=fopen("issue.txt","rb");
while(fread(&s,sizeof(s),1,fp)==1)
        {
         if( (strcmp(s.sName,se_name)==0) && (s.sRoll==se_roll))
                {
                    printf("\t%-10d %-30s %-20s %-10d %-30s %s\n",s.id, s.sName, s.sClass, s.sRoll, s.bookName, s.date);
                }
        }
fclose(fp);
getch();
}
