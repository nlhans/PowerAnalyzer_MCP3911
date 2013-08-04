#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MCP3911.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MCP3911.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1278887395/23lc1024.o ${OBJECTDIR}/_ext/1639450193/spi.o ${OBJECTDIR}/_ext/1639450193/uart.o ${OBJECTDIR}/_ext/1519963337/circularBuffer.o ${OBJECTDIR}/_ext/1519963337/insight.o ${OBJECTDIR}/_ext/1278887395/mcp3911.o ${OBJECTDIR}/_ext/1278887395/mcp6s26.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1278887395/23lc1024.o.d ${OBJECTDIR}/_ext/1639450193/spi.o.d ${OBJECTDIR}/_ext/1639450193/uart.o.d ${OBJECTDIR}/_ext/1519963337/circularBuffer.o.d ${OBJECTDIR}/_ext/1519963337/insight.o.d ${OBJECTDIR}/_ext/1278887395/mcp3911.o.d ${OBJECTDIR}/_ext/1278887395/mcp6s26.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1278887395/23lc1024.o ${OBJECTDIR}/_ext/1639450193/spi.o ${OBJECTDIR}/_ext/1639450193/uart.o ${OBJECTDIR}/_ext/1519963337/circularBuffer.o ${OBJECTDIR}/_ext/1519963337/insight.o ${OBJECTDIR}/_ext/1278887395/mcp3911.o ${OBJECTDIR}/_ext/1278887395/mcp6s26.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MCP3911.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128GP804
MP_LINKER_FILE_OPTION=,--script=p33FJ128GP804.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=0
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1278887395/23lc1024.o: ../src/devices/23lc1024.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1278887395 
	@${RM} ${OBJECTDIR}/_ext/1278887395/23lc1024.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/devices/23lc1024.c  -o ${OBJECTDIR}/_ext/1278887395/23lc1024.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1278887395/23lc1024.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=1
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278887395/23lc1024.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1639450193/spi.o: ../src/drivers/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1639450193 
	@${RM} ${OBJECTDIR}/_ext/1639450193/spi.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/drivers/spi.c  -o ${OBJECTDIR}/_ext/1639450193/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1639450193/spi.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=2
	@${FIXDEPS} "${OBJECTDIR}/_ext/1639450193/spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1639450193/uart.o: ../src/drivers/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1639450193 
	@${RM} ${OBJECTDIR}/_ext/1639450193/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/drivers/uart.c  -o ${OBJECTDIR}/_ext/1639450193/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1639450193/uart.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=3
	@${FIXDEPS} "${OBJECTDIR}/_ext/1639450193/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1519963337/circularBuffer.o: ../src/utils/circularBuffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1519963337 
	@${RM} ${OBJECTDIR}/_ext/1519963337/circularBuffer.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/utils/circularBuffer.c  -o ${OBJECTDIR}/_ext/1519963337/circularBuffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1519963337/circularBuffer.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=4
	@${FIXDEPS} "${OBJECTDIR}/_ext/1519963337/circularBuffer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1519963337/insight.o: ../src/utils/insight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1519963337 
	@${RM} ${OBJECTDIR}/_ext/1519963337/insight.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/utils/insight.c  -o ${OBJECTDIR}/_ext/1519963337/insight.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1519963337/insight.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=5
	@${FIXDEPS} "${OBJECTDIR}/_ext/1519963337/insight.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1278887395/mcp3911.o: ../src/devices/mcp3911.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1278887395 
	@${RM} ${OBJECTDIR}/_ext/1278887395/mcp3911.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/devices/mcp3911.c  -o ${OBJECTDIR}/_ext/1278887395/mcp3911.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1278887395/mcp3911.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=6
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278887395/mcp3911.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1278887395/mcp6s26.o: ../src/devices/mcp6s26.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1278887395 
	@${RM} ${OBJECTDIR}/_ext/1278887395/mcp6s26.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/devices/mcp6s26.c  -o ${OBJECTDIR}/_ext/1278887395/mcp6s26.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1278887395/mcp6s26.o.d"        -g -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=7
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278887395/mcp6s26.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=0
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1278887395/23lc1024.o: ../src/devices/23lc1024.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1278887395 
	@${RM} ${OBJECTDIR}/_ext/1278887395/23lc1024.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/devices/23lc1024.c  -o ${OBJECTDIR}/_ext/1278887395/23lc1024.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1278887395/23lc1024.o.d"        -g -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=1
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278887395/23lc1024.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1639450193/spi.o: ../src/drivers/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1639450193 
	@${RM} ${OBJECTDIR}/_ext/1639450193/spi.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/drivers/spi.c  -o ${OBJECTDIR}/_ext/1639450193/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1639450193/spi.o.d"        -g -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=2
	@${FIXDEPS} "${OBJECTDIR}/_ext/1639450193/spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1639450193/uart.o: ../src/drivers/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1639450193 
	@${RM} ${OBJECTDIR}/_ext/1639450193/uart.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/drivers/uart.c  -o ${OBJECTDIR}/_ext/1639450193/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1639450193/uart.o.d"        -g -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=3
	@${FIXDEPS} "${OBJECTDIR}/_ext/1639450193/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1519963337/circularBuffer.o: ../src/utils/circularBuffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1519963337 
	@${RM} ${OBJECTDIR}/_ext/1519963337/circularBuffer.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/utils/circularBuffer.c  -o ${OBJECTDIR}/_ext/1519963337/circularBuffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1519963337/circularBuffer.o.d"        -g -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=4
	@${FIXDEPS} "${OBJECTDIR}/_ext/1519963337/circularBuffer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1519963337/insight.o: ../src/utils/insight.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1519963337 
	@${RM} ${OBJECTDIR}/_ext/1519963337/insight.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/utils/insight.c  -o ${OBJECTDIR}/_ext/1519963337/insight.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1519963337/insight.o.d"        -g -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=5
	@${FIXDEPS} "${OBJECTDIR}/_ext/1519963337/insight.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1278887395/mcp3911.o: ../src/devices/mcp3911.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1278887395 
	@${RM} ${OBJECTDIR}/_ext/1278887395/mcp3911.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/devices/mcp3911.c  -o ${OBJECTDIR}/_ext/1278887395/mcp3911.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1278887395/mcp3911.o.d"        -g -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=6
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278887395/mcp3911.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1278887395/mcp6s26.o: ../src/devices/mcp6s26.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1278887395 
	@${RM} ${OBJECTDIR}/_ext/1278887395/mcp6s26.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/devices/mcp6s26.c  -o ${OBJECTDIR}/_ext/1278887395/mcp6s26.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1278887395/mcp6s26.o.d"        -g -omf=elf -O0 -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/devices" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/drivers" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src/utils" -I"C:/Users/Hans/Documents/GitHub/mcp3911/src" -msmart-io=1 -Wall -msfr-warn=off -DF_NUM=7
	@${FIXDEPS} "${OBJECTDIR}/_ext/1278887395/mcp6s26.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MCP3911.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MCP3911.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1  -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PICKIT2=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MCP3911.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MCP3911.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MCP3911.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
