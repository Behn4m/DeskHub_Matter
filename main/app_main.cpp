#include <nvs_flash.h>
#include "MatterComponent.h"
#include "BaseProcess.h"
#include "DerivedProcess.h"

DoneMatter::BaseInterfaceHandler bIh;
DoneMatter::DeivedInterfaceHandler DerivedbIh;

extern "C" void app_main()
{    
    nvs_flash_init();

    matterComp();

    // DoneMatter::BaseInterfaceHandler bIF;

    // DoneMatter::BaseProcess bP(500);    

    DoneMatter::DerivedProcess dProcess(500);
    dProcess.TaskInit(
        &DerivedbIh,
        "2ndProcess",
        1000,
        NULL,
        1,
        NULL);        
    )

    vTaskDelay(5000/portTICK_PERIOD_MS);
    unsigned int numberOfTasks = uxTaskGetNumberOfTasks();
    printf("Number of tasks: %u\n", numberOfTasks);
    printf("CONFIG_FREERTOS_HZ =%d\n",CONFIG_FREERTOS_HZ);

}
