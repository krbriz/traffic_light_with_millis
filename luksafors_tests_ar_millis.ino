const int redPin =  5;   
const int yellowPin =  6;    
const int greenPin =  7;     
const int buttonPin = 4; 

// Variables will change:

int redState = LOW;           
int yellowState = LOW;            
int greenState = LOW;            

long startTime = 0;       

bool pressed = false; 

unsigned long currentTime = millis();
long elapsedTime = currentTime-startTime;


int buttonState = 0;
long cycleTime = 30000;          

void RedBlink()
{
  digitalWrite(redState, HIGH); 
  delay(1000);                      
  digitalWrite(redState, LOW);
  delay(1000);
  
}
void setup() {
  pinMode(redPin, OUTPUT);  
  pinMode(yellowPin, OUTPUT);      
  pinMode(greenPin, OUTPUT); 
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);  

}
void loop()
 {
  if(Serial.available())
  {
    String command = Serial.readStringUntil('\n');

    if(command == "NAKTS")
    {
      Nakts;
      Serial.println("NAKTS REZIIMS IESLEEGTS");
    }
}
currentTime = millis();
bool currentState = digitalRead(buttonPin);
elapsedTime = currentTime-startTime;
  if(elapsedTime > cycleTime)  // this if statement resets the cycle timer
    startTime = currentTime;
    // if the elepsed time is less then 15 seconds set the red state to high:
    if ( elapsedTime > 20000)
      if (currentState == pressed){
      Serial.println("gaajeejs");
      while(digitalRead(buttonPin)== pressed)
      redState = HIGH;}       
    else
      redState = LOW;

    if ( elapsedTime > 15000 && elapsedTime< 20000)
      yellowState = HIGH;
    else
      yellowState = LOW;
    if (elapsedTime < 15000)
      greenState = HIGH;
    else
      greenState = LOW;
    digitalWrite(redPin, redState);
    digitalWrite(yellowPin, yellowState);
    digitalWrite(greenPin, greenState);
}
void Nakts(){
  digitalWrite(yellowState, HIGH);  
  delay(1000);                       
  digitalWrite(yellowState, LOW);    
  delay(1000); 
  }

  
//  }
