/**
 * PHP EMBEDDED SYSTEMS 
 * 
 * Smart Home by Andrzej Pichliński
 * Skeleton for MySensors Gateway Serial Wired
 * andrzej.pichlinski@gmail.com
 * 
 * A1 LivingRoom 1
 * A2 LivingRoom 2
 * A3 LivingRoom LED
 * A4 Hall 1 
 * A5 HALL 2
 * A6 Kitchen
 * A7 Bedroom
 * A8 Office
 * A9 Bathroom - @todo: additional
 * A10 WC - @todo: additional
 */

// Enable debug prints to serial monitor
#define MY_DEBUG 


// Enable and select radio type attached
//#define MY_RADIO_NRF24
//#define MY_RADIO_RFM69

// Set LOW transmit power level as default, if you have an amplified NRF-module and
// power your radio separately with a good regulator you can turn up PA level. 
//#define MY_RF24_PA_LEVEL RF24_PA_LOW

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 8000000L
#define MY_BAUD_RATE 38400
#endif

// Flash leds on rx/tx/err
// #define MY_LEDS_BLINKING_FEATURE
// Set blinking period
// #define MY_DEFAULT_LED_BLINK_PERIOD 300

// Inverses the behavior of leds
// #define MY_WITH_LEDS_BLINKING_INVERSE

// Enable inclusion mode
#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
#define MY_INCLUSION_BUTTON_FEATURE

// Inverses behavior of inclusion button (if using external pullup)
//#define MY_INCLUSION_BUTTON_EXTERNAL_PULLUP

// Set inclusion mode duration (in seconds)
#define MY_INCLUSION_MODE_DURATION 60 
// Digital pin used for inclusion mode button
#define MY_INCLUSION_MODE_BUTTON_PIN  13

// Uncomment to override default HW configurations
//#define MY_DEFAULT_ERR_LED_PIN 4  // Error led pin
//#define MY_DEFAULT_RX_LED_PIN  6  // Receive led pin
//#define MY_DEFAULT_TX_LED_PIN  5  // the PCB, on board LED

#include <SPI.h>
#include <MySensors.h>  
#include <Bounce2.h>

// Enable repeater functionality for this node
#define MY_REPEATER_FEATURE


#define RELAY_1   2  // Arduino Digital I/O pin number for first relay (second on pin+1 etc)
#define RELAY_2   3
#define RELAY_3   4
#define RELAY_4   5

#define RELAY_5   6
#define RELAY_6   7
#define RELAY_7   8
#define RELAY_8   9

#define RELAY_9   10
#define RELAY_10  11
#define RELAY_11  12
#define RELAY_12  13

#define NUMBER_OF_RELAYS 12 // Total number of attached relays
#define RELAY_ON 1  // GPIO value to write to turn on attached relay
#define RELAY_OFF 0 // GPIO value to write to turn off attached relay

#define BUTTON_PIN A0
#define BUTTON2_PIN A1
#define BUTTON3_PIN A2
#define BUTTON4_PIN A3

#define BUTTON5_PIN A4
#define BUTTON6_PIN A5
#define BUTTON7_PIN A6
#define BUTTON8_PIN A7

#define BUTTON9_PIN A8
#define BUTTON10_PIN A9
#define BUTTON11_PIN A10
#define BUTTON12_PIN A11

void before() { 
  for (int sensor=1, pin=RELAY_1; sensor<=NUMBER_OF_RELAYS;sensor++, pin++) {
    // Then set relay pins in output mode
    pinMode(pin, OUTPUT);   
    // Set relay to last known state (using eeprom storage) 
    digitalWrite(pin, loadState(sensor)?RELAY_ON:RELAY_OFF);
  }
}
Bounce debouncer = Bounce();
Bounce debouncer2 = Bounce();
Bounce debouncer3 = Bounce();
Bounce debouncer4 = Bounce();

Bounce debouncer5 = Bounce();
Bounce debouncer6 = Bounce();
Bounce debouncer7 = Bounce();
Bounce debouncer8 = Bounce();

Bounce debouncer9 = Bounce();
Bounce debouncer10 = Bounce();
Bounce debouncer11 = Bounce();
Bounce debouncer12 = Bounce();

void setup() { 
  // Setup locally attached sensors
  delay(10000);
   // Setup the button.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
  
  pinMode(BUTTON5_PIN, INPUT_PULLUP);
  pinMode(BUTTON6_PIN, INPUT_PULLUP);
  pinMode(BUTTON7_PIN, INPUT_PULLUP);
  pinMode(BUTTON8_PIN, INPUT_PULLUP);

  pinMode(BUTTON9_PIN, INPUT_PULLUP);
  pinMode(BUTTON10_PIN, INPUT_PULLUP);
  pinMode(BUTTON11_PIN, INPUT_PULLUP);
  pinMode(BUTTON12_PIN, INPUT_PULLUP);
  
  // After setting up the button, setup debouncer.
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5);
  debouncer2.attach(BUTTON2_PIN);
  debouncer2.interval(5);
  debouncer3.attach(BUTTON3_PIN);
  debouncer3.interval(5);
  debouncer4.attach(BUTTON4_PIN);
  debouncer4.interval(5);

  debouncer5.attach(BUTTON5_PIN);
  debouncer5.interval(5);
  debouncer6.attach(BUTTON6_PIN);
  debouncer6.interval(5);
  debouncer7.attach(BUTTON7_PIN);
  debouncer7.interval(5);
  debouncer8.attach(BUTTON8_PIN);
  debouncer8.interval(5);

  debouncer9.attach(BUTTON9_PIN);
  debouncer9.interval(5);
  debouncer10.attach(BUTTON10_PIN);
  debouncer10.interval(5);
  debouncer11.attach(BUTTON11_PIN);
  debouncer11.interval(5);
  debouncer12.attach(BUTTON12_PIN);
  debouncer12.interval(5);
  
  //presentation();
}
void presentation()  
{   
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Relay", "1.0");

  for (int sensor=1, pin=RELAY_1; sensor<=NUMBER_OF_RELAYS;sensor++, pin++) {
    // Register all sensors to gw (they will be created as child devices)
    present(sensor, S_LIGHT);
  }
}

MyMessage msg(1, V_LIGHT);
MyMessage msg2(2, V_LIGHT);
MyMessage msg3(3, V_LIGHT);
MyMessage msg4(4, V_LIGHT);

MyMessage msg5(5, V_LIGHT);
MyMessage msg6(6, V_LIGHT);
MyMessage msg7(7, V_LIGHT);
MyMessage msg8(8, V_LIGHT);

MyMessage msg9(9, V_LIGHT);
MyMessage msg10(10, V_LIGHT);
MyMessage msg11(11, V_LIGHT);
MyMessage msg12(12, V_LIGHT);

void loop() { 
  // Send locally attached sensor data here 
  if (debouncer.update()) {
    // Get the update value.
    int value = debouncer.read();
    // Send in the new value.
    if(value == LOW){
         saveState(1, !loadState(1));
         digitalWrite(RELAY_1, loadState(1)?RELAY_ON:RELAY_OFF);
         send(msg.set(loadState(1)));
         }
  }
  if (debouncer2.update()) {
      int value2 = debouncer2.read();
    if(value2 == LOW){
         saveState(2, !loadState(2));
         digitalWrite(RELAY_2, loadState(2)?RELAY_ON:RELAY_OFF);
         send(msg2.set(loadState(2)));
         }
  }
  if (debouncer3.update()) {
      int value3 = debouncer3.read();
    if(value3 == LOW){
         saveState(3, !loadState(3));
         digitalWrite(RELAY_3, loadState(3)?RELAY_ON:RELAY_OFF);
         send(msg3.set(loadState(3)));
         }
  }
  if (debouncer4.update()) {
      int value4 = debouncer4.read();
    if(value4 == LOW){
         saveState(4, !loadState(4));
         digitalWrite(RELAY_4, loadState(4)?RELAY_ON:RELAY_OFF);
         send(msg4.set(loadState(4)));
         }
  }
  //RELAY 2
  if (debouncer5.update()) {
      int value5 = debouncer5.read();
    if(value5 == LOW){
         saveState(5, !loadState(5));
         digitalWrite(RELAY_5, loadState(5)?RELAY_ON:RELAY_OFF);
         send(msg5.set(loadState(5)));
         }
  }
  if (debouncer6.update()) {
      int value6 = debouncer6.read();
    if(value6 == LOW){
         saveState(6, !loadState(6));
         digitalWrite(RELAY_6, loadState(6)?RELAY_ON:RELAY_OFF);
         send(msg6.set(loadState(6)));
         }
  }
  if (debouncer7.update()) {
      int value7 = debouncer7.read();
    if(value7 == LOW){
         saveState(7, !loadState(7));
         digitalWrite(RELAY_7, loadState(7)?RELAY_ON:RELAY_OFF);
         send(msg7.set(loadState(7)));
         }
  }
  if (debouncer8.update()) {
      int value8 = debouncer8.read();
    if(value8 == LOW){
         saveState(8, !loadState(8));
         digitalWrite(RELAY_8, loadState(8)?RELAY_ON:RELAY_OFF);
         send(msg8.set(loadState(8)));
         }
  }
  //RELAY 3
  if (debouncer9.update()) {
      int value9 = debouncer9.read();
    if(value9 == LOW){
         saveState(9, !loadState(9));
         digitalWrite(RELAY_9, loadState(9)?RELAY_ON:RELAY_OFF);
         send(msg9.set(loadState(9)));
         }
  }
  if (debouncer10.update()) {
      int value10 = debouncer10.read();
    if(value10 == LOW){
         saveState(10, !loadState(10));
         digitalWrite(RELAY_10, loadState(10)?RELAY_ON:RELAY_OFF);
         send(msg10.set(loadState(10)));
         }
  }
  if (debouncer11.update()) {
      int value11 = debouncer11.read();
    if(value11 == LOW){
         saveState(11, !loadState(11));
         digitalWrite(RELAY_11, loadState(11)?RELAY_ON:RELAY_OFF);
         send(msg11.set(loadState(11)));
         }
  }
  if (debouncer12.update()) {
      int value12 = debouncer12.read();
    if(value12 == LOW){
         saveState(12, !loadState(12));
         digitalWrite(RELAY_12, loadState(12)?RELAY_ON:RELAY_OFF);
         send(msg12.set(loadState(12)));
         }
  }
}


void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_LIGHT) {
     // Change relay state
     digitalWrite(message.sensor-1+RELAY_1, message.getBool()?RELAY_ON:RELAY_OFF);
     // Store state in eeprom
     saveState(message.sensor, message.getBool());
     // Write some debug info
     Serial.print("Incoming change for sensor:");
     Serial.print(message.sensor);
     Serial.print(", New status: ");
     Serial.println(message.getBool());
   } 
}
