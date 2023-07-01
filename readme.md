# EAC Example Game Cheat
A simple data manipulation cheat for the eos-eac-example-game (https://github.com/msc-dev-ac/eos-eac-example-game).  If successful, once loaded into the game process memory via preload linking, this cheat hooks the `send()` function from libc changing any 'HELLO' messages to 'PWNED'.  Rather than using the LD_PRELOAD environment variable to load the cheat, the `/etc/ld.so.preload` file is used to avoid any issues with environment variables not being passed from the launcher to the game process.

## Usage
```bash
# The setup file contains functions to build/load the cheat
$> source setup.sh

# Build the cheat.so shared object file
$> build

# Put the cheat into /etc/ld.so.preload (note this will apply the cheat to all processes launched on the system)
$> enable

# Remove the entry from /etc/ld.so.preload
$> disable
```