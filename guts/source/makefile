TOOL_DIR  := $(HOME)/cosmo/bin/
TARGET_DIR := ../../

COSMO_TARGET    := $(TARGET_DIR)flow.com
MEMCHECK_TARGET := $(TARGET_DIR)flow

TARGET_SOURCE := guts/source/
BUILD_DIR     := ../build

DIRS    := $(wildcard ./*/)
DIRS    := $(filter-out ./makefile,$(DIRS))
ISEARCH := $(foreach dir,$(DIRS),-I$(dir))

SEARCH  := $(foreach dir,$(DIRS),$(dir)*.cpp)
LSEARCH := $(sort $(wildcard */*.lua))
SOURCES := $(wildcard $(SEARCH))

OBJECTS := $(patsubst ./%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
OBJECTS += $(OBJECTS_EXTRA)

DEPENDS := $(OBJECTS:.o=.d)

.PHONY: all cosmo memcheck clean show dirs

all: cosmo

cosmo: CXX    := $(TOOL_DIR)cosmoc++ -D_COSMO_SOURCE -MMD -MP -I.
cosmo: LINKER := $(TOOL_DIR)cosmoc++
cosmo: $(COSMO_TARGET)

memcheck: CXX    := clang++ -std=c++11 -fsanitize=address -g -O0 -MMD -MP 
memcheck: LINKER := clang++ -fsanitize=address
memcheck: $(MEMCHECK_TARGET)


$(COSMO_TARGET): $(OBJECTS) $(LSEARCH)
	@mkdir -p $(dir $@)
	$(LINKER) $(OBJECTS) -o $@
	rm -f $(TARGET_DIR)*.elf $(TARGET_DIR)*.dbg
	cd $(TARGET_DIR) && zip -qr flow.com $(TARGET_SOURCE)


$(MEMCHECK_TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(LINKER) $(OBJECTS) -o $@


$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(ISEARCH) -c -o $@ $<


dirs:
	@echo DIRS = $(DIRS)


show:
	@echo DIRS            = $(DIRS)
	@echo SEARCH          = $(SEARCH)
	@echo LSEARCH         = $(LSEARCH)
	@echo SOURCES         = $(SOURCES)
	@echo OBJECTS         = $(OBJECTS)
	@echo DEPENDS         = $(DEPENDS)
	@echo COSMO_TARGET    = $(COSMO_TARGET)
	@echo MEMCHECK_TARGET = $(MEMCHECK_TARGET)


clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPENDS)
