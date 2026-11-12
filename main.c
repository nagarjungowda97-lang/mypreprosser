#include<stdio.h>
#include<string.h>

int file_inclusion(int argc,char **argv);
int comment_removal(int argc,char **argv);
int macro_substitution(int argc,char **argv);

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        printf("Usage: ./mypreprocessor filename.c\n");
        return 1;
    }

    char s[100];
    char *a[2];

    strcpy(s,argv[1]);
    s[strlen(s)-1]='i';

    a[0]="file_inclusion";
    a[1]=argv[1];
    file_inclusion(2,a);

    rename(s,"temp1.c");

    a[0]="comment_removal";
    a[1]="temp1.c";
    comment_removal(2,a);

    rename("temp1.i","temp2.c");

    a[0]="macro_substitution";
    a[1]="temp2.c";
    macro_substitution(2,a);

    rename("temp2.i",s);


    return 0;
}

