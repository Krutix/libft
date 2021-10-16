DOXYGEN_DIR ?= ./docs/
DOXYGEN_CFG ?= doxygen.cfg
DOXYGEN_EXE ?= doxygen

.PHONY: doxygen
doxygen:
	mkdir ${DOXYGEN_OUTPUT}; ${DOXYGEN} ${DOXYGEN_DIR}${DOXYGEN_CFG}
