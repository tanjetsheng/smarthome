#include "unity.h"
#include "smarthousesystem.h"
#include "mock_getcoordinate.h"

void setUp(void)
{}
void tearDown(void)
{}

GpsCoordinate out2km={
  200,
  7445,
};

GpsCoordinate in2km={
  100,
  4345,
};

GpsCoordinate nearGaragedoor={
  225,
  5300,
};

GpsCoordinate  inGarage={
  215,
  5300,
};

GpsCoordinate nearkitchen={
  197,
  5100,
};


void test_smarthousesystem_when_out_house_2km_expect_alloff(void)
{
  getCoordinate_ExpectAndReturn(out2km);
  turn_Expect(AIRCOND,OFF);
  turn_Expect(WATER_HEATER,OFF);
  turn_Expect(GARAGE_DOOR,OFF);
  turn_Expect(KITCHEN_LIGHT,OFF);
  doSmartThing();
  
}

void test_smarthousesystem_when_in_house_2km_expect_kictchenlight_on_waterheater_on(void)
{
  getCoordinate_ExpectAndReturn(in2km);
  turn_Expect(AIRCOND,ON);
  turn_Expect(WATER_HEATER,ON);
    doSmartThing(); 
}

void test_smarthousesystem_neargarage_expect_garagedoor_open(void)
{
 getCoordinate_ExpectAndReturn(nearGaragedoor);
  turn_Expect(GARAGE_DOOR,ON); 
  doSmartThing();
}

void test_smarthousesystem_ingarage_expect_garagedoor_off(void)
{
  getCoordinate_ExpectAndReturn(inGarage);
  turn_Expect(GARAGE_DOOR,OFF);
  doSmartThing();
}

void test_smarthousesystem_nearkitchen_expect_kitchenlight_on(void)
{
  getCoordinate_ExpectAndReturn(nearkitchen);
  turn_Expect(KITCHEN_LIGHT,ON);
  doSmartThing();
}









