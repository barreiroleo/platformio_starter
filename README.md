# Platformio template and simulation

- C++17 standard.
- Debug and release configurations for AVR ATmega328 boards.
- Core libraries.

## Linux + Simulide

1. Start a pair of linked virtual serial ports:
    ```sh
    socat -d -d pty,raw,echo=0,link=/tmp/ttyS1 pty,raw,echo=0,link=/tmp/ttyS2
    ```
2. In Simulide, configure the serial port component to use `/tmp/ttyS2`.
3. Use `/tmp/ttyS1` with your preferred monitoring tool, for example:
    ```sh
    pio device monitor --port /tmp/ttyS1 --baud 9600 --echo --filter time
    # Or
    picocom -b 19600 -r -l /tmp/ttyS1
    # Or
    cat /tmp/ttyS1
    ```

---

## Linux + QEMU (VirtManager) + Windows 10 + Proteus

After setting up your system:

1. Add a serial port to your VM by editing the XML configuration:
    ```xml
    <serial type="unix">
      <source mode="bind" path="/tmp/vm-serial.sock"/>
      <target type="isa-serial" port="0">
        <model name="isa-serial"/>
      </target>
    </serial>
    ```
2. Expose the socket as a virtual serial port:
    ```sh
    sudo socat UNIX-CONNECT:/tmp/vm-serial.sock PTY,link=/tmp/ttyV0,raw,echo=0
    ```
3. Monitor the serial port:
    ```sh
    sudo $HOME/.local/bin/pio device monitor --port /tmp/ttyV0 --baud 9600 --echo --filter time
    ```
    > Note: Root privileges are required to access `/tmp/ttyV0`.

---

## Windows + Com0Com + Proteus

1. Download and install Com0Com: [https://sourceforge.net/projects/com0com/](https://sourceforge.net/projects/com0com/)
2. Use the Setup tool to create a new virtual serial port pair.
3. Configure Proteus to use the new port.
4. Monitor the port with your preferred tools as usual.
