#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

// Program which allows you to create rename or delete a directory from within the current directory.
//Options are "c" to make a directory, "d" to delete a directory, or "r" to rename a directory. 

int main(int ac, char* inp[])
{
 if(ac < 2 || ac > 4)
 {
  printf("dirp OPTION FILE [FILE]");
  return 0;
 }

 // checks which command the users inputs and if the correct # of arguements are entered.
 if(inp[1][1] == 'c' && ac == 3)
 {
  mkdir(inp[2], 0744);
 }
 else if(inp[1][1] == 'd' && ac == 3)
 {
  if( rmdir(inp[2]) == -1)
  {
	//checks error type.
   int errchk = errno;
   if(errchk == ENOENT)
   {
    printf("ERROR: directory does not exist. ");
    return 0;
   }
   else if (errchk = ENOTEMPTY)
   {
	   printf("ERROR: directory is not empty, please delete or move files in directory. ");
   }
   else
   {
	   printf("Something happened.");
	   return 0;
   }
  }
 }
 else if(inp[1][1] == 'r' && ac == 4)
 {
  rename(inp[2], inp[3]);
 }
 
return 0;
}
