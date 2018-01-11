#include <graphics.h>
#include<dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int n=-1;
char st[200];

void store(char v1,char v2)
{
n++;
char[n]=v1;
n++;
char[n]='-';
n++
char[n]=v2;
n++;
char[n]=',';
return (st);

}

int chkdisconn(int *p, int erow , int ecol,int directed)
{
int mark[20],i,j;
if(!directed)
{
for(i=0;i<=no;i++)
vertmark[i]='0';



for(i=0;i<no;i++)
{
for(j=0;j<n0;j++)

{ 

if(((i!=erow)&&(j!=ecol))||((i!=ecol)&&(j!=erow)))
{
if(*(p+i*20+j)==1)
{
 
mark[i]=-1;
mark[j]=-1;
}
}
}
for(i=0;i<no;i++)
{
if(mark[i]==-1)
count++;
}
if(count===no.)
rerturn(1);
return(0);
}
}
else
{
for(i=0;i<=no;i++)
vertmark[i]='0';



for(i=0;i<no;i++)
{
for(j=0;j<n0;j++)

{ 

if(((i!=erow)&&(j!=ecol)))
{
if(*(p+i*20+j)==1)
{
 
mark[i]=-1;
mark[j]=-1;
}
}
}
for(i=0;i<no;i++)
{
if(mark[i]==-1)
count++;
}
if(count===no.)
rerturn(1);
return(0);
}


}
}


void intro();
void  eulerpathfinder( int*,int,int,int,char);
void hamilton_path(int*,int,char*);

void main()
{
 int gdriver = DETECT, gmode, errorcode;
 char stylestr[40];

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

 int adja[20][20],diff[20],t=0;
 int i=0,j,row,col,counter=0,no=0,k;
 int count1=0,count2=0,f=0,r=0,z=0;
 int u=0,h=0;
 int midx,midy,maxx,maxy,maxcol;
 char vertices[20],ch;
 char edges[200],gr;
 char *p;
 int s=0;
 int deg[20],arr[20][20];

 midx = getmaxx() / 2;
 midy = getmaxy() / 2;
 maxx = getmaxx();
 maxy = getmaxy();
 maxcol= getmaxcolor();

  _setcursortype(_SOLIDCURSOR);

 /* p is a pointer used to access every element of edges array */

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

 re:

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
   else
    goto re;

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
 outtextxy(330,129,"Your graph has   vertices and   edges.");
 settextstyle(2, HORIZ_DIR, 5);
 outtextxy(330,179,"Do you wish to continue to have a look of adjancy matrix?");
 gotoxy(38,9);
 printf("%d",no);
 gotoxy(57,9);
 printf("%d",counter);

 if((getch()=='y')||(getch()=='Y'))
  {
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
     gotoxy(29,10+u);
     for(j=0;j<no;j++)
      {
       gotoxy(29+h,10+u);
       printf("%d",adja[i][j]);
       h=h+5;
      }
    }

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
   }//if(gr=='y')

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
    eulerpathfinder(&adja[0][0],counter,no,k,gr);
   }
 }        //if getch=='y'

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
  if(f==no)
   {
    t=1;
    outtextxy(330,170,"EULER PATH EXISTS!!!");
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
    eulerpathfinder(&adja[0][0],counter,no,k,gr);
   }
 getch();
 }//gr==n

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
	exit(0);
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
      k=0;
      for(j=0;j<no;j++)
       {
	if((adja[i][j]!=0)||(i==j))
	 continue;
	else
	 {
	  arr[i][k]=j;
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
	  exit(0);
	 }
       }
     }
    if(i==no)
     {
      outtextxy(330,170,"HAMILTONIAN PATH EXISTS!!!");
     }
   }
  closegraph();
  getch();
 }


void eulerpathfinder(int *p,int counter,int no,int nextv,char directed)
{

int go=-1,i,j,next;
if(directed=='y')
{
for(j=0;j<=no;j++)
{

if((*(p+nextv*20+j))==1)
{
if(chkdisconn(p,nextv,j))
{
store(nextv,j);
*(p+nextv*20+j)=-1;
*(p+ j*20+nextv)=-1;
edge++;

eulerpathfinder(p,j);
return;
}
else
next=j;
}
}
if(next!=-1)
return(eulerpathfinder(p,next));
else

{
if(edges==counter)
{
if(startingvertex==nextv)
{
printf("EULER CIRCUIT");
printf("%s",store);
return
}
else
{
printf("EULER PATH EXISTS")
printf("%s",store);
return
}
}

 printf("NEITHER EULER PATH NOR EULER CIRCUIT EXIXTS");
 return;
}
}
else
{
for(j=0;j<=no;j++)
{

if((*(p+nextv*20+j))==1)
{
if(chkdisconn(p,nextv,j))
{
store(nextv,j);
*(p+nextv*20+j)=-1;
edge++;

eulerpathfinder(p,j);
return;
}
else
next=j;
}
}
if(next!=-1)
return(eulerpathfinder(p,next));
else

{
if(edges==counter)
{
if(startingvertex==nextv)
{
printf("EULER CIRCUIT");
for(i=0;i<=n;i++)
printf("%c",st[i]);
return
}
else
{
printf("EULER PATH EXISTS")
printf("%c",st[i]);
return
}
}

 printf("NEITHER EULER PATH NOR EULER CIRCUIT EXIXTS");
 return;
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
	{
	 if(*(x+p*20+j)==1)
	  *(x+p*20+j)=-1;
	}
       i=j;
      }
     if(f==no)
      {
       gotoxy(30,15);
       for(s=0;s<no;s++)
	{
	 gotoxy(30+q,15);
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
      *(x+i*20+j)==1;
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