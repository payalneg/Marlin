/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2021 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#pragma once

//
// MKS Robin Nano V3, MKS Eagle pinmap
//

//#define HAS_OTG_USB_HOST_SUPPORT                  // USB Flash Drive support

// Avoid conflict with TIMER_TONE
#define STEP_TIMER 10

// Use one of these or SDCard-based Emulation will be used
//#define SRAM_EEPROM_EMULATION                   // Use BackSRAM-based EEPROM emulation
//#define FLASH_EEPROM_EMULATION                  // Use Flash-based EEPROM emulation
#define SPI_EEPROM
#define SOFTWARE_SPI 1

#define SPI_CHAN_EEPROM1                     1
#define SPI_EEPROM1_CS_PIN                PA15  // datasheet: /CS pin, found with multimeter, not tested
#define EEPROM_SCK_PIN                    PB3  // datasheet: CLK pin, found with multimeter, not tested
#define EEPROM_MISO_PIN                   PB4  // datasheet: DO pin, found with multimeter, not tested
#define EEPROM_MOSI_PIN                   PB5  // datasheet: DI pin, found with multimeter, not tested
#define EEPROM_PAGE_SIZE               0x1000U  // 4K (from datasheet)
#define MARLIN_EEPROM_SIZE 16UL * (EEPROM_PAGE_SIZE)  // Limit to 64K for now...

//
// Steppers
//
//#define X_DUAL_ENDSTOPS

#define X_ENABLE_PIN                        PE13
#define X_STEP_PIN                          PB10
#define X_DIR_PIN                           PB12

#define X2_ENABLE_PIN                        X_ENABLE_PIN
#define X2_STEP_PIN                          PE11
#define X2_DIR_PIN                           PE12

#define Y_ENABLE_PIN                        X_ENABLE_PIN
#define Y_STEP_PIN                          PE15
#define Y_DIR_PIN                           PB13

#define Z_ENABLE_PIN                        X_ENABLE_PIN
#define Z_STEP_PIN                          PB14
#define Z_DIR_PIN                           PB11

#define E0_ENABLE_PIN                       PE0
#define E0_STEP_PIN                         PB9
#define E0_DIR_PIN                          PB7
#define E0_SERIAL_TX_PIN                    PB5
#define E0_SERIAL_RX_PIN                    E0_SERIAL_TX_PIN  

#define E1_ENABLE_PIN                       E0_ENABLE_PIN
#define E1_STEP_PIN                         PB8
#define E1_DIR_PIN                          PB6
#define E1_SERIAL_TX_PIN                    PB3
#define E1_SERIAL_RX_PIN                    E1_SERIAL_TX_PIN         

#define X_MIN_PIN                        PC6
#define X_MAX_PIN                        PE14
#define Y_MAX_PIN                        PD15
#define Z_MIN_PIN                        PC8


            


//
// Temperature Sensors
//
#define TEMP_0_PIN                          PB0   // TH1
#define TEMP_1_PIN                          PB1   // TH1
#define TEMP_BED_PIN                        PC5   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN                      PD4//PA12 // HEATER1
#define HEATER_1_PIN                      PD5//PA11   // HEATER1
#define HEATER_BED_PIN                    PD3//PC9   // HOT BED

#define FAN_PIN                           PD6  // FAN
#define FAN1_PIN                           PD0  // FAN

#define FAN_SOFT_PWM_REQUIRED

// Random Info
#define USB_SERIAL              -1  // USB Serial
#define WIFI_SERIAL              3  // USART3
#define MKS_WIFI_MODULE_SERIAL   1  // USART1
#define MKS_WIFI_MODULE_SPI      2  // SPI2

  /**
   *    RET6 12864 LCD
   *        ------
   *  PC6  | 1  2 | PB2
   *  PB10 | 3  4 | PB11
   *  PB14   5  6 | PB13
   *  PB12 | 7  8 | PB15
   *   GND | 9 10 | 5V
   *        ------
   */
  #define EXP3_01_PIN                       PD8
  #define EXP3_02_PIN                       PB15 
  #define EXP3_03_PIN                       PD10
  #define EXP3_04_PIN                       PD9
  #define EXP3_05_PIN                       PD12
  #define EXP3_06_PIN                       PD11
  #define EXP3_07_PIN                       PD14
  #define EXP3_08_PIN                       PD13

#if ENABLED(CR10_STOCKDISPLAY)

  #define LCD_PINS_RS                EXP3_07_PIN
  #define LCD_PINS_ENABLE            EXP3_08_PIN
  #define LCD_PINS_D4                EXP3_06_PIN

  #define BTN_ENC                    EXP3_02_PIN
  #define BTN_EN1                    EXP3_03_PIN
  #define BTN_EN2                    EXP3_05_PIN

  #ifndef HAS_PIN_27_BOARD
    #define BEEPER_PIN               EXP3_01_PIN
  #endif
#endif