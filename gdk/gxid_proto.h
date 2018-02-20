/* GDK - The GIMP Drawing Kit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the 
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA  02111-1307, USA.
 */
#define GXID_CLAIM_DEVICE       1
#define GXID_RELEASE_DEVICE     2

#define GXID_RETURN_OK          0
#define GXID_RETURN_ERROR       -1

typedef struct GxidClaimDevice_ GxidClaimDevice;
typedef struct GxidReleaseDevice_ GxidReleaseDevice;
typedef struct GxidMessageAny_ GxidMessageAny;
typedef union GxidMessage_ GxidMessage;

typedef unsigned long GxidU32;
typedef long GxidI32;

struct GxidClaimDevice_ {
  GxidU32 type;
  GxidU32 length;
  GxidU32 device;
  GxidU32 window;
  GxidU32 exclusive;
};

struct GxidReleaseDevice_ {
  GxidU32 type;
  GxidU32 length;
  GxidU32 device;
  GxidU32 window;
};

struct GxidMessageAny_ {
  GxidU32 type;
  GxidU32 length;
};

union GxidMessage_ {
  GxidMessageAny any;
  GxidClaimDevice claim;
  GxidReleaseDevice release;
};
