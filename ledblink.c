#include<stdio.h>

int main()
{
        FILE *LEDHandler=NULL;
        char *LEDPath="/sys/class/leds/beaglebone:green:usr0/brightness";
        
        while(1) {
        if(LEDHandler=fopen(LEDPath,"r+")){
                fwrite("1", 1, 1,LEDHandler);
                fclose(LEDHandler);
        }
        sleep(1);
        if(LEDHandler=fopen(LEDPath,"r+")){
                fwrite("0", 1, 1,LEDHandler);
                fclose(LEDHandler);
        sleep(1);
        }
        }

        return 0;
}

