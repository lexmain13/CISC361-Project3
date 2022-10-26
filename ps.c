#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

/*
User program to test the system call
*/
int
main(int argc, char *argv[])
{
  crsp();	//call the crsp function
  exit();	//call exit once it's done
}
