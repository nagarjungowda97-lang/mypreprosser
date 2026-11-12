#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int file_inclusion(int argc,char ** argv)
{
FILE * fp=fopen(argv[1],"r"),*fs;
if(fp==0)
{
printf("file not present\n");
return 0;
}
char t[50],*p,*z,*x,ang[50][50],*y,path[100];
int len,i,c=0,j=0,k=0,ch;
len=strlen(argv[1]);
for(i=0;i<len-1;i++)
t[i]=argv[1][i];
t[i++]='i';
t[i]='\0';
fs=fopen(t,"w");
/*if(fs==0)
{
printf("file not present\n");
perror("out file\n");
fclose(fp);
return 1;
}
*/
//printf("%s\n",t);
while((ch=fgetc(fp))!=-1)
c++;
//printf("%d\n",c);
p=malloc((c+1));
z=malloc((c+1)*1000000);
rewind(fp);
i=0;
while((ch=fgetc(fp))!=-1)
p[i++]=ch;
p[i]='\0';
x=p;
c=0;
j=0;
while(*x)
{
if(strstr(x,"#include")==x)
{
c++;
//x+=8;
y=x+8;
//z++;
while(*y && *y==' ')
y++;
if(*(y)=='"')
{
i=0;
y++;
while(*y && *y!='"' && i<49)
{
ang[j][i++]=*y;
y++;
}
ang[j][i]='\0';
j++;
}
else if(*y=='<')
{
i=0;
y++;
while(*y && *y!='>' && i<49)
{
ang[j][i++]=*y;
y++;
}
ang[j][i]='\0';
j++;
}
x+=8;
}
else
x++;
}
//printf("%s\n",y);
k=0;
//printf("%d\n",c);
for(i=0;i<j;i++)
{
//printf("%s\n",ang[i]);
}
FILE *fh1;
for(i=0;i<j;i++)
{
fh1=fopen(ang[i],"r");
if(fh1==0)
{
strcpy(path,"/usr/include/");
strcat(path,ang[i]);
fh1=fopen(path,"r");
if(fh1==0)
{
printf("file not found\n");
continue;
}
}
while((ch=fgetc(fh1))!=-1)
z[k++]=ch;
fclose(fh1);
//z[k]='\0';
//printf("%s\n",z);
}
x=y+1;
if(j>0)
{
//y++;
for(i=0;x[i];i++,k++)
z[k]=x[i];
}
z[k]='\0';
//printf("%s\n",z);
fprintf(fs,"%s\n",z);
fclose(fp);
fclose(fs);
//fclose(fh1);
free(p);
free(z);
return 0;
}

