int lane1G =13;
int lane1Y =12;
int lane1R =11;

int lane2G =10;
int lane2Y =9;
int lane2R =8;

int lane4G =7;
int lane4Y =6;
int lane4R =5;

int lane3R =4;
int lane3Y =3;
int lane3G =2;

int lane=1;

void setup()
{
  Serial.begin(9600);
}

void normal()
{
  Serial.println("Hello");
  delay(1000);
}

void emergency()
{
   if (lane==1)
  {Serial.println("Lane 1");}

   if (lane==2)
  {Serial.println("Lane 2");}

   if (lane==3)
  {Serial.println("Lane 3");}
  
   if (lane==4)
  {Serial.println("Lane 4");}
  
}


float distance()
{
    static int d=10;
    d--;
  delay(5000);
    return d;
  
}


void loop()
{
    unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;
  if (currentMillis - previousMillis >= 5000) {
    previousMillis = currentMillis;
    int d = distance();
    if (d < 10) {
      emergency();
      return; // Exit the loop to keep the emergency function active
    }
  }
  normal();
}