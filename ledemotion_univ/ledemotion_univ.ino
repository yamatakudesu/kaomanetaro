int anode[8] = { 7, 15, 16, 5, 18, 6, 8, 9 };
int cathode[8] = { 4,  10,  3,  11,  12,  2,  14,  17};
int mode = 0;

void setup() {
  // open the port by 9600bps
  Serial.begin(9600);
  // anode initialization by LOW
  for(int ano = 0; ano < 8; ano++)
  {
    pinMode(anode[ano],OUTPUT);
    digitalWrite(anode[ano],LOW);
  }
  // cathode initialization by HIGH
  for(int cat = 0; cat < 8; cat++)
  {
    pinMode(cathode[cat],OUTPUT);
    digitalWrite(cathode[cat],HIGH);
  }
}

boolean happiness[8][8]={ {0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0} };

boolean sadness[8][8] ={ {0, 0, 0, 0, 0, 0, 1, 0},
                         {1, 0, 0, 0, 0, 1, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 0},
                         {0, 0, 0, 0, 0, 0, 1, 0} };

boolean neutral[8][8] ={ {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0} };

boolean surprise[8][8]={ {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 1, 1, 1, 0, 0, 0},
                         {0, 1, 0, 0, 1, 0, 0, 0},
                         {0, 1, 0, 0, 1, 0, 0, 0},
                         {0, 0, 1, 1, 1, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0} };

boolean anger[8][8]  = { {0, 0, 0, 1, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 1, 0, 0, 0, 0, 0, 0},
                         {1, 0, 0, 0, 0, 0, 0, 0},
                         {1, 0, 0, 0, 0, 0, 0, 0},
                         {0, 1, 0, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0} };


void loop() {
  if (mode == 1){
        for(int cat = 0; cat < 8; cat++)
      {
        digitalWrite(cathode[cat],LOW); //change to LOW
        //anode loop
        for(int ano = 0; ano < 8; ano++)
        {
          digitalWrite(anode[ano],anger[cat][ano]); //HIGH or LOW
        }
        delayMicroseconds(100); //time of lighting up
        for(int ano = 0; ano < 8; ano++)
        {
          
          digitalWrite(anode[cat],LOW); //return to LOW
        }
        digitalWrite(cathode[cat],HIGH); //return to HIGH
      }
    }
    if (mode == 2){
        for(int cat = 0; cat < 8; cat++)
      {
        digitalWrite(cathode[cat],LOW); //change to LOW
        //anode loop
        for(int ano = 0; ano < 8; ano++)
        {
          digitalWrite(anode[ano],happiness[cat][ano]); //HIGH or LOW
        }
        delayMicroseconds(100); //time of lighting up
        for(int ano = 0; ano < 8; ano++)
        {
          
          digitalWrite(anode[cat],LOW); //return to LOW
        }
        digitalWrite(cathode[cat],HIGH); //return to HIGH
      }
    }
    if (mode == 3){
        for(int cat = 0; cat < 8; cat++)
      {
        digitalWrite(cathode[cat],LOW); //change to LOW
        //anode loop
        for(int ano = 0; ano < 8; ano++)
        {
          digitalWrite(anode[ano],neutral[cat][ano]); //HIGH or LOW
        }
        delayMicroseconds(100); //time of lighting up
        for(int ano = 0; ano < 8; ano++)
        {
          
          digitalWrite(anode[cat],LOW); //return to LOW
        }
        digitalWrite(cathode[cat],HIGH); //return to HIGH
      }
    }
    if (mode == 4){
        for(int cat = 0; cat < 8; cat++)
      {
        digitalWrite(cathode[cat],LOW); //change to LOW
        //anode loop
        for(int ano = 0; ano < 8; ano++)
        {
          digitalWrite(anode[ano],sadness[cat][ano]); //HIGH or LOW
        }
        delayMicroseconds(100); //time of lighting up
        for(int ano = 0; ano < 8; ano++)
        {
          
          digitalWrite(anode[cat],LOW); //return to LOW
        }
        digitalWrite(cathode[cat],HIGH); //return to HIGH
      }
  }
  if (mode == 5){
        for(int cat = 0; cat < 8; cat++)
      {
        digitalWrite(cathode[cat],LOW); //change to LOW
        //anode loop
        for(int ano = 0; ano < 8; ano++)
        {
          digitalWrite(anode[ano],surprise[cat][ano]); //HIGH or LOW
        }
        delayMicroseconds(100); //time of lighting up
        for(int ano = 0; ano < 8; ano++)
        {
          
          digitalWrite(anode[cat],LOW); //return to LOW
        }
        digitalWrite(cathode[cat],HIGH); //return to HIGH
      }
  }
  int tmp;
  if (Serial.available() > 0) {
    tmp = Serial.read();
    Serial.print(tmp); //for debug

    if(tmp != -1){
      Serial.print(tmp);

      switch(tmp){
        case 'a':
          mode = 1;
          break;
        case 'b':
          mode = 2;
          break;
        case 'c':
          mode = 3;
          break;
        case 'd':
          mode = 4;
          break;
        case 'e':
          mode = 5;
          break;
      }
    
    }
  }
}

