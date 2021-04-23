#include "HX711.h"

HX711 scale;                          

float calibration_factor = -26.5;          // калибровка!
float units;
float ounces;

void setup() {
  Serial.begin(9600); 
//  scale.begin(A1, A0);
  scale.begin(3, 2);
  scale.set_scale();
  scale.tare();                              //Сбрасываем на 0
  scale.set_scale(calibration_factor);       //Применяем калибровку
}

void loop() { 
  char c;
  String str = "";
  if(Serial.available())  
  {  
    c = Serial.read();
    str += c;
  }
  if(str.equals("H")){
  //  Serial.print("Reading: ");
    
    for(int i = 0;i < 10; i ++) units =+ scale.get_units(), 10;   // усредняем показания считав 10 раз 
    units / 10;                                                   // делим на 10
     
    ounces = units * 0.035274;                                    // переводим унции в граммы           
//    ounces = scale.get_units() * 0.035274;   
    Serial.print(ounces*-1);                                          // отправляем в монитор порта
  //  Serial.print(" grams");  
  //  Serial.println(); 
  }
}
/*#include "HX711.h"

HX711 scale;   // DT, CLK

float calibration_factor = -3.7; // this calibration factor is adjusted according to my load cell
float units;
float ounces;

void setup() {
  Serial.begin(9600);
  scale.begin(A1, A0);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  scale.set_scale();
  scale.tare();  //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
}

void loop() {
  char c;
  String str = "";
  int i = 0;
  /*if(Serial.available())  
  {  
    c = Serial.read();
    str += c;
  }
  
    if(str.equals("H")){*/
/*    scale.set_scale(calibration_factor); //Adjust to this calibration factor
  
    Serial.print("Reading: ");
    units = scale.get_units(), 10;
    if (units < 0)
    {
      units = 0.00;
    }
    ounces = units * 0.035274;
    Serial.print(ounces);
    Serial.print(" grams"); 
    Serial.print(" calibration_factor: ");
    Serial.print(calibration_factor);
    Serial.println();
  
    if(Serial.available())
    {
      char temp = Serial.read();
      if(temp == '+' || temp == 'a')
        calibration_factor += 1;
      else if(temp == '-' || temp == 'z')
        calibration_factor -= 1;
    }
//  }
}*/

/*void setup()  
{  
  Serial.begin(9600);  
}  

void loop()  
{  
  char c;
  if(Serial.available())  
  {  
    c = Serial.read();  
    Serial.print(c);  
  }  
}*/
