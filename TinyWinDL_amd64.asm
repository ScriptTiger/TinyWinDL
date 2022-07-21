format  pe64    console
entry   main

OFN     equ     "TinyWinDL_amd64.exe"
VERSION equ     "1.0.0.0"

include	"win64axp.inc"
include	"gP_win64.inc"

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