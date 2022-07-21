format  pe      console
entry   main

OFN     equ     "TinyWinDL_386.exe"
VERSION equ     "1.0.0.0"

include	"win32axp.inc"
include	"gP_win32.inc"

section ".idata"import\
                data\
                readable

        include ".idata.inc"

section ".text" code\
                executable

        include ".text.inc"

section	".data."writeable

	include	".data.inc"

section ".rsrc" data\
                resource\
                readable

        include ".rsrc.inc"

section ".bss"  writeable

        include ".bss.inc"