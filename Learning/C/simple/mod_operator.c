#include <stdio.h>
#define BLOCK_SIZE 16
main()
{

int i;
int m_size[6] = {16, 6, 26, 32, 35, 40}; 

for (i =0 ;  i <= 8 ; i++) {
printf ("val=%d  rem=%d quo=%d \t ||", m_size[i], m_size[i]/BLOCK_SIZE, m_size[i]%BLOCK_SIZE );
printf ("val=%d  rem=%d quo=%d\n", m_size[i], (m_size[i]+BLOCK_SIZE -1)/BLOCK_SIZE, (m_size[i]+BLOCK_SIZE -1)%BLOCK_SIZE );
}
}
