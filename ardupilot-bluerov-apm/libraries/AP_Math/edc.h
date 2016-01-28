// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Copyright (C) 2010 Swift Navigation Inc.
// Contact: Fergus Noble <fergus@swift-nav.com>
   
#ifndef __EDC_H_
#define __EDC_H_

#include <AP_Progmem.h>

#include <stdint.h>

uint16_t crc16_ccitt(const uint8_t *buf, uint32_t len, uint16_t crc);

#endif /* __EDC_H_ */
