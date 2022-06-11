/*
  modes_esp.h - WS2812FX header file for ESP8266 and ESP32 microprocessors

  LICENSE

  The MIT License (MIT)

  Copyright (c) 2016  Harm Aldick

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.


  CHANGELOG

  2022-03-23   Separated from the original WS2812FX.h file
*/
#ifndef modes_esp_basic_h
#define modes_esp_basic_h

#define MODE_COUNT (sizeof(_modes)/sizeof(_modes[0]))
#define MODE_PTR(x) this->*_modes[x].mode_ptr
#define MODE_NAME(x) _modes[x].name

#define FX_MODE_STATIC                   0
#define FX_MODE_BLINK                    1
#define FX_MODE_BREATH                   2
#define FX_MODE_COLOR_WIPE               3
#define FX_MODE_COLOR_WIPE_INV           4 
#define FX_MODE_COLOR_WIPE_REV           5
#define FX_MODE_COLOR_WIPE_REV_INV       6
#define FX_MODE_COLOR_WIPE_RANDOM        7
#define FX_MODE_RANDOM_COLOR             8
#define FX_MODE_SINGLE_DYNAMIC           9
#define FX_MODE_MULTI_DYNAMIC           10
#define FX_MODE_RAINBOW                 11
#define FX_MODE_RAINBOW_CYCLE           12
#define FX_MODE_SCAN                    13
#define FX_MODE_DUAL_SCAN               14
#define FX_MODE_FADE                    15
#define FX_MODE_THEATER_CHASE           16
#define FX_MODE_THEATER_CHASE_RAINBOW   17
#define FX_MODE_RUNNING_LIGHTS          18
#define FX_MODE_TWINKLE                 19
#define FX_MODE_TWINKLE_RANDOM          20
#define FX_MODE_TWINKLE_FADE            21
#define FX_MODE_TWINKLE_FADE_RANDOM     22
#define FX_MODE_SPARKLE                 23
#define FX_MODE_FLASH_SPARKLE           24
#define FX_MODE_HYPER_SPARKLE           25
#define FX_MODE_STROBE                  26
#define FX_MODE_STROBE_RAINBOW          27
#define FX_MODE_MULTI_STROBE            28
#define FX_MODE_BLINK_RAINBOW           29
#define FX_MODE_CHASE_WHITE             30
#define FX_MODE_CHASE_COLOR             31
#define FX_MODE_CHASE_RANDOM            32
#define FX_MODE_CHASE_RAINBOW           33
#define FX_MODE_CHASE_FLASH             34
#define FX_MODE_CHASE_FLASH_RANDOM      35
#define FX_MODE_CHASE_RAINBOW_WHITE     36
#define FX_MODE_CHASE_BLACKOUT          37
#define FX_MODE_CHASE_BLACKOUT_RAINBOW  38
#define FX_MODE_COLOR_SWEEP_RANDOM      39
#define FX_MODE_RUNNING_COLOR           40
#define FX_MODE_RUNNING_RED_BLUE        41
#define FX_MODE_RUNNING_RANDOM          42
#define FX_MODE_LARSON_SCANNER          43
#define FX_MODE_COMET                   44
#define FX_MODE_FIREWORKS               45
#define FX_MODE_FIREWORKS_RANDOM        46
#define FX_MODE_MERRY_CHRISTMAS         47
#define FX_MODE_FIRE_FLICKER            48
#define FX_MODE_FIRE_FLICKER_SOFT       49
#define FX_MODE_FIRE_FLICKER_INTENSE    50
#define FX_MODE_CIRCUS_COMBUSTUS        51
#define FX_MODE_HALLOWEEN               52
#define FX_MODE_BICOLOR_CHASE           53
#define FX_MODE_TRICOLOR_CHASE          54
#define FX_MODE_TWINKLEFOX              55
#define FX_MODE_RAIN                    56
#define FX_MODE_CUSTOM                  57  // keep this for backward compatiblity
#define FX_MODE_CUSTOM_0                57  // custom modes need to go at the end
#define FX_MODE_CUSTOM_1                58
#define FX_MODE_CUSTOM_2                59
#define FX_MODE_CUSTOM_3                60
#define FX_MODE_CUSTOM_4                61
#define FX_MODE_CUSTOM_5                62
#define FX_MODE_CUSTOM_6                63
#define FX_MODE_CUSTOM_7                64

typedef struct Mode {
  const __FlashStringHelper* name;
  const __FlashStringHelper* category;
  uint16_t (WS2812FX::*mode_ptr)(void);
} mode;

// mode categories
const char cat_simple[]  PROGMEM = "Simple";
const char cat_wipe[]    PROGMEM = "Wipe";
const char cat_sweep[]   PROGMEM = "Sweep";
const char cat_special[] PROGMEM = "Special";
const char cat_custom[]  PROGMEM = "Custom";

// create GLOBAL names to allow WS2812FX to compile with sketches and other libs
// that store strings in PROGMEM (get rid of the "section type conflict with __c"
// errors once and for all. Amen.)
const char name_0[] PROGMEM = "Static";
const char name_1[] PROGMEM = "Breath";
const char name_2[] PROGMEM = "Rainbow";
const char name_3[] PROGMEM = "Rainbow Cycle";
const char name_4[] PROGMEM = "Fade";
const char name_5[] PROGMEM = "Larson Scanner";
const char name_6[] PROGMEM = "OFF";

// define static array of member function pointers.
// make sure the order of the _modes array elements matches the FX_MODE_* values
__attribute__ ((unused)) static mode _modes[] = {
  { FSH(name_0),  FSH(cat_simple),  &WS2812FX::mode_static },
  { FSH(name_1),  FSH(cat_special), &WS2812FX::mode_breath },
  { FSH(name_2), FSH(cat_simple),  &WS2812FX::mode_rainbow },
  { FSH(name_3), FSH(cat_wipe),    &WS2812FX::mode_rainbow_cycle },
  { FSH(name_4), FSH(cat_sweep),   &WS2812FX::mode_fade },
  { FSH(name_5), FSH(cat_sweep),   &WS2812FX::mode_larson_scanner },
  { FSH(name_6), FSH(cat_custom),  &WS2812FX::mode_custom_0 }
};
#endif
