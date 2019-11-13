#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main() {
  /* From the manual:
  struct stat {  when _DARWIN_FEATURE_64_BIT_INODE is defined
         dev_t           st_dev;           ID of device containing file
         mode_t          st_mode;          Mode of file
         nlink_t         st_nlink;         Number of hard links
         ino_t           st_ino;           File serial number
         uid_t           st_uid;           User ID of the file
         gid_t           st_gid;           Group ID of the file
         dev_t           st_rdev;          Device ID
         struct timespec st_atimespec;     time of last access
         struct timespec st_mtimespec;     time of last data modification
         struct timespec st_ctimespec;     time of last status change
         struct timespec st_birthtimespec; time of file creation(birth)
         off_t           st_size;          file size, in bytes
         blkcnt_t        st_blocks;        blocks allocated for file
         blksize_t       st_blksize;       optimal blocksize for I/O
         uint32_t        st_flags;         user defined flags for file
         uint32_t        st_gen;           file generation number
         int32_t         st_lspare;        RESERVED: DO NOT USE!
         int64_t         st_qspare[2];     RESERVED: DO NOT USE!
     };
*/
  struct stat a ;
  stat("main.c", &a) ;
  printf("\n\nSURPRISE! We are using the main file!\n") ;
  printf("\nFile size: %lld bytes\n", a.st_size) ;
  printf("File mode: %d\n", a.st_mode) ;
  printf("Last time accessed: %s\n", ctime(&a.st_atime)) ;

  float x = (float) a.st_size / 1024 ;
  while (x >= 1024) {
    x = x / 1024 ; // KB
    //printf("x = %f\n", x) ;
  }
  float y = (float) a.st_size / 1048576 ;
  while (y >= 1048576) { // MB
    y = y / 1048576 ;
    //printf("y = %f\n", y) ;
  }
  float z = (float) a.st_size / 1073741824 ;
  while (z >= 1073741824) {
    z = z / 1073741824 ; // GB
    //printf("z = %f/n", z) ;
  }
  printf("File size: %f KB, %f MB, %f GB\n", x, y, z) ;

  char p [10] ;
  char pe [10] = "rwxrwxrwx" ;
  int i ;
	for (i = 0 ; i < 9 ; i++) {
		if ( !( (1 << (8-i)) & a.st_mode) ) pe[i] = '-' ;
	}
	strcat(p, pe) ; // add on the permissions
  printf("File permissions: %s\n", p) ;

  return 0 ;
}
