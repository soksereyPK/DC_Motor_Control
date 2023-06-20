###########################################################################
## Makefile for calling other makefiles
###########################################################################

###########################################################################
## MACROS
###########################################################################
###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################
## Toolchain Name:          Arduino ARM


###########################################################################
## TOOLCHAIN MACROS
###########################################################################
# ARDUINO_ROOT = Intrinsically defined
# ARDUINO_PACKAGES_TOOLS_ROOT = Intrinsically defined
# ARDUINO_PORT = Intrinsically defined
# ARDUINO_MCU = Intrinsically defined
# ARDUINO_BAUD = Intrinsically defined
# ARDUINO_PROTOCOL = Intrinsically defined
# ARDUINO_F_CPU = Intrinsically defined
SHELL = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
ARDUINO_TOOLS = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin


#-------------------------
# Directives/Utilities
#-------------------------
RM                        = 
ECHO                      = echo
MV                        = 


#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM Assembler
AS_PATH := $(ARDUINO_TOOLS)
AS := $(AS_PATH)/arm-none-eabi-gcc

# C Compiler: Arduino ARM C Compiler
CC_PATH := $(ARDUINO_TOOLS)
CC := $(CC_PATH)/arm-none-eabi-gcc

# Linker: Arduino ARM Linker
LD_PATH = $(ARDUINO_TOOLS)
LD := $(LD_PATH)/arm-none-eabi-gcc


# C++ Compiler: Arduino ARM C++ Compiler
CPP_PATH := $(ARDUINO_TOOLS)
CPP := $(CPP_PATH)/arm-none-eabi-g++

# C++ Linker: Arduino ARM C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD := $(CPP_LD_PATH)/arm-none-eabi-gcc

# Archiver: Arduino ARM Archiver
AR_PATH := $(ARDUINO_TOOLS)
AR := $(AR_PATH)/arm-none-eabi-ar

# Indexing: Arduino ARM Ranlib
RANLIB_PATH := $(ARDUINO_TOOLS)
RANLIB := $(RANLIB_PATH)/arm-none-eabi-ranlib

# Execute: Execute
EXECUTE = $(PRODUCT)


# Builder: GMAKE Utility
MAKE_PATH = C:/Program Files/MATLAB/R2022a/bin/win64
MAKE = $(MAKE_PATH)/gmake


#--------------------------------------
# Faster Runs Build Configuration
#--------------------------------------
ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -std=gnu11 \
                       -Os \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -nostdlib  \
                       --param max-inline-insns-single=500  \
                       -Dprintf=iprintf  \
                       -DARDUINO=10801  \
                       -MMD -MP 
CPPFLAGS             = -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions  \
                       -Os \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -nostdlib  \
                       --param max-inline-insns-single=500  \
                       -Dprintf=iprintf  \
                       -DARDUINO=10801  \
                       -MMD -MP 
CPP_LDFLAGS          =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
CPP_SHAREDLIB_LDFLAGS =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =


###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################
#---------------
# C Compiler
#---------------
CFLAGS_SKIPFORSIL = -MD -mcpu=cortex-m3 -fpermissive -DF_CPU=84000000L -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Due\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_DUE_ -DARDUINO_NUM_SERIAL_PORTS=4 -DARDUINO_ARM -DARDUINO_ARM_CORTEX_M3
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)
#-----------------
# C++ Compiler
#-----------------
CPPFLAGS_SKIPFORSIL = -MD -mcpu=cortex-m3 -fpermissive -DF_CPU=84000000L -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Due\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_DUE_ -DARDUINO_NUM_SERIAL_PORTS=4 -DARDUINO_ARM -DARDUINO_ARM_CORTEX_M3
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)
#---------------
# C++ Linker
#---------------
CPP_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a
CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)
#------------------------------
# C++ Shared Library Linker
#------------------------------
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a
CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)
#-----------
# Linker
#-----------
LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a
LDFLAGS += $(LDFLAGS_SKIPFORSIL)
#--------------------------
# Shared Library Linker
#--------------------------
SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a
SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)


-include codertarget_assembly_flags.mk


###########################################################################
## Define Macros
###########################################################################
SLMKPATH=C:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARDUIN~2/STATIC~1
MODELMK=posi.mk
SLIB_PATH=C:/Users/LabPC/DOCUME~1/MATLAB/R2022a/ARDUIN~1/ARDUIN~1/FASTER~1
VARIANT_HEADER_PATH=$(ARDUINO_SAM_ROOT)/hardware/sam/1.6.12/variants/arduino_due_x
ARDUINO_SKETCHBOOK_ROOT=C:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/aIDE/portable/SKETCH~1/LIBRAR~1
ARDUINO_BASESUPPORTPKG_ROOT=C:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARDUIN~2
ARDUINO_SAM_BOARDS=1


###########################################################################
## Export Variables
###########################################################################
export AR
export RANLIB
export AS
export CC
export CPP
export ASFLAGS
export CFLAGS
export CPPFLAGS
export ARFLAGS
export SLIB_PATH
export VARIANT_HEADER_PATH
export ARDUINO_SKETCHBOOK_ROOT
export ARDUINO_BASESUPPORTPKG_ROOT
export ARDUINO_SAM_BOARDS


###########################################################################
## PHONY TARGETS
###########################################################################
.PHONY : all
all : 
	@echo "### Generating static library."
	"$(MAKE)" -j7 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f samcore.mk all
	"$(MAKE)" -j7 SHELL="$(SHELL)" -f "$(MODELMK)" all

