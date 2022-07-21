format	pe64	console
entry	main

include	"win64axp.inc"
include	"gP_win64.inc"

section	""	data\
		readable\
		writeable\
		import\
		code\
		executable

	include ".idata.inc"
	include ".text.inc"
	include	".data.inc"
	include ".bss.inc"