#include <stdbool.h>

#include "city.h"
#include "city_curl.h"
#include "city_parse.h"
#include "city_types.h"
#include "city_config.h"

#include "net_api.h"

#define CITY_CUSTOM "/custom/city/city.json"

static url_sts  url = { '\0' };
static city_map map = { '\0' };

city_init cityInit( void ) {
    bool failed = false;
    city_init status = CITY_OK;

    failed = city_config(CITY_CUSTOM);
    if (!failed) {
        status = CITY_FILE_PROCESS_NOK;
        goto exit;
    }

    if (internetAvail()) {
       failed = weatherURL(&url);
       if (failed) {
           status = CITY_WEATHER_URL_NOK;
           goto exit;
       }

       failed = jsonConfig(&map);
       if (failed) {
           goto exit;
       }
   } else {
      printf("NOTICE: Internet is not available\n");
      status = CITY_WEATHER_URL_NOK;
   }

exit:
    return status;
}

int main(int argc, char *argv[]) {
    bool failed = true;

    city_init status = cityInit();
    if (status != CITY_OK) {
        printf("Initializing the city failed - status(%d)\n", status);
        failed = false;
    }

    return failed;
}
