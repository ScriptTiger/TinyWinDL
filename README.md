[![Say Thanks!](https://img.shields.io/badge/Say%20Thanks-!-1EAEDB.svg)](https://docs.google.com/forms/d/e/1FAIpQLSfBEe5B_zo69OBk19l3hzvBmz3cOV6ol1ufjh0ER1q3-xd2Rg/viewform)

# TinyWinDL
This is a trivial downloader for Windows which is basically just a wrapper for `URLDownloadToFileA`. Being a trivial downloader, it does not attempt to recover from an error nor does it follow dynamic links, so all links should be static. Use cases for TinyWinDL are trivial files, such as small files storing non-critical settings or configurations, which are synchronized regularly and missing a synchronization here or there is not important.

Usage: `TinyWinDL <url> <file>`

If no arguments, case-sensitive environmental variables used:

twdl_url  
twdl_file

If environmental variables not set, input will be prompted interactively.

**Dependencies**  
If you are trying to build TinyWinDL yourself, the fasmg and fasmgP submodules may not be cloned as default behavior, depending on what git software you are using.

fasmg:  
https://github.com/tgrysztar/fasmg

fasmgP:  
https://github.com/ScriptTiger/fasmgP

**TinyWinDL_386**  
32-bit TinyWinDL.

**TinyWinDL_386_micro**  
32-bit TinyWinDL condensed into a single code section.

**TinyWinDL_amd64**  
64-bit TinyWinDL.

**TinyWinDL_amd64_micro**  
64-bit TinyWinDL condensed into a single code section.

# More About ScriptTiger

For more ScriptTiger scripts and goodies, check out ScriptTiger's GitHub Pages website:  
https://scripttiger.github.io/
