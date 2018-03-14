#include <SPI.h>
#include <Pixy.h>

// This is the main Pixy object
Pixy pixy;

void setup()
{
  Serial.begin(9600);
  Serial.print("Starting...\n");

  pixy.init();
}

int X = 5;
int runXtimes = 0; //setting up a variable to determine number of times loop should be run
int x1, y1, x2, y2, x3, y3, x4, y4;

void loop()
{
  if (runXtimes < X) //if statement to determine number of times to run through program
  {
    static int i = 0;
    int j;
    uint16_t blocks;
    char buf[32];

    // grab blocks!
    blocks = pixy.getBlocks();

    // If there are detect blocks, print them!
    if (blocks)
    {
      i++;

      // do this (print) every 50 frames because printing every
      // frame would bog down the Arduino
      if (i % 50 == 0)
      {
        sprintf(buf, "Detected %d:\n", blocks);
        Serial.print(buf);
        for (j = 0; j < blocks; j++)
        {
          if (j==0)
          {
          sprintf(buf, "  block %d: ", j);
          Serial.print(buf);
          pixy.blocks[j].print();
          x1 = pixy.blocks[j].x; //store the x coordinate of the point as x1
          y1 = pixy.blocks[j].y; //store the y coordinate of the point as y1
          }
          else if (j==1)
          {
          sprintf(buf, "  block %d: ", j);
          Serial.print(buf);
          pixy.blocks[j].print();
          x2 = pixy.blocks[j].x; //store the x coordinate of the point as x2
          y2 = pixy.blocks[j].y; //store the y coordinate of the point as y2
          }
          else if (j==2)
          {
          sprintf(buf, "  block %d: ", j);
          Serial.print(buf);
          pixy.blocks[j].print();
          x3 = pixy.blocks[j].x; //store the x coordinate of the point as x3
          y3 = pixy.blocks[j].y; //store the y coordinate of the point as y3
          }
          else if (j==3)
          {
          sprintf(buf, "  block %d: ", j);
          Serial.print(buf);
          pixy.blocks[j].print();
          x4 = pixy.blocks[j].x; //store the x coordinate of the point as x4
          y4 = pixy.blocks[j].y; //store the y coordinate of the point as y4
          }
        }
        runXtimes++; //count up the number of times run
      }
    }
  }
  else if (runXtimes == X) //else if, print coordinates of the point on the desired run
  {
    Serial.print("The X Coordinate of point 1 is: ");
    Serial.println(x1);
    Serial.print("The Y Coordinate of point 1 is: ");
    Serial.println(y1);
    Serial.print("The X Coordinate of point 2 is: ");
    Serial.println(x2);
    Serial.print("The Y Coordinate of point 2 is: ");
    Serial.println(y2);
    Serial.print("The X Coordinate of point 3 is: ");
    Serial.println(x3);
    Serial.print("The Y Coordinate of point 3 is: ");
    Serial.println(y3);
    Serial.print("The X Coordinate of point 4 is: ");
    Serial.println(x4);
    Serial.print("The Y Coordinate of point 4 is: ");
    Serial.println(y4);
    runXtimes++;

//assuming that the distances from the origin will always be 1, 2, 3, 4 (from closest to furthest)
    int len_1, len_2, len_3, len_4, tmp, i, j;
    int n=3;
    len_1 = sqrt(x1^2+y1^2);
    len_2 = sqrt(x2^2+y2^2);
    len_3 = sqrt(x3^2+y3^2);
    len_4 = sqrt(x4^2+y4^2);

//sort the array in acending order
    coord_array = [len_1, len_2, len_3, len_4];
    for(i=0;i<n;i++){
      for(j=0;j<n-i;j++){
        if(ar[j]>ar[j+1]){
          tmp=ar[j];
          ar[j]=ar[j+1];
          ar[j+1]=tmp;
          }
        }
     }
    coord_1 = coord_array[0];
    coord_2 = coord_array[1];
    coord_3 = coord_array[2];
    coord_4 = coord_array[3];

    X1 = 

    length_13 = sqrt((x1-x3)^2+(y1-y3)^2)
    length_24 = sqrt((x2-x4)^2+(y2-y4)^2) 
  }
}
