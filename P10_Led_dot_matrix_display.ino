

#include <Arial14.h>
#include <Arial_black_16.h>
#include <Arial_Black_16_ISO_8859_1.h>
#include <DMD.h>
#include <SystemFont5x7.h>
#include <SPI.h>
#include "TimerOne.h"
#include <SoftwareSerial.h> 
/* you can remove the fonts if unused */
#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1
DMD dmd( DISPLAYS_ACROSS , DISPLAYS_DOWN );
DMD display(1,1);

void ScanDMD()
{ 
dmd.scanDisplayBySPI();
}

void setup(){
    Timer1.initialize( 3000 );           
   Timer1.attachInterrupt(ScanDMD);    

Serial.begin(9600);
Timer1.initialize( 2000 );           
Timer1.attachInterrupt( ScanDMD );  
dmd.clearScreen( true );            
}

String textToScroll="WELCOMES ";

void drawText( String dispString ){
dmd.clearScreen( true );
dmd.selectFont( Arial_Black_16 );
char newString[256];
int sLength = dispString.length();
dispString.toCharArray( newString, sLength+1 );
dmd.drawMarquee( newString , sLength , ( 32*DISPLAYS_ACROSS )-1 ,0);
long start=millis();
long timer=start;
long timer2=start;
boolean ret=false;
while( !ret ){
if ( ( timer+30 ) < millis() ) {
  ret=dmd.stepMarquee( -1 , 0 );
  timer=millis();
}
}
}

void loop()
{  Serial.println(textToScroll);
drawText(textToScroll);
  {   Timer1.initialize( 1000 );           
Timer1.attachInterrupt( ScanDMD );  
display.clearScreen(true);
display.selectFont(System5x7);                     
display.drawString(5,0,"HI",4, GRAPHICS_NORMAL); 
display.drawString(5,9,"FRND",4, GRAPHICS_NORMAL);     
display.clearScreen(true);
display.drawString(5,0,"Tomorrow never comes",  GRAPHICS_NORMAL);
display.drawString(1,9," Be Happy ",5, GRAPHICS_NORMAL); 
delay(2000);
display.clearScreen(true);
display.drawString(2,4,"Its just a begining ",5,  GRAPHICS_NORMAL);        
delay(2000);
display.clearScreen(true);
display.drawString(5,4,"keep Calm",5,  GRAPHICS_NORMAL);   
delay(500);
}}
