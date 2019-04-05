#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_cmd_int(char *cmd)
{
  char next;
  while(getchar(cmd) == ' ')
    next = getchar(cmd);
  next = getchar(cmd);
  return atoi(next);
}

void create_img()
{
  
}

int main(void)
{
  char cmd[15], **img;
  scanf(" %s", cmd);
  while(cmd != 'X')
  {
    switch(cmd[1])
    {
      case 'I':
	parse_cmd(cmd);
	create_img();
	break;
      case 'C':
	break;
      case 'L':
	break;
      case 'V':
	break;
      case 'H':
	break;
      case 'K':
	break;
      case 'F':
	break;
      case 'S':
	break;
      case 'X':
	break;
      default:
	break;
    }
    scanf(" %s", cmd);
  }
  return 0;
}