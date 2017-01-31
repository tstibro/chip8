# CHIP8
Chip8 emulator written in C++ with SDL2 graphics library.

I made this project because I am interested in hardware emulation and
I wanted to see how hard is it to make na emulator (even easy one like this).

<img src="invadersDemo.gif" alt="Chip8 Emulator - Space Invaders Demo" height="351" width="641" />

## Instalation

Chip8 emulator can be installed simply by copying the following files anywhere you want.

- Chip8emu.exe
- Chip8lib.dll
- SDL2.dll
- SDL2_mixer.dll
- beepsfx.wav

## Controls

Original emulator had 16 keys which are mapped as follows:

     CHIP8        KEYBOARD
    1 2 3 C	      7 8 9 W  
    4 5 6 D   =>  4 5 6 Q  
    7 8 9 E       1 2 3 E  
    A 0 B F       A 0 S F  

Every game may use different keys for control, but for example here is how  to play the INVADERS:

    Move Left = 4
    Move Right = 6
    Shoot = 5
  

## Building from source
**NOTE:** *Currently Chip8 emulator is compatible with Windows OS only.*
### Prerequisites
To build the emulator, you need, apart from the source code, a open-source library
called SDL (Simple DirectMedia Layer) of version 2.

#### C/C++ IDE (Visual Studio)
This project has been developed using *Visual Studio Community 2015* which is a
free version of Visual Studio. For the most convenient way to build the emulator I recommend using Visual Studio.

#### SDL2 library
1. Go to [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php)  
2. Download **Development Libraries**
3. Extract the ZIP somewhere. (My path is C:\Development\Dependencies)

### Emulator Source Code
If you haven't done so already, now we need to get the source code of the emulator.  
**Either:**  
1. Download the ZIP archive  
**Or:**  
1. Open up ***git*** in console   
2. And type `git clone https://github.com/tstibro/chip8.git`

### Visual Studio solution configuration
Before we can build the solution, we need to setup Visual Studio so it knows  
where our SDL2 library and it's source code is stored.   

1. Open **Chip8emu.sln** in Visual Studio
2. Right-click on **Chip8emu** project  
3. **Properties**
4. Select **All Configurations** in **Configuration** dropdown  
5. Go to **Configuration Properties -> VC++ Directories**
6. Click on edit next to **Include Directories**
7. And enter paths to SDL2 and SDL2mixer includes
My are:  
C:\Development\Dependencies\SDL2_mixer-2.0.1\include  
C:\Development\Dependencies\SDL2-2.0.4\include  
8. Click on edit next to **Library Directories**
9. And enter paths to SDL2 and SDL2mixer libraries  
My are:  
C:\Development\Dependencies\SDL2_mixer-2.0.1\lib\x86  
C:\Development\Dependencies\SDL2-2.0.4\lib\x86  
10. Go to **C/C++ -> General**  
11. Click on edit next to **Additional Include Directories**
12. And enter paths to SDL2 and SDL2mixer includes  
My are:  
C:\Development\Dependencies\SDL2_mixer-2.0.1\include  
C:\Development\Dependencies\SDL2-2.0.4\include  
13.  Go To **Linker -> Input**  
14.  Click on edit next to **Additional Dependencies**  
15.  And add each on separate line like this:  
SDL2.lib  
SDL2main.lib  
SDL2_mixer.lib  
16. Done. Build the solution.



## Attributions  
**Beep Sound:** https://www.freesound.org/people/unfa/sounds/215416  
**tiny file dialogs:** Guillaume Vareille, http://tinyfiledialogs.sourceforge.net
