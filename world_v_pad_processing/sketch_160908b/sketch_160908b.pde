float xpos, ypos;
  float tempxpos, tempypos; 
  int size = 20; 
  boolean over = false; 
  boolean move = false; 

  // Spring simulation constants 
  float mass;       // Mass 
  float k = 0.2;    // Spring constant 
  float damp;       // Damping 
  float rest_posx;  // Rest position X 
  float rest_posy;  // Rest position Y 

  // Spring simulation variables 
  //float pos = 20.0; // Position 
  float velx = 0.0;   // X Velocity 
  float vely = 0.0;   // Y Velocity 
  float accel = 0;    // Acceleration 
  float force = 0;    // Force 


  int me;

void setup() {
  size(640, 360);
  noStroke(); 
  
   xpos = tempxpos = 100; 
    ypos = tempypos = 100;
    rest_posx = 100;
    rest_posy = 100;
    size = 0;
    damp = 0.94; 
    mass = 3; 
    k = 0.2;
  

}


void draw() {
  background(51); 
    if (move) { 
      rest_posy = mouseY; 
      rest_posx = mouseX;
    } 

    force = -k * (tempypos - rest_posy);  // f=-ky 
    accel = force / mass;                 // Set the acceleration, f=ma == a=f/m 
    vely = damp * (vely + accel);         // Set the velocity 
    tempypos = tempypos + vely;           // Updated position 

    force = -k * (tempxpos - rest_posx);  // f=-ky 
    accel = force / mass;                 // Set the acceleration, f=ma == a=f/m 
    velx = damp * (velx + accel);         // Set the velocity 
    tempxpos = tempxpos + velx;           // Updated position 

ellipse(100,100,tempxpos, tempypos);


}

void mouseReleased() {
tempxpos=0; tempypos=0;
}