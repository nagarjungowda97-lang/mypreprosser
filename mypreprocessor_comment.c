#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comment_removal(int argc,char ** argv)
{
FILE *fp=fopen(argv[1],"r");
char s[100],*t,*p;
int len,i,flag=0,c=0,j,ch;
len=strlen(argv[1]);
for(i=0;i<len-1;i++)
s[i]=argv[1][i];
s[i]='i';
i++;
s[i]='\0';
FILE *fs=fopen(s,"w");
while((ch=fgetc(fp))!=-1)
c++;
p=malloc(c+1);
t=malloc(c+1);
rewind(fp);
i=0;
while((ch=fgetc(fp))!=-1)
p[i++]=ch;
p[i]='\0';
rewind(fp);
for(i=0,j=0;p[i];i++)
{
if(i+1<c && p[i]=='/'&& p[i+1]=='/' )
{
while(p[i]!='\n' && p[i])
i++;
i--;
}
else if(+1<c && p[i]=='/' && p[i+1]=='*')
{
while(i+1<c&&(p[i]!='*' || p[i+1]!='/'))
i++;
if(i+1<c)
i++;
else
break;
}
else
{
t[j]=p[i];
j++;
}
}
t[j]='\0';
fprintf(fs,"%s",t);
fclose(fp);
fclose(fs);
free(p);
free(t);
p=t=0;

return 0;
}

