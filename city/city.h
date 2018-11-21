#ifndef _CITYH_
#define _CITYH_

#include <stdio.h>

#define MAX_KEY_SIZE        32U
#define MAX_UNIT_FORMAT     16U
#define MAX_LANG_SIZE       12U
#define MAX_CITY_NAME       256U
#define MAX_ID              16U
#define MAX_LAT_LON         12U
#define MAX_ZIPCODE         16U

#define MAX_WEATHER_PAR     128U
#define MAX_WEATHER_DESC    256U
#define MAX_ICON_ID         4U

#define MAX_MESSAGE_SIZE    16U
#define MAX_COUNTRY_CODE    2U

#define MAX_BASE_PAR        64U

typedef struct unit_format_e {
    STANDARD = 0,
    METRIC,
    IMPERIAL
} unit_format;

typedef struct url_sts_s {
    char key[MAX_KEY_SIZE + 1];
    unit_format u_format;
    char u_string[MAX_UNIT_FORMAT];
    char lang[MAX_LANG_SIZE];
    char city[MAX_CITY_NAME];
    char id[MAX_ID];
    char lat_log[MAX_LAT_LON];
    char zip[MAX_ZIPCODE];
} url_sts;

typedef struct city_coord_s {
    float lon;
    float lat;
} city_coord;

typedef struct city_weather_s {
    int id;
    char main[MAX_WEATHER_PAR];
    char desc[MAX_WEATHER_DESC];
    char icon[MAX_ICON_ID];
} city_weather;

typedef struct city_main_s {
    float temp;
    float pressure;
    float humidity;
    float high;
    float low;
    float sea_level;
    float grnd_level;
} city_main;

typedef struct city_wind_s {
    float speed;
    float deg;
} city_wind;

typedef struct city_clouds_s {
    int all;
} city_cloud;

typedef struct city_rain_s {
    float hour_1;
    float hour_2;
} city_rain;

typedef struct city_snow_s {
    float hour_1;
    float hour_2;
} city_snow;

typedef struct city_sys_s {
    int id;
    int type;
    char message[MAX_MESSAGE_SIZE];
    char country[MAX_COUNTRY_CODE];
    float sunrise;
    long sunset;
} city_sys;

typedef struct city_misc_s {
	char base[MAX_BASE_PAR];
	float visibility;
	long dt;
	long id;
	char name[MAX_CITY_NAME];
	long cod;
} city_misc;

typedef struct city_map_s {
    city_coord      coord;
    city_weather    weather;
    city_main       main;
    city_wind       wind;
    city_cloud      cloud;
    city_rain       rain;
    city_snow       snow;
    city_sys        sys;
    city_misc       misc;
} city_map;

#endif
