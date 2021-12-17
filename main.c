#include "config.h"
#include "lcd.h"
#include "ssd.h"
#include "io.h"
#include "keypad.h"
#include "bits.h"
#include "tela1.h"

//inicio do programa
void main(void) {
pinMode(DISP_1_PIN, OUTPUT);
    pinMode(DISP_2_PIN, OUTPUT);
    pinMode(DISP_3_PIN, OUTPUT);
    pinMode(DISP_4_PIN, OUTPUT);

    char i, j;
    char time;
    unsigned char tecla;
    lcdInit();
    lcdCommand(0X80);
    
        lcdString("MAQUINA DE SUCO");
    
    lcdCommand(0XC0);

        lcdString("(S)");
    
    kpInit();
    ssdInit();
    for (;;) {
        digitalWrite(DISP_1_PIN, LOW);
        digitalWrite(DISP_2_PIN, LOW);
        digitalWrite(DISP_3_PIN, LOW);
        digitalWrite(DISP_4_PIN, LOW);

        kpDebounce();

            if(kpReadKey() == 'S') {
                ssdDigit(0, 3);
                lcdCommand(0x01);
                Tela1();
            }
        
        for (time = 0; time < 100; time++);
          
    }
}

