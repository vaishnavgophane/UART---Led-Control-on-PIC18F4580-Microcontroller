#include<p18f4580.h>
int main()
{
	int a;
	TRISCbits.RC6 = 0;   // UART Transmit Pin
	TRISCbits.RC7 = 1;   // UART Recieve Pin
	TRISCbits.RC0 = 0;   // LED Pin

	// UART Configuration 
	TXSTA = 0x24; // TXSTA register Configuration
	RCSTA = 0x90; // RCSTA register Configuration
	SPBRG = 0X19;// Baud Rate Calculation

	while(1)
	{
		//TXREG = 'a';// Data Send
		PIR1bits.RCIF = 0; // Interrupt Flag 
		while(PIR1bits.RCIF == 0);
		
			a = RCREG;
			switch(a)
			{
				case '1': 
				PORTCbits.RC0 = 1;
				break;
				case '0':
				PORTCbits.RC0 = 0;
				break;
				PIR1bits.RCIF = 0;// Flag Clear
			}
		
	}	
}