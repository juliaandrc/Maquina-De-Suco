#include "tela1.h"
#include "tela2.h"
#include "config.h"
#include "lcd.h"
#include "ssd.h"
#include "io.h"
#include "keypad.h"
#include "bits.h"
#include "atraso.h"

void Tela1(void) {
    char i;
    char time;
    unsigned char tecla;

    lcdCommand(0X80);
    lcdString("Suco: Laranja(L)");
    lcdCommand(0XC0);
    lcdString("Suco: Morango(R)");

    for (;;) {
        ssdUpdate();
        kpDebounce();
   
            if(kpReadKey() == 'L')  {
                lcdCommand(0x01);
                ssdDigit(1, 3);
                lcdString("Suco de Laranja");
                lcdCommand(0XC0);
                lcdString("Selecionado");
                atraso_ms(1500);
                lcdCommand(0x01);
                Tela2();
            }
            if(kpReadKey() == 'R') {
                lcdCommand(0x01);
                lcdString("Suco de Morango");
                lcdCommand(0XC0);
                lcdString("Selecionado");
                atraso_ms(1500);
                ssdDigit(2, 3);
                lcdCommand(0x01);
                Tela2();
            }
    }
}
