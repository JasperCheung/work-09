#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(){
  printf("adding files...\n");
  int fd = open("0 these.test", O_CREAT | O_RDWR, 0644);
  close(fd);
  fd = open("1 are.test", O_CREAT | O_RDWR, 0644);
  close(fd);
  fd = open("2 regular.test", O_CREAT | O_RDWR, 0644);
  close(fd);
  fd = open("3 files.test", O_CREAT | O_RDWR, 0644);
  close(fd);
  printf("adding directories...\n");
  mkdir("theD",0777);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  DIR *haha = opendir("."); //I OPEN FILE
  printf("Statistics for directory: .\n");
  
  //DIRECTORIES
  
  printf("Directories: \n");
  struct dirent *thing = readdir(haha);
  while( thing ) {
    if (thing -> d_type != DT_REG){
      printf("   %s\n", thing -> d_name);
    }
    thing = readdir(haha);
  }
  
  
  //REGULARRRRRRRRRRRRRRRRRRRRRRRRRRS
  /*
    opendir again to set directory stream to start
    don't have to closedir()??? works though
  */

  haha = opendir("."); 
  thing = haha;
  int hugeness = 0; // v e r y  b i g (in bytes!)
  printf("Regular Files: \n");
   while( thing ) {
    if (thing -> d_type == DT_REG){
      printf("   %s\n", thing -> d_name);
      //size
      struct stat data;
      stat(thing -> d_name, &data);
      hugeness += data.st_size;
    }
    thing = readdir(haha);
   }
   printf("Total size of regular files:\n   %d Bytes\n", hugeness);
   closedir(haha); // DONE!
}
   
  
  


  
  
  
  

 
     
