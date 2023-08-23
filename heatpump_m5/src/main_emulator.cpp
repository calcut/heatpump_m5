
#include "app_hal.h"

int main(void)
{

	hal_setup();

  while(1)
  {
    hal_loop();
  }
}
