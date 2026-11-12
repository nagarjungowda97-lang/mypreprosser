#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int macro_substitution(int argc,char ** argv)
{
FILE *fp=fopen(argv[1],"r");
if(fp==0)
{
printf("file not present\n");
return 1;
}
int c=0,i,len,j,k,b,flag=0,h,r=0,out,o,u,v,w,match,temp,ch,capacity;
char *p,*g,t[20],m[500][500],n[500][500],*q,*a,*z,f[100],*x,para[500][500],arg[500][500],count[50];
len=strlen(argv[1]);
for(i=0;i<len-1;i++)
t[i]=argv[1][i];
t[i++]='i';
t[i]='\0';
FILE *fs=fopen(t,"w");
while((ch=fgetc(fp))!=-1)
c++;
rewind(fp);
p=malloc(c+1);
z=malloc((c+1));
capacity=c+1;
i=0;
while((ch=fgetc(fp))!=-1)
p[i++]=ch;
p[i]='\0';
rewind(fp);
c=0;
while((fgets(f,100,fp))!=0)
{
if(strstr(f,"#define")!=0)
c++;
}
if(c==0)
{
strcpy(z,p);
fprintf(fs,"%s",z);
fclose(fp);
fclose(fs);
free(p);
free(z);
return 0;
}
x=p;
q=0;
for(h=0;h<c;h++)
{
x=strstr(x,"#define");
if(x==0)
break;
q=x;
x+=7;
/*if(q==0)
{
strcpy(z,p);
fprintf(fs,"%s",z);
fclose(fp);
fclose(fs);
return 0;

}
*/
//a=q;
while(*q!=' ' && *q)
q++;

q++;
a=q;
while(*a!='(' && *a!=' ')
a++;
i=0;
for(;q<a;q++,i++)
m[h][i]=*q;
m[h][i]='\0';
if(*a=='(')
{
a++;
//g=a;
i=0;
while(*a && *a!=')')
{
//for(i=0;a<g;a++,i++)
para[h][i++]=*a;
a++;
}
para[h][i]='\0';
}
//else
//{
//para[h]=0;
//}
q=a+1;
while(*a && *a!='\n')
a++;
for(i=0;q<a;q++,i++)
n[h][i]=*q;
n[h][i]='\0';
a++;
//x+=7;
}
for(i=0;i<c;i++)
printf("%s    %s  %s\n",m[i],para[i],n[i]);
x=p;
for(j=0;x<a;x++,j++)
z[j]=*x;
//printf("%s\n",z);
for(i=0;a[i];i++)
{
flag=0;
for(h=0;h<c;h++)
{
if(a[i]==m[h][0])
{
for(k=0;m[h][k];k++)
if(a[i+k]!=m[h][k])
break;
if(m[h][k]=='\0')
{
temp=k;
if(a[i+k]=='(')
{
r=0;
//out=0;
q=a+i+k+1;
while(*q!=')' && *q)
{
out=0;
while(*q!=',' && *q!=')')
{
arg[r][out++]=*q;
q++;
}
arg[r][out]='\0';
r++;
if(*q==',')
q++;
}
out=0;
b=0;
while(n[h][b])
{
if((n[h][b]>='a' && n[h][b]<='z') ||
(n[h][b]>='A' && n[h][b]<='Z') ||
n[h][b]=='_')
{
k=0;

while((n[h][b]>='a' && n[h][b]<='z') ||
(n[h][b]>='A' && n[h][b]<='Z') ||
(n[h][b]>='0' && n[h][b]<='9') ||
n[h][b]=='_')
{
count[k++]=n[h][b++];
}
count[k]='\0';

match=0;
v=0;
o=0;

while(para[h][v])
{
w=0;

while(para[h][v+w] && para[h][v+w]!=',')
w++;

if(w==k)
{
for(u=0;u<k;u++)
if(count[u]!=para[h][v+u])
break;
if(count[u]=='\0')
{
for(u=0;arg[o][u];u++)
f[out++]=arg[o][u];

match=1;
break;
}
}

v+=w;

if(para[h][v]==',')
v++;

o++;
}

if(match==0)
{
for(u=0;count[u];u++)
f[out++]=count[u];
}
}
else
{
f[out++]=n[h][b++];
}
}

f[out]='\0';
strcpy(n[h],f);



}
for(o=0;o<r;o++)
printf("%s\n",arg[o]);
for(b=0;n[h][b];b++,j++)
z[j]=n[h][b];
while(j+(int)strlen(n[h])+1>capacity)
{
capacity=capacity*2;
z=realloc(z,capacity);
}
if(a[i+temp]=='(')
i=q-a;
else
i+=temp-1;
flag=1;
break;
}
}
}
if(flag==0)
{
z[j]=a[i];
if(j+1>=capacity)
{
capacity=capacity*2;
z=realloc(z,capacity);
}
j++;
}
}
fprintf(fs,"%s\n",z);
fclose(fp);
fclose(fs);
free(p);
free(z);
return 0;
}

