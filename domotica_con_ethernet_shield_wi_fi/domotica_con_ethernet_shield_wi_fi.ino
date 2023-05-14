
//PROGRAMMA ETHERNET SHIELD CONTROLLO PIN CON IP 

//Version: Arduino * Ethernet shield comando wifi su IP
//Author: Claudio Vella
//:  Francesco Crovelli - Italia
//Progetti e codici su: http://francescocrovelli.softr.app/

//ARDUINO MEGA + ETHERNET SHIELD

#include <Ethernet.h>
#include <SPI.h>
#include <EEPROM.h>


//Settare l`IP manualmente
byte ip[] = { 
  192, 168, 1, 89 };   //Inserire il vostro IP
byte gateway[] = { 
  192, 168, 1, 254 }; //Inserire il vostro gateway (lasciare invariato)
byte subnet[] = { 
  255, 255, 255, 0 }; //Lasciare invariato il subnet mask se non necessario

// se necessario cambiare l'indirizzo MAC ( molto raro)
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

//Porta Ethernet
EthernetServer server = EthernetServer(80); //porta 80 di default 

//Il numero di uscite che si vanno a commutare
int outputQuantity = 10; 
 
//Invertire l`uscita dei Pin
boolean outputInverted = false; //true o false
// Questo viene fatto in caso la scheda relè attiva il relè negativo , invece che su alimentazione positiva

//Aggiornamento pagina Html
int refreshPage = 15; //di default è 10sec. 
//Attenzione che se si aggiornano troppo veloce le pagine potrebbero diventare inacessibbili .

//visualizzare o nascondere " Attivare tutti i pin " pulsanti nella parte inferiore della pagina
int switchOnAllPinsButton = false; //true or false

// Selezionare i Pin in uscita
int outputAddress[10] = {22,24,26,28,30,32,34,36,38,40}; //Inserire il numero dei  10 Pin in uscita
//ATTENZIONE i PIN 10, 11, 12 e 13 sulla scheda Duemilanove sono usati per la ethernet shield, quindi non si possono utilizzare.
//ATTENZIONE i PIN 10, 50, 51, 52 e 53 sulla scheda Arduino Mega sono usati per la ethernet shield, quindi non si possono utilizzare.
//ATTENZIONE il PIN 4, è usato per la SD card,quindi non può essere utilizzato.

// Scrivere il testo del dispositivo che si va ad utilizzare 
String buttonText[10] = {
  "01. Luce Soggiorno","02. Presa Soggiorno","03. Luce Camera","04. Presa Camera","05. Presa Tv ","06. Luce Cucina","07. Presa Cucina","08. Luce Bagno","09. Luci Giardino","10. Cancello"};

// Impostare l'uscita per mantenere l'ultimo stato.
int retainOutputStatus[10] = {1,0,0,0,1,1,1,1,1,1};//1 - mantieni l'ultimo stato . 0 - sarà fuori dopo aver tolto l´alimetazione.

int outp = 0;
boolean printLastCommandOnce = false;
boolean printButtonMenuOnce = false;
boolean initialPrint = true;
String allOn = "";
String allOff = "";
boolean reading = false;
boolean outputStatus[10]; 
String rev = "V 1.0";
unsigned long timeConnectedAt;
boolean writeToEeprom = false;
//EthernetClient client;



void setup(){
  Serial.begin(9600);

  initEepromValues();
  readEepromValues();

  //Set pins as Outputs 
  boolean currentState = false;
  for (int var = 0; var < outputQuantity; var++){

    pinMode(outputAddress[var], OUTPUT);       

    //Passare tutte le uscite , on oppure off all'avvio
    if(outputInverted == true) {
   
      if(outputStatus[var] == 0){currentState = true;}else{currentState = false;} 
      digitalWrite(outputAddress[var], currentState);
      
    }
    else{
      
      
      if(outputStatus[var] == 0){currentState = false;}else{currentState = true;}
      digitalWrite(outputAddress[var], currentState);
    }

  }

 
  Ethernet.begin(mac, ip, gateway, subnet); 

  server.begin();
  Serial.print("Server started at ");
  Serial.println(Ethernet.localIP());
}


void loop(){

  checkForClient();
}

void checkForClient(){

  EthernetClient client = server.available();

  if (client) {

    boolean currentLineIsBlank = true;
    boolean sentHeader = false;

    while (client.connected()) {
      if (client.available()) {

        char c = client.read();
        
          if(c == '*'){

          printHtmlHeader(client); //chiamata per inizializzazione HTML e CSS
          printLoginTitle(client);
          printHtmlFooter(client);
          break;
        }
        
        if(!sentHeader){
          
            printHtmlHeader(client); 
            printHtmlButtonTitle(client); //scrivere il titolo del bottone
            
      
          sentHeader = true;
        }

        if(reading && c == ' '){
          reading = false;
        }

        if(c == '?') {
          reading = true; 
        }

 
        if(reading){
          
          //se l`imput è H l`uscita equivale a 1
          if(c == 'H') {
            outp = 1;
          }
          
          //se l`imput è L l`uscita equivale a 0
          if(c == 'L') {
            outp = 0;
          }
          
          Serial.print(c);   //scrivi il valore c sulla comunicazione seriale
         
          switch (c) {

             case '0':
              
               triggerPin(outputAddress[0], client, outp);
               break;            
             case '1':
            
               triggerPin(outputAddress[1], client, outp);
               break;             
             case '2':
               
               triggerPin(outputAddress[2], client, outp);
               break;
             case '3':
               
               triggerPin(outputAddress[3], client, outp);
               break;
             case '4':
               
               triggerPin(outputAddress[4], client, outp);
               break;
             case '5':
               
               triggerPin(outputAddress[5], client, outp);
               
               break;
             case '6':
               
               triggerPin(outputAddress[6], client, outp);
               break;
             case '7':
               
               triggerPin(outputAddress[7], client, outp);
               break;
             case '8':
               
               triggerPin(outputAddress[8], client, outp);
               break;
             case '9':
               
               triggerPin(outputAddress[9], client, outp);
               break;
          } 

        }
        
        if (c == '\n' && currentLineIsBlank){
          printLastCommandOnce = true;
          printButtonMenuOnce = true;
          triggerPin(777, client, outp); 
          break;
        }
        


        
      }
    }
    
    printHtmlFooter(client); 
 
  } 
else
   {  
  
      
      if (millis() > (timeConnectedAt + 60000)){           

             if (writeToEeprom == true){ 
                 writeEepromValues();  //scrivere sulla EEPROM lo stato delle uscite.
                 Serial.println("Nessun client per più di un minuto.");
                 writeToEeprom = false;
             }
             
      }
   }


}


void triggerPin(int pin, EthernetClient client, int outp){
  

 
  if (pin != 777){ 

    if(outp == 1) {
      if (outputInverted ==false){ 
        digitalWrite(pin, HIGH);
      } 
      else{
        digitalWrite(pin, LOW);
      }
    }
    if(outp == 0){
      if (outputInverted ==false){ 
        digitalWrite(pin, LOW);
      } 
      else{
        digitalWrite(pin, HIGH);
      }
    }


  }
  
  readOutputStatuses();


  
  if (printButtonMenuOnce == true){
    printHtmlButtons(client);
    printButtonMenuOnce = false;
  }

}


void printHtmlButtons(EthernetClient client){

  
  client.println("");
  //client.println("<p>");
  client.println("<FORM>");
  client.println("<table border=\"0\" align=\"center\">");





  
  for (int var = 0; var < outputQuantity; var++)  {      

    
    allOn += "H";
    allOn += outputAddress[var];
    allOff += "L";
    allOff += outputAddress[var];


    client.print("<tr>\n");        


    client.print("<td><h4>");
    client.print(buttonText[var]);
    client.print("</h4></td>\n");

    
    client.print("<td>");
    
    client.print("<INPUT TYPE=\"button\" VALUE=\"ON ");
    
    client.print("\" onClick=\"parent.location='/?H");
    client.print(var);
    client.print("'\"></td>\n");

     
    client.print(" <td><INPUT TYPE=\"button\" VALUE=\"OFF");
    
    client.print("\" onClick=\"parent.location='/?L");
    client.print(var);
    client.print("'\"></td>\n");


    
    if (outputStatus[var] == true ){                                                            
      if (outputInverted == false){                                                              
        client.print(" <td><div class='green-circle'><div class='glare'></div></div></td>\n"); 
      }
      else{                                                                                    
        client.print(" <td><div class='black-circle'><div class='glare'></div></div></td>\n"); 
      }
    }
    else                                                                                      
    {
      if (outputInverted == false){                                                           
        client.print(" <td><div class='black-circle'><div class='glare'></div></div></td>\n"); 
      }
      else{                                                                                    
        client.print(" <td><div class='green-circle'><div class='glare'></div></div></td>\n");                     
      }
    }  




   
    client.print("</tr>\n");  
  }

  if (switchOnAllPinsButton == true ){

   
    client.print("<tr>\n<td><INPUT TYPE=\"button\" VALUE=\"Switch ON All Pins");
    client.print("\" onClick=\"parent.location='/?");
    client.print(allOn);
    client.print("'\"></td>\n");

               
    client.print("<td><INPUT TYPE=\"button\" VALUE=\"Switch OFF All Pins");
    client.print("\" onClick=\"parent.location='/?");
    client.print(allOff);
    client.print("'\"></td>\n<td></td>\n<td></td>\n</tr>\n");
  }

 
  client.println("</table>");
  client.println("</FORM>");
  //client.println("</p>"); 

}


void readOutputStatuses(){
  for (int var = 0; var < outputQuantity; var++)  { 
    outputStatus[var] = digitalRead(outputAddress[var]);
    
  }

}

void readEepromValues(){
    for (int adr = 0; adr < outputQuantity; adr++)  { 
    outputStatus[adr] = EEPROM.read(adr); 
    }
}


void writeEepromValues(){
    for (int adr = 0; adr < outputQuantity; adr++)  { 
    EEPROM.write(adr, outputStatus[adr]);
    }

} 


void initEepromValues(){
      for (int adr = 0; adr < outputQuantity; adr++){        
         if (EEPROM.read(adr) > 1){
                EEPROM.write(adr, 0);
         } 
 
      }
  
}



 void printHtmlHeader(EthernetClient client){
          Serial.print("Serving html Headers at ms -");
          timeConnectedAt = millis(); 
          Serial.print(timeConnectedAt); 
          writeToEeprom = true; 
          
          
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connnection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<head>");

         
          client.println("<title>Ethernet Switching</title>");
          client.println("<meta name=\"description\" content=\"Arduino Controllo Ethernet\"/>");

          
          client.print("<meta http-equiv=\"refresh\" content=\"");
          client.print(refreshPage);
          client.println("; url=/\">");

          
          client.println("<meta name=\"apple-mobile-web-app-capable\" content=\"yes\">");
          client.println("<meta name=\"apple-mobile-web-app-status-bar-style\" content=\"default\">");
          client.println("<meta name=\"viewport\" content=\"width=device-width, user-scalable=no\">");          

          
          client.println("<style type=\"text/css\">");
          client.println("");

          
          client.println("html { height:100%; }");  

          client.println("  body {");
          client.println("    height: 100%;");
          client.println("    margin: 0;");
          client.println("    font-family: helvetica, sans-serif;");
          client.println("    -webkit-text-size-adjust: none;");
          client.println("   }");
          client.println("");
          client.println("body {");
          client.println("    -webkit-background-size: 100% 21px;");
          client.println("    background-color: #C0C0C0;");
          client.println("    background-image:");
          client.println("   }");
          client.println("");
          client.println(".view {");
          client.println("    min-height: 100%;");
          client.println("    overflow: auto;");
          client.println("   }");
          client.println("");
          client.println(".header-wrapper {");
          client.println("    height: 44px;");
          client.println("    font-weight: bold;");
          client.println("    text-shadow: rgba(0,0,0,0.7) 0 -1px 0;");
          client.println("    border-top: solid 1px rgba(255,255,255,0.6);");
          client.println("    border-bottom: solid 1px rgba(0,0,0,0.6);");
          client.println("    color: #fff;");
          client.println("    background-color: #808080;");
          client.println("    background-image:");
          client.println("    -webkit-gradient(linear, left top, left bottom,");
          client.println("    from(rgba(255,255,255,.4)),");
          client.println("    to(rgba(255,255,255,.05)) ),");
          client.println("    -webkit-gradient(linear, left top, left bottom,");
          client.println("    from(transparent),");
          client.println("    to(rgba(0,0,64,.1)) );");
          client.println("    background-repeat: no-repeat;");
          client.println("    background-position: top left, bottom left;");
          client.println("    -webkit-background-size: 100% 21px, 100% 22px;");
          client.println("    -webkit-box-sizing: border-box;");
          client.println("   }");
          client.println("");
          client.println(".header-wrapper h1 {");
          client.println("    text-align: center;");
          client.println("    font-size: 25px;");
          client.println("    line-height: 44px;");
          client.println("    margin: 0;");
          client.println("   }");
          client.println("");
          client.println(".group-wrapper {");
          client.println("    margin: 9px;");
          client.println("    }");
          client.println("");
          client.println(".group-wrapper h2 {");
          client.println("    color: #4c566c;");
          client.println("    font-size: 17px;");
          client.println("    line-height: 0.8;");
          client.println("    font-weight: bold;");
          client.println("    text-shadow: #fff 0 1px 0;");
          client.println("    margin: 20px 10px 12px;");
          client.println("   }");
          client.println("");
          client.println(".group-wrapper h3 {");
          client.println("    color: #4c566c;");
          client.println("    font-size: 12px;");
          client.println("    line-height: 1;");
          client.println("    font-weight: bold;");
          client.println("    text-shadow: #fff 0 1px 0;");
          client.println("    margin: 20px 10px 12px;");
          client.println("   }");
          client.println("");
          client.println(".group-wrapper h4 {");  
          client.println("    color: #212121;");
          client.println("    font-size: 14px;");
          client.println("    line-height: 1;");
          client.println("    font-weight: bold;");
          client.println("    text-shadow: #aaa 1px 1px 3px;");
          client.println("    margin: 5px 5px 5px;");
          client.println("   }");
          client.println(""); 
          client.println(".group-wrapper table {");
          client.println("    background-color: #fff;");
          client.println("    -webkit-border-radius: 10px;");

          client.println("    -moz-border-radius: 10px;");
          client.println("    -khtml-border-radius: 10px;");
          client.println("    border-radius: 10px;");


          client.println("    font-size: 17px;");
          client.println("    line-height: 20px;");
          client.println("    margin: 9px 0 20px;");
          client.println("    border: solid 1px #a9abae;");
          client.println("    padding: 11px 3px 12px 3px;");
          client.println("    margin-left:auto;");
          client.println("    margin-right:auto;");

          client.println("    -moz-transform :scale(1);"); 
          client.println("    -moz-transform-origin: 0 0;");



          client.println("   }");
          client.println("");


          
          client.println(".green-circle {");
          client.println("    display: block;");
          client.println("    height: 23px;");
          client.println("    width: 23px;");
          client.println("    background-color: #0f0;");
          //client.println("    background-color: rgba(200, 132, 198, 0.8);");
          client.println("    -moz-border-radius: 11px;");
          client.println("    -webkit-border-radius: 11px;");
          client.println("    -khtml-border-radius: 11px;");
          client.println("    border-radius: 11px;");
          client.println("    margin-left: 1px;");

          client.println("    background-image: -webkit-gradient(linear, 0% 0%, 0% 90%, from(rgba(46, 184, 0, 0.8)), to(rgba(148, 255, 112, .9)));@");
          client.println("    border: 2px solid #ccc;");
          client.println("    -webkit-box-shadow: rgba(11, 140, 27, 0.5) 0px 10px 16px;");
          client.println("    -moz-box-shadow: rgba(11, 140, 27, 0.5) 0px 10px 16px; /* FF 3.5+ */");
          client.println("    box-shadow: rgba(11, 140, 27, 0.5) 0px 10px 16px; /* FF 3.5+ */");

          client.println("    }");
          client.println("");

          
          client.println(".black-circle {");
          client.println("    display: block;");
          client.println("    height: 23px;");
          client.println("    width: 23px;");
          client.println("    background-color: #FF0000;");
          client.println("    -moz-border-radius: 11px;");
          client.println("    -webkit-border-radius: 11px;");
          client.println("    -khtml-border-radius: 11px;");
          client.println("    border-radius: 11px;");
          client.println("    margin-left: 1px;");
          client.println("    -webkit-box-shadow: rgba(11, 140, 27, 0.5) 0px 10px 16px;");
          client.println("    -moz-box-shadow: rgba(11, 140, 27, 0.5) 0px 10px 16px; /* FF 3.5+ */"); 
          client.println("    box-shadow: rgba(11, 140, 27, 0.5) 0px 10px 16px; /* FF 3.5+ */");
          client.println("    }");
          client.println("");

          
          client.println("   .glare {");
          client.println("      position: relative;");
          client.println("      top: 1;");
          client.println("      left: 5px;");
          client.println("      -webkit-border-radius: 10px;");
          client.println("      -moz-border-radius: 10px;");
          client.println("      -khtml-border-radius: 10px;");
          client.println("      border-radius: 10px;");
          client.println("      height: 1px;");
          client.println("      width: 13px;");
          client.println("      padding: 5px 0;");
          client.println("      background-color: rgba(200, 200, 200, 0.25);");
          client.println("      background-image: -webkit-gradient(linear, 0% 0%, 0% 95%, from(rgba(255, 255, 255, 0.7)), to(rgba(255, 255, 255, 0)));");
          client.println("    }");
          client.println("");


          
          client.println("</style>");
          client.println("</head>");

          
          client.println("<body>");
          client.println("<div class=\"view\">");
          client.println("    <div class=\"header-wrapper\">");
          client.println("      <h1>Arduino Controllo Ethernet</h1>");
          client.println("    </div>");



 }


void printHtmlFooter(EthernetClient client){
    
    printLastCommandOnce = false;
    printButtonMenuOnce = false;
    allOn = "";
    allOff = "";
    
    
    client.println("\n<h3 align=\"center\">&copy; Salvatore Fancello - progettiarduino.weebly.com <br> Italia - 2016 -");
    client.println(rev);
    client.println("</h3></div>\n</div>\n</body>\n</html>");

    delay(1); 

    client.stop(); // chiudi la connessione
    
    Serial.println(" - Fatto, Chiusura connessione.");
    
    delay (2); 
    
 } 


void printHtmlButtonTitle(EthernetClient client){
          client.println("<div  class=\"group-wrapper\">");
          client.println("    <h2>Controllo Dispositivi da Remoto</h2>");
          client.println();
}


void printLoginTitle(EthernetClient client){
      
          client.println("    <h2>Please enter the user data to login.</h2>");
          client.println();
}

