#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>

#define FILE_PATH_KEY "/dev/input/event1"
//#define FILE_PATH_KEY "/dev/gpio1"
#define FILE_PATH_LED "/sys/class/leds/led1/brightness"

/*****************************************************/
/* In / Out Test application                         */
/* Takes input from DevKit8000 "user_button"         */
/* and sets LED1 accordingly                         */
/* Uses a blocking read to wait for user_button event*/
/*****************************************************/
int main(int narg, char *argp[])
{
  size_t fileKey, fileLed;
  int errsv;

  printf("using file: %s\n", argp[1]);

  /*
   * Open Files
   */
  if((fileKey = open(argp[1], O_RDONLY | O_NONBLOCK)) < 0) {
    errsv = errno;	
    printf("ERROR:Error opening %s\n", argp[1]);
    return errno;
  }

  /*
   * The gpio_key, uses the input driver 
   * event structure:
   *
   * struct input_event {
   *       struct timeval time;
   *       unsigned short type;
   *       unsigned short code;
   *       unsigned int value;
   * };
   * 
   * See this article: http://www.linuxjournal.com/article/6429
   * and linux doc: linux/Documentation/input/input.txt
   */

//  struct input_event event;
  char event[12];
  char ledVal;
  size_t reader;

  /*
   * Perform a blocking read from the keypad
   */
//  reader = read(fileKey, &event, sizeof(struct input_event));
  reader = read(fileKey, &event, sizeof(event));
  if(reader == -1) {
    errsv = errno;
    printf("Error reading error no: %i\n", errsv); }
  else {
    printf("read elements: %i\n\n", reader); 
//    printf("str = %i\n", event.value); }
    printf("str = %s\n", event); }

  close(fileKey);
  return 0;


}

