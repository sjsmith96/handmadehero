@echo off


set CommonCompilerFlags=-MTd -nologo /fp:fast -Gm- -EHa- -Od -GR- -Oi -WX -W4 -wd4201 -wd4100 -wd4189 -wd4456 -wd4505 -DHANDMADE_INTERNAL=1 -DHANDMADE_SLOW=1 -DHANDMADE_WIN32=1 -FC -Z7
set CommonLinkerFlags=-incremental:no -opt:ref user32.lib Gdi32.lib winmm.lib

REM TODO - can we just build both x86 and x64 with one exe?

IF NOT EXIST ..\..\build mkdir ..\..\build
pushd ..\..\build

REM 32-bit build
REM %CommonCompilerFlags% ..\handmade\code\win32_handmade.cpp /link subsystem:wimdows,5.1 %CommonLinkerFlags%

REM 64-bit build
del *.pdb >NUL 2>NUL
REM Opitmization switched /O2 /Oi
echo WAITING FOR PDB > lock.tmp
cl %CommonCompilerFlags% ..\handmade\code\handmade.cpp -Fmhandmade.map -LD /link -incremental:no -opt:ref -PDB:handmade_%random%.pdb /EXPORT:GameGetSoundSamples /EXPORT:GameUpdateAndRender
del lock.tmp
cl %CommonCompilerFlags% ..\handmade\code\win32_handmade.cpp -Fmwin32_handmade.map /link %CommonLinkerFlags% 
popd
