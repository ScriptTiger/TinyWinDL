hlpStrs	db	"/?",0,\
		"-?",0,\
		"/help",0,\
		"-help",0,\
		"--help",0,\
		0
usage	db	"Usage: TinyWinDL <url> <file>",13,10,\
		" If no arguments, case-sensitive environmental variables used:",13,10,13,10,\
		" twdl_url",13,10,\
		" twdl_file",13,10,13,10,\
		" If environmental variables not set, input will be prompted interactively.",13,10,\
		0
urlenv	db	"twdl_url",0
fileenv	db	"twdl_file",0
askURL	db	"URL:",13,10,0
askFile	db	"File:",13,10,0
dl1	db	"Downloading ",0
dl2	db	" to ",0
dl3	db	"...",13,10,0
done	db	"Download complete",13,10,0

common_definitions