// Free fall threshold
#define THRESHOLD 65  
#define PREFIX "LBB_"

void setup() {
  Serial.begin(); 
  Bean.enableConfigSave(false);
  Bean.setLed(0, 0, 0);
}

void loop() {
  for(int i = 0; i < 10; i++){
    AccelerationReading currentAccel = Bean.getAcceleration();   
    uint32_t magnitude = abs(currentAccel.xAxis) + abs(currentAccel.yAxis) + abs(currentAccel.zAxis);
    
    // Is the Bean in free fall?                                            
    if(magnitude < THRESHOLD){
      String res = "";
      uint8_t r = 0;
      uint8_t g = 0;
      uint8_t b = 0;
      
      int rand = random(6);
      
      switch(rand) {
        case 0:
          res = "1 (Red)";
          r = 255; g = 0; b = 0;
          break; 
          
        case 1:
          res = "2 (Yellow)";
          r = 255; g = 255; b = 0;
          break; 
          
        case 2:
          res = "3 (Fuschia)";
          r = 255; g = 0; b = 255;
          break; 
       
        case 3:
          res = "4 (Green)";
          r = 0; g = 255; b = 0;
          break;
        
        case 4:
          res = "5 (Aqua)";
          r = 0; g = 255; b = 255;
          break;
        
        case 5:
          res = "6 (Blue)";
          r = 0; g = 0; b = 255;
          break;   
       }
      
       Serial.println(res);
       Bean.setLed(r, g, b);
       
       String beanName = PREFIX;
       beanName += res;
       Bean.setBeanName(beanName);
       
       Bean.sleep(1000);
    }
    
    Bean.sleep(50);
  }
}


