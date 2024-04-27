###########################################################################
## Makefile generated for component 'Torque_control'. 
## 
## Makefile     : Torque_control.mk
## Generated on : Sat Apr 27 10:16:22 2024
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/Torque_control.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = Torque_control
MAKEFILE                  = Torque_control.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2022b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2022b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/sokse/OneDrive/MyGithub/DC_Motor_Control/Matlab_Simulink/DC_Torque_control_with_TB6612fng_driver
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
SLIB_PATH                 = C:/Users/sokse/DOCUME~1/MATLAB/R2022b/ARDUIN~1/ESP32W~1/FASTER~1
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          ESP32
# Supported Version(s):    
# ToolchainInfo Version:   2022b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ARDUINO_ROOT
# ARDUINO_PORT
# ARDUINO_MCU
# ARDUINO_BAUD
# ARDUINO_PROTOCOL
# ARDUINO_F_CPU
# ARDUINO_IDE_VERSION
# ESP_BOARD_NAME
# ESP_VARIANT_NAME
# ESP_FLASH_MODE
# ESP_FLASH_FREQUENCY
# ESP_FLASH_SIZE
# ESP_PARTITION_SCHEME
# ESP_DEFINES
# ESP_EXTRA_FLAGS
# ESP_EXTRA_LIBS

#-----------
# MACROS
#-----------

SHELL                 = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX           = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN           = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
PRODUCT_PARTITION_BIN = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).partitions.bin
ARDUINO_XTENSA_TOOLS  = $(ARDUINO_ESP32_ROOT)/tools/xtensa-esp32-elf-gcc/$(ESP32_GCC_VERSION)/bin
ARDUINO_ESP32_TOOLS   = $(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools
ARDUINO_ESP32_SDK     = $(ARDUINO_ESP32_TOOLS)/sdk
ELF2BIN_OPTIONS       =  elf2image --flash_mode $(ESP_FLASH_MODE) --flash_freq $(ESP_FLASH_FREQUENCY) --flash_size $(ESP_FLASH_SIZE) 

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -Wl,--start-group -lgcc -lesp_websocket_client -lwpa2 -ldetection -lesp_https_server -lwps -lhal -lconsole -lpe -lsoc -lsdmmc -lpthread -llog -lesp_http_client -ljson -lmesh -lesp32-camera -lnet80211 -lwpa_supplicant -lc -lmqtt -lcxx -lesp_https_ota -lulp -lefuse -lpp -lmdns -lbt -lwpa -lspiffs -lheap -limage_util -lunity -lrtc -lmbedtls -lface_recognition -lnghttp -ljsmn -lopenssl -lcore -lfatfs -lm -lprotocomm -lsmartconfig -lxtensa-debug-module -ldl -lesp_event -lesp-tls -lfd -lespcoredump -lesp_http_server -lfr -lsmartconfig_ack -lwear_levelling -ltcp_transport -llwip -lphy -lvfs -lcoap -lesp32 -llibsodium -lbootloader_support -ldriver -lcoexist -lasio -lod -lmicro-ecc -lesp_ringbuf -ldetection_cat_face -lapp_update -lespnow -lface_detection -lapp_trace -lnewlib -lbtdm_app -lwifi_provisioning -lfreertos -lfreemodbus -lethernet -lnvs_flash -lspi_flash -lc_nano -lexpat -lfb_gfx -lprotobuf-c -lesp_adc_cal -ltcpip_adapter  -lstdc++  $(ESP_EXTRA_LIBS) -Wl,--end-group -Wl,-EL -lcore

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: ESP32 Assembler
AS_PATH = $(ARDUINO_XTENSA_TOOLS)
AS = "$(AS_PATH)/xtensa-esp32-elf-gcc"

# C Compiler: ESP32 C Compiler
CC_PATH = $(ARDUINO_XTENSA_TOOLS)
CC = "$(CC_PATH)/xtensa-esp32-elf-gcc"

# Linker: ESP32 Linker
LD_PATH = $(ARDUINO_XTENSA_TOOLS)
LD = "$(LD_PATH)/xtensa-esp32-elf-gcc"

# C++ Compiler: ESP32 C++ Compiler
CPP_PATH = $(ARDUINO_XTENSA_TOOLS)
CPP = "$(CPP_PATH)/xtensa-esp32-elf-g++"

# C++ Linker: ESP32 C++ Linker
CPP_LD_PATH = $(ARDUINO_XTENSA_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/xtensa-esp32-elf-gcc"

# Archiver: ESP32 Archiver
AR_PATH = $(ARDUINO_XTENSA_TOOLS)
AR = "$(AR_PATH)/xtensa-esp32-elf-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
ESPTOOL_PATH = $(ARDUINO_ESP32_ROOT)/tools/esptool_py/$(ESP32_FLASHTOOL_VERSION)
ESPTOOL = "$(ESPTOOL_PATH)/esptool.exe"

# Partition Generator: Partition Generator
GENPART = $(ARDUINO_ESP32_TOOLS)/gen_esp32part.exe

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =



#---------------------------
# Model-Specific Options
#---------------------------

ASFLAGS = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  -Wall -x assembler-with-cpp $(ASFLAGS_ADDITIONAL) $(DEFINES) $(INCLUDES) -c $(ESP_DEFINES) $(ESP_EXTRA_FLAGS)

CFLAGS = -std=gnu99 -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -Wpointer-arith -w -Wno-maybe-uninitialized -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-variable -Wno-deprecated-declarations -Wno-unused-parameter -Wno-sign-compare -Wno-old-style-declaration -MMD -c -DF_CPU=$(ARDUINO_F_CPU) -DARDUINO=$(ARDUINO_IDE_VERSION) -DARDUINO_$(ESP_BOARD_NAME)  -DARDUINO_ARCH_ESP32 "-DARDUINO_BOARD=\"$(ESP_BOARD_NAME)\"" "-DARDUINO_VARIANT=\"$(ESP_VARIANT_NAME)\"" -DARDUINO_PARTITION_$(ESP_PARTITION_SCHEME) -DESP32 -DCORE_DEBUG_LEVEL=0 -Os $(ESP_DEFINES) $(ESP_EXTRA_FLAGS) -g

LDFLAGS = -nostdlib "-L$(ARDUINO_ESP32_SDK)/lib" "-L$(ARDUINO_ESP32_SDK)/ld"  -T esp32_out.ld -T esp32.project.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.libgcc.ld -T esp32.rom.spiram_incompatible_fns.ld  -u esp_app_desc -u ld_include_panic_highint_hdl -u call_user_start_cpu0   -w -Os  -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  -u __cxa_guard_dummy -u __cxx_fatal_exception  $(ESP_DEFINES) $(ESP_EXTRA_FLAGS) -g

SHAREDLIB_LDFLAGS = -g

CPPFLAGS = -std=gnu++11 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -w -Wno-error=maybe-uninitialized -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-missing-field-initializers -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=$(ARDUINO_F_CPU) -DARDUINO=$(ARDUINO_IDE_VERSION) -DARDUINO_$(ESP_BOARD_NAME)  -DARDUINO_ARCH_ESP32 "-DARDUINO_BOARD=\"$(ESP_BOARD_NAME)\"" "-DARDUINO_VARIANT=\"$(ESP_VARIANT_NAME)\"" -DARDUINO_PARTITION_$(ESP_PARTITION_SCHEME) -DESP32 -DCORE_DEBUG_LEVEL=0 -Os $(ESP_DEFINES) $(ESP_EXTRA_FLAGS) -g

CPP_LDFLAGS = -nostdlib "-L$(ARDUINO_ESP32_SDK)/lib" "-L$(ARDUINO_ESP32_SDK)/ld"  -T esp32_out.ld -T esp32.project.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.libgcc.ld -T esp32.rom.spiram_incompatible_fns.ld  -u esp_app_desc -u ld_include_panic_highint_hdl -u call_user_start_cpu0   -w -Os  -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  -u __cxa_guard_dummy -u __cxx_fatal_exception  $(ESP_DEFINES) $(ESP_EXTRA_FLAGS) -g

CPP_SHAREDLIB_LDFLAGS = -g

ARFLAGS = cru

ESPTOOLFLAGS_BIN = --chip esp32 $(ELF2BIN_OPTIONS) -o $(PRODUCT_BIN)  $(PRODUCT)

GENPARTFLAGS_HEX = -q  $(START_DIR)/$(PRODUCT_NAME)_ert_rtw/partitions.csv $(PRODUCT_PARTITION_BIN)

DOWNLOAD_FLAGS = 

EXECUTE_FLAGS = 

MAKE_FLAGS = -f $(MAKEFILE)

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/Torque_control.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/SUPPOR~1/ARDUIN~2/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/shared/svd/include -I$(START_DIR)/Torque_control_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/common -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/cores/esp32 -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/variants/esp32 -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/freertos -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/config -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp32 -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/soc -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/heap -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/log -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/driver -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/spi_flash -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/app_trace -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/app_update -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/asio -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/bootloader_support -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/bt -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/coap -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/console -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/efuse -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp-tls -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp_adc_cal -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp_event -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp_http_client -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp_http_server -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp_https_ota -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp_https_server -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp_ringbuf -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp_websocket_client -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/espcoredump -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/ethernet -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/expat -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/fatfs -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/freemodbus -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/freertos/freertos -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/idf_test -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/jsmn -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/json -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/libsodium -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/lwip -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/mbedtls -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/mdns -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/micro-ecc -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/mqtt -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/newlib -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/nghttp -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/nvs_flash -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/openssl -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/protobuf-c -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/protocomm -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/pthread -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/sdmmc -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/smartconfig_ack -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/spiffs -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/tcp_transport -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/tcpip_adapter -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/ulp -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/unity -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/vfs -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/wear_levelling -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/wifi_provisioning -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/wpa_supplicant -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/xtensa-debug-module -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp-face -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/esp32-camera -I$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/tools/sdk/include/fb_gfx -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/SUPPOR~1/ARDUIN~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/SUPPOR~1/ARDUIN~1/SCHEDU~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022b/toolbox/target/shared/freertos/include -I$(START_DIR)/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DXCP_MAX_CTO_SIZE=32 -DXCP_MAX_DTO_SIZE=65532 -DXCP_MAX_ODT_ENTRY_SIZE=255 -DXCP_MAX_DAQ=65535 -DXCP_MIN_DAQ=0 -DXCP_MAX_EVENT_CHANNEL=128 -DXCP_ID_FIELD_TYPE=0 -DXCP_TIMESTAMP_SIZE=4 -DXCP_ADDRESS_GRANULARITY=XCP_ADDRESS_GRANULARITY_BYTE -DCODERTARGET_XCP_DAQ_PACKED_MODE -DCODERTARGET_XCP_MAX_CONTIGUOUS_SAMPLES=2 -D_MW_ARDUINO_LOOP_=1 -DMW_ARDUINO_STEP_SIZE=10000 -DMW_ARDUINO_MICROS -DARDUINO_NUM_SERIAL_PORTS=3 -D_RTT_BAUDRATE_SERIAL0_=9600 -D_RTT_BAUDRATE_SERIAL2_=9600 -D_RTT_CONFIG_SERIAL0_=SERIAL_8N1 -D_RTT_CONFIG_SERIAL2_=SERIAL_8N1 -D_RTT_ANALOG_REF_=0 -DMW_RTIO_SERIAL0 -D_RTT_PWM_BLOCKS_ -DARDUINO_DEFAULT_PWM_FREQUENCY=1000
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DXCP_DAQ_SUPPORT -DXCP_CALIBRATION_SUPPORT -DXCP_TIMESTAMP_SUPPORT -DXCP_TIMESTAMP_BASED_ON_SIMULATION_TIME -DXCP_SET_MTA_SUPPORT -DEXTMODE_XCP_TRIGGER_SUPPORT -DINTERNAL_XCP_MEM_BLOCK_1_SIZE=128 -DINTERNAL_XCP_MEM_BLOCK_1_NUMBER=1 -DINTERNAL_XCP_MEM_BLOCK_2_SIZE=144 -DINTERNAL_XCP_MEM_BLOCK_2_NUMBER=4 -DINTERNAL_XCP_MEM_BLOCK_3_SIZE=32 -DINTERNAL_XCP_MEM_BLOCK_3_NUMBER=4 -DINTERNAL_XCP_MEM_RESERVED_POOLS_TOTAL_SIZE=66206 -DINTERNAL_XCP_MEM_RESERVED_POOLS_NUMBER=5 -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=65536 -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=1 -DXCP_MEM_BLOCK_1_SIZE=32 -DXCP_MEM_BLOCK_1_NUMBER=1 -DXCP_MEM_BLOCK_2_SIZE=48 -DXCP_MEM_BLOCK_2_NUMBER=1 -DXCP_MEM_BLOCK_3_SIZE=32 -DXCP_MEM_BLOCK_3_NUMBER=1 -DXCP_MEM_RESERVED_POOLS_TOTAL_SIZE=421 -DXCP_MEM_RESERVED_POOLS_NUMBER=2 -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=3 -DXCP_MEM_DAQ_RESERVED_POOLS_NUMBER=1 -DXCP_MIN_EVENT_NO_RESERVED_POOL=2
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DINCLUDE_xTaskGetCurrentTaskHandle=1 -DOS_STKSIZE=8192 -DINCLUDE_vTaskDelete -DINCLUDE_vTaskDelay=1 -DUSE_FREERTOS -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=Torque_control -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/MW_arduino_digitalio.cpp C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/MW_ArduinoEncoder.cpp C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c $(START_DIR)/Torque_control_ert_rtw/Torque_control.c $(START_DIR)/Torque_control_ert_rtw/Torque_control_data.c $(START_DIR)/Torque_control_ert_rtw/rtGetInf.c $(START_DIR)/Torque_control_ert_rtw/rtGetNaN.c $(START_DIR)/Torque_control_ert_rtw/rt_nonfinite.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_standard.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_daq.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_calibration.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_fifo.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_transport.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_mem_default.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_drv_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/common/xcp_utils.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_frame_serial.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinotarget/registry/../src/MW_ArduinoHWInit.cpp C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp "$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/cores/esp32/IPAddress.cpp" "$(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/cores/esp32/Print.cpp" C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/shared/freertos/src/mw_freertos_init.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/shared/freertos/src/mw_thread.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/shared/freertos/src/mw_timer.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/shared/freertos/src/mw_semaphore.c C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinotarget/registry/../src/rtiostream_serial_daemon.cpp

MAIN_SRC = $(START_DIR)/Torque_control_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_arduino_digitalio.o MW_ArduinoEncoder.o MW_PWM.o MW_PWMDriver.o ArduinoPinHandleMap.o xcp_ext_mode.o Torque_control.o Torque_control_data.o rtGetInf.o rtGetNaN.o rt_nonfinite.o xcp_ext_common.o xcp_ext_classic_trigger.o xcp.o xcp_standard.o xcp_daq.o xcp_calibration.o xcp_fifo.o xcp_transport.o xcp_mem_default.o xcp_drv_rtiostream.o xcp_utils.o xcp_frame_serial.o xcp_ext_param_default_serial.o MW_ArduinoHWInit.o io_wrappers.o IPAddress.o Print.o mw_freertos_init.o mw_thread.o mw_timer.o mw_semaphore.o rtiostream_serial_daemon.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(SLIB_PATH)/MW_RebuildSrc_Core.o $(SLIB_PATH)/libcore.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -DESP_PLATFORM "-DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\"" -DHAVE_CONFIG_H -DGCC_NOT_5_2_0=0 -DWITH_POSIX -D_RUNONTARGETHARDWARE_BUILD_ -DMW_DONOTSTART_SCHEDULER -D_ROTH_ESP32_
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------
# Linker
#-----------

LDFLAGS_ = -L"$(SLIB_PATH)"
LDFLAGS_SKIPFORSIL =  

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"
SHAREDLIB_LDFLAGS_SKIPFORSIL =  

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -DESP_PLATFORM "-DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\"" -DHAVE_CONFIG_H -DGCC_NOT_5_2_0=0 -DWITH_POSIX -D_RUNONTARGETHARDWARE_BUILD_ -DMW_DONOTSTART_SCHEDULER -D_ROTH_ESP32_
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -L"$(SLIB_PATH)"
CPP_LDFLAGS_SKIPFORSIL =  

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL =  

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	echo "### Invoking postbuild tool "Binary Converter" ..."
	$(ESPTOOL) $(ESPTOOLFLAGS_BIN)
	echo "### Done invoking postbuild tool."
	echo "### Invoking postbuild tool "Partition Generator" ..."
	$(GENPART) $(GENPARTFLAGS_HEX)
	echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/Torque_control_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/Torque_control_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/Torque_control_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/Torque_control_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_arduino_digitalio.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/MW_arduino_digitalio.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_ArduinoEncoder.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/MW_ArduinoEncoder.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PWM.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PWMDriver.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ArduinoPinHandleMap.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xcp_ext_mode.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/Torque_control_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Torque_control.o : $(START_DIR)/Torque_control_ert_rtw/Torque_control.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Torque_control_data.o : $(START_DIR)/Torque_control_ert_rtw/Torque_control_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/Torque_control_ert_rtw/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/Torque_control_ert_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/Torque_control_ert_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_common.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_classic_trigger.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_standard.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_standard.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_daq.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_daq.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_calibration.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_calibration.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_fifo.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_fifo.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_transport.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_transport.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_mem_default.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_mem_default.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_drv_rtiostream.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_drv_rtiostream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_utils.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/common/xcp_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_frame_serial.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_frame_serial.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_param_default_serial.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_ArduinoHWInit.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinotarget/registry/../src/MW_ArduinoHWInit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


io_wrappers.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


IPAddress.o : $(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/cores/esp32/IPAddress.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Print.o : $(ARDUINO_ESP32_ROOT)/hardware/esp32/$(ESP32_LIB_VERSION)/cores/esp32/Print.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mw_freertos_init.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/shared/freertos/src/mw_freertos_init.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_thread.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/shared/freertos/src/mw_thread.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_timer.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/shared/freertos/src/mw_timer.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_semaphore.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/shared/freertos/src/mw_semaphore.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtiostream_serial_daemon.o : C:/ProgramData/MATLAB/SupportPackages/R2022b/toolbox/target/supportpackages/arduinotarget/registry/../src/rtiostream_serial_daemon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo "### PRODUCT = $(PRODUCT)"
	echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	echo "### BUILD_TYPE = $(BUILD_TYPE)"
	echo "### INCLUDES = $(INCLUDES)"
	echo "### DEFINES = $(DEFINES)"
	echo "### ALL_SRCS = $(ALL_SRCS)"
	echo "### ALL_OBJS = $(ALL_OBJS)"
	echo "### LIBS = $(LIBS)"
	echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	echo "### ASFLAGS = $(ASFLAGS)"
	echo "### CFLAGS = $(CFLAGS)"
	echo "### LDFLAGS = $(LDFLAGS)"
	echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	echo "### CPPFLAGS = $(CPPFLAGS)"
	echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	echo "### ARFLAGS = $(ARFLAGS)"
	echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	echo "### ESPTOOLFLAGS_BIN = $(ESPTOOLFLAGS_BIN)"
	echo "### GENPARTFLAGS_HEX = $(GENPARTFLAGS_HEX)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


