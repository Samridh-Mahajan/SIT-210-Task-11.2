String command;
const int motor1A = 2;  // Motor 1, input 1
const int motor1B = 3;  // Motor 1, input 2
const int motor2A = 4;  // Motor 2, input 1
const int motor2B = 5;  // Motor 2, input 2
const int motor1C = 6;
const int motor2C = 7;  
String string = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}

void loop() {
  
    command = Serial.readStringUntil('\n');
    command.trim();

     if (command.equals("f") || command.equals("b") || command.equals("l") || command.equals("r") || command.equals("s") || command.equals("c")) {
    string = command;
  }

    if(string.equals("f"))
    {
      Serial.println(command);
      moveForward();
      // delay(2000);
    }
    else if(string.equals("b"))
    {
      Serial.println(command);
      moveBackward();
      // delay(2000);
    }
    else if(string.equals("l"))
    {
      Serial.println(command);
      turnLeft();
      // delay(2000);
    }
    else if(string.equals("r"))
    {
      Serial.println(command);
      turnRight();
      // delay(2000);
    }
    else if(string.equals("s"))
    {
      Serial.println(command);
      Stop();
      // delay(2000);
    }
    else if(string.equals("c"))
    {
      Serial.println(command);
      Conveyor();
      // delay(2000);
    }
    else{
      Stop();
    }
  // }
  delay(1000); 
  
}
void moveForward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void moveBackward() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void turnLeft() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  
  
}

void turnRight() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void Stop()
{
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor1C, LOW);
  digitalWrite(motor2C, LOW);
}
void Conveyor()
{
  digitalWrite(motor1C, HIGH);
  digitalWrite(motor2C, HIGH);
}