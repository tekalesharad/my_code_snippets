#include <stdio.h>

main()
{
int startX=0;
int startY=0;
int maxX=6, maxY=6;
int x, y;
int z=0;

	for ( y=startY; y<=maxY ; y += 2 )
	{
		for ( x=startX; x<=maxX; x += 2 )
		{
			printf("%d %d \n", x, y );

			if( y == 6 )
			{
				printf("Max Y reached.. return");
				return;
			}

			if( x == 6 )	
			{
				printf("Max X reached..  reset values %d %d \n", x, y);
				//x=startX;
				goto END_X;
			}
		} 
END_X:
	z=0;
	}
}
