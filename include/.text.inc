main:

	os.Entry

	;Clear HBX and use to determine interactive or unattended mode
	xor	HBX,HBX

	cmp	[os.Argc],2
	jl	.geturlenv
	mov	HDI,[os.Argv]	
	xor	al,al
	call	strings.NxtB
	mov	HSI,hlpStrs
	mov	HDX,HAX
	mov	HDI,HAX
	xor	cl,cl
	.helpStr:
	call	strings.CmpB
	cmp	HAX,0
	je	.help
	xor	al,al
	mov	HDI,HSI
	call	strings.NxtB
	cmp	byte[HAX],0
	je	.geturl
	mov	HSI,HAX
	mov	HDI,HDX
	jmp	.helpStr

	.help:
	mov	HSI,usage
	call	os.Cout
	jmp	.exit

	.geturl:
	mov	[srcURL],HDI
	inc	HBX
	jmp	.getfile

	.geturlenv:
	mov	HSI,urlenv
	call	os.GetEnv
	cmp	HAX,0
	je	.prompturl
	mov	[srcURL],HAX
	inc	HBX
	jmp	.getfile

	.prompturl:
        mov     HSI,askURL
        call    os.Cout
        mov     HDI,srcURL
	mov	HCX,1
	mov	HDX,BUFCAP
        call    os.Cin

	.getfile:
	cmp	[os.Argc],3
	jl	.getfileenv
	mov	HDI,[os.Argv]
	xor	al,al
	mov	HCX,2
	call	strings.NB
	mov	[dstFile],HAX
	inc	HBX
	jmp	.download

	.getfileenv:
	mov	HSI,fileenv
	call	os.GetEnv
	cmp	HAX,0
	je	.promptfile
	mov	[dstFile],HAX
	inc	HBX
	jmp	.download

	.promptfile:
        mov     HSI,askFile
        call    os.Cout
        mov     HDI,dstFile
	mov	HCX,1
	mov	HDX,BUFCAP
        call    os.Cin

	.download:

        ;Prompt that the download is in progress
        mov     HSI,dl1
        call    os.Cout
        mov     HSI,[srcURL]
        call    os.Cout
        mov     HSI,dl2
        call    os.Cout
        mov     HSI,[dstFile]
        call    os.Cout
        mov     HSI,dl3
        call    os.Cout

        ;Download URL to file
        push    0
        invoke  URLDownloadToFileA,\
                0,\
                [srcURL],\
                [dstFile],\
                0

        ;Free heap allocations now, rather than waiting for os.Exit to do it automatically
	call	asto.Flush

        ;Prompt that download complete
        mov     HSI,done
        call    os.Cout

	;Pause before exiting if in interactive mode
	cmp	HBX,2
	je	.exit
        call    libc.Pause

	;Standard exit without errors, setting exit code to 0
	.exit:
	xor	HCX,HCX
	;If errors, set exit code and jmp os.Exit
	os.Exit