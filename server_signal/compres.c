#include <stdio.h>
#include <fcntl.h>
int main()
{
 int rfd, d,t1,t2;
 char c[2],temp;
 rfd = open("test.txt", O_RDONLY, 0);
 while (1) {
 d = read(rfd, c, 2);
 t1 = (int)c[0] - 32;
 t1 = ((t1 << 4) >> 4);
 t2 = (int)c[1] - 32;     
 t2 = ((t2 << 4) >> 4);
 temp = (char)(t1 | t2); 
 printf("%c",temp);
 if(d == 1)
 break;
 }
 return 0;
}
 
