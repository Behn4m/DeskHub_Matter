#include <nvs_flash.h>
#include "MatterComponent.h"
#include "BaseProcess.h"

extern "C" void app_main()
{    
    nvs_flash_init();

    matterComp();

    // DoneMatter::BaseInterfaceHandler bIF;

    // DoneMatter::BaseProcess bP(500);    

}
