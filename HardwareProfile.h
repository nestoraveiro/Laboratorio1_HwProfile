/*
 #ifndef _HARDWARE_PROFILE_H    
#define _HARDWARE_PROFILE_H

#define LEDA_SetDigitalOutput() (TRISAbits.TRISA7=0)
#define LEDB_SetDigitalOutput() (TRISBbits.TRISB14=0)

#define LEDA_SetHigh()  (LATAbits.LATA7=1)
#define LEDA_SetLow()   (LATAbits.LATA7=0)
#define LEDA_Toggle()   ((PORTAbits.PORTA7==1) ? (LATAbits.LATA7=0):(LATAbits.LATA7=1))

#define LEDB_SetHigh()  (LATBbits.LATB14=1)
#define LEDB_SetLow()   (LATBbits.LATB14=0)
#define LEDB_Toggle()   ((PORTBbits.PORTB14==1) ? (LATBbits.LATB14=0):(LATBbits.LATB14=1))
#endif 
 */

#ifndef _HARDWARE_PROFILE_H    /* Guard against multiple inclusion */
#define _HARDWARE_PROFILE_H

// configura puertos de leds como salidas
#define LEDA_SetDigitalOutput() (TRISAbits.TRISA7=0)
#define LEDB_SetDigitalOutput() (TRISBbits.TRISB14=0)

// configura puertos de botones como entradas discretas
#define BTN2_SetDigitalInput() (ANSELBbits.ANSB15=0, TRISBbits.TRISB15=1)
#define BTN3_SetDigitalInput() (ANSELAbits.ANSA13=0, TRISAbits.TRISA13=1)

// configura pull down en entradas para asegurar el cero al abrir los swtches Y DESHABILITA PULL UP!
#define BTN2_SetPullDown() (CNPDBbits.CNPDB15=1, CNPUBbits.CNPUB15=0)
#define BTN3_SetPullDown() (CNPDAbits.CNPDA13=1, CNPUAbits.CNPUA13=0)

// captura estado de entradas de botones 2 y 3
#define BTN2_getvalue   PORTBbits.RB15
#define BTN3_getvalue   PORTAbits.RA13

//

#define LEDA_SetHigh()  (LATAbits.LATA7=1)
#define LEDA_SetLow()   (LATAbits.LATA7=0)
#define LEDA_Toggle()   (LATAbits.LATA7=!PORTAbits.RA7)

#define LEDB_SetHigh()  (LATBbits.LATB14=1)
#define LEDB_SetLow()   (LATBbits.LATB14=0)
#define LEDB_Toggle()   (LATBbits.LATB14=!PORTBbits.RB14)

//.......................................... Configuraciones de Hardware para INTERRUPCIONES LAB 2.....
//............................................Habilitar interrupciones.................................
// Habilitar control y estilo de notificaciones por Botones 2(A) y 3(B)
#define BTN2_SetInt() do {\ CNCONAbits.ON=1;\ CNCONAbits.CNSTYLE=1;\} while(0);
#define BTN3_SetInt() do {\CNCONBbits.ON=1;\CNCONBbits.CNSTYLE=1;\} while(0);

//....................................SETEO DE TRANSICIONES............................................
//BOTON A
#define BTN2_SetIntLowEdge() do {\CNEN0Abits.CNIE0A15=0;\ CNEN1Abits.CNIE1A15=1;\} while(0);
#define BTN2_SetIntHighEdge() do {\CNEN0Abits.CNIE0A15=1;\ CNEN1Abits.CNIE1A15=0;\} while(0);
#define BTN2_SetIntBothEdge() do {\CNEN0Abits.CNIE0A15=1;\ CNEN1Abits.CNIE1A15=1;\} while(0);
//BOTON B
#define BTN3_SetIntLowEdge() do {\CNEN0Bbits.CNIE0B15=0;\ CNEN1Bbits.CNIE1B15=1;\} while(0);
#define BTN3_SetIntHighEdge() do {\CNEN0Bbits.CNIE0B15=1;\ CNEN1Bbits.CNIE1B15=0;\} while(0);
#define BTN3_SetIntBothEdge() do {\CNEN0Bbits.CNIE0B15=1;\ CNEN1Bbits.CNIE1B15=1;\} while(0);

//.........................................VECTORES Y PRIORIDADES..........................................
//Interupcoionde con multi vectores
#define INT_init() do {\INTCONbits.VS=1;\INTCONbits.MVEC=1;\}while(0); //REVISAR EL VS puede que no sea necesario
//
#define INT_init() do {\IPC2bits.CNCIP=2;


\INTCONbits.MVEC=1;\}while(0); //REVISAR EL VS puede que no sea necesario


#endif