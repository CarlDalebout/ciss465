//main.cpp

#include <iostream>
#include "Room.h"

int main ()
{
  Room rooms;
  rooms.parse_line("123 single_bed 193.45 1\n"); //room_number|room_type|room_price|available
  return 0;
}
