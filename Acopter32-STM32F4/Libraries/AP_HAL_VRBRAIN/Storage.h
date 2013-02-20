/* -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * Storage.h --- AP_HAL_VRBRAIN storage driver.
 *
 * Copyright (C) 2013, Virtualrobotix.com Roberto Navoni , Emile 
 * All Rights Reserved.
 *
 * This software is released under the "BSD3" license.  Read the file
 * "LICENSE" for more information.
 *
 * Written by Roberto Navoni  <info@virtualrobotix.com>, 11 January 2013
 */

#ifndef __AP_HAL_VRBRAIN_STORAGE_H__
#define __AP_HAL_VRBRAIN_STORAGE_H__

#include <AP_HAL_VRBRAIN.h>
#include <i2c.h>

#define MC24C64		//Defines the EEPROM MC24C64
#define EEPROM_ADDRESS	0xA0

#define EEPROM_PAGE_SIZE	(uint32_t)0x10000
#define EEPROM_START_ADDRESS	0x00

class VRBRAIN::VRBRAINStorage : public AP_HAL::Storage
{
public:
  VRBRAINStorage():Status(0){}
  void init(void*);
  uint8_t  read_byte(uint16_t loc);
  uint16_t read_word(uint16_t loc);
  uint32_t read_dword(uint16_t loc);
  void     read_block(void *dst, uint16_t src, size_t n);

  void write_byte(uint16_t loc, uint8_t value);
  void write_word(uint16_t loc, uint16_t value);
  void write_dword(uint16_t loc, uint32_t value);
  void write_block(uint16_t dst, void* src, size_t n);

private:
  uint16_t format(void);
  uint16_t read(uint16_t Address);
  uint16_t read(uint16_t Address, uint16_t *Data);
  uint16_t write(uint16_t Address, uint16_t Data);

  void eeprom_read_block (void *pointer_ram, const void *pointer_eeprom, size_t n);
  void eeprom_write_block (const void *pointer_ram, void *pointer_eeprom, size_t n);
  uint8_t eeprom_read_byte (const uint8_t *addr);
  uint16_t eeprom_write_byte (uint8_t *addr, uint8_t value);
  uint16_t eeprom_read_word (const uint16_t *addr);
  void eeprom_write_word (uint16_t *addr, uint16_t value);
  uint32_t eeprom_read_dword (const uint32_t *addr);
  void eeprom_write_dword (uint32_t *addr, uint32_t value);

  uint16_t Status;
};

#endif // __AP_HAL_VRBRAIN_STORAGE_H__
