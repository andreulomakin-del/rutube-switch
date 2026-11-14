# Requires devkitPro + devkitA64 + libnx
TARGET := rutube_switch
BUILD := build
SOURCES := source
INCLUDES :=
ARCH := -march=armv8-a+crc+crypto -mtune=cortex-a57 -mtp=soft -fPIE
CFLAGS := -g -Wall -O2 -ffunction-sections $(ARCH) $(INCLUDES) -D__SWITCH__
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
LDFLAGS := -specs=$(DEVKITPRO)/libnx/switch.specs -g $(ARCH) -Wl,--gc-sections
LIBS := -lnx
LIBDIRS :=

include $(DEVKITPRO)/libnx/switch_rules
