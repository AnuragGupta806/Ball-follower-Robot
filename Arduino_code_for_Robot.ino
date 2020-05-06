int rl = 9;
int fl = 5;
int fr = 10;
int rr = 6;
String s, p, q;
float d, x, y;                                   //Variables Declared

void setup() {
  pinMode(rl, OUTPUT);
  pinMode(fl, OUTPUT);
  pinMode(rr, OUTPUT);
  pinMode(fr, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  //Pins Setup
}

void loop() {
  if (Serial.available())                         //Obtain serial data from Raspberry pi about ball
  {
    s = Serial.readStringUntil('\n');             // reads centre of ball and its distance from robot
    d = s.toFloat();
    Serial.read();
    p = Serial.readStringUntil('\n');
    x = p.toFloat();                               //X coordinate of ball
    Serial.read();
    q = Serial.readStringUntil('\n');
    y = q.toFloat();                              //Y coordinate of ball
    if (d > 20)
    {
      digitalWrite(13, LOW);
      forward();
      if (y < 70)
        HLeft();
      else {
        if (x > 380 && x < 620)
          turnRight();
        else if (x < 250 && x > 20)
          turnLeft();
        else if (x >= 250 && x <= 380)
          forward();
        else if (x >= 620)
          HRight();
        else if (x <= 20)
          HLeft();
      }
    }
    else if (d <= 20) {
      if (y < 70)
        HLeft();
      else
      {
        if (x > 620)
          HRight();
        else if (x < 20)
          HLeft();
        else
          pause();
      }
      digitalWrite(13, HIGH);
    }


  }
}
void forward()
{
  analogWrite(fl, 170);
  analogWrite(fr, 170);
  analogWrite(rl, 0);
  analogWrite(rr, 0);
}

void turnLeft()
{
  analogWrite(fl, 120);
  analogWrite(fr, 195);
  analogWrite(rl, 0);
  analogWrite(rr, 0);
}

void turnRight()
{
  analogWrite(fl, 195);
  analogWrite(rr, 0);
  analogWrite(rl, 0);
  analogWrite(fr, 120);
}

void pause()
{
  analogWrite(fl, 0);
  analogWrite(rr, 0);
  analogWrite(rl, 0);
  analogWrite(fr, 0);
}

void HLeft()                     // Hard Left motion of Robot
{
  analogWrite(fl, 0);
  analogWrite(rr, 0);
  analogWrite(rl, 0);
  analogWrite(fr, 200);
}

void HRight()                    // Hard Right motion of Robot
{
  analogWrite(fl, 200);
  analogWrite(rr, 0);
  analogWrite(rl, 0);
  analogWrite(fr, 0);
}
