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
  pinMode(lane1R,OUTPUT);
  pinMode(lane1R,OUTPUT);
  pinMode(lane1R,OUTPUT);
  
  pinMode(lane2R,OUTPUT);
  pinMode(lane2Y,OUTPUT);
  pinMode(lane2G,OUTPUT);
  
  pinMode(lane3R,OUTPUT);
  pinMode(lane3Y,OUTPUT);
  pinMode(lane3G,OUTPUT);
  
  pinMode(lane4R,OUTPUT);
  pinMode(lane4Y,OUTPUT);
  pinMode(lane4G,OUTPUT);
}

void normal()
{
 //setup
  digitalWrite(lane2G, LOW);
  digitalWrite(lane3G, LOW);
  digitalWrite(lane4G, LOW);

  digitalWrite(lane1R, LOW);
  digitalWrite(lane2R,HIGH);
  digitalWrite(lane3R,HIGH);
  digitalWrite(lane4R,HIGH);

  digitalWrite(lane1Y, LOW);
  digitalWrite(lane2Y, LOW);
  digitalWrite(lane3Y, LOW);
  digitalWrite(lane4Y, LOW);

   //Lane 1
  digitalWrite(lane1G,HIGH);

  delay(7000);
  digitalWrite(lane1G,LOW);
  digitalWrite(lane1Y,HIGH);
  
  delay(3000);
  //Lane2
  digitalWrite(lane1Y,LOW);
  digitalWrite(lane2R,LOW);
  digitalWrite(lane1R,HIGH);
  digitalWrite(lane2G,HIGH);

  delay(7000);
  digitalWrite(lane2G,LOW);
  digitalWrite(lane2Y,HIGH);
  
  delay(3000);
  //Lane3
  digitalWrite(lane2Y,LOW);
  digitalWrite(lane3R,LOW);
  digitalWrite(lane2R,HIGH);
  digitalWrite(lane3G,HIGH);
  
  delay(7000);
  digitalWrite(lane3G,LOW);
  digitalWrite(lane3Y,HIGH);
  
  delay(3000);
  //Lane4
  digitalWrite(lane3Y,LOW);
  digitalWrite(lane4R,LOW);
  digitalWrite(lane3R,HIGH);
  digitalWrite(lane4G,HIGH);

  delay(7000);
  digitalWrite(lane4G,LOW);
  digitalWrite(lane4Y,HIGH);
  
  delay(3000);
}

void emergency()
{
   if (lane==1)
  {digitalWrite(lane1G, HIGH);
  digitalWrite(lane2R, HIGH);
  digitalWrite(lane3R, HIGH);
  digitalWrite(lane4R, HIGH);}

  if (lane==2)
  {digitalWrite(lane1R, HIGH);
  digitalWrite(lane2G, HIGH);
  digitalWrite(lane3R, HIGH);
  digitalWrite(lane4R, HIGH);}

  if (lane==3)
  {digitalWrite(lane1R, HIGH);
  digitalWrite(lane2R, HIGH);
  digitalWrite(lane3G, HIGH);
  digitalWrite(lane4R, HIGH);}

  if (lane==4)
  {digitalWrite(lane1R, HIGH);
  digitalWrite(lane2R, HIGH);
  digitalWrite(lane3R, HIGH);
  digitalWrite(lane4G, HIGH);}
}


int  distance(int d)
{
    d--;
    return d;
}



void loop()
{
    try
    {
      
        normal();
        if(d<20)
        {
          throw("wrong")
        }
      
    }
    catch(const char* exception)
    {
      emergency();
    }
    
}