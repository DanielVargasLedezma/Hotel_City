#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/C_Files/Cliente.o \
	${OBJECTDIR}/C_Files/Contenedora.o \
	${OBJECTDIR}/C_Files/DateGenerator.o \
	${OBJECTDIR}/C_Files/Habitacion.o \
	${OBJECTDIR}/C_Files/Hotel.o \
	${OBJECTDIR}/C_Files/Informacion.o \
	${OBJECTDIR}/C_Files/Interfaz.o \
	${OBJECTDIR}/C_Files/ListaReservaciones.o \
	${OBJECTDIR}/C_Files/Reservaciones.o \
	${OBJECTDIR}/C_Files/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hotel_city.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hotel_city.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hotel_city ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/C_Files/Cliente.o: C_Files/Cliente.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Cliente.o C_Files/Cliente.c

${OBJECTDIR}/C_Files/Contenedora.o: C_Files/Contenedora.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Contenedora.o C_Files/Contenedora.c

${OBJECTDIR}/C_Files/DateGenerator.o: C_Files/DateGenerator.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/DateGenerator.o C_Files/DateGenerator.c

${OBJECTDIR}/C_Files/Habitacion.o: C_Files/Habitacion.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Habitacion.o C_Files/Habitacion.c

${OBJECTDIR}/C_Files/Hotel.o: C_Files/Hotel.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Hotel.o C_Files/Hotel.c

${OBJECTDIR}/C_Files/Informacion.o: C_Files/Informacion.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Informacion.o C_Files/Informacion.c

${OBJECTDIR}/C_Files/Interfaz.o: C_Files/Interfaz.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Interfaz.o C_Files/Interfaz.c

${OBJECTDIR}/C_Files/ListaReservaciones.o: C_Files/ListaReservaciones.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/ListaReservaciones.o C_Files/ListaReservaciones.c

${OBJECTDIR}/C_Files/Reservaciones.o: C_Files/Reservaciones.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/Reservaciones.o C_Files/Reservaciones.c

${OBJECTDIR}/C_Files/main.o: C_Files/main.c
	${MKDIR} -p ${OBJECTDIR}/C_Files
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/C_Files/main.o C_Files/main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
