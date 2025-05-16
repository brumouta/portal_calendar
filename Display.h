#include "Arduino.h"
#include "DisplayGDEW075T7.h"
#include "resources/image.h"
#include "global.h"
#include "weather.h"
#include "localization.h"

#ifndef PORTALCALENDAR_DISPLAY_H
#define PORTALCALENDAR_DISPLAY_H

class DisplayClass
{
public:
    ~DisplayClass();
    void error(String message, bool willRetry);
    void update(const tm *now, const Locale& locale, bool showWeather);
    void showWelcomeScreen();
    void showConfigServerScreen(String ssid, String password, String hostname, String connectedWifiName);
    void fastClear(bool black = false);
    #ifdef DEV_WEBSERVER
    void showDevWebserverScreen(String ssid, IPAddress localIp);
    #endif
    #ifdef DEBUG
    void testChamberIcons();
    #endif

private:
    void initDisplay();
    void initFrameBuffer();
    void cleanup();
    const Image* getWeatherConditionIcon(WeatherCondition condition, bool day);
    void drawWeatherInfoText(const char* text, const Image* symbol, int32_t x, int32_t y);
    void drawDailyWeather(const DailyWeather& weather, int32_t x, const Locale& locale);
    void drawWeatherEntry(const WeatherEntry& weather, int32_t x);
    void drawChamberIcon(const Image& icon, int32_t x, int32_t y);
    void drawStandardSeparators();
    void drawChamberNumber(int number, int total);
    void drawApertureLogo();
    DisplayGDEW075T7 *_display = nullptr;
    FrameBuffer *_frameBuffer = nullptr;
};

extern DisplayClass Display;

#endif // PORTALCALENDAR_DISPLAY_H
