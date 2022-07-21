format	pe	console
entry	main

include	"win32axp.inc"
include	"gP_win32.inc"

section	""	data\
		readable\
		writeable\
		import\
		code\
		executable

	include	".idata.inc"
	include	".text.inc"
	include	".data.inc"
	include	".bss.inc"