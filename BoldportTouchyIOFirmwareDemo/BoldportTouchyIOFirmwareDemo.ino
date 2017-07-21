/**
*  BoldportTouchyIOFirmwareDemo sketch
*
*   Created 2017-07-16 by Keith Burzinski  @kbx81  kbx81x@gmail.com
*   
*   This sketch was developed with Boldport Club's project number 6 known as The Cuttle.
*   The Cuttle is effectively an Arduino clone, based on the ATMEGA328P microcontroller.
*   It was connected to Boldport Club's project number 13, known as Cordwood-Too; the
*    #defines below describe the pin-to-LED connections. The Touchy's TX and RX pins were
*    connected to The Cuttle's (Arduino's) RX and TX pins, which correspond to digital
*    I/O pins 0 & 1, respectively.
*   All the hardware was operated at 3.3 volts...this is VERY IMPORTANT as the EFM8SB1
*    microcontroller that is Touchy's brain is a 3.3-volt-only device!
*    
*   The code that follows is by no means great/optimized/pretty code...
*    ...but it should get the point across. :)
*/

// LED pins on the Arduino
#define led1Pin   3
#define led2Pin   5
#define led3Pin   6
#define led4Pin  11
#define led5Pin  10
#define led6Pin   9
#define led7Pin   7
#define led8Pin   8

// LED bits used by the I/O firmware
#define LED1  0x01
#define LED2  0x02
#define LED3  0x04
#define LED4  0x08
#define LED5  0x10
#define LED6  0x20

// button bits used by the I/O firmware
#define BUTTON1   0x01
#define BUTTON2   0x02
#define BUTTON3   0x04
#define BUTTON4   0x08
#define BUTTON5   0x10
#define BUTTON6   0x20

// flag bits used...to indicate things
#define RXERROR   0x20
#define TXERROR   0x40
#define SOF       0x80


void setup() {
  pinMode(led1Pin, OUTPUT);     // sets the digital pin as output
  pinMode(led2Pin, OUTPUT);     // sets the digital pin as output
  pinMode(led3Pin, OUTPUT);     // sets the digital pin as output
  pinMode(led4Pin, OUTPUT);     // sets the digital pin as output
  pinMode(led5Pin, OUTPUT);     // sets the digital pin as output
  pinMode(led6Pin, OUTPUT);     // sets the digital pin as output
  pinMode(led7Pin, OUTPUT);     // sets the digital pin as output
  pinMode(led8Pin, OUTPUT);     // sets the digital pin as output

  analogWrite(led1Pin, 0);      // sets the LED off
  analogWrite(led2Pin, 0);      // sets the LED off
  analogWrite(led3Pin, 0);      // sets the LED off
  analogWrite(led4Pin, 0);      // sets the LED off
  analogWrite(led5Pin, 0);      // sets the LED off
  analogWrite(led6Pin, 0);      // sets the LED off
  digitalWrite(led7Pin, LOW);   // sets the LED off
  digitalWrite(led8Pin, LOW);   // sets the LED off

  Serial.begin(115200);
  Serial.setTimeout(10);
}


void loop() {
  uint8_t intensity = 0, rxByteCounter = 0, rxBuffer[4], txBuffer[4];
  float angle = 0;

  txBuffer[0] = SOF | TXERROR;  // setting TXERROR will cause Touchy to transmit its state to us
  txBuffer[1] = 0;    // turn off all of Touchy's LEDs
  txBuffer[2] = 0;    // this would be LED1 intensity but will be ignored based on byte 0 above
  txBuffer[3] = 0;    // this would be LED6 intensity but will be ignored based on byte 0 above
  Serial.write(txBuffer, 4);   // send it out Serial

  while(true) {
    if (Serial.available()) {      // If anything comes in Serial...
      // digitalWrite(led7Pin, HIGH);    // sets an activity LED on
  
      Serial.readBytes(rxBuffer, 4);  // populate the buffer with bytes received
  
      if (rxBuffer[0] & SOF) {          // if the first byte had our "start of frame" bit set...
        // digitalWrite(led8Pin, HIGH);    // sets an activity LED on
        angle = rxBuffer[3] | (rxBuffer[2] << 8);
        intensity = angle * 32 / 45;    // 256 / 360 reduces to 32 / 45
  
        txBuffer[0] = 0x80 | (~rxBuffer[1] & (LED1 | LED6));
        txBuffer[1] = rxBuffer[1];
        txBuffer[2] = intensity;
        txBuffer[3] = intensity;
        delay(4);   // Touchy needs a few cycles before we transmit to get its head on straight...
        Serial.write(txBuffer, 4);   // send it out Serial
  
        if (rxBuffer[1] & LED1) {
          analogWrite(led1Pin, intensity);
        }
        if (rxBuffer[1] & LED2) {
          analogWrite(led2Pin, intensity);
        }
        if (rxBuffer[1] & LED3) {
          analogWrite(led3Pin, intensity);
        }
        if (rxBuffer[1] & LED4) {
          analogWrite(led4Pin, intensity);
        }
        if (rxBuffer[1] & LED5) {
          analogWrite(led5Pin, intensity);
        }
        if (rxBuffer[1] & LED6) {
          analogWrite(led6Pin, intensity);
        }
      }
  //    digitalWrite(led7Pin, LOW);    // sets an activity LED off
  //    digitalWrite(led8Pin, LOW);    // sets an activity LED off
    }
  }
}
