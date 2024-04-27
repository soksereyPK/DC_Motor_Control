###########################################################################
## Makefile for calling other makefiles
###########################################################################

###########################################################################
## MACROS
###########################################################################
###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################
## Toolchain Name:          ESP32


###########################################################################
## TOOLCHAIN MACROS
###########################################################################
# ARDUINO_ROOT = Intrinsically defined
# ARDUINO_PORT = Intrinsically defined
# ARDUINO_MCU = Intrinsically defined
# ARDUINO_BAUD = Intrinsically defined
# ARDUINO_PROTOCOL = Intrinsically defined
# ARDUINO_F_CPU = Intrinsically defined
# ARDUINO_IDE_VERSION = Intrinsically defined
# ESP_BOARD_NAME = Intrinsically defined
# ESP_VARIANT_NAME = Intrinsically defined
# ESP_FLASH_MODE = Intrinsically defined
# ESP_FLASH_FREQUENCY = Intrinsically defined
# ESP_FLASH_SIZE = Intrinsically defined
# ESP_PARTITION_SCHEME = Intrinsically defined
# ESP_DEFINES = Intrinsically defined
# ESP_EXTRA_FLAGS = Intrinsically defined
# ESP_EXTRA_LIBS = Intrinsically defined
SHELL = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
PRODUCT_PARTITION_BIN = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).partitions.bin
ARDUINO_XTENSA_TOOLS = $(ARDUINO_ESP32_ROOT)/tools/xtensa-esp32-elf-gcc/$(ESP32_GCC_VERSION)/bin
ARDUINO_ESP32_TOOLS = $(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools
ARDUINO_ESP32_SDK = $(ARDUINO_ESP32_TOOLS)/sdk
ELF2BIN_OPTIONS =  elf2image --flash_mode $(ESP_FLASH_MODE) --flash_freq $(ESP_FLASH_FREQUENCY) --flash_size $(ESP_FLASH_SIZE)


#-------------------------
# Directives/Utilities
#-------------------------
RM                        = 
ECHO                      = echo
MV                        = 


#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: ESP32 Assembler
AS_PATH := $(ARDUINO_XTENSA_TOOLS)
AS := $(AS_PATH)/xtensa-esp32-elf-gcc

# C Compiler: ESP32 C Compiler
CC_PATH := $(ARDUINO_XTENSA_TOOLS)
CC := $(CC_PATH)/xtensa-esp32-elf-gcc

# Linker: ESP32 Linker
LD_PATH = $(ARDUINO_XTENSA_TOOLS)
LD := $(LD_PATH)/xtensa-esp32-elf-gcc


# C++ Compiler: ESP32 C++ Compiler
CPP_PATH := $(ARDUINO_XTENSA_TOOLS)
CPP := $(CPP_PATH)/xtensa-esp32-elf-g++

# C++ Linker: ESP32 C++ Linker
CPP_LD_PATH = $(ARDUINO_XTENSA_TOOLS)
CPP_LD := $(CPP_LD_PATH)/xtensa-esp32-elf-gcc

# Archiver: ESP32 Archiver
AR_PATH := $(ARDUINO_XTENSA_TOOLS)
AR := $(AR_PATH)/xtensa-esp32-elf-ar

# Indexing: ESP32 Ranlib
RANLIB_PATH := $(ARDUINO_XTENSA_TOOLS)
RANLIB := $(RANLIB_PATH)/xtensa-esp32-elf-ranlib

# Execute: Execute
EXECUTE = $(PRODUCT)


# Builder: GMAKE Utility
MAKE_PATH = C:/Program Files/MATLAB/R2022b/bin/win64
MAKE = $(MAKE_PATH)/gmake


#--------------------------------------
# Faster Runs Build Configuration
#--------------------------------------
ARFLAGS              = cru
ASFLAGS              = -MMD -MP  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c \
                       $(ESP_DEFINES) $(ESP_EXTRA_FLAGS)
ESPTOOLFLAGS_BIN     = --chip esp32 $(ELF2BIN_OPTIONS) -o $(PRODUCT_BIN)  $(PRODUCT)
CFLAGS               = -std=gnu99 -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wpointer-arith -w -Wno-maybe-uninitialized -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-deprecated-declarations -Wno-unused-parameter -Wno-sign-compare -Wno-old-style-declaration -MMD -c \
                       -DF_CPU=$(ARDUINO_F_CPU) -DARDUINO=$(ARDUINO_IDE_VERSION) -DARDUINO_$(ESP_BOARD_NAME)  \
                       -DARDUINO_ARCH_ESP32 "-DARDUINO_BOARD=\"$(ESP_BOARD_NAME)\"" "-DARDUINO_VARIANT=\"$(ESP_VARIANT_NAME)\"" -DARDUINO_PARTITION_$(ESP_PARTITION_SCHEME) -DESP32 -DCORE_DEBUG_LEVEL=0 \
                       -Os \
                       $(ESP_DEFINES) $(ESP_EXTRA_FLAGS)
CPPFLAGS             = -std=gnu++11 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -w -Wno-error=maybe-uninitialized -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-missing-field-initializers -Wno-sign-compare -fno-rtti -MMD -c \
                       -DF_CPU=$(ARDUINO_F_CPU) -DARDUINO=$(ARDUINO_IDE_VERSION) -DARDUINO_$(ESP_BOARD_NAME)  \
                       -DARDUINO_ARCH_ESP32 "-DARDUINO_BOARD=\"$(ESP_BOARD_NAME)\"" "-DARDUINO_VARIANT=\"$(ESP_VARIANT_NAME)\"" -DARDUINO_PARTITION_$(ESP_PARTITION_SCHEME) -DESP32 -DCORE_DEBUG_LEVEL=0 \
                       -Os \
                       $(ESP_DEFINES) $(ESP_EXTRA_FLAGS)
CPP_LDFLAGS          =  -nostdlib "-L$(ARDUINO_ESP32_SDK)/lib" "-L$(ARDUINO_ESP32_SDK)/ld"  \
                       -T esp32_out.ld -T esp32.project.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.libgcc.ld -T esp32.rom.spiram_incompatible_fns.ld  \
                       -u esp_app_desc -u ld_include_panic_highint_hdl -u call_user_start_cpu0   \
                       -w -Os  \
                       -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  \
                       -u __cxa_guard_dummy -u __cxx_fatal_exception  \
                       $(ESP_DEFINES) $(ESP_EXTRA_FLAGS)
CPP_SHAREDLIB_LDFLAGS =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -nostdlib "-L$(ARDUINO_ESP32_SDK)/lib" "-L$(ARDUINO_ESP32_SDK)/ld"  \
                       -T esp32_out.ld -T esp32.project.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.libgcc.ld -T esp32.rom.spiram_incompatible_fns.ld  \
                       -u esp_app_desc -u ld_include_panic_highint_hdl -u call_user_start_cpu0   \
                       -w -Os  \
                       -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  \
                       -u __cxa_guard_dummy -u __cxx_fatal_exception  \
                       $(ESP_DEFINES) $(ESP_EXTRA_FLAGS)
MAKE_FLAGS           = -f $(MAKEFILE)
GENPARTFLAGS_HEX     = -q  $(START_DIR)/$(PRODUCT_NAME)_ert_rtw/partitions.csv $(PRODUCT_PARTITION_BIN)
SHAREDLIB_LDFLAGS    =


###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################
#---------------
# C Compiler
#---------------
CFLAGS_SKIPFORSIL = -DESP_PLATFORM "-DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\"" -DHAVE_CONFIG_H -DGCC_NOT_5_2_0=0 -DWITH_POSIX -D_RUNONTARGETHARDWARE_BUILD_ -DMW_DONOTSTART_SCHEDULER -D_ROTH_ESP32_
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)
#-----------------
# C++ Compiler
#-----------------
CPPFLAGS_SKIPFORSIL = -DESP_PLATFORM "-DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\"" -DHAVE_CONFIG_H -DGCC_NOT_5_2_0=0 -DWITH_POSIX -D_RUNONTARGETHARDWARE_BUILD_ -DMW_DONOTSTART_SCHEDULER -D_ROTH_ESP32_
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)
#---------------
# C++ Linker
#---------------
CPP_LDFLAGS_SKIPFORSIL =  
CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)
#------------------------------
# C++ Shared Library Linker
#------------------------------
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL =  
CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)
#-----------
# Linker
#-----------
LDFLAGS_SKIPFORSIL =  
LDFLAGS += $(LDFLAGS_SKIPFORSIL)
#--------------------------
# Shared Library Linker
#--------------------------
SHAREDLIB_LDFLAGS_SKIPFORSIL =  
SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)


-include codertarget_assembly_flags.mk


###########################################################################
## Define Macros
###########################################################################
SLMKPATH=C:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/SUPPOR~1/ARDUIN~2/STATIC~1
MODELMK=Torque_control.mk
SLIB_PATH=C:/Users/sokse/DOCUME~1/MATLAB/R2022b/ARDUIN~1/ESP32W~1/FASTER~1
VARIANT_HEADER_PATH=$(ARDUINO_ESP32_ROOT)/hardware/esp32/1.0.6/variants/esp32
ARDUINO_SKETCHBOOK_ROOT=C:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/aIDE/portable/SKETCH~1/LIBRAR~1
ARDUINO_BASESUPPORTPKG_ROOT=C:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/SUPPOR~1/ARDUIN~2


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


###########################################################################
## PHONY TARGETS
###########################################################################
.PHONY : all
all : 
	@echo "### Generating static library."
	"$(MAKE)" -j5 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f esp32core.mk all
	"$(MAKE)" -j5 SHELL="$(SHELL)" -f "$(MODELMK)" all

