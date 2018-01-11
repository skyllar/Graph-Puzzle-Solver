#include <graphics.h>
#include<dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
# include<string.h>



void intro();
void  euler_path( int*,int,int,int,char*,char);
void hamilton_path(int*,int,char*);
void color(char*,int,int*);
void cover(char*,int,int*);
void matching(char*,int ,int*);

void main()
{

 int gdriver = DETECT, gmode, errorcode;
 char stylestr[40];
  int adja[20][20],diff[20],t=0;
 int i=0,j,row,col,counter=0,no=0;
 int count1=0,count2=0,f=0,r=0,z=0;
 int u=0,h=0;
 char vertices[20],ch;
 char edges[200],gr;
 /* p is a pointer used to access every element of edges array */
 char *p;
 int k=0;
 int deg[20],arr[20][20];
 int midx,midy,maxx,maxy,maxcol;

 /* initialize graphics and local variables */
 initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  /* read result of initialization */
 errorcode = graphresult();

 if (errorcode != grOk)  /* an error occurred */
  {
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1); /* terminate with an error code */
  }



/* edges array takes a set of edges as input,
   adja is used for adjacency matrix, counter contains the no. of edges in
   the graph, vertices array consists of the vertices in the graph */




 midx = getmaxx() / 2;
 midy = getmaxy() / 2;
 maxx = getmaxx();
 maxy = getmaxy();
 maxcol= getmaxcolor();

clrscr();
 /*vertices array initialised to character '0' so that it doesn't contain
   any garbage value */

for(i=0;i<20;i++)
{
 vertices[i]='0';
}

/* adja array is initialised to 0
   so that it doesn't contain any garbage value */

for(i=0;i<20;i++)
{
 for(j=0;j<20;j++)
 {
  adja[i][j]=0;
 }
}
for(i=0;i<20;i++)
{
 diff[i]=0;

}

intro();

 getch();
 clrscr();

setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0,maxx, midy/4-5);
 bar(0, 0,midx/4-15, maxy);
 bar(0, 7*midy/4-25,maxx, maxy);
 bar(7*midx/4+15, 0,maxx, maxy);
 setfillstyle(0, maxcol);
 bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(1, HORIZ_DIR, 3);

 outtextxy(250,100,"Enter the set of edges....");
 settextstyle(2, HORIZ_DIR, 5);
 outtextxy(330,125,"(as in following manner..{a-b,b-c,c-d,d-a,a-c})");
 outtextxy(330,137,"(please ensure the small letters, comma,");
 outtextxy(330,149,"bar between letters and curly braces.)");
 gotoxy(15,13);
 gets(edges);
 settextstyle(1, HORIZ_DIR, 1);
 outtextxy(230,242,"Is it a directed graph?") ;
 gotoxy(50,16) ;
 scanf("%c",&gr);

 getch();
 clrscr();

p=&edges[1];
i=0;
j=0;



 /*entering vertices in vertices array after scanning the set of edges
  and simultaniously making adjacency matrix */

while(1)
 {
  if(('a'<=(*p))&&((*p)<='z'))
  {
   while(vertices[i]!='0')
   {
    i++;
   }
   vertices[i]=*p;
   row=i;
   for(j=0;j<i;j++)
   {
    if(vertices[j]==vertices[i])
    {
     vertices[i]='0';
     row=j;
     break;
    }
   }

   i=0;
   p=p+2;
   while(vertices[i]!='0')
   {
    i++;
   }
   vertices[i]=*p;
   col=i;
   for(j=0;j<i;j++)
   {
    if(vertices[j]==vertices[i])
    {
     vertices[i]='0';
     col=j;
     break;
    }
   }
  if(gr=='y')
  adja[row][col]=1;

  if(gr=='n')
  {
   adja[row][col]=1;
   adja[col][row]=1;
   }
  counter=counter+1;

  }
  p=p+1;
  if(*p==',')
  {

   p=p+1;

   continue;
  }
  if(*p=='}')
  break;
 }
 /* finished the task of making adjacency matrix and vertices array */
for(i=0;i<20;i++)
{
 if(vertices[i]!='0')
  {
   no=no+1;
  }
 }
 setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0,maxx, midy/4-5);
 bar(0, 0,midx/4-15, maxy);
 bar(0, 7*midy/4-25,maxx, maxy);
 bar(7*midx/4+15, 0,maxx, maxy);
 setfillstyle(0, maxcol);
 bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;

 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(1, HORIZ_DIR, 2);
 outtextxy(330,129,"Your graph has   vertices and   edges.");
 settextstyle(2, HORIZ_DIR, 5);
 outtextxy(330,179,"Do you wish to continue to have a look of adjancy matrix?");
 gotoxy(38,9);
 printf("%d",no);
 gotoxy(57,9);
 printf("%d",counter);


 getch();
 clrscr();

 setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0,maxx, midy/4-5);
 bar(0, 0,midx/4-15, maxy);
 bar(0, 7*midy/4-15,maxx, maxy);
 bar(7*midx/4+15, 0,maxx, maxy);
 setfillstyle(0, maxcol);
 bar(midx/4-15,midy/4-5,7*midx/4+25,7*midy/4-15)  ;
 rectangle(midx/4-10,midy/4,7*midx/4+20,7*midy/4-20)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+25,7*midy/4-15)  ;

 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(1, HORIZ_DIR, 3);
 outtextxy(330,110,"THE ADJACENCY MATRIX ");

gotoxy(24,15);
for(i=0;i<no;i++)
  {
  u=u+3;
  gotoxy(24,10+u);
  printf("%c",vertices[i]);
  }
  for(i=0;i<no;i++)
  {
  h=h+5 ;
  gotoxy(24+h,10);
  printf("%c",vertices[i]);
  }
  u=0;

for(i=0;i<no;i++)
{
  h=0;
  u=u+3;
  gotoxy(29,5+u);
  for(j=0;j<no;j++)
  {

   gotoxy(29+h,10+u);
   printf("%d",adja[i][j]);
   h=h+5;
  }
 }
 getch();
 clrscr();

 /* checking whether the graph is directed or not */
 if(gr=='y')
 {

  /* calculating the outgoing degree of every vertex in count1
    and incoming degree of every vertex in count2*/

   for(i=0;i<no;i++)
  {
   count1=0;
   count2=0;
   for(j=0;j<no;j++)
   {
    if(adja[i][j]==1)
     {

     count1=count1+1;
     }

   }
   for(j=0;j<no;j++)
   {
    if(adja[j][i]==1)
     count2=count2+1;
   }

     /* diff[] array consists of the difference of the incoming and
      outgoing degree of every vertex */

    diff[i]=count1-count2;

  }
  /* if the diff. of incoming  and outgoing degree of every vertex is 0
     euler circuit exists */
  for(i=0;i<no;i++)
  {
   if(diff[i]==0)
    {
     /* f is used for calculating the no. of vertices with 0
    difference in outgoing and incoming degree*/

     f=f+1;

    }
   }
   for(i=0;i<no;i++)
   {

    /* difference is 1 and -1 for 2 vertices and all the diff. are 0
     euler path exists */

   if(diff[i]==1)
   {
    r=r+1;
    k=i;

   }
   if(diff[i]==-1)
   {
   z=z+1;
   }
   }
  setfillstyle(10, maxcol);
    /* fill the screen with the pattern */
    bar(0, 0,maxx, midy/4-5);
    bar(0, 0,midx/4-15, maxy);
    bar(0, 7*midy/4-25,maxx, maxy);
    bar(7*midx/4+15, 0,maxx, maxy);
    setfillstyle(0, maxcol);
    bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
    rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
    rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;

    settextjustify(CENTER_TEXT, CENTER_TEXT);
    settextstyle(1, HORIZ_DIR, 2);
    outtextxy(330,129,"and the degree of vertices are...");

  u=0;
  for(i=0;i<no;i++)
  {
  u=u+2;
  gotoxy(30,10+u);
  printf("%c",vertices[i]);

  gotoxy(45,10+u);
  printf("%d",diff[i]);

  }
 getch();
 clrscr();


  setfillstyle(10, maxcol);
  /* fill the screen with the pattern */
  bar(0, 0,maxx, midy/4-5);
  bar(0, 0,midx/4-15, maxy);
  bar(0, 7*midy/4-25,maxx, maxy);
  bar(7*midx/4+15, 0,maxx, maxy);
  setfillstyle(0, maxcol);
  bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
  rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
  rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  settextstyle(1, HORIZ_DIR, 2);


 if(f==no)
 {
  outtextxy(330,170,"EULER CIRCUIT EXISTS!!!");

 /* t is an indicator showing whether a euler circuit or path
   exists or not */
 t=1;
 }
 if((r==1)&&(f==(no-2))&&(z==1))
 {
  outtextxy(330,170,"EULER PATH EXISTS!!!");
 t=1;
 }
 if(t==0)
 {
  outtextxy(330,200,"NEITHER EULER CIRCUIT NOR EULER PATH EXISTS");
 }


 if(t==1)
 {
  /* function for finding the euler path or circuit if exists */

  euler_path(&adja[0][0],counter,no,k,vertices,gr);
  }
 }
r=0;
f=0;

 /* finding euler path or circuit for undirected graph */

if(gr=='n')
{
 for(i=0;i<no;i++)
 {

  count1=0;
  for(j=0;j<no;j++)
  {
   if(adja[j][i]==1)
   {
    count1=count1+1;
   }
  }
   deg[i]=count1;
  if((count1%2)==0)
  {
  f=f+1;
  }
  else
  {
   r=r+1;

  }
 }
setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0,maxx, midy/4-5);
 bar(0, 0,midx/4-15, maxy);
 bar(0, 7*midy/4-25,maxx, maxy);
 bar(7*midx/4+15, 0,maxx, maxy);
 setfillstyle(0, maxcol);
 bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;

 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(1, HORIZ_DIR, 2);

 if(f==no)
  {
  t=1;
      outtextxy(330,170,"EULER CIRCUIT EXISTS!!!");
  }
 if((r==2)&&(f==(no-2)))
 {
 t=1;
  outtextxy(330,170,"EULER PATH EXISTS!!");
 }
 if(t==0)
 {
  outtextxy(330,200,"NEITHER EULER CIRCUIT NOR EULER PATH EXISTS");
 }
 if(t==1)
 {
 euler_path(&adja[0][0],counter,no,k,vertices,gr);
 }

}
getch();
setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0,maxx, midy/4-5);
 bar(0, 0,midx/4-15, maxy);
 bar(0, 7*midy/4-25,maxx, maxy);
 bar(7*midx/4+15, 0,maxx, maxy);
 setfillstyle(0, maxcol);
 bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;

 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(1, HORIZ_DIR, 2);

/*finding whether hamiltonian path exists or not*/
if(gr=='n')
{
 for(i=0;i<=no-1;i++)
 {
  for(j=i+1;j<=no-1;j++)
  {
   if((deg[i]+deg[j])>=no-1)
     continue;
   else
   {

     outtextxy(330,170,"HAMILTONIAN PATH MAY OR MAY NOT EXIST");
	settextstyle(2, HORIZ_DIR, 5);
	outtextxy(330,230,"(Since finding the hamiltonian path is a ");
	outtextxy(330,245,"incomplete problemso it would be appropriate");
	outtextxy(330,260,"to say the above statment.)") ;
       //	 getch();
	// clrscr();
	 goto pos;
   }
  }
 }
 if(i==no)
 {

   outtextxy(330,170,"HAMILTONIAN PATH EXISTS!!!");
  hamilton_path(&adja[0][0],no,vertices);

 }
  /* to check whether hamiltonian circuit exists or not*/
  for(i=0;i<20;i++)
  {
   for(j=0;j<20;j++)
   {
     arr[i][j]=100;
   }
  }
  for(i=0;i<no;i++)
  {
   int k=0;
   for(j=0;j<no;j++)
   {
    if((adja[i][j]!=0)||(i==j))
      continue;
    else
    {
      arr[i][k]=j;
      //printf("%d\t",arr[i][k]);
      k++;
    }
   }
 }
 for(i=0;i<no;i++)
 {
   for(k=0;arr[i][k]!=100;k++)
   {
     if((deg[i]+deg[arr[i][k]])>=no)
       continue;
     else
     {

      outtextxy(330,170,"HAMILTONIAN PATH MAY OR MAY NOT EXIST");
	  settextstyle(2, HORIZ_DIR, 5);
	  outtextxy(330,230,"(Since finding the hamiltonian path is a ");
	  outtextxy(330,245,"incomplete problemso it would be appropriate");
	  outtextxy(330,260,"to say the above statment.)") ;


       goto pos;
     }
   }
 }
 if(i==no)
 {


     outtextxy(330,170,"HAMILTONIAN PATH EXISTS!!!");

 }
   pos:


}

getch();
clrscr();
matching(vertices,no,&adja[0][0]);
getch();
clrscr();
color(vertices,no,&adja[0][0]);
getch();
clrscr();
cover(vertices,no,&adja[0][0]);


getch();
}


void matching(char *vertices, int no,int *x)
{
int i,h=0,j,k,n,v,w=0,arr1[20];
int midx,midy,maxx,maxy,maxcol;
midx = getmaxx() / 2;
 midy = getmaxy() / 2;
 maxx = getmaxx();
 maxy = getmaxy();
 maxcol= getmaxcolor();

for(i=0;i<no;i++)
{
arr1[i]=-1;
}

setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0,maxx, midy/4-5);
 bar(0, 0,midx/4-15, maxy);
 bar(0, 7*midy/4-25,maxx, maxy);
 bar(7*midx/4+15, 0,maxx, maxy);
 setfillstyle(0, maxcol);
 bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;


settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(1, HORIZ_DIR, 4);

outtextxy(330,130,"MATCHING");

settextstyle(2, HORIZ_DIR, 5);
	  outtextxy(330,170,"(It represnt the subset of edges that are ");
	  outtextxy(330,185,"not adjacent to each other");

for(i=0;i<no;i++)
 {
  n=0;
  for(k=0;k<no;k++)
  {
  if(i==arr1[k])
  {
  n=1;
  break;

   }
  }
  if(n==1)
  continue;

  for(j=0;j<no;j++)
  {
   v=0;
  for(k=0;k<no;k++)
  {
  if(j==arr1[k])
  {
  v=1;
  break;
  }
  }
   if(v==1)
   continue;

   if((*(x+i*20+j))==1)
   {

   arr1[w]=i;
   w++;
   arr1[w]=j;
   w++;
   gotoxy(25,15+h);
   printf("%c   -   %c :",vertices[i],vertices[j]);
   h=h+2;
  *(x+i*20+j)= -1;
  *(x+j*20+i)= -1;

   break;
   }
  }

  }
 for(i=0;i<no;i++)
 {
 for(j=0;j<no;j++)
  {
   if((*(x+i*20+j))==-1)
    {
    (*(x+i*20+j))=1;
    (*(x+j*20+i))=1;
   }
   }
   }
}

void euler_path( int *x, int counter, int no, int k ,char *vertices,char gr)
{
 int i,j,y,t,m=0,s=0,flag=0,q;
 char path[60];
  /* path is an array consisting of vertices containing the euler path */

 for(i=0;i<60;i++)
  path[i]='0';
 for(i=k;i<no; )
  {
   if(q==i)
   break;
   q=i;

  /*printing euler path or circuit whatever exists*/

  if(flag==counter)
  {
   gotoxy(20,15);

   for(y=0;y<20;y++)
   {
    if((path[y]!='0')&&(path[y+1]=='0'))
    {
     printf("%c",path[y]);
    }
   if((path[y]!='0')&& (path[y]!=path[y+1])&&(path[y+1]!='0'))
    {
     printf("%c to ",path[y]);
    }

   }
   getch();
   clrscr();

  break;
  }
  flag=flag+1;

   for(j=0;j<no;j++)
   {
    if((*(x+i*20+j))==0)
    {
      continue;
    }
    if((*(x+i*20+j))==-1)
    {


    continue;
    }

    if((*(x+i*20+j))==1)
    {
     path[m]=vertices[i];
     m++;
     path[m]=vertices[j];
     m++;


      /* if an edge is traversed,it is marked as -1 in the adjacency matrix*/
       if(gr=='y')
       {
	(*(x+i*20+j))= -1;
       }
       if(gr=='n')
       {
       (*(x+i*20+j))=-1;
       (*(x+j*20+i))=-1;
       }

      /*  s indicates the no. of edges traversed so far */

       s=s+1;

     i=j;
     break;
    }
    }
    }


if(s<counter)
   {


    for(y=0;y<20;y++)
     path[y]='0';
    for(t=0;t<no;t++)
    {
     for(j=0;j<no;j++)
     {
      if((*(x+t*20+j))==-1)
       *(x+t*20+j)=1;
     }
    }
     /* all the edges are not traversed then again function euler_path is
       called starting with a different vertex */

     k=k+1;
     if(k<no)
     {
     euler_path(x,counter,no,k,vertices,gr);
   }

}

for(i=0;i<no;i++)
{
 for(j=0;j<no;j++)
 {
  if( (*(x+i*20+j))==-1)
   {
    *(x+i*20+j)=1;
   }
  }
 }

}
/*function for findin hamiltonian path*/
void hamilton_path(int* x,int no,char* vertices)
{
char hamilton[20];
int i,j,k=0,p,s,h,f=1,q=0;
for(i=0;((i<no)&&(f!=no));i++)
{
 hamilton[0]=*(vertices+i);
 h=i;
 k++;
 for(j=0;j<no;j++)
 {
  if((*(x+i*20+j)==1)&&(j!=h))
  {
   hamilton[k]=*(vertices+j);
   k++;
   f=f+1;

   *(x+j*20+i)=-1;
   for(p=0;p<no;p++)
   {    if(*(x+p*20+j)==1)
      *(x+p*20+j)=-1;
   }
   i=j;
  }
  if(f==no)
  {
   for(s=0;s<no;s++)
   {
    gotoxy(28+q,15);
    printf("%c to ",hamilton[s]);
   q=q+5;
   }
   getch();
   clrscr();
  }

 }
}
for(i=0;i<20;i++)
{
for(j=0;j<20;j++)
{
  if(*(x+i*20+j)==-1)
   *(x+i*20+j)=1;
}
}
}

void color(char *vertices,int no,int *x)
{int a=0,midx,midy,maxx,maxy,maxcol;
int i,s,k,j,t,l=10;
char *paint[20];
char *color[]={"red","green","blue","magenta","pink","cyan","yellow","black","white","orange"};
int total=1;
for(i=0;i<20;i++)
   paint[i]=0;

 paint[0]=color[0];
 for(i=0,s=1;i<no-1;i++)
 {
   for(k=0;k<=i;k++)
   {
    if(*(x+k*20+i+1)==1)
     continue;
    else
     {
     paint[i+1]=paint[k];
     for(t=0;t<=i;)
     {
      if(*(x+(i+1)*20+t)==1)
       {
	l=strcmp(paint[t],paint[i+1]);
	if(l==0)
	{
	paint[i+1]=0;
	break;
	}
	else
	{
	 t++;
	}
       }
      else
      {
       t++;
      }
     }//3rd for loop
     }//else
     if(paint[i+1]!=0)
       break;
   } // 2nd for loop

   if(k==(i+1)&&(paint[i+1]==0))
   {
     paint[i+1]=color[s];
     s++;
   }

   l=10;
 }

midx = getmaxx() / 2;
 midy = getmaxy() / 2;
 maxx = getmaxx();
 maxy = getmaxy();
 maxcol= getmaxcolor();

setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0,maxx, midy/4-5);
 bar(0, 0,midx/4-15, maxy);
 bar(0, 7*midy/4-25,maxx, maxy);
 bar(7*midx/4+15, 0,maxx, maxy);
 setfillstyle(0, maxcol);
 bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;


settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(1, HORIZ_DIR, 4);

outtextxy(325,130,"COLOURING");

settextstyle(2, HORIZ_DIR, 5);

 for(i=0;i<no;i++)
 {
  gotoxy(20,12+a);
  printf("Color of vertex %c is %s",vertices[i],paint[i]);
  a+=1;
 }

 for(i=1;i<no;i++)
 {
  for(j=0;j<=i-1;)
  {
   if(paint[i]==paint[j])
    break;
   else
    j++;
  }
  if(j==i)
   total++;
 }
 gotoxy(31,22);
 printf("GRAPH IS %d- CHROMATIC",total);

}
void cover(char *vertices,int no,int *x)
{ int midx,midy,maxx,maxy,maxcol;
int deg1[20],m=1,i,t,j,k;
char vset[20],eset[200];
char *pvset=vset;
char *peset=eset;

 for(i=0;i<20;i++)
 {
  vset[i]='0';
  deg1[i]=0;
 }
 for(i=0;i<200;i++)
 {
 eset[i]='0';
 }
 vset[0]=vertices[0];
 for(i=0,t=0;t<no;t++)
 {
  for(j=0;j<no;j++)
  {
   if(*(x+i*20+j)==1)
   {
    deg1[i]++;
    deg1[j]++;
    if(deg1[j]==2)
     {
     *(x+i*20+j)=-1;
     *(x+j*20+i)=-1;
     deg1[i]--;
     deg1[j]--;
     continue;
     }
     *(x+i*20+j)=-1;
     *(x+j*20+i)=-1;

     pvset++;
     *(pvset)=vertices[j];
     *(peset)=vertices[i];
     peset++;
     *peset='-';
     peset++;
     *peset=vertices[j];
     peset++;
     *peset=',';
     peset++;

   }
  }
   for(j=0;j<no;j++)
   {
    if(vset[m]==vertices[j])
    {
     m++;
     i=j;
     break;
    }
   }

 }
 peset--;
 *peset='0';


midx = getmaxx() / 2;
 midy = getmaxy() / 2;
 maxx = getmaxx();
 maxy = getmaxy();
 maxcol= getmaxcolor();

setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0,maxx, midy/4-5);
 bar(0, 0,midx/4-15, maxy);
 bar(0, 7*midy/4-25,maxx, maxy);
 bar(7*midx/4+15, 0,maxx, maxy);
 setfillstyle(0, maxcol);
 bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;


settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(1, HORIZ_DIR, 4);

outtextxy(325,130,"COVERING");
settextstyle(2, HORIZ_DIR, 5);
	  outtextxy(330,170,"(It represnt the set of edges that are ");
	  outtextxy(330,185,"covering every vertex in G");

gotoxy(30,15);
 for(k=0;eset[k]!='0';k++)
  printf("%c ",eset[k]);
 for(i=0;i<no;i++)
 {
 for(j=0;j<no;j++)
  {
   if((*(x+i*20+j))==-1)
    {
    (*(x+i*20+j))=1;
    (*(x+j*20+i))=1;
   }
   }
   }

 }


void intro()
{
 int midx,midy,maxx,maxy,maxcol;
 midx = getmaxx() / 2;
 midy = getmaxy() / 2;
 maxx = getmaxx();
 maxy = getmaxy();
 maxcol= getmaxcolor();
 /* select the fill style */
 setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0, maxx, maxy);
 rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;

 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3); ///6 IS SIZE
 setcolor(4);
 outtextxy(315,125,"WELCOME");
 outtextxy(310,170,"TO");
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
 outtextxy(324,250,"EULER's PATH FINDER");
 getch();//delay(1200);

 clrscr();
 setfillstyle(10, maxcol);
 /* fill the screen with the pattern */
 bar(0, 0, maxx, maxy);
 setcolor(15);
 rectangle(midx/4,midy/4,7*midx/4+10,7*midy/4-30)  ;
 rectangle(midx/4-5,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
 setcolor(4);
 outtextxy(330,200,"INTRODUCTION");
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
 outtextxy(325,250,"(If you don't want an introduction press Esc)");
 if((getch())=='z')
  return;
 else
  {
   setfillstyle(10, maxcol);
   bar(0, 0,maxx, midy/4-5);
   bar(0, 0,midx/4-15, maxy);
   bar(0, 7*midy/4-25,maxx, maxy);
   bar(7*midx/4+15, 0,maxx, maxy);
   setfillstyle(0, maxcol);
   bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
   rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(4, HORIZ_DIR, 4);
   setcolor(4);
   outtextxy(315,100,"INTRODUCTION");
   settextstyle(1, HORIZ_DIR, 2);
   outtextxy(350,160,"LEONARD EULAR was a Swiss mathmatician.");
   outtextxy(330,185,"He is considered to be father of graph theory.");
   outtextxy(330,210,"He solved the very famous Koingsberg bridge ");
   outtextxy(330,235,"problem in 1736 in his very first paper of GT.");

   /* draw ellipse */
   line(240,260,480,260);
   ellipse(300, 300, 0, 360, 40, 15);
   ellipse(430,300,0,360,40,15);
   line(340,300,390,300);
   line(342,302,390,302);
   line(240,340,480,340);
   line(430,285,430,260);
   line(432,285,432,260);
   line(430,315,430,340);
   line(432,315,432,340);
   line(280,260,295,285);
   line(282,260,297,285);
   line(320,260,305,285);
   line(318,260,303,285);
   line(280,340,295,315);
   line(282,340,297,315);
   line(320,340,305,315);
   line(318,340,303,315);
   outtextxy(300,298,"A");
   outtextxy(430,298,"B");
   getch();//delay(2500);

   clrscr();
   setfillstyle(10, maxcol);
   /* fill the screen with the pattern */
   bar(0, 0,maxx, midy/4-5);
   bar(0, 0,midx/4-15, maxy);
   bar(0, 7*midy/4-25,maxx, maxy);
   bar(7*midx/4+15, 0,maxx, maxy);
   setfillstyle(0, maxcol);
   bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
   rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(290,95,"WHAT IS EULAR GRAPH??");
   settextstyle(1, HORIZ_DIR, 2);
   outtextxy(363,145,"In a graph G,if a closed walk contains ") ;
   outtextxy(310,170,"all the edges of the grapg G,the walk is ");
   outtextxy(280,195,"called a EULER LINE or EULER CYCLE.");
   outtextxy(340,225,"A graph G is called as EULER GRAPH if it");
   outtextxy(240,250,"contains a EULER LINE in G.");
   outtextxy(325,290,"An open walk in a graph is called an EULER");
   outtextxy(325,315,"PATH if it contains all the edges of graph G.");
   getch();//delay(2500);

   clrscr();
   setfillstyle(10, maxcol);
   /* fill the screen with the pattern */
   bar(0, 0,maxx, midy/4-5);
   bar(0, 0,midx/4-15, maxy);
   bar(0, 7*midy/4-25,maxx, maxy);
   bar(7*midx/4+15, 0,maxx, maxy);
   setfillstyle(0, maxcol);
   bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
   rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(315,100,"SIR WILLIAM HAMILTON");
   settextstyle(1, HORIZ_DIR, 2);
   outtextxy(370,145,"Sir Rowan Hamilton was a very famous  ");
   outtextxy(332,170,"Irish mathematician. He invented a game ");
   outtextxy(330,195,"consisting of a solid regular dodecahedron ");
   outtextxy(340,220,"in 1857 and the concept is used in solving ");
   outtextxy(317,245,"the famous travelling salesman problem");
   outtextxy(337,270,"where the salesman is to eake a tour of all");
   outtextxy(340,295,"cities going through edges such that no city");
   outtextxy(300,320,"appears more than one in the tour. ");
   getch();//delay(2500);

   clrscr();
   setfillstyle(10, maxcol);
   /* fill the screen with the pattern */
   bar(0, 0,maxx, midy/4-5);
   bar(0, 0,midx/4-15, maxy);
   bar(0, 7*midy/4-25,maxx, maxy);
   bar(7*midx/4+15, 0,maxx, maxy);
   setfillstyle(0, maxcol);
   bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
   rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(4, HORIZ_DIR, 3);
   outtextxy(290,95,"WHAT IS HAMILTONIAN GRAPH?");
   settextstyle(1, HORIZ_DIR, 2);
   outtextxy(363,145,"In a graph G,a circuit that contains") ;
   outtextxy(310,170,"each vertex of G exactly once except the");
   outtextxy(325,195,"terminal vertices that appear twice is called");
   outtextxy(280,225,"as HAMILTONIAN CIRCUIT");
   outtextxy(320,250,"A graph G is called as HAMILTONIAN GRAPH");
   outtextxy(315,275,"if it contains a HAMILTONIAN CIRCUIT in G.");
   outtextxy(323,300,"If we delete one edge from the hamiltonian");
   outtextxy(327,325,"circuit,we get a path called HAMILTONIAN PATH");
   getch();//delay(2500);

   clrscr();
   setfillstyle(10, maxcol);
   /* fill the screen with the pattern */
   bar(0, 0,maxx, midy/4-5);
   bar(0, 0,midx/4-15, maxy);
   bar(0, 7*midy/4-25,maxx, maxy);
   bar(7*midx/4+15, 0,maxx, maxy);
   setfillstyle(0, maxcol);
   bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
   rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(4, HORIZ_DIR, 4);
   outtextxy(310,95,"LET US TAKE A EXAMPLE...");
   settextstyle(1, HORIZ_DIR, 2);
   outtextxy(330,140,"Suppose you wish to know presence of EULER");
   outtextxy(330,165,"or HAMILTONIAN path in following set of edges.");
   outtextxy(325,205,"{ a-b, a-c, b-e, b-c, c-e, e-d, c-d }");
   outtextxy(190,250,"Let us consider the ");
   outtextxy(170,275,"edges undirected.");
   outtextxy(175,305,"Then graph is =>");
   line(370,350,450,350);  //  e-d
   line(370,290,450,290); //  b-c
   line(370,350,370,290);  //  b-e
   line(450,350,450,290); //   c-d
   line(370,350,450,290);//e-c
   line(410,250,370,290);  //   a-b
   line(410,250,450,290);  //    a-c
   settextstyle(2, HORIZ_DIR, 7);
   outtextxy(410,240,"a");
   outtextxy(365,350,"e");
   outtextxy(365,290,"b");
   outtextxy(455,290,"c");
   outtextxy(455,350,"d");
   getch();//delay(2500);

   clrscr();
   setfillstyle(10, maxcol);
   /* fill the screen with the pattern */
   bar(0, 0,maxx, midy/4-5);
   bar(0, 0,midx/4-15, maxy);
   bar(0, 7*midy/4-25,maxx, maxy);
   bar(7*midx/4+15, 0,maxx, maxy);
   setfillstyle(0, maxcol);
   bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
   rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(1, HORIZ_DIR, 3);
   outtextxy(310,95,"The graph has both EULER as well");
   outtextxy(310,125," as HAMILTONIAN path");
   settextstyle(1, HORIZ_DIR, 2);
   outtextxy(310,155,"Let us see for Euler first.... ")  ;
   settextstyle(2, HORIZ_DIR, 7);
   outtextxy(300,205,"a");
   outtextxy(245,350,"e");
   outtextxy(245,260,"b");
   outtextxy(355,260,"c");
   outtextxy(355,350,"d");
   delay(500);
   line(250,260,350,260); //  b-c
   delay(500);
   line(300,210,350,260);  //    a-c
   delay(500);
   line(300,210,250,260);  //   a-b
   delay(500);
   line(250,350,250,260);  //  b-e
   delay(500);
   line(250,350,350,350);  //  e-d
   delay(500);
   line(350,350,350,260); //   c-d
   delay(500);
   line(250,350,350,260);//e-c
   delay(1000);

   clrscr();
   setfillstyle(10, maxcol);
   /* fill the screen with the pattern */
   bar(0, 0,maxx, midy/4-5);
   bar(0, 0,midx/4-15, maxy);
   bar(0, 7*midy/4-25,maxx, maxy);
   bar(7*midx/4+15, 0,maxx, maxy);
   setfillstyle(0, maxcol);
   bar(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   rectangle(midx/4-10,midy/4,7*midx/4+10,7*midy/4-30)  ;
   rectangle(midx/4-15,midy/4-5,7*midx/4+15,7*midy/4-25)  ;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   settextstyle(1, HORIZ_DIR, 3);
   outtextxy(310,95,"The graph has both EULER as well");
   outtextxy(310,125," as HAMILTONIAN path");
   settextstyle(1, HORIZ_DIR, 2);
   outtextxy(310,155,"Now for Hamiltonian path.... ")  ;
   settextstyle(2, HORIZ_DIR, 7);
   outtextxy(300,205,"a");
   outtextxy(245,350,"e");
   outtextxy(245,260,"b");
   outtextxy(355,260,"c");
   outtextxy(355,350,"d");
   delay(1000);
   line(300,210,250,260);  //   a-b
   delay(500);
   line(250,350,250,260);  //  b-e
   delay(500);
   line(250,350,350,350);  //  e-d
   delay(500);
   line(350,350,350,260); //   c-d
   delay(500);
  }
}


