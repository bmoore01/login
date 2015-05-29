#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

FILE *pinFile;

bool compare(char firstString[16], char secondString[16])
{
  int i;
  int len =  (sizeof(*firstString) * 16 );
  for (i = 0;i < len;i++)
    {
      if (firstString[i] != secondString[i])
	{
	  return false;
	}
      else if (firstString[i] == '\0' && secondString[i] == '\0')
	{
	  return true;
	}
    }
  return true;
}

void setPass()
{
  pinFile = fopen("pin.dat","w");
  char pin[16];
  char secondPin[16];
  int match = false;
  do
    {
      printf("Please set your pin:\n ");
      scanf("%s", pin);
      printf("Please enter your pin again:\n ");
      scanf("%s", secondPin);
      match = compare(pin, secondPin);
    } while (match != true);
  fputs(pin,pinFile);
  fclose(pinFile);
}

bool readPass()
{
  char enteredPin[16];
  char filePin[16];
  bool result;
  pinFile = fopen("pin.dat","r");
  fscanf(pinFile,"%s\n",filePin);
  printf("Login:\n");
  printf("Please enter your pin\n");
  scanf("%s", enteredPin);
  if(compare(filePin, enteredPin) == true)
    {
      result = true;
    }
    else
      {
	result = false;
      }
  fclose(pinFile);
  return result;
}
