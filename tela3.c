#include "tela3.h"
#include "config.h"
#include "lcd.h"
#include "atraso.h"
#include "ssd.h"
#include "io.h"
#include "keypad.h"
#include "bits.h"

void Tela3(void) {

    unsigned char i, j;
    char tecla;
    char msg1[11] = "FAZENDO...";
    char msg2[15] = "PEDIDO PRONTO!";

    lcdCommand(0x01);
    lcdCommand(0X80);

    lcdString("FAZENDO...");
    
    atraso_ms(5000);
    for (;;) {
        ssdUpdate();
        lcdCommand(0XC0);

            lcdString("PEDIDO PRONTO!");
        

       
    }
}
