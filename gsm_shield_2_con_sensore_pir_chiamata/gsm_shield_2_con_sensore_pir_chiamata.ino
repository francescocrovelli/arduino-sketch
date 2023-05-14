
#include <GSM.h>
 
GSM gsmAccess; // initialize the library instance
GSMVoiceCall vcs;
String remoteNumber="insert-here-your-phone-number";
char charBuffer[20];
int digitalPir = 4; // Pir connected to digital pin 4
int statePir = 1; // variable to store the Pir state
 
void setup()
{
  pinMode(digitalPir, INPUT);
  remoteNumber.toCharArray(charBuffer, 20);
  Serial.begin(9600);
  Serial.println("\n- Starting Setup -\n");
 
  // connection state
  boolean notConnected = true;
 
  // start GSM Shield
  while(notConnected) {
    if(gsmAccess.begin()==GSM_READY)
      notConnected = false;
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  Serial.println("GSM initialized.");
  Serial.println("waiting for 10s...");
  delay(10000);
}
 
void loop()
{
  statePir = digitalRead(digitalPir);
  Serial.println(statePir);
 
  if (!statePir) {
    if (vcs.voiceCall(charBuffer)) {
      Serial.println("Call Established. Enter line to end");
      while(vcs.getvoiceCallStatus()==TALKING);
      vcs.hangCall();
      Serial.println("Call finished.");
 
      delay(1000);
    }
 
    Serial.println("Waiting for 30s...");
    delay(30000);
  }
}
