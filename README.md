# Temperature Converter Tool (`tempconv`)

A simple command-line and interactive tool to convert temperatures between Fahrenheit and Celsius. The tool also includes a visually appealing output using the `drawbox` utility.

## Features
- Convert Fahrenheit to Celsius.
- Convert Celsius to Fahrenheit.
- Interactive mode for easy use.
- Command-line mode for scripting.
- Visually appealing output using `drawbox`.

## Installation

### Prerequisites
- **C++ Compiler**: Ensure you have `g++` or `clang` installed.
- **DrawBox Utility**: The `drawbox` utility is required for the visual output. You can compile it from source.

### Step 1: Install `drawbox`
1. Download the `drawbox.cpp` file:
   ```bash
   wget https://raw.githubusercontent.com/KaliforniaGator/DrawBox/refs/heads/main/drawbox.cpp
   ```
2. Compile `drawbox` using `g++` or `clang`:
   ```bash
   g++ drawbox.cpp -o drawbox
   ```
   or
   ```bash
   clang++ drawbox.cpp -o drawbox
   ```
  If you don't want to compile, you can download the binary directly from:
  
  MacOS:
  https://github.com/KaliforniaGator/DrawBox/releases/tag/macOS

  Linux:
  https://github.com/KaliforniaGator/DrawBox/releases/tag/binary
  
   
3. Move the `drawbox` executable to a directory in your `PATH` (e.g., `/usr/local/bin`):
   ```bash
   sudo mv drawbox /usr/local/bin/
   ```

### Step 2: Compile `tempconv`
1. Clone this repository or download the `tempconv.cpp` file.
2. Compile `tempconv` using `g++` or `clang`:
   ```bash
   g++ TempConv.cpp -o tempconv
   ```
   or
   ```bash
   clang++ TempConv.cpp -o tempconv
   ```
3. Move the `tempconv` executable to a directory in your `PATH` (e.g., `/usr/local/bin`):
   ```bash
   sudo mv tempconv /usr/local/bin/
   ```

## Usage

### Command-Line Mode
You can use `tempconv` directly from the command line with the following options:
```bash
tempconv -cF <temperature>  # Convert Celsius to Fahrenheit
tempconv -fC <temperature>  # Convert Fahrenheit to Celsius
tempconv --help             # Display help message
```

#### Examples:
- Convert 25°C to Fahrenheit:
  ```bash
  tempconv -cF 25
  ```
- Convert 77°F to Celsius:
  ```bash
  tempconv -fC 77
  ```

### Interactive Mode
If you run `tempconv` without any arguments, it will launch in interactive mode:
```bash
tempconv
```
You will be presented with a menu where you can choose to:
1. Convert Fahrenheit to Celsius.
2. Convert Celsius to Fahrenheit.
3. Exit the program.

## Example Output
When converting temperatures, the result will be displayed in a visually appealing box using the `drawbox` utility:
```
+-----------------------------+
| 77.00F is 25.00C            |
+-----------------------------+
```

## Troubleshooting
- **Invalid Input**: If you enter a non-numeric value for the temperature, the program will display an error message and prompt you to enter a valid number.
- **Missing `drawbox`**: If the `drawbox` utility is not installed or not in your `PATH`, the program will not display the box around the output. Ensure `drawbox` is properly installed.

## License
This project is open-source and available under the [MIT License](LICENSE).

## Contributing
Contributions are welcome! Please open an issue or submit a pull request if you have any improvements or bug fixes.

---

Enjoy converting temperatures with style! 🌡️
