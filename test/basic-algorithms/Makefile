CC=/home/obfuscator/Github_Project/MPIWasm/wasi-sdk-20.0/bin/clang

ORIGIN=origin
FLATTEN=flatten
CALLTOINDIRECT=call

CFLAGS += --sysroot=/home/obfuscator/Github_Project/MPIWasm/wasi-sdk-20.0/share/wasi-sysroot

SRCS =$(wildcard *.c)
# OBJS =$(patsubst %.c,%.wasm,$(SRCS))
ORIGIN_WATOBJECTS =$(patsubst %.wat,%.wasm,$(wildcard $(ORIGIN)/*.wat))
OBFUSCTATED_WATOBJECTS =$(patsubst %.wasm,%.wat,$(wildcard $(OBFUSCATED)/*.wasm))
ORIGIN_WASM := $(addprefix $(ORIGIN)/,$(notdir $(SRCS:.c=.wasm)))

FLATTEN_WASM := $(addprefix $(FLATTEN)/,$(notdir $(SRCS:.c=.wasm)))
CALLTOINDIRECT_WASM := $(addprefix $(CALLTOINDIRECT)/,$(notdir $(SRCS:.c=.wasm)))

.PHONY: compile, convert, clean
compile: $(ORIGIN_WASM) $(FLATTEN_WASM) $(CALLTOINDIRECT_WASM)

$(ORIGIN)/%.wasm: %.c
	$(CC) $(CFLAGS) $< -O0 -o $@

$(FLATTEN)/%.wasm: %.c
	$(CC) $(CFLAGS) $< -O0 -o $@

$(CALLTOINDIRECT)/%.wasm: %.c
	$(CC) $(CFLAGS) $< -O0 -o $@

convert: $(ORIGIN_WATOBJECTS) $(OBFUSCTATED_WATOBJECTS)

$(ORIGIN)/%.wasm: $(ORIGIN)/%.wat
	wat2wasm  $< --enable-annotations -o $@

$(OBFUSCATED)/%.wat: $(OBFUSCATED)/%.wasm
	wasm2wat $< -o $@

clean:
	rm -rf $(ORIGIN)
	rm -rf $(FLATTEN)
	rm -rf $(CALLTOINDIRECT)

	mkdir $(ORIGIN)
	mkdir $(FLATTEN)
	mkdir $(CALLTOINDIRECT)