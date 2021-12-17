#include "tela2.h"
#include "tela3.h"
#include "config.h"
#include "atraso.h"
#include "lcd.h"
#include "ssd.h"
#include "io.h"
#include "keypad.h"
#include "bits.h"

void Tela2(void) {
    char i;
    char time;
    unsigned char tecla;
    lcdCommand(0X80);
 
        lcdString("Tamanho do Copo");
    
    lcdCommand(0XC0);

        lcdString("P(a)  M(b)  G(y)");
    
   
    for (;;) {
        ssdUpdate();
        kpDebounce();
            if(kpReadKey() == 'A') {
                lcdCommand(0x01);
                lcdString("P(a)");
                lcdCommand(0XC0);
                lcdString("Tamanho P Selec.");
                ssdDigit(4, 3);
                atraso_ms(1500);
                lcdCommand(0x01);
                Tela3();
            }
            if(kpReadKey() == 'B') {
                lcdCommand(0x01);
                lcdString("M(b)");
                lcdCommand(0XC0);
                lcdString("Tamanho M Selec.");
                ssdDigit(5, 3);
                atraso_ms(1500);
                lcdCommand(0x01);
                Tela3();
            }
            if(kpReadKey() == 'Y') {
                lcdCommand(0x01);
                lcdString("G(y)");
                lcdCommand(0XC0);
                lcdString("Tamanho G Selec.");
                ssdDigit(6, 3);
                atraso_ms(1500);
                lcdCommand(0x01);
                Tela3();
            }
            
        }
        for (time = 0; time < 100; time++);
    }

