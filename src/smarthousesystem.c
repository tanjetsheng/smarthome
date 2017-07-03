#include "smarthousesystem.h"
#include "getcoordinate.h"
#include <math.h>
#include <stdlib.h>

GpsCoordinate House={
  200,
  5345,
};

GpsCoordinate GarageDoor={
  220,
  5300,
};

GpsCoordinate Garage={
  215,
  5300,
};

GpsCoordinate Kitchen={
  196,
  5100,
};

void doSmartThing(){
  GpsCoordinate gps;
  gps = getCoordinate();
  
  if(sqrt(pow((gps.x-House.x),2)+(pow((gps.y-House.y),2)))<=2000)
  {
    turn(AIRCOND,ON);
    turn(WATER_HEATER,ON);
  }
  else if(sqrt(pow((gps.x-GarageDoor.x),2)+(pow((gps.y-GarageDoor.y),2)))==5)
  {
    turn(GARAGE_DOOR,ON);
  }
  else if((gps.x==Garage.x)&&(gps.y==Garage.y))
  {
    turn(GARAGE_DOOR,OFF);
  }
  else if(sqrt((pow((gps.x-Kitchen.x),2))+(pow((gps.y-Kitchen.y),2)))<=1)
  {
    turn(KITCHEN_LIGHT,ON);
  }
  else
  {
    turn(AIRCOND,OFF);
    turn(WATER_HEATER,OFF);
    turn(GARAGE_DOOR,OFF);
    turn(KITCHEN_LIGHT,OFF);
  }
}