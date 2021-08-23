#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int width=20,height=20,gameover;
int x,y,fx,fy,score,flag;
int tailx[100],taily[100];
int counttail=0;

void setup()
{
    gameover=0;
    x=width/2;
    y=height/2;
    level1:
    fx=rand()%20;
    if(fx==0)
    goto level1;
    level2:
    fy=rand()%20;
    if(fy==0)
    goto level2;
    score=0;

}

void draw()
{
    int i,j,k;
    system("cls");
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            if(i==0 || j==0 || i==width-1 || j==height-1)printf("*");
            else
            {
                if(i==x && j==y)printf("O");
                else if(i==fx && j==fy)printf("F");
                else
                {
                    int ch=0;
                    for(k=0;k<counttail;k++)
                    {
                        if(i==tailx[k] && j==taily[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                    printf(" ");
                }
                
            }
            
        }
        printf("\n");
    }
    printf("SCORE= %d\n",score);
}

void input()
{
    if(kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 'z':
            flag=4;
            break;
        case 'x':
            gameover=1;
            break;
        }
    }
}

void logic()
{
    int i;
    int prevx=tailx[0],prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(i=1;i<counttail;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(flag)
    {
        case 1:
            y--;break;
        case 2:
            y++;break;
        case 3:
            x--;break;
        case 4:
            x++;break;
        default:
            break;
    }
    if(x<0||x>width||y<0||y>height)gameover=1;
    for(i=0;i<counttail;i++)if(x==tailx[i] && y==taily[i])gameover=1;
    if(x==fx && y==fy)
    {
        level3:
        fx=rand()%20;
        if(fx==0)
        goto level3;
        level4:
        fy=rand()%20;
        if(fy==0)
        goto level4;
        score+=10;
        counttail++;
    }
}

int main()
{
    int m,n;
    level5:
    setup();
    while(gameover==0)
    {
    draw();
    input();
    logic();
    
    for(m=0;m<10000;m++)
    for(n=0;n<10000;n++);

    for(m=0;m<10000;m++)
    for(n=0;n<10000;n++);
    }
    char c;
    printf("Press Y to continue again: ");
    scanf("%c",&c);
    if(c=='y'||c=='Y')
    goto level5;
    return 0;
}
