# Replay

Saves a short audio replay of the last few seconds, similar to an instant replay used in sports matches. Useful during virtual school lessons. 

Negates the need to constantly record your virtual school lessons to capture a key phrase. Simply type 's' whenever you missed something and the last 30 seconds of audio will be saved to your drive.

## Installation

Clone this git repo and compile the C++ file using g++. Use this command:

``` 
g++ Record.cpp replay.cpp -pthread -o replay
```

Now there will be an executable named 'replay' in your current directory.

Assuming you are on Linux, you will need to configure the ffmpeg source using 'pavucontrol'.  To do this, open pavucontrol while 'replay' is running, click on 'Recording', and look for the row corresponding to the ffmpeg instance (probably Lavf... or smtg). In the dropdown menu, select 'Monitor of ...' where ... is the speaker whose audio you wish to record. Pavucontral will remember this configuration, so you will only have to do it once. If you want to change the source from which you record audio, repeat this process but choose another 'Monitor of ...', perhaps the one for your headphones.

## Dependancies

You will need ffmpeg installed, since it is used to grab your computer's audio.

## Usage

``` $ replay [-b bitrate] [-d delay] ```

After running `replay`, you can give input through the terminal

Type 's' to save the last 'd' seconds. A 'saved recording' info message will appear.

Type 'q' to quit

## Options

```
-d [delay_in_sec]
```

- set the number of seconds of past audio to record when 's' is typed
- default value: 30

```
-b [bitrate_in_kHz]
```

- set the bitrate of the audio recorded
- higher bitrate means better quality audio but also a larger filesize
- default value: 50
