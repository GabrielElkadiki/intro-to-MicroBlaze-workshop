/******************************************************************************/
/*                                                                            */
/* main.c -- IEEE Carleton Intro to MicroBlaze Workshop source file           */
/*                                                                            */
/******************************************************************************/
/* Author: Gabriel Elkadiki                                                   */
/*                                                                            */
/******************************************************************************/
/* File Description:                                                          */
/*                                                                            */
/* This code will display values from the flash_shift IP on an OLEDrgb screen */
/*                                                                            */
/******************************************************************************/

#include "PmodOLEDrgb.h"
#include "sleep.h"
#include "xil_cache.h"
#include "xparameters.h"

void Initialize();
void EnableCaches();
void DisableCaches();

PmodOLEDrgb oledrgb;

void int_to_bin_str(unsigned int in, char* out){	// This creates a binary character array out of an integer.
  int k;
  for (int c = 12; c >= 0; c--)
  {
	k = in >> c;
	if (k & 1)
		out[c] = '1';
	else
		out[c] = '0';
  }
}

int main(void) {
   Initialize();
   char display[12];				// Our display string, we can only display 12 out of our 16 bits within one line of the OLEDrgb
   int mem_address = 0x44A00000;	// Make sure this matches the address for our IP using the Address Editor in Vivado
   int offset = 0;					// This int will allow us to control which slave register to output (slv_reg0 is 0)
   while(1){						// This program will not stop until we kill it
	   int_to_bin_str(Xil_In32(mem_address + 4*offset), display);	// our Slave Register is accessed and then input to function
	   for(int s = 11; s >= 0; s--){								// We can only output
		  OLEDrgb_DrawGlyph(&oledrgb, display[s]);					// This draws out a character
		  OLEDrgb_AdvanceCursor(&oledrgb);							// This moves the cursor to select the next coordinate (->)
	   }
	   OLEDrgb_SetCursor(&oledrgb, 0, 0);							// This resets the coordinates back to the top left
   }

}

void Initialize() {
   EnableCaches();	// To guarantee the caches are cleaned before running
   DisableCaches();
   EnableCaches();
   OLEDrgb_begin(&oledrgb, XPAR_PMODOLEDRGB_0_AXI_LITE_GPIO_BASEADDR,
         XPAR_PMODOLEDRGB_0_AXI_LITE_SPI_BASEADDR);
}

void EnableCaches() {
#ifdef __MICROBLAZE__
#ifdef XPAR_MICROBLAZE_USE_ICACHE
   Xil_ICacheEnable();
#endif
#ifdef XPAR_MICROBLAZE_USE_DCACHE
   Xil_DCacheEnable();
#endif
#endif
}

void DisableCaches() {
#ifdef __MICROBLAZE__
#ifdef XPAR_MICROBLAZE_USE_DCACHE
   Xil_DCacheDisable();
#endif
#ifdef XPAR_MICROBLAZE_USE_ICACHE
   Xil_ICacheDisable();
#endif
#endif
}
