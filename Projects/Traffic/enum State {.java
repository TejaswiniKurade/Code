enum State {
  NORMAL,
  EXCEPTION
};

State state = NORMAL;

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

void loop() {
  Serial.println("Hello");
  delay(1000);
  switch (state) {
    case NORMAL:
      // check data condition
      if (is_data_condition_met()) {
        // enter exception state
        state = EXCEPTION;
        // handle exception
        handle_exception();
      }
      break;
    case EXCEPTION:
      // handle exception
      handle_exception();
      // check if exception is resolved
      if (is_exception_resolved()) {
        // return to normal state
        state = NORMAL;
      }
      break;
  }
  // continue normal loop code
}
int distance()
{
    static int d=10;
    d--;
    delay(5000);
    return d;
  
}
bool is_data_condition_met() 
{
  // code to check data condition
  int d=distance();
  if(d<10)
  {
    return true;
  }
}

void handle_exception() 
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

bool is_exception_resolved()
 {
    // code to check if exception is resolved
    if(d==0)
    {
      return true;
    }
}