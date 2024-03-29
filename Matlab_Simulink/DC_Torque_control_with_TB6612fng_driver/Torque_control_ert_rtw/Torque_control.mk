###########################################################################
## Makefile generated for component 'Torque_control'. 
## 
## Makefile     : Torque_control.mk
<<<<<<< HEAD
## Generated on : Sat Oct 15 08:20:39 2022
=======
## Generated on : Sat Apr 22 17:06:28 2023
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
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
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2022a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2022a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/sokse/OneDrive/MyGithub/DC_Motor_Control/Matlab_Simulink/DC_Torque_control_with_TB6612fng_driver
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
<<<<<<< HEAD
SLIB_PATH                 = C:/Users/sokse/DOCUME~1/MATLAB/R2022a/ARDUIN~1/ARDUIN~2/FASTER~1
=======
SLIB_PATH                 = C:/Users/LabPC/DOCUME~1/MATLAB/R2022a/ARDUIN~1/ARDUIN~1/FASTER~1
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Arduino ARM
# Supported Version(s):    
# ToolchainInfo Version:   2022a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ARDUINO_ROOT
# ARDUINO_PACKAGES_TOOLS_ROOT
# ARDUINO_PORT
# ARDUINO_MCU
# ARDUINO_BAUD
# ARDUINO_PROTOCOL
# ARDUINO_F_CPU

#-----------
# MACROS
#-----------

SHELL                       = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
ARDUINO_TOOLS               = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
<<<<<<< HEAD
TOOLCHAIN_LIBS = -lm -lcomm -lcore
=======
TOOLCHAIN_LIBS = -Wl,--end-group -lm -gcc -lcore
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM Assembler
AS_PATH = $(ARDUINO_TOOLS)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: Arduino ARM C Compiler
CC_PATH = $(ARDUINO_TOOLS)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: Arduino ARM Linker
LD_PATH = $(ARDUINO_TOOLS)
LD = "$(LD_PATH)/arm-none-eabi-gcc"

# C++ Compiler: Arduino ARM C++ Compiler
CPP_PATH = $(ARDUINO_TOOLS)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: Arduino ARM C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-gcc"

# Archiver: Arduino ARM Archiver
AR_PATH = $(ARDUINO_TOOLS)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPY_PATH = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin
OBJCOPY = "$(OBJCOPY_PATH)/arm-none-eabi-objcopy"

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

ASFLAGS = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  -Wall -x assembler-with-cpp $(ASFLAGS_ADDITIONAL) $(DEFINES) $(INCLUDES) -c

CFLAGS = -std=gnu11 -Os -c -w -ffunction-sections -fdata-sections  -nostdlib  --param max-inline-insns-single=500  -Dprintf=iprintf  -DARDUINO=10801  -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" -g

LDFLAGS = -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections -g

SHAREDLIB_LDFLAGS = -g

CPPFLAGS = -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions  -Os -c -w -ffunction-sections -fdata-sections  -nostdlib  --param max-inline-insns-single=500  -Dprintf=iprintf  -DARDUINO=10801  -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" -g

CPP_LDFLAGS = -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections -g

CPP_SHAREDLIB_LDFLAGS = -g

ARFLAGS = ruvs

OBJCOPYFLAGS_BIN = -O binary $(PRODUCT) $(PRODUCT_BIN)

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

<<<<<<< HEAD
INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/shared/svd/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARDUIN~2/include -I$(START_DIR)/Torque_control_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/common -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src -I$(MATLAB_ROOT)/rtw/c/ext_mode/common -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(ARDUINO_ROOT)/hardware/arduino/avr/cores/arduino -I$(ARDUINO_ROOT)/hardware/arduino/avr/variants/mega -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARDUIN~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARDUIN~1/SCHEDU~1/include -I$(ARDUINO_ROOT)/hardware/tools/avr/avr/include/avr -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/shared/EXTERN~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/aIDE/LIBRAR~1/Servo/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/aIDE/hardware/arduino/avr/LIBRAR~1/Wire/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/aIDE/hardware/arduino/avr/LIBRAR~1/Wire/src/utility -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/aIDE/hardware/arduino/avr/LIBRAR~1/SPI/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/aIDE/LIBRAR~1/Servo/src/avr
=======
INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARDUIN~2/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/shared/svd/include -I$(START_DIR)/Torque_control_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/common -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/include -I$(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src -I$(MATLAB_ROOT)/rtw/c/ext_mode/common -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/system/libsam -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/system/CMSIS/CMSIS/Include -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/system/CMSIS/Device/ATMEL -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/cores/arduino -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/cores/arduino/avr -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARDUIN~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARDUIN~1/SCHEDU~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/shared/EXTERN~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARMCOR~1/SCHEDU~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2022a/toolbox/target/SUPPOR~1/ARMCOR~1/xcp/include
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

<<<<<<< HEAD
DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DXCP_MAX_CTO_SIZE=32 -DXCP_MAX_DTO_SIZE=65532 -DXCP_MAX_ODT_ENTRY_SIZE=255 -DXCP_MAX_DAQ=65535 -DXCP_MIN_DAQ=0 -DXCP_MAX_EVENT_CHANNEL=128 -DXCP_ID_FIELD_TYPE=0 -DXCP_TIMESTAMP_SIZE=4 -DXCP_ADDRESS_GRANULARITY=XCP_ADDRESS_GRANULARITY_BYTE -DCODERTARGET_XCP_DAQ_PACKED_MODE -DCODERTARGET_XCP_MAX_CONTIGUOUS_SAMPLES=2 -DXCP_MEM_RESERVED_POOLS_TOTAL_SIZE=436 -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=3 -D_MW_ARDUINO_LOOP_=1 -DMW_ARDUINO_STEP_SIZE=1000 -DMW_ARDUINO_MICROS -DARDUINO_NUM_SERIAL_PORTS=4 -D_RTT_BAUDRATE_SERIAL0_=9600 -D_RTT_BAUDRATE_SERIAL1_=9600 -D_RTT_BAUDRATE_SERIAL2_=9600 -D_RTT_BAUDRATE_SERIAL3_=9600 -D_RTT_ANALOG_REF_=0 -DMW_RTIO_SERIAL0
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DXCP_EXTMODE_SIMULATION_TIME_IN_TICKS -DXCP_DAQ_SUPPORT -DXCP_CALIBRATION_SUPPORT -DXCP_TIMESTAMP_SUPPORT -DXCP_TIMESTAMP_BASED_ON_SIMULATION_TIME -DXCP_SET_MTA_SUPPORT -DXCP_MEM_DAQ_RESERVED_POOLS_NUMBER=3 -DEXTMODE_XCP_TRIGGER_SUPPORT -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=2048 -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=1 -DXCP_MEM_BLOCK_1_SIZE=32 -DXCP_MEM_BLOCK_1_NUMBER=2 -DXCP_MEM_BLOCK_2_SIZE=48 -DXCP_MEM_BLOCK_2_NUMBER=2 -DXCP_MEM_BLOCK_3_SIZE=64 -DXCP_MEM_BLOCK_3_NUMBER=1
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=Torque_control -DNUMST=3 -DNCSTATES=1 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
=======
DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DXCP_MAX_CTO_SIZE=255 -DXCP_MAX_DTO_SIZE=65532 -DXCP_MAX_ODT_ENTRY_SIZE=255 -DXCP_MAX_DAQ=65535 -DXCP_MIN_DAQ=0 -DXCP_MAX_EVENT_CHANNEL=128 -DXCP_ID_FIELD_TYPE=0 -DXCP_TIMESTAMP_SIZE=4 -DXCP_ADDRESS_GRANULARITY=XCP_ADDRESS_GRANULARITY_BYTE -DCODERTARGET_XCP_DAQ_PACKED_MODE -DCODERTARGET_XCP_MAX_CONTIGUOUS_SAMPLES=2 -DXCP_MEM_RESERVED_POOLS_TOTAL_SIZE=867 -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=3 -DMW_TIMERID=8 -DMW_TIMERCOUNT=26250 -DMW_SAM_CLOCKID=TC_CMR_TCCLKS_TIMER_CLOCK3 -DARDUINO_NUM_SERIAL_PORTS=4 -D_RTT_BAUDRATE_SERIAL0_=9600 -D_RTT_BAUDRATE_SERIAL1_=9600 -D_RTT_BAUDRATE_SERIAL2_=9600 -D_RTT_BAUDRATE_SERIAL3_=9600 -D_RTT_ANALOG_REF_=0 -DMW_RTIO_SERIAL0
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DXCP_DAQ_SUPPORT -DXCP_CALIBRATION_SUPPORT -DXCP_TIMESTAMP_SUPPORT -DXCP_TIMESTAMP_BASED_ON_SIMULATION_TIME -DXCP_SET_MTA_SUPPORT -DXCP_MEM_DAQ_RESERVED_POOLS_NUMBER=2 -DEXTMODE_XCP_TRIGGER_SUPPORT -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=24576 -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=1 -DXCP_MEM_BLOCK_1_SIZE=32 -DXCP_MEM_BLOCK_1_NUMBER=1 -DXCP_MEM_BLOCK_2_SIZE=32 -DXCP_MEM_BLOCK_2_NUMBER=1 -DXCP_MEM_BLOCK_3_SIZE=48 -DXCP_MEM_BLOCK_3_NUMBER=1
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=Torque_control -DNUMST=2 -DNCSTATES=1 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

<<<<<<< HEAD
SRCS = C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_arduinoI2C.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_arduino_digitalio.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_ArduinoEncoder.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp xcp_ext_mode.c $(START_DIR)/Torque_control_ert_rtw/Torque_control.c $(START_DIR)/Torque_control_ert_rtw/Torque_control_data.c $(START_DIR)/Torque_control_ert_rtw/rtGetInf.c $(START_DIR)/Torque_control_ert_rtw/rtGetNaN.c $(START_DIR)/Torque_control_ert_rtw/rt_nonfinite.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_standard.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_daq.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_calibration.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_fifo.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_transport.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_mem_default.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_drv_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_frame_serial.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../src/MW_ArduinoHWInit.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arduinoAVRScheduler.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../src/rtiostream_serial_daemon.cpp
=======
SRCS = C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_ArduinoEncoder.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp xcp_ext_mode.c $(START_DIR)/Torque_control_ert_rtw/Torque_control.c $(START_DIR)/Torque_control_ert_rtw/Torque_control_data.c $(START_DIR)/Torque_control_ert_rtw/rtGetInf.c $(START_DIR)/Torque_control_ert_rtw/rtGetNaN.c $(START_DIR)/Torque_control_ert_rtw/rt_nonfinite.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_standard.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_daq.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/xcp_calibration.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_fifo.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_transport.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_mem_default.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/xcp_drv_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_frame_serial.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arm_m3_cortex_handler.c C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../src/MW_ArduinoHWInit.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arduinoARMScheduler.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../src/rtiostream_serial_daemon.cpp C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/armcortexmbase/xcp/src/sys_arch.c
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

MAIN_SRC = $(START_DIR)/Torque_control_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

<<<<<<< HEAD
OBJS = MW_arduinoI2C.o MW_arduino_digitalio.o MW_ArduinoEncoder.o MW_PWM.o MW_PWMDriver.o ArduinoPinHandleMap.o xcp_ext_mode.o Torque_control.o Torque_control_data.o rtGetInf.o rtGetNaN.o rt_nonfinite.o xcp_ext_common.o xcp_ext_classic_trigger.o xcp.o xcp_standard.o xcp_daq.o xcp_calibration.o xcp_fifo.o xcp_transport.o xcp_mem_default.o xcp_drv_rtiostream.o xcp_frame_serial.o xcp_ext_param_default_serial.o MW_ArduinoHWInit.o io_wrappers.o arduinoAVRScheduler.o rtiostream_serial_daemon.o
=======
OBJS = MW_ArduinoEncoder.o MW_PWM.o MW_PWMDriver.o ArduinoPinHandleMap.o xcp_ext_mode.o Torque_control.o Torque_control_data.o rtGetInf.o rtGetNaN.o rt_nonfinite.o xcp_ext_common.o xcp_ext_classic_trigger.o xcp.o xcp_standard.o xcp_daq.o xcp_calibration.o xcp_fifo.o xcp_transport.o xcp_mem_default.o xcp_drv_rtiostream.o xcp_frame_serial.o xcp_ext_param_default_serial.o arm_m3_cortex_handler.o MW_ArduinoHWInit.o io_wrappers.o arduinoARMScheduler.o m3m4m4f_multitasking.o rtiostream_serial_daemon.o sys_arch.o
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

<<<<<<< HEAD
LIBS = $(SLIB_PATH)/MW_RebuildSrc_Comm.o $(SLIB_PATH)/MW_RebuildSrc_Core.o
=======
LIBS = $(SLIB_PATH)/MW_RebuildSrc_Core.o $(SLIB_PATH)/libcore.a
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

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

CFLAGS_SKIPFORSIL = -MD -mcpu=cortex-m3 -fpermissive -DF_CPU=84000000L -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Due\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_DUE_ -DARDUINO_NUM_SERIAL_PORTS=4 -DARDUINO_ARM -DARDUINO_ARM_CORTEX_M3
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------
# Linker
#-----------

LDFLAGS_ = -L"$(SLIB_PATH)"
LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"
SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -MD -mcpu=cortex-m3 -fpermissive -DF_CPU=84000000L -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Due\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_DUE_ -DARDUINO_NUM_SERIAL_PORTS=4 -DARDUINO_ARM -DARDUINO_ARM_CORTEX_M3
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -L"$(SLIB_PATH)"
CPP_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

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
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
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


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/Torque_control_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/Torque_control_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/Torque_control_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/Torque_control_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/Torque_control_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/Torque_control_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/Torque_control_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/protocol/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


<<<<<<< HEAD
MW_arduinoI2C.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_arduinoI2C.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_arduino_digitalio.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_arduino_digitalio.cpp
=======
%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/platform/default/%.cxx
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_ArduinoEncoder.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_ArduinoEncoder.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PWM.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PWMDriver.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ArduinoPinHandleMap.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Torque_control.o : $(START_DIR)/Torque_control_ert_rtw/Torque_control.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Torque_control_data.o : $(START_DIR)/Torque_control_ert_rtw/Torque_control_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/Torque_control_ert_rtw/ert_main.c
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


xcp_frame_serial.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/slave/transport/src/xcp_frame_serial.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_param_default_serial.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_m3_cortex_handler.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arm_m3_cortex_handler.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_ArduinoHWInit.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../src/MW_ArduinoHWInit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


io_wrappers.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


arduinoARMScheduler.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arduinoARMScheduler.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


m3m4m4f_multitasking.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtiostream_serial_daemon.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/arduinotarget/registry/../src/rtiostream_serial_daemon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sys_arch.o : C:/ProgramData/MATLAB/SupportPackages/R2022a/toolbox/target/supportpackages/armcortexmbase/xcp/src/sys_arch.c
	$(CC) $(CFLAGS) -o "$@" "$<"


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
	echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


