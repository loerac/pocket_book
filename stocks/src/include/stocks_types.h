#ifndef _STOCKS_TYPES_H_
#define _STOCKS_TYPES_H_

typedef enum stock_time_series {
   TIME_SERIES_INTRADAY = 0,
   TIME_SERIES_DAILY,
   TIME_SERIES_DAILY_ADJUSTED,
   TIME_SERIES_WEEKLY,
   TIME_SERIES_WEEKLY_ADJUSTED,
   TIME_SERIES_MONTHLY,
   TIME_SERIES_MONTHLY_ADJUSTED
   TIME_SERIES_QUOTE_ENDPOINT,
   MAX_TIME_SERIES,
   TIME_SERIES_ERROR
} stock_time_series_s;

#endif /* _STOCKS_TYPES_H_ */

