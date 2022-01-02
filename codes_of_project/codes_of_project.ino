/*
 Project Name : Portable Soil Moisture Meter Device
 Revision Date: 02.01.2022
 Author       : Zeki Tepret
 //-------------------------------------------------------------------------------------------------------------------
 Purpose      : Providing the optimum environment for the plant by measuring the moisture in the soil
 //-------------------------------------------------------------------------------------------------------------------
 System Input :
                1- Soil moisture sensor: To measure the soil moisture
 System Output: 
                1- To display information about the soil and plant
 //--------------------------------------------------------------------------------------------------------------------
 System work  : Soil moisture sensing process is carried out with soil moisture sensor and according to the sensor,
                value LCD is printed some text about plants.
 //----------------------------------------------------------------------------------------------------------------------
 */
 //-----------------------------------------------------------------------------------------------------------------------

 //DEFINITIONS

#include <LiquidCrystal_I2C.h>
const int olcum=A0;
int deger;                              //To store sensor value
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() 
{
  lcd.begin();
  Serial.begin(9600);
 }

void loop() 
{
  deger=analogRead(A0);
  Serial.println(deger);


    if(deger<50){                     //case1        
    lcd.setCursor(1,0);
    lcd.print("Well hydrated");
    delay(3000);
    lcd.clear();
   }
  else if(deger<125){                 //case2
    lcd.setCursor(0,0);
    lcd.print("Hydration level");
    lcd.setCursor(3,1);
    lcd.print("is okay");
    delay(3000);
    lcd.clear();
   }
   else if(deger<300){                 //case3
    lcd.setCursor(0,0);
    lcd.print("Caution! It is ");
    lcd.setCursor(0,1);
    lcd.print("getting thirsty");
    delay(3000);
    lcd.clear();
   }
   else{                               //case4
    lcd.setCursor(0,0);
    lcd.print("Warning! It is");
    lcd.setCursor(0,1);
    lcd.print("about to dry");
    delay(3000);
    lcd.clear();
   }
}
