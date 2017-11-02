// gpio_blink.c
// toggle a gpio high-low
// gpio23 = P8_13 (see Malloy P8 header chart)
// to configure P8_13 as output:
//   echo 23 > /sys/class/gpio/export
//   echo out > /sys/class/gpio/direction

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
        if(argc!=3){
                printf("Syntax: %s <no_of_times_to_blink> <delay_us>\n",argv[0]);
                return 0;
        }
        int delay=atoi(argv[2]);
        int no=atoi(argv[1]);
        FILE *LEDHandler=NULL;
        char *LEDPath="/sys/class/gpio/gpio23/value";
        int i;
        for(i=0;i<no;i++){
                if(LEDHandler=fopen(LEDPath,"r+")){
                        printf("LED on\n\033[F\033[J");
                        fwrite("1", 1, 1,LEDHandler);
                        fclose(LEDHandler);
                }
                usleep(delay);
                if(LEDHandler=fopen(LEDPath,"r+")){
                        printf("LED off\n\033[F\033[J");
                        fwrite("0", 1, 1,LEDHandler);
                        fclose(LEDHandler);
                }
                usleep(delay);
        }

        return 0;
}


