# KeyScan

A tool to show you the ROW and COL of keys on a Psion SIBO/EPOC16 machine.

It is based around the `p_getscancodes()` function in PLIB, which calls the `HwGetScanCodes` system call.

It was designed to work out the keyboard wiring for the Siena, but could be used on any SIBO machine running EPOC16 3.18 or later (i.e. the Series 3a onwards, plus HCs that have been updated). It can't be used on earlier machines because `HwGetScanCodes` wasn't implemented.

## How KeyScan works

Every 0.5 seconds, KeyScan will call `p_getscancodes()`. The output of that is put into an array of 10 words, which represent the physical columns (COLs) of the keyboard. Each bit in a word represents the physical ROWs. KeyScan iterates through each COL and, if any key is pressed (i.e. if `scan[i]` isn't `0`), it works out which ROW has been activated.

KeyScan handles multiple keys pressed on the same COL, and multiple ROWs.

Each line starts with `COLc:ROWr (0xrr)`, which are the COL and ROW in decimal, followed in parentheses by the ROW mask in hex.

At the end of each line, in square brackets, KeyScan prints the COL number and its value in binary, regardless of how many keys have been pressed.

You can exit KeyScan by pressing **Psion-Esc**.

## Compiling

You will need:

- A copy of DOS (physical machine, in a VM, or DosBox)
- The Psion SIBO C SDK
- JPI TopSpeed C 3.0 or later

There are instructions in the SIBO C SDK documentation on how to set up the SDK, including the correct location of files and setting up your `PATH` environment variable.

To compile, just run `make` at the command prompt.

```powershell
C:\PROJECTS\KEYSCAN\>make
```

To remove the compiled files, run `clean` (the equivalent of `make clean`).

```powershell
C:\PROJECTS\KEYSCAN\>clean
```

## Installing

You will need to copy `KEYSCAN.IMG` to the `IMG` folder on the main drive of your SIBO device. If the folder doesn't exist, create it.

You might also need to install `RunImg`. You can do this on the System Screen by pressing **Psion-J**, selecting **RunImg** and pressing **Enter**.

You should see `KEYSCAN` below the `RunImg` icon.

## TODO
- [ ] Capture application keys

## Other Notes

I've included my `c_cpp_properties.json` file for Visual Studio Code, in case it's useful to anyone. You will need to change the path so that it points to your copy of SDK. I've set the C standard to C89 and the IntelliSense mode to `windows-msvc-x86` - this seems to make IntelliSense complain the least.
